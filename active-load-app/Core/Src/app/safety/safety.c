#include "safety.h"
#include "app_data.h"
#include "app_config.h"
#include "stm32l1xx_hal.h"

//

static safety_st_t s_status = 0;

//

void safety_init(void)
{
    s_status = SAFETY_OK;
}

//

void safety_deinit(void)
{

}

//

void safety_prcs(void)
{
    // TODO: Logging errors, which are critical!
    int32_t voltage_mV = app_data_get_voltage();
    if ( voltage_mV >= app_data_get_voltage_max())
    {
        s_status = SAFETY_FAULT;
    }
    else if (voltage_mV < app_data_get_voltage_min())
    {
        s_status = SAFETY_FAULT;
    }

    int32_t current_mA = app_data_get_current();
    if (current_mA >= app_data_get_current_max())
    {
        s_status = SAFETY_FAULT;
    }

    if ((voltage_mV * current_mA / 1000) >= app_data_get_power_max())
    {
        s_status = SAFETY_FAULT;
    }

    if (app_data_get_temp_int() > SAFETY_TEMP_MAX)
    {
        s_status = SAFETY_FAULT;
    }

    if ((HAL_GetTick() - app_data_get_timestamp()) > SAFETY_MEAS_TIMEOUT)
    {
        s_status = SAFETY_FAULT;
    }
}

//

void safety_rst(void)
{
    s_status = SAFETY_OK;
}

//



//

safety_st_t safety_get_status(void)
{
    return s_status;
}
