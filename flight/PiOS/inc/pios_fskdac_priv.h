/**
 ******************************************************************************
 * @addtogroup PIOS PIOS Core hardware abstraction layer
 * @{
 * @addtogroup   PIOS_FSKDAC FSK DAC Functions
 * @brief PIOS interface for FSK DAC implementation
 * @{
 *
 * @file       pios_fskdac.h
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2015
 * @brief      Generates Bel202 encoded serial data on the DAC channel
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


#ifndef PIOS_FSKDADC_PRIV_H
#define PIOS_FSKDADC_PRIV_H

#include <pios.h>
#include <pios_stm32.h>
#include "fifo_buffer.h"

extern const struct pios_com_driver pios_fskdac_com_driver;

//! Configuration structure for FSK DAC
struct pios_fskdac_config {
	struct stm32_dma dma;
	struct pios_tim_channel tim;
	TIM_TimeBaseInitTypeDef tim_base;
};

extern int32_t PIOS_FSKDAC_Init(uintptr_t * fskdac_id, const struct pios_fskdac_config * cfg);
extern void PIOS_FSKDAC_DMA_irq_handler();

#endif /* PIOS_FSKDADC_PRIV_H */