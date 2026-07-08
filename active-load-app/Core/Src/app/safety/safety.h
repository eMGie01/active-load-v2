#pragma once

#include <stdbool.h>

typedef enum
{
    SAFETY_OK = 0,
    SAFETY_WARN = -1,
    SAFETY_FAULT = -2,
} safety_st_t;

void safety_init(void);
void safety_deinit(void);
void safety_prcs(void);
void safety_rst(void);

safety_st_t safety_get_status(void);
