/*
 * servo.c
 *
 *  Created on: Feb 24, 2021
 *      Author: piotr
 */

#include "main.h"

TIM_HandleTypeDef *pwm_tim;
uint32_t pwm_channel;

void servo_init(TIM_HandleTypeDef *tim, uint32_t channel)
{
	pwm_tim = tim;
	pwm_channel = channel;

	__HAL_TIM_SET_COMPARE(pwm_tim, pwm_channel, SERVO_MIN_US);
	HAL_TIM_PWM_Start(pwm_tim, pwm_channel);
}

void servo_set_angle(uint8_t angle)
{
	if(angle < SERVO_MIN_ANGLE)
		angle = SERVO_MIN_ANGLE;
	else if(angle > SERVO_MAX_ANGLE)
		angle = SERVO_MAX_ANGLE;

	uint32_t pwm_duty_us;

	pwm_duty_us = SERVO_MIN_US + (angle * (SERVO_MAX_US - SERVO_MIN_US))/SERVO_MAX_ANGLE;

	__HAL_TIM_SET_COMPARE(pwm_tim, pwm_channel, pwm_duty_ms);
}

void servo_set_speed(int speed)
{
	if(speed < -SERVO_MAX_SPEED)
		speed = -SERVO_MAX_SPEED;
	else if(speed > SERVO_MAX_SPEED)
		speed = SERVO_MAX_SPEED;

	uint32_t pwm_duty_us;

	pwm_duty_us = (SERVO_MAX_US + SERVO_MIN_US)/2 + (speed * (SERVO_MAX_US - SERVO_MIN_US)/2)/SERVO_MAX_SPEED;

	__HAL_TIM_SET_COMPARE(pwm_tim, pwm_channel, pwm_duty_ms);
}
