#pragma once

#include <stdint.h>

enum app_data_mode
{
    APP_DATA_MODE_CC = 0,
    APP_DATA_MODE_CP = 1,
    APP_DATA_MODE_CR = 2,
};

void app_data_init(void);

// --- setters called only by cntrl module ---
void app_data_set_voltage_code(int32_t val);
void app_data_set_current_code(int32_t val);

// --- setters called by COMM module ---
void app_data_set_voltage_max(int32_t val);
void app_data_set_voltage_min(int32_t val);
void app_data_set_current_max(int32_t val);
void app_data_set_power_max(int32_t val);
void app_data_set_setpoint(int32_t val);
void app_data_set_mode(enum app_data_mode mode);

// -- getters ---
int32_t app_data_get_voltage_code(void);
int32_t app_data_get_voltage(void);
int32_t app_data_get_current_code(void);
int32_t app_data_get_current(void);
int32_t app_data_get_voltage_max(void);
int32_t app_data_get_voltage_min(void);
int32_t app_data_get_current_max(void);
int32_t app_data_get_power_max(void);
int32_t app_data_get_setpoint_code(void);
uint32_t app_data_get_timestamp(void);
int32_t app_data_get_temp_int(void);
enum app_data_mode app_data_get_mode(void);
