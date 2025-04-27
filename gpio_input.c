#include "gpio_input.h"
#include <gpiod.h>
#include <unistd.h>
#include <poll.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define GPIO_CHIP "/dev/gpiochip0"
#define GPIO_LINE_1 17
#define GPIO_LINE_2 27
#define CONSUMER "clock_app"

#define DEBOUNCE_DELAY_MS     30
#define DEBOUNCE_INTERVAL_MS  200

volatile int gpio_button_1_pressed = 0;
volatile int gpio_button_2_pressed = 0;

static struct timespec last_press_1 = {0};
static struct timespec last_press_2 = {0};

static long elapsed_ms(struct timespec *last) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return (now.tv_sec - last->tv_sec) * 1000 + (now.tv_nsec - last->tv_nsec) / 1000000;
}

static void* gpio_thread(void* arg) {
    struct gpiod_chip *chip = gpiod_chip_open(GPIO_CHIP);
    struct gpiod_line *line1 = gpiod_chip_get_line(chip, GPIO_LINE_1);
    struct gpiod_line *line2 = gpiod_chip_get_line(chip, GPIO_LINE_2);
    struct gpiod_line_event event;

    gpiod_line_request_rising_edge_events(line1, CONSUMER);
    gpiod_line_request_rising_edge_events(line2, CONSUMER);

    int fd1 = gpiod_line_event_get_fd(line1);
    int fd2 = gpiod_line_event_get_fd(line2);

    struct pollfd pfds[2] = {
        { .fd = fd1, .events = POLLIN },
        { .fd = fd2, .events = POLLIN }
    };

    while (1) {
        poll(pfds, 2, -1);

        if (pfds[0].revents & POLLIN) {
            gpiod_line_event_read(line1, &event);
            if (event.event_type == GPIOD_LINE_EVENT_RISING_EDGE &&
                elapsed_ms(&last_press_1) >= DEBOUNCE_INTERVAL_MS) {
                usleep(DEBOUNCE_DELAY_MS * 1000);
                if (gpiod_line_get_value(line1)) {
                    clock_gettime(CLOCK_MONOTONIC, &last_press_1);
                    gpio_button_1_pressed = 1;
                }
            }
        }

        if (pfds[1].revents & POLLIN) {
            gpiod_line_event_read(line2, &event);
            if (event.event_type == GPIOD_LINE_EVENT_RISING_EDGE &&
                elapsed_ms(&last_press_2) >= DEBOUNCE_INTERVAL_MS) {
                usleep(DEBOUNCE_DELAY_MS * 1000);
                if (gpiod_line_get_value(line2)) {
                    clock_gettime(CLOCK_MONOTONIC, &last_press_2);
                    gpio_button_2_pressed = 1;
                }
            }
        }

        usleep(1000);
    }

    return NULL;
}

void gpio_input_start(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, gpio_thread, NULL);
    pthread_detach(thread);
}

