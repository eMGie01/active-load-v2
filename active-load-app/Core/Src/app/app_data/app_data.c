#include "app_data.h"
#include "app_config.h"
#include "stm32l1xx_hal.h"

//

static int32_t s_voltage_max = 0;
static int32_t s_voltage_min = 0;
static int32_t s_current_max = 0;
static volatile int32_t s_voltage_code = 0;
static volatile int32_t s_current_code = 0;
static int32_t s_power_max = 0;
static volatile uint32_t s_timestamp = 0;
static int32_t s_temp_int = 0;

//

void app_data_init(void)    
{
    s_voltage_code = 0;
    s_current_code = 0;
    s_timestamp = 0;
    s_voltage_max = SAFETY_VOLTAGE_MAX;
    s_current_max = SAFETY_CURRENT_MAX;
    s_power_max = SAFETY_POWER_MAX;
}

// --- setters called only by cntrl module ---

void app_data_set_voltage_code(int32_t val)
{
    s_voltage_code = val;
    s_timestamp = HAL_GetTick();
}

//

void app_data_set_current_code(int32_t val)
{
    s_current_code = val;
    s_timestamp = HAL_GetTick();
}

// --- setters called by COMM module ---

void app_data_set_voltage_max(int32_t val)
{
    if (val > SAFETY_VOLTAGE_MAX)
    {
        // log, that it cannot be higher than DEFAULT one
        s_voltage_max = SAFETY_VOLTAGE_MAX;
    }
    else
    {
        s_voltage_max = val;
    }
}

//

void app_data_set_voltage_min(int32_t val)
{
    if (val < SAFETY_VOLTAGE_MIN)
    {
        // log, that it cannot be lower than DEFAULT one
        s_voltage_max = SAFETY_VOLTAGE_MAX;
    }
    else
    {
        s_voltage_min = val;
    }
}

//

void app_data_set_current_max(int32_t val)
{
    if (val > SAFETY_CURRENT_MAX)
    {
        // log, that it cannot be higher than DEFAULT one
        s_current_max = SAFETY_CURRENT_MAX;
    }
    else
    {
        s_current_max = val;
    }
}

//

void app_data_set_power_max(int32_t val)
{
    if (val > SAFETY_POWER_MAX)
    {
        // log, that it cannot be higher than DEFAULT one
        s_power_max = SAFETY_POWER_MAX;
    }
    else
    {
        s_power_max = val;
    }
}

//  -- getters ---

int32_t app_data_get_voltage_code(void)
{
    return s_voltage_code;
}

//

int32_t app_data_get_current_code(void)
{
    return s_current_code;
}

//

int32_t app_data_get_voltage_max(void)
{
    return s_voltage_max;
}

//

int32_t app_data_get_voltage_min(void)
{
    return s_voltage_min;
}

//

int32_t app_data_get_current_max(void)
{
    return s_current_max;
}

//

int32_t app_data_get_power_max(void)
{
    return s_power_max;
}

//

uint32_t app_data_get_timestamp(void)
{
    return s_timestamp;
}

//

int32_t app_data_get_temp_int(void)
{
    return s_temp_int;
}
