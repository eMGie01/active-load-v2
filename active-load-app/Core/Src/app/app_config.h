#pragma once

// --- hardware limits ---
#define APP_VOLTAGE_MAX_MV      14500   // 15V max input
#define APP_VOLTAGE_MIN_MV      11000   // 11V min input
#define APP_CURRENT_MAX_MA      12000   // 12A max current sink
#define APP_POWER_MAX_MW        50000   // 50W max power sink
#define APP_TEMP_MAX_C          150     // 150°C max heatsink

// --- safety module ---
#define SAFETY_VOLTAGE_MAX      APP_VOLTAGE_MAX_MV
#define SAFETY_VOLTAGE_MIN      APP_VOLTAGE_MIN_MV
#define SAFETY_CURRENT_MAX      APP_CURRENT_MAX_MA
#define SAFETY_POWER_MAX        APP_POWER_MAX_MW
#define SAFETY_TEMP_MAX         APP_TEMP_MAX_C
#define SAFETY_MEAS_TIMEOUT_MS  1000    // 1 second timeout
