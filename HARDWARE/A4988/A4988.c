// 用来控制4路a4988步进电机驱动器
#include "A4988.h"
/*GPIO_motornum和GPIOx用于选择电机，GPIO_direction用于选择电机方向，dir：0为逆1为正，k为90°的倍数*/
void MOTOR_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(Motor_RCC, ENABLE);

	// Motor初始化
	GPIO_InitStructure.GPIO_Pin = Motor1_DIR | Motor1_STEP | Motor2_DIR | Motor2_STEP | Motor3_DIR | Motor3_STEP | Motor4_DIR | Motor4_STEP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Motor_GPIO, &GPIO_InitStructure);

	GPIO_ResetBits(Motor_GPIO, Motor1_STEP);
	GPIO_ResetBits(Motor_GPIO, Motor1_DIR);

	GPIO_ResetBits(Motor_GPIO, Motor2_STEP);
	GPIO_ResetBits(Motor_GPIO, Motor2_DIR);

	GPIO_ResetBits(Motor_GPIO, Motor3_STEP);
	GPIO_ResetBits(Motor_GPIO, Motor3_DIR);

	GPIO_ResetBits(Motor_GPIO, Motor4_STEP);
	GPIO_ResetBits(Motor_GPIO, Motor4_DIR);
}
//第一个形参用来补偿步进电机速度。四个电机可以分开设置。
void motor(unsigned int speed, unsigned int motor1_dir, unsigned int motor1_step, unsigned int motor2_dir, unsigned int motor2_step, unsigned int motor3_dir, unsigned int motor3_step, unsigned int motor4_dir, unsigned int motor4_step)
{
	unsigned int i;

	switch (motor1_dir) // 设置的电机旋转方向
	{
	case 0:
		GPIO_SetBits(Motor_GPIO, Motor1_DIR); // 置1
		break;
	case 1:
		GPIO_ResetBits(Motor_GPIO, Motor1_DIR); // 置0
		break;
	default:
		break;
	}

	switch (motor2_dir)
	{
	case 0:
		GPIO_SetBits(Motor_GPIO, Motor2_DIR);
		break;
	case 1:
		GPIO_ResetBits(Motor_GPIO, Motor2_DIR);
		break;
	default:
		break;
	}

	switch (motor3_dir)
	{
	case 0:
		GPIO_SetBits(Motor_GPIO, Motor3_DIR);
		break;
	case 1:
		GPIO_ResetBits(Motor_GPIO, Motor3_DIR);
		break;
	default:
		break;
	}

	switch (motor4_dir)
	{
	case 0:
		GPIO_SetBits(Motor_GPIO, Motor4_DIR);
		break;
	case 1:
		GPIO_ResetBits(Motor_GPIO, Motor4_DIR);
		break;
	default:
		break;
	}

	for (i = 0; i < motor1_step || i < motor2_step||i < motor3_step||i < motor4_step; i++)// 对每个步进电机，如果当前步数计数 i 小于目标步数，则生成步进脉冲
	{
		if (i < motor1_step)
		{
			GPIO_SetBits(Motor_GPIO, Motor1_STEP);
			delay_us(speed); 
			GPIO_ResetBits(Motor_GPIO, Motor1_STEP);
			delay_us(speed);
		}
		if (i < motor2_step)
		{
			GPIO_SetBits(Motor_GPIO, Motor2_STEP);
			delay_us(speed);
			GPIO_ResetBits(Motor_GPIO, Motor2_STEP);
			delay_us(speed);
		}
		if (i < motor3_step)
		{
			GPIO_SetBits(Motor_GPIO, Motor3_STEP);
			delay_us(speed);
			GPIO_ResetBits(Motor_GPIO, Motor3_STEP);
			delay_us(speed);
		}
		if (i < motor4_step)
		{
			GPIO_SetBits(Motor_GPIO, Motor4_STEP);
			delay_us(speed); 
			GPIO_ResetBits(Motor_GPIO, Motor4_STEP);
			delay_us(speed);
		}
	}
}
