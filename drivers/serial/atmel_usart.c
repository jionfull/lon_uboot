/*
 * Copyright (C) 2004-2006 Atmel Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <common.h>
#ifndef CONFIG_AT91_LEGACY
#define CONFIG_AT91_LEGACY
#warning Please update to use C structur SoC access !
#endif
#include <watchdog.h>

#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/memory-map.h>

#if defined(CONFIG_USART0)
# define USART_ID	0
# define USART_BASE	USART0_BASE
#elif defined(CONFIG_USART1)
# define USART_ID	1
# define USART_BASE	USART1_BASE
#elif defined(CONFIG_USART2)
# define USART_ID	2
# define USART_BASE	USART2_BASE
#elif defined(CONFIG_USART3)
# define USART_ID	3
# define USART_BASE	USART3_BASE
#endif


#include "tl16c752_reg.h"

#define serial_out(x,y) writeb(x,y)
#define serial_in(y) 	readb(y)
#define BASEADDR  (0x30000000)

DECLARE_GLOBAL_DATA_PTR;

void lonPlat_init ()
{
}


void lonPlat_putc ( char c)
{
	while ((serial_in(BASEADDR+FRR) & 0x01) == 0);
	serial_out(c, BASEADDR+BUF);
}

int lonPlat_getc ()
{
	while ((serial_in(BASEADDR+LSR) & BIT_RX_NOEMPTY) == 0) {
	}
	return serial_in(BASEADDR+BUF);
}

int lonPlat_tstc ()
{
	return ((serial_in(BASEADDR+LSR) & BIT_RX_NOEMPTY) != 0);
}

static int lon9263_init(void)
{
}
static void lon9263_setbrg(void)
{
}


void serial_setbrg(void)
{
	unsigned long divisor;
	unsigned long usart_hz;

	/*
	 *              Master Clock
	 * Baud Rate = --------------
	 *                16 * CD
	 */
}

int serial_init(void)
{
    UartPuts("serial_init_is run\r\n");
	return 0;
}

void serial_putc(char c)
{
	if (c == '\n')
		serial_putc('\r');
    return lonPlat_putc(c);

}

void serial_puts(const char *s)
{
	while (*s)
		serial_putc(*s++);
}

int serial_getc(void)
{
	return lonPlat_getc();
}

int serial_tstc(void)
{
	return lonPlat_tstc();
}
/* 
struct serial_device serial_lon9263_device =
{
	"serial_lon9263",
	"Lon",
	lon9263_init,
	NULL,
	lon9263_setbrg,
	lon9263_getc,
	lon9263_tstc,
	lon9263_putc,
	lon9263_puts,
}; */
