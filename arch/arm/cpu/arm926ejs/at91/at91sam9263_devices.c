/*
 * (C) Copyright 2007-2008
 * Stelian Pop <stelian.pop@leadtechdesign.com>
 * Lead Tech Design <www.leadtechdesign.com>
 *
 * (C) Copyright 2009
 * Daniel Gorsulowski <daniel.gorsulowski@esd.eu>
 * esd electronic system design gmbh <www.esd.eu>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/hardware.h>
#include <asm/arch/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_pmc.h>
#include <asm/arch/at91_pio.h>





void at91_serial_hw_init(void)
{


}

#ifdef CONFIG_HAS_DATAFLASH
void at91_spi0_hw_init(unsigned long cs_mask)
{

}

void at91_spi1_hw_init(unsigned long cs_mask)
{
}
#endif

#ifdef CONFIG_MACB
void at91_macb_hw_init(void)
{
	at91_set_a_periph(AT91_PIO_PORTE, 21, 0);	/* ETXCK_EREFCK */
	at91_set_b_periph(AT91_PIO_PORTC, 25, 0);	/* ERXDV */
	at91_set_a_periph(AT91_PIO_PORTE, 25, 0);	/* ERX0 */
	at91_set_a_periph(AT91_PIO_PORTE, 26, 0);	/* ERX1 */
	at91_set_a_periph(AT91_PIO_PORTE, 27, 0);	/* ERXER */
	at91_set_a_periph(AT91_PIO_PORTE, 28, 0);	/* ETXEN */
	at91_set_a_periph(AT91_PIO_PORTE, 23, 0);	/* ETX0 */
	at91_set_a_periph(AT91_PIO_PORTE, 24, 0);	/* ETX1 */
	at91_set_a_periph(AT91_PIO_PORTE, 30, 0);	/* EMDIO */
	at91_set_a_periph(AT91_PIO_PORTE, 29, 0);	/* EMDC */

#ifndef CONFIG_RMII
	at91_set_a_periph(AT91_PIO_PORTE, 22, 0);	/* ECRS */
	at91_set_b_periph(AT91_PIO_PORTC, 26, 0);	/* ECOL */
	at91_set_b_periph(AT91_PIO_PORTC, 22, 0);	/* ERX2 */
	at91_set_b_periph(AT91_PIO_PORTC, 23, 0);	/* ERX3 */
	at91_set_b_periph(AT91_PIO_PORTC, 27, 0);	/* ERXCK */
	at91_set_b_periph(AT91_PIO_PORTC, 20, 0);	/* ETX2 */
	at91_set_b_periph(AT91_PIO_PORTC, 21, 0);	/* ETX3 */
	at91_set_b_periph(AT91_PIO_PORTC, 24, 0);	/* ETXER */
#endif
}
#endif

#ifdef CONFIG_USB_OHCI_NEW
void at91_uhp_hw_init(void)
{
	/* Enable VBus on UHP ports */
	at91_set_pio_output(AT91_PIO_PORTA, 21, 0);
	at91_set_pio_output(AT91_PIO_PORTA, 24, 0);
}
#endif

#ifdef CONFIG_AT91_CAN
void at91_can_hw_init(void)
{
	at91_pmc_t	*pmc	= (at91_pmc_t *) AT91_PMC_BASE;

	at91_set_a_periph(AT91_PIO_PORTA, 13, 0);	/* CAN_TX */
	at91_set_a_periph(AT91_PIO_PORTA, 14, 1);	/* CAN_RX */

	/* Enable clock */
	writel(1 << AT91SAM9263_ID_CAN, &pmc->pcer);
}
#endif
