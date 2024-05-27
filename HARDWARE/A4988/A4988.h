#ifndef __A4988_H
#define __A4988_H
#include "delay.h"
// 使用麦克纳姆轮，每个电机要单独控制才能实现全向移动。

#define Motor_GPIO GPIOA // GPIOA
#define Motor_RCC RCC_APB2Periph_GPIOA
// 第一个步进电机A4988的接线

#define Motor1_DIR GPIO_Pin_0  // DIR
#define Motor1_STEP GPIO_Pin_1 // STEP

// 第二个步进电机A4988的接线
#define Motor2_DIR GPIO_Pin_2 // DIR
#define Motor2_STEP GPIO_Pin_3  // STEP

// 第三个步进电机A4988的接线

#define Motor3_DIR GPIO_Pin_4  // DIR
#define Motor3_STEP GPIO_Pin_5 // STEP

// 第四个步进电机A4988的接线
#define Motor4_DIR GPIO_Pin_6 // DIR
#define Motor4_STEP GPIO_Pin_7  // STEP

void MOTOR_Init(void);
void motor(unsigned int speed,
	unsigned int motor1_dir, 
	unsigned int motor1_step, 
		unsigned int motor2_dir, 
			unsigned int motor2_step,
				unsigned int motor3_dir, 
					unsigned int motor3_step, 
						unsigned int motor4_dir, 
							unsigned int motor4_step);

#endif
