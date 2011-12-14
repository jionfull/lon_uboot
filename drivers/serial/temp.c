/*
 * =====================================================================================
 *
 *       Filename:  tl16c752.c
 *
 *    Description:  tl16c752 opration
 *
 *        Version:  1.0
 *        Created:  2011年11月10日 19时15分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */
#include "../include/gpio.h"
#include "tl16c752_reg.h"
#define BAND       9600
#define BASEADDR  (0x30000000)
#define D5 AT91C_PIN_PA(25)

void Tl16c752_Init()
{
    WRITEREG(BASEADDR+LCR,BIT_LATCH_EN);
    WRITEREG(BASEADDR+DLH,0x00);
    WRITEREG(BASEADDR+DLL,65);
    WRITEREG(BASEADDR+LCR,BIT_WORDLEN_8);
    WRITEREG(BASEADDR+EFR,0x10);
    WRITEREG(BASEADDR+FCR,0x37);
    WRITEREG(BASEADDR+MCR,0x04);
    WRITEREG(BASEADDR+IER,0x00);

}
void Tl16c752_Send(unsigned char val)
{
    while((READREG(BASEADDR+FRR)&0x01)==0)
    {
    }

    WRITEREG(BASEADDR+BUF,val);

}
unsigned char Tl16c752_RxChk()
{
    if(READREG(BASEADDR+LSR)&BIT_RX_NOEMPTY)
    {
         return 1;
    }
    return 0;
}
unsigned char  Tl16c752_Read(unsigned char* const val)
{
    if(READREG(BASEADDR+LSR)&BIT_RX_NOEMPTY)
    {
        *val = READREG(BASEADDR+BUF);
         return 1;
    }
    return 0;
}
