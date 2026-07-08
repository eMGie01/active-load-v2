#include "drv_init.h"
#include "board_config.h"
#include "mcp3561.h"
#include "mcp3561_regs.h"
#include "spi.h"

static drv_handles_t s_drv = {0};

void drv_init()
{
    // MCP3561 - VOLTAGE
    mcp3561_init(&s_drv.adc_voltage, &hspi2, V_ADC_CS_PORT, V_ADC_CS_PIN);
    mcp3561_cfg_t adc_voltage_cfg = {0};
    adc_voltage_cfg.dev_id = 0x01;
    adc_voltage_cfg.config0 = CLK_SEL_INT_CLK_OUTPUT_DIS << MCP3561_CONFIG0_CLK_SEL_POS | CS_SEL_NO_CURRENT_SOURCE << MCP3561_CONFIG0_CS_SEL_POS | ADC_MODE_CONVERSION << MCP3561_CONFIG0_ADC_MODE_POS;
    adc_voltage_cfg.config1 = PRE_AMCLK_MCLK_DIV_1 << MCP3561_CONFIG1_PRE_POS | OSR_98304 << MCP3561_CONFIG1_OSR_POS;
    adc_voltage_cfg.config2 = BOOST_CH_CUR_X1 << MCP3561_CONFIG2_BOOST_POS | GAIN_X1 << MCP3561_CONFIG2_GAIN_POS | AZ_MUX_AUTO_ZEROING_DIS << MCP3561_CONFIG2_AZ_MUX_POS;
    adc_voltage_cfg.config3 = CONV_MODE_CONTINOUS << MCP3561_CONFIG3_CONV_MODE_POS | DATA_FORMAT_24_BIT << MCP3561_CONFIG3_DATA_FORMAT_POS;
    adc_voltage_cfg.irq = IRQ_MODE_LH_IRQ << MCP3561_IRQ_IRQ_MODE_POS | EN_FASTCMD_EN << MCP3561_IRQ_FASTCMD_POS | EN_STP_DIS << MCP3561_IRQ_EN_STP_POS;
    adc_voltage_cfg.mux = MUX_CH0 << MCP3561_MUX_MUX_VIN_P_POS | MUX_AGND << MCP3561_MUX_MUX_VIN_N_POS;
    adc_voltage_cfg.scan = 0U;
    adc_voltage_cfg.timer = 0U;
    adc_voltage_cfg.offsetcal = 0U;
    adc_voltage_cfg.gaincal = 0U;
    mcp3561_save_cfg(&s_drv.adc_voltage, &adc_voltage_cfg);
}