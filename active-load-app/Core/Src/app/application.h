#pragma once

// APP_STATE
enum app_st
{
    APP_ST_ERR = -1,
    APP_ST_IDLE,
    APP_ST_STRT,
    APP_ST_RUN,
    APP_ST_STOP,
    APP_ST_RST,
};

// APP_EVENT
enum app_evt
{
    APP_EVT_NONE,
    APP_EVT_START,
    APP_EVT_STOP,
    APP_EVT_RSTRT,
    APP_EVT_FAULT,
};

void app_init(void);
void app_deinit(void);
void app_runtime(void);

void app_evt_push(enum app_evt new_evt);
