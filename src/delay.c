/*****************************************************************************
 *   Placeholder for delay functions.
 *   Part of the proposed solutions for LPCXpresso Experiment Kit
 *
 *   Copyright(C) 2013, Embedded Artists AB
 *   All rights reserved.
 *
 ******************************************************************************/

#include "type.h"
#include "delay.h"

#define MS_1           2440

/*****************************************************************************
 ** Function name:               delayNops
 **
 ** Descriptions:                Delay by executing a given number of NOPs.
 **                              About 2.440.000 iterations per second.
 **
 ** parameters:                  number of NOP instructions
 ** Returned value:              None
 **
 *****************************************************************************/
void
delayNops(uint32_t nops)
{
  volatile uint32_t i;

  for (i = 0; i < nops; i++)
    asm volatile ("nop");
}

/*****************************************************************************
 ** Function name:               delayMS
 **
 ** Descriptions:                Delay execution for specified time.
 **
 ** parameters:                  delay in milliseconds
 ** Returned value:              None
 **
 *****************************************************************************/
void
delayMS(uint32_t ms)
{
  volatile uint32_t i;
  uint32_t nops;
  nops = MS_1 * ms;

  for (i = 0; i < nops; i++)
    asm volatile ("nop");
}
