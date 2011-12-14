/*
 * =====================================================================================
 *
 *       Filename:  serial_lon9263.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011年12月13日 00时27分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <common.h>
#include <watchdog.h>
#include <serial.h>
#include "tl16c752_reg.h"
#define BAND       9600
#define BASEADDR  (0x30000000)

static int lon9263_init(void)
{
}
static void lon9263_setbrg(void)
{
}

static void lon9263_putc(const char c)
{

}

static void lon9263_puts(const char *s)
{
	return pxa_puts_dev(lon9263_INDEX,s);
}

static int lon9263_getc(void)
{
	return pxa_getc_dev(lon9263_INDEX);
}

static int lon9263_tstc(void)
{
	return pxa_tstc_dev(lon9263_INDEX);
}


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
};
