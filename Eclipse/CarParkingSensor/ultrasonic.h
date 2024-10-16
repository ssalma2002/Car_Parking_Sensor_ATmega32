/*
 * ultrasonic.h
 *
 *  Created on: Oct 16, 2024
 *      Author: syous
 */
#include"icu.h"
#include"gpio.h"
#include <util/delay.h>
#include "std_types.h"
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define TRIGGER_PORT PORTD_ID
#define TRIGGER_PIN PIN7_ID

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
