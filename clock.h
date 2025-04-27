#pragma once
#ifndef CLOCK_APP_H
#define CLOCK_APP_H

#include "lvgl.h"

#define NUM_FORECAST_DAYS 6

#ifdef __cplusplus
extern "C" {
#endif

    void clock_app_init(void);

#ifdef __cplusplus
}
#endif

#endif // CLOCK_APP_H

