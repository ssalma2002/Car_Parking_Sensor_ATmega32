/*
 * led.c
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */
#include "led.h"
/*
 * o Red LED: Connected to PB5
 o Green LED: Connected to PB6
 o Blue LED: Connected to PB7
 */
void LEDS_init(void) {
	GPIO_setupPinDirection( RED_PORT, RED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection( GREEN_PORT, GREEN_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection( BLUE_PORT, BLUE_PIN, PIN_OUTPUT);
#if POSITIVE_LOGIC
	GPIO_writePin(RED_PORT, RED_PIN, LOGIC_LOW);
	GPIO_writePin(GREEN_PORT, GREEN_PIN, LOGIC_LOW);
	GPIO_writePin(BLUE_PORT, BLUE_PIN, LOGIC_LOW);
#else
	GPIO_writePin(RED_PORT, RED_PIN, LOGIC_HIGH);
		GPIO_writePin(GREEN_PORT, GREEN_PIN, LOGIC_HIGH);
		GPIO_writePin(BLUE_PORT, BLUE_PIN, LOGIC_HIGH);
#endif
}

void LED_on(LED_ID id) {
#if POSITIVE_LOGIC
	switch (id) {
	case red:
		GPIO_writePin(RED_PORT, RED_PIN, LOGIC_HIGH);
		break;
	case green:
		GPIO_writePin(GREEN_PORT, GREEN_PIN, LOGIC_HIGH);
		break;
	case blue:
		GPIO_writePin(BLUE_PORT, BLUE_PIN, LOGIC_HIGH);
		break;
	}
#else
	switch(id){
		case red:
			GPIO_writePin(RED_PORT, RED_PIN, LOGIC_LOW);
			break;
		case green:
				GPIO_writePin(GREEN_PORT, GREEN_PIN, LOGIC_LOW);
				break;
		case blue:
				GPIO_writePin(BLUE_PORT, BLUE_PORT, LOGIC_LOW);
				break;
}
#endif
}
	void LED_off(LED_ID id) {
#if POSITIVE_LOGIC
		switch (id) {
		case red:
			GPIO_writePin(RED_PORT, RED_PIN, LOGIC_LOW);
			break;
		case green:
			GPIO_writePin(GREEN_PORT, GREEN_PIN, LOGIC_LOW);
			break;
		case blue:
			GPIO_writePin(BLUE_PORT, BLUE_PIN, LOGIC_LOW);
			break;
		}
#else
	switch(id){
			case red:
				GPIO_writePin(RED_PORT, RED_PIN, LOGIC_HIGH);
				break;
			case green:
					GPIO_writePin(GREEN_PORT, GREEN_PIN, LOGIC_HIGH);
					break;
			case blue:
					GPIO_writePin(BLUE_PORT, BLUE_PIN, LOGIC_HIGH);
					break;
	}
#endif
	}

