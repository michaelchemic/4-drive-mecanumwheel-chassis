#ifndef __A4988_H
#define __A4988_H
#include "delay.h"
// ʹ�������ķ�֣�ÿ�����Ҫ�������Ʋ���ʵ��ȫ���ƶ���

#define Motor_GPIO GPIOA // GPIOA
#define Motor_RCC RCC_APB2Periph_GPIOA
// ��һ���������A4988�Ľ���

#define Motor1_DIR GPIO_Pin_0  // DIR
#define Motor1_STEP GPIO_Pin_1 // STEP

// �ڶ����������A4988�Ľ���
#define Motor2_DIR GPIO_Pin_2 // DIR
#define Motor2_STEP GPIO_Pin_3  // STEP

// �������������A4988�Ľ���

#define Motor3_DIR GPIO_Pin_4  // DIR
#define Motor3_STEP GPIO_Pin_5 // STEP

// ���ĸ��������A4988�Ľ���
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
