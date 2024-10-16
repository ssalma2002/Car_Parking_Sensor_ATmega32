/*
 * led.h
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */

#ifndef LED_H_
#define LED_H_
#include "gpio.h"
#include "common_macros.h"
#include "std_types.h"
/*The driver should support both Led connections Positive Logic and Negative Logic.
 *
 */

/*Ports config for red, green,blue*/
#define RED_PORT PORTC_ID
#define RED_PIN PIN0_ID

#define GREEN_PORT PORTC_ID
#define GREEN_PIN PIN1_ID

#define BLUE_PORT PORTC_ID
#define BLUE_PIN PIN2_ID

/*POSITIVE LOGIC or NEGATIVE LOGIC */
#define POSITIVE_LOGIC 1
//#define NEGATIVE_LOGIC 1

typedef enum {
	red,green,blue
}LED_ID;
void LEDS_init(void) ;

void LED_on(LED_ID id) ;

void LED_off(LED_ID id) ;


#endif /* LED_H_ */
