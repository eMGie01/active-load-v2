/**
 * @file mcp3561_init.c
 * @author Marek Gałeczka
 * @brief 
 * @version 0.2
 * @date 2026-07-06
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "mcp3561.h"
#include <string.h>


mcp3561_err_t 
mcp3561_init(mcp3561_t *h, SPI_HandleTypeDef * hspi, GPIO_TypeDef * port, uint16_t pin)
{
    if ( !h || !hspi || !port )
    {
        return MCP_INVALID_ARG_ERR;
    }

    if ( h->init )
    {
        return MCP_ALREADY_INITED;
    }

    h->hspi = hspi;
    h->cs_port = port;
    h->cs_pin = pin;

    HAL_GPIO_WritePin(h->cs_port, h->cs_pin, GPIO_PIN_SET);
    h->init = true;

    return MCP_OK;
}


mcp3561_err_t
mcp3561_save_cfg(mcp3561_t *h, mcp3561_cfg_t *cfg)
{
    if ( !h || !cfg || !h->hspi || !h->cs_port || cfg->dev_id > 3u )
    {
        return MCP_INVALID_ARG_ERR;
    }

    if ( !h->init )
    {
        return MCP_NOT_INITIALIZED;
    }

    h->config = *cfg;

    h->config.config0 &= (MCP3561_CONFIG0_CLK_SEL_MSK |
                          MCP3561_CONFIG0_CS_SEL_MSK  |
                          MCP3561_CONFIG0_ADC_MODE_MSK);

    h->config.config1 &= (MCP3561_CONFIG1_PRE_MSK |
                          MCP3561_CONFIG1_OSR_MSK);

    h->config.config2   &= (MCP3561_CONFIG2_BOOST_MSK |
                            MCP3561_CONFIG2_GAIN_MSK  |
                            MCP3561_CONFIG2_AZ_MUX_MSK);

    h->config.config3   &= (MCP3561_CONFIG3_CONV_MODE_MSK   |
                            MCP3561_CONFIG3_DATA_FORMAT_MSK |
                            MCP3561_CONFIG3_CRC_FORMAT_MSK  |
                            MCP3561_CONFIG3_EN_CRCCOM_MSK   |
                            MCP3561_CONFIG3_EN_OFFCAL_MSK   |
                            MCP3561_CONFIG3_EN_GAINCAL_MSK);

    h->config.irq       &= (MCP3561_IRQ_IRQ_MODE_MSK |
                            MCP3561_IRQ_FASTCMD_MSK  |
                            MCP3561_IRQ_EN_STP_MSK);

    h->config.mux       &= (MCP3561_MUX_MUX_VIN_P_MSK |
                            MCP3561_MUX_MUX_VIN_N_MSK);

    h->config.scan      &= MCP3561_SCAN_DLY_MSK | MCP3561_SCAN_CHANNEL_SEL_MSK;
    h->config.timer     &= MCP3561_TIMER_MSK;
    h->config.offsetcal &= MCP3561_OFFSETCAL_MSK;
    h->config.gaincal   &= MCP3561_GAINCAL_MSK;
    
    return MCP_OK;
}


mcp3561_err_t
mcp3561_deinit(mcp3561_t *h)
{
    if ( !h )
    {
        return MCP_INVALID_ARG_ERR;
    }

    if ( h->cs_port )
    {
        HAL_GPIO_WritePin(h->cs_port, h->cs_pin, GPIO_PIN_SET);
    }

    memset(h, 0, sizeof(*h));
    return MCP_OK;
}