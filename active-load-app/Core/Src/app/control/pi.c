#include "pi.h"
#include "assert.h"

void pi_init(pi_t *pi, int32_t kp, int32_t ki, int32_t dt_ms, int32_t out_min, int32_t out_max)
{
    assert(pi);
    assert(dt_ms > 0);
    assert(out_min < out_max);

    pi->kp       = kp;
    pi->ki       = ki;
    pi->dt_ms    = dt_ms;
    pi->integral = 0;
    pi->out_min  = out_min;
    pi->out_max  = out_max;
}

int32_t pi_update(pi_t *pi, int32_t setpoint, int32_t measurement)
{
    assert(pi);

    int32_t error = setpoint - measurement;

    // P
    int64_t p_term = (int64_t)pi->kp * error;

    // I
    int64_t i_step = ((int64_t)pi->ki * error * pi->dt_ms + 500) / 1000;
    pi->integral  += (int32_t)i_step;

    if (pi->integral > pi->out_max) pi->integral = pi->out_max;
    if (pi->integral < pi->out_min) pi->integral = pi->out_min;

    int64_t output = p_term + (int64_t)pi->integral;

    if (output > pi->out_max) return pi->out_max;
    if (output < pi->out_min) return pi->out_min;

    return (int32_t)output;
}

void pi_rst(pi_t *pi)
{
    assert(pi);
    pi->integral = 0;
}
