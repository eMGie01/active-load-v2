#include "application.h"
#include "app_data.h"
#include "comm.h"
#include "control.h"
#include "main.h"
#include "safety.h"
#include "sd_card.h"
#include "ui.h"

//

static enum app_st   s_state  = 0;
static enum app_evt  s_event  = 0;

//

static void s_app_st_idle(void);
static void s_app_st_strt(void);
static void s_app_st_run(void);
static void s_app_st_stop(void);
static void s_app_st_rst(void);
static void s_app_st_err(void);

//

static void s_switch_st(const enum app_st new_st)
{
   s_state = new_st;
}

//

void app_runtime(void)
{
   safety_prcs();
   if (safety_get_status() == SAFETY_FAULT)
   {
      cntrl_dis();
      s_switch_st(APP_ST_ERR);
   }

   switch (s_state)
   {
      case APP_ST_IDLE:
      {
         s_app_st_idle();
         break;
      }
      case APP_ST_STRT:
      {
         s_app_st_strt();
         break;
      }
      case APP_ST_RUN:
      {
         s_app_st_run();
         break;
      }
      case APP_ST_STOP:
      {
         s_app_st_stop();
         break;
      }
      case APP_ST_RST:
      {
         s_app_st_rst();
         break;
      }
      case APP_ST_ERR:
      {
         s_app_st_err();
         break;
      }
      default:
      {
         s_app_st_err();
         break;
      }
   }
}

// 

void app_init(void)
{
   s_state = APP_ST_IDLE;
   s_event = APP_EVT_NONE;

   (void)app_data_init();
   (void)safety_init();
   (void)comm_init();
   (void)cntrl_init();
   (void)ui_init();
   (void)sd_card_init();
}

//

void app_deinit(void)
{
   // it does not have turn off button, so it is not applicated yet
   (void)sd_card_deinit();
   (void)ui_deinit();
   (void)cntrl_deinit();
   (void)comm_deinit();
   (void)safety_deinit();
}

//

void app_evt_push(enum app_evt new_evt)
{
   s_event = new_evt;
}

//

static void s_app_st_idle(void)
{
   (void)ui_prcs();
   (void)comm_prcs();

   if (s_event == APP_EVT_START)
   {
      s_event = APP_EVT_NONE;
      s_switch_st(APP_ST_STRT);
   }
}

//

static void s_app_st_strt(void)
{
   cntrl_en();
   s_switch_st(APP_ST_RUN);
}

//

static void s_app_st_run(void)
{
   (void)ui_prcs();
   (void)comm_prcs();
   (void)sd_card_prcs();

   if (s_event == APP_EVT_STOP)
   {
      s_event = APP_EVT_NONE;
      cntrl_dis();
      s_switch_st(APP_ST_STOP);
      // start timer for 30 sek to gather rest data ... after 30 sek send event about rstrt
   }
   else if (s_event == APP_EVT_FAULT)
   {
      s_event = APP_EVT_NONE;
      cntrl_dis();
      s_switch_st(APP_ST_ERR);
   }
}

//

static void s_app_st_stop(void)
{
   (void)ui_prcs();
   (void)comm_prcs();
   (void)sd_card_prcs();

   if (s_event == APP_EVT_RSTRT)
   {
      s_event = APP_EVT_NONE;
      s_switch_st(APP_ST_RST);
   }
}

//

static void s_app_st_rst(void)
{
   (void)cntrl_rst();
   (void)sd_card_rst();
   (void)ui_rst();
   (void)safety_rst();
   s_event = APP_EVT_NONE;
   s_switch_st(APP_ST_IDLE);
}

//

static void s_app_st_err(void)
{
   // TODO: log error, signal UI, decide revovery
   Error_Handler();  // just for now
}

//
