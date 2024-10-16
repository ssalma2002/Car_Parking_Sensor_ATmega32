/*
 * ultrasonic.c
 *
 *  Created on: Oct 16, 2024
 *      Author: syous
 */

#include"ultrasonic.h"



volatile uint8 edge_flag;

void Ultrasonic_init(void){
	ICU_ConfigType icuConfig;
	icuConfig.clock = F_CPU_8;
	icuConfig.edge = RAISING;

	ICU_init(&icuConfig);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(TRIGGER_PORT,TRIGGER_PIN,PIN_OUTPUT);
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_LOW);
}

void Ultrasonic_Trigger(void){
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void){
	uint16 distance;
	Ultrasonic_Trigger();
	while(edge_flag != 2);
	distance = (uint16)((float32)(ICU_getInputCaptureValue()/113.6));
	edge_flag=0;
	return distance;
}

void Ultrasonic_edgeProcessing(void){

	edge_flag++;
	if(edge_flag==1){
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(edge_flag==2){
		ICU_setEdgeDetectionType(RAISING);

	}

}

