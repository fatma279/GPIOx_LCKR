/*
 *  Created on: july 9, 2021
 *      Author: Fatma

 */

// ----------------------------------------------------------------------------

#include <STD_TYPES.h>
#include <BIT_MATH.h>
#include "RCC_interface.h"
#include "DIO_interface.h"



void main(void)
{
	u32 loc_readLockMode;
    u8 Loc_U8ReadPin;
	/* initiat system clock */
      RCC_voidInitSysClock();

	/* enable periperal port A on  APb2 */
	 RCC_voidEnablePrephiralClock(RCC_APB2, RCC_PORTA);

	 /* configure pin 0 as output push pull 2MHZ */
	  GPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);

	 /* configure pin 1 as output push pull 2MHZ */
	   GPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);

	 /* lock the configuration of the port bit 0 */
	   loc_readLockMode = GPIO_VoidLockMode(GPIOA, PIN0);



  // Infinite loop
  while (1)
    {

	  /* get pin 0 in Port configuration lock register */
	  Loc_U8ReadPin= GET_BIT(loc_readLockMode,PIN0);

	  if(Loc_U8ReadPin)
	  {
	    //PA0 configuration has been locked

			/*set pin 0 high */
		  GPIO_voidSetPinValue(GPIOA, PIN0, HIGH);
	  }
	  else
	  {
	    //PA0 configuration has not been locked

			/*set pin 1 high */
		  GPIO_voidSetPinValue(GPIOA, PIN1, HIGH);
	  }

    }
}

