/**
 * @file mcp3561.h
 * @author Marek Gałeczka
 * @brief 
 * @version 0.2
 * @date 2026-07-06
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "mcp3561_regs.h"
#include "stm32l1xx.h"

typedef enum 
{
    MCP_OK              = (0),
    MCP_INVALID_ARG_ERR = (-1),
    MCP_RUNTIME_ERR     = (-2),
    MCP_NOT_INITIALIZED = (-3),
    MCP_ALREADY_INITED  = (-4),
} mcp3561_err_t;

typedef struct
{
    uint8_t             dev_id;
    uint8_t             config0;
    uint8_t             config1;
    uint8_t             config2;
    uint8_t             config3;
    uint8_t             irq;
    uint8_t             mux;
    uint32_t            scan;
    uint32_t            timer;
    uint32_t            offsetcal;
    uint32_t            gaincal;
} mcp3561_cfg_t;

typedef struct
{
    SPI_HandleTypeDef   *hspi;
    GPIO_TypeDef        *cs_port;
    uint16_t            cs_pin;
    mcp3561_cfg_t       config;
    bool                init;
} mcp3561_t;

mcp3561_err_t mcp3561_init(mcp3561_t *h, SPI_HandleTypeDef *hspi, GPIO_TypeDef *port, uint16_t pin);
mcp3561_err_t mcp3561_save_cfg(mcp3561_t *h, mcp3561_cfg_t *cfg);
mcp3561_err_t mcp3561_deinit(mcp3561_t *h);

mcp3561_err_t mcp3561_reset(mcp3561_t *h, uint32_t timeout_ms);
mcp3561_err_t mcp3561_write_cfg(mcp3561_t *h, uint32_t timeout_ms);
mcp3561_err_t mcp3561_read_cfg(mcp3561_t *h, mcp3561_cfg_t *cfg, uint32_t timeout_ms);
mcp3561_err_t mcp3561_read_adc(mcp3561_t *h, int32_t *raw, uint32_t timeout_ms);

#ifdef __cplusplus
}
#endif
