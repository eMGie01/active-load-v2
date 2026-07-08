#pragma once

#include "mcp3561.h"

typedef struct
{
    mcp3561_t adc_voltage;
    mcp3561_t adc_current;
} drv_handles_t;

void drv_init(void);
