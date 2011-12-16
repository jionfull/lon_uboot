/*
 * COM1 lonPlat support
 * originally from linux source (arch/powerpc/boot/ns16550.c)
 * modified to use CONFIG_SYS_ISA_MEM and new defines
 */

#include <config.h>
#include <common.h>
#include <watchdog.h>
#include <linux/types.h>
#include <asm/io.h>
#include <serial.h>
#include "tl16c752_reg.h"


#define serial_out(x,y) writeb(x,y)
#define serial_in(y) 	readb(y)
#define BASEADDR  (0x30000000)

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

static void lon9263_putc(const char c)
{
    return lonPlat_putc(c);

}

static void lon9263_puts(const char *s)
{
	while (*s) {
		lonPlat_putc(*s++);
	}
}

static int lon9263_getc(void)
{
	return lonPlat_getc();
}

static int lon9263_tstc(void)
{
	return lonPlat_tstc();
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
