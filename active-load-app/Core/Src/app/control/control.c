#include "control.h"
#include "pi.h"
#include "app_data.h"
// #include "drv_dac.h"
#include "drv_voltage.h"
#include "drv_current.h"

#include <stdbool.h>
#include <stdint.h>

//

static volatile bool s_enabled = false;
static pi_t pi = {0};

//

int32_t s_cntrl_calc_setpoint(int32_t v_code)
{
    switch(app_data_get_mode())
    {
        case APP_DATA_MODE_CC:
            return app_data_get_setpoint_code();
        case APP_DATA_MODE_CP:
            return app_data_get_setpoint_code() / v_code;
        case APP_DATA_MODE_CR:
            return v_code / app_data_get_setpoint_code();
        default:
            return 0;
    }
}

//

void cntrl_isr()
{
    int32_t voltage_code = drv_voltage_read(); // this is bit value
    int32_t current_code = drv_current_read();

    app_data_set_voltage_code(voltage_code);
    app_data_set_current_code(current_code);

    if (s_enabled)
    {
        // int32_t setpoint_code = s_cntrl_calc_setpoint(voltage_code); // in bit value
        // int32_t output_code = pi_update(&pi, setpoint_code, current_code); // only CC for now
        // drv_dac_set(output_code); // in bit value
    }
}

//

void cntrl_init(void)
{
    s_enabled = false;
    int32_t kp = app_data_get_m_kp();
    int32_t ki = app_data_get_m_ki();
    pi_init(&pi, );

    drv_dac_set(0);
}

//

void cntrl_deinit(void)
{
    cntrl_dis();
    pi_deinit();
}

//

void cntrl_update(void)
{
    cntrl_dis();
    pi_deinit();
    pi_init();
}

//

void cntrl_en(void)
{
    pi_reset();
    s_enabled = true;
}

//

void cntrl_dis(void)
{
    s_enabled = false;
    drv_dac_set(0);
}

//

void cntrl_rst(void)
{
    cntrl_dis();
    pi_reset();
}

//

