/*
 * main.c
 *
 *  Created on: Oct 16, 2024
 *      Author: syous
 */
#include "ultrasonic.h"
#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include"common_macros.h"

int main(void) {
	uint8 crash_flag = 0;
	SET_BIT(SREG, 7);
	Ultrasonic_init();
	LCD_init();
	Buzzer_init();
	LEDS_init();

	uint16 distance;


	while (1) {


		LCD_displayStringRowColumn(0, 3, "Ultrasonic");
		LCD_displayStringRowColumn(1, 0, "Distance: ");

		distance = Ultrasonic_readDistance();
		LCD_moveCursor(1, 11);
		LCD_intgerToString(distance);
		LCD_displayString("cm ");
		if (distance >= 6 && distance <= 10) {
			LED_on(red);
			LED_on(green);
			LED_on(blue);
		} else if (distance >= 11 && distance <= 15) {
			LED_on(red);
			LED_on(green);
			LED_off(blue);
		} else if (distance >= 16 && distance <= 20) {
			LED_on(red);
			LED_off(green);
			LED_off(blue);
		} else if (distance > 20) {
			LED_off(red);
			LED_off(green);
			LED_off(blue);
		}
		if (distance <= 5) {
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 0, "STOP");
			Buzzer_on();
			crash_flag = 1;
		}
		while (crash_flag) {
			distance = Ultrasonic_readDistance();
			_delay_ms(10);
			if (distance > 5) {
				crash_flag = 0;
				Buzzer_off();
				LCD_clearScreen();
			}
		}

	}
}
