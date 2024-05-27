#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "a4988.h"

extern uint8_t motor_mode;
extern float stepping_angle;

extern uint8_t rx_buffer[RX_BUFFER_SIZE];
extern uint8_t rx_index;

int main(void)
{ 
    delay_init();                                   // 延时函数初始化
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 设置中断优先级分组2
	  uart1_init(115200);
	  USART_Send_String(USART1, "USART1 Send OK!");
    LED_Init();                                     // LED驱动初始化
    MOTOR_Init();                                   // 电机驱动IO初始化
	 
    while (1) {
 switch (motor_mode){
	 case 0x01:
 motor(500,0,stepping_angle,0,stepping_angle,1,stepping_angle,1,stepping_angle);//前进
	 	 break;
	 case 0x02:
	motor(500,1,stepping_angle,1,stepping_angle,0,stepping_angle,0,stepping_angle);//后退
	 break;
case 0x03:
	motor(500,0,stepping_angle,1,stepping_angle,1,stepping_angle,0,stepping_angle);//左平移
	 break;
case 0x04:
	motor(500,1,stepping_angle,0,stepping_angle,0,stepping_angle,1,stepping_angle);//右平移
	 break;
case 0x05:
	motor(500,1,stepping_angle,1,stepping_angle,1,stepping_angle,1,stepping_angle);//原地左转
	 break;
case 0x06:
		motor(500,0,stepping_angle,0,stepping_angle,0,stepping_angle,0,stepping_angle);//原地右转
	 break;
case 0x07:
  motor(500,0,stepping_angle,0,0,1,stepping_angle,0,0);//左前移动
	 break;
case 0x08:
		motor(500,0,0,0,stepping_angle,0,0,1,stepping_angle);//右前移动
	 break;
case 0x09:
	motor(500,0,0,1,stepping_angle,0,0,0,stepping_angle);//左后移动
	 break;
case 0x10:
motor(500,1,stepping_angle,0,0,0,stepping_angle,0,0);//右后移动
	 break;
 }
            


				
	  
	
				
				
		
		
		///////////////////////////////debug///////////////////////////////
			//	motor(500,0,stepping_angle,0,stepping_angle,1,stepping_angle,1,stepping_angle);//前进
	
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,1,stepping_angle,1,stepping_angle,1,stepping_angle);//原地左转
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,1,stepping_angle,0,stepping_angle,0,stepping_angle);//后退
		//		delay_ms(10000);
		//		motor(500,0,stepping_angle,1,stepping_angle,1,stepping_angle,0,stepping_angle);//左平移
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,0,stepping_angle,0,stepping_angle,1,stepping_angle);//右平移
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,1,stepping_angle,1,stepping_angle,1,stepping_angle);//原地左转
		//		delay_ms(10000);
		//		motor(500,0,stepping_angle,0,stepping_angle,0,stepping_angle,0,stepping_angle);//原地右转
		//		delay_ms(10000);
		//	  motor(500,0,stepping_angle,0,0,1,stepping_angle,0,0);//左前移动
		//		delay_ms(10000);
		//		motor(500,0,0,0,stepping_angle,0,0,1,stepping_angle);//右前移动
		//    delay_ms(10000);
		//		motor(500,0,0,1,stepping_angle,0,0,0,stepping_angle);//左后移动
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,0,0,0,stepping_angle,0,0);//右后移动
		//		delay_ms(10000);
		///////////////////////////////debug///////////////////////////////
		
    }
}




