/*
 * =====================================================================================
 *
 *       Filename:  tl16c752.h
 *
 *    Description:  register struct
 *
 *        Version:  1.0
 *        Created:  2011年09月27日 01时40分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */


#ifndef  tl16c752_reg_INC
#define  tl16c752_reg_INC

#define WRITEREG(ADDR,VAL) (*(volatile unsigned char *)(ADDR))=(VAL)
#define writeb(value, address) \
	(*(volatile unsigned char *)(address)) = (value)
#define READREG(ADDR) (*(volatile unsigned char *)(ADDR))
#define BUF     0x00
#define IER     0x01
#define IIR     0x02
#define LCR     0x03
#define MCR     0x04
#define LSR     0x05
#define MSR     0x06
#define SPR     0x07

#define DLL     0x00
#define DLH     0x01
#define AFR     0x02
#define FCR     0x02
#define EFR     0x02
#define XON_1     0x04
#define XON_2     0x05
#define XOFF_1     0x06
#define XOFF_2     0x07
#define TCR     0x05
#define TLR     0x06
#define FRR     0x07


//FCR BIT define
#define BIT_FIFO_EN (0x01)
#define BIT_CLRFIFO (0x02)
#define BIT_TX_TRIG_LEVEL_8 (0x00)
#define BIT_TX_TRIG_LEVEL_16 (0x10)
#define BIT_TX_TRIG_LEVEL_32 (0x20)
#define BIT_TX_TRIG_LEVEL_56 (0x30)
#define BIT_RX_TRIG_LEVEL_8 (0x00)
#define BIT_RX_TRIG_LEVEL_16 (0x40*1)
#define BIT_RX_TRIG_LEVEL_32 (0x40*2)
#define BIT_RX_TRIG_LEVEL_56 (0x40*3)

//LCR bit define
#define BIT_STOP_BITS_1 (0x00)
#define BIT_STOP_BITS_2 (0x01<<3)
#define BIT_WORDLEN_8 (0x03)
#define BIT_LATCH_EN (0x80)
#endif   /* ----- #ifndef tl16c752_inc_INC  ----- */

//LSR BIT define
#define BIT_RX_NOEMPTY (0x01)
#define BIT_RX_OVERRUN (0x01<<1)
#define BIT_RX_PARITYERR (0x01<<2)
#define BIT_RX_FRAMINGERR (0x01<<3)
#define BIT_RX_BREAK     (0x01<<4)
#define BIT_TX_HLODEMPTY (0x01<<5)
#define BIT_TX_SHIFTEMPTY (0x01<<6)
#define BIT_TX_HAVEERR     (0x01<<6)

//FIFO_RDY BIT DEFINE
#define  BIT_TX_CHA_SPACEENOUGH (0x01)
#define  BIT_TX_CHB_SPACEENOUGH (0x02)
#define  BIT_TX_CHA_CHARENOUGH (0x10)
#define  BIT_TX_CHB_CHARENOUGH (0x20)
