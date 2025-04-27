#ifndef GPIO_INPUT_H
#define GPIO_INPUT_H


void gpio_input_start(void);

// To be updated by the gpio thread:
extern volatile int gpio_button_1_pressed;
extern volatile int gpio_button_2_pressed;

#endif

