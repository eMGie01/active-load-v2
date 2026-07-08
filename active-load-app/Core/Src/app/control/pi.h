#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pi_controller
{
    int32_t kp;
    int32_t ki;
    int32_t dt_ms;
    int32_t integral;
    int32_t out_min;
    int32_t out_max;
} pi_t;

void    pi_init(pi_t *pi, int32_t kp, int32_t ki, int32_t dt_ms, int32_t out_min, int32_t out_max);
int32_t pi_update(pi_t *pi, int32_t setpoint, int32_t meas);
void    pi_rst(pi_t *pi);
void    pi_deinit(pi_t *pi);

#ifdef __cplusplus
}
#endif
