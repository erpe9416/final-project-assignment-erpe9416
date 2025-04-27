#include <stdio.h>
#include <stdlib.h>

#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"

#include "demo_app.h"
#include "clock.h"

int main(int argc, char **argv)
{
    /* 1) Initialize LVGL */
    lv_init();

    /* 2) Initialize the display driver (fbdev/drm/sdl/etc) */
    lv_linux_disp_init();

    /* 3) Build our clock screen */
    clock_app_init();

    lv_demo_run_loop(); 

    return 0;
}
