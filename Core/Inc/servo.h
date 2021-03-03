/*
 * servo.h
 *
 *  Created on: Feb 24, 2021
 *      Author: piotr
 */

#include "main.h"

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#define SERVO_MAX_US		2000
#define SERVO_MIN_US		1000

#define SERVO_MAX_ANGLE		90
#define SERVO_MIN_ANGLE		0

#define	SERVO_MAX_SPEED		100

void servo_init(TIM_HandleTypeDef *, uint32_t);
void servo_set_angle(uint8_t);
void servo_set_speed(int);

#endif /* INC_SERVO_H_ */
