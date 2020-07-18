/*****************************************************************************
 *   The proposed solution for LPCXpresso Experiment Kit, Lab 5c
 *
 *   Copyright(C) 2013, Embedded Artists AB
 *   All rights reserved.
 *
 ******************************************************************************/

#include "LPC11xx.h"
#include "type.h"
#include "board.h"
#include "gpio.h"
#include "delay.h"
#include "adc.h"
#include <stdio.h>

int main (void)
{
  uint32_t analogValue;

  printf("\nThis program reads AIN0 (light sensor) repeatedly...\n");

  //Initialize ADC peripheral and pin-mixing
  ADCInit(4500000);  //4.5MHz ADC clock

  while(1)
  {
	//get initial value (could be 0 also)
	analogValue = getADC(AIN0);

    //Integer smoothing
    analogValue = ((7*analogValue) + getADC(AIN2)) >> 3;

    printf("\nAIN2=%d", analogValue);

    //Delay 250ms
    delayMS(250);
  }

  return 0;
}
