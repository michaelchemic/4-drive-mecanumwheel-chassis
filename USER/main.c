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
    delay_init();                                   // ��ʱ������ʼ��
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // �����ж����ȼ�����2
	  uart1_init(115200);
	  USART_Send_String(USART1, "USART1 Send OK!");
    LED_Init();                                     // LED������ʼ��
    MOTOR_Init();                                   // �������IO��ʼ��
	 
    while (1) {
 switch (motor_mode){
	 case 0x01:
 motor(500,0,stepping_angle,0,stepping_angle,1,stepping_angle,1,stepping_angle);//ǰ��
	 	 break;
	 case 0x02:
	motor(500,1,stepping_angle,1,stepping_angle,0,stepping_angle,0,stepping_angle);//����
	 break;
case 0x03:
	motor(500,0,stepping_angle,1,stepping_angle,1,stepping_angle,0,stepping_angle);//��ƽ��
	 break;
case 0x04:
	motor(500,1,stepping_angle,0,stepping_angle,0,stepping_angle,1,stepping_angle);//��ƽ��
	 break;
case 0x05:
	motor(500,1,stepping_angle,1,stepping_angle,1,stepping_angle,1,stepping_angle);//ԭ����ת
	 break;
case 0x06:
		motor(500,0,stepping_angle,0,stepping_angle,0,stepping_angle,0,stepping_angle);//ԭ����ת
	 break;
case 0x07:
  motor(500,0,stepping_angle,0,0,1,stepping_angle,0,0);//��ǰ�ƶ�
	 break;
case 0x08:
		motor(500,0,0,0,stepping_angle,0,0,1,stepping_angle);//��ǰ�ƶ�
	 break;
case 0x09:
	motor(500,0,0,1,stepping_angle,0,0,0,stepping_angle);//����ƶ�
	 break;
case 0x10:
motor(500,1,stepping_angle,0,0,0,stepping_angle,0,0);//�Һ��ƶ�
	 break;
 }
            


				
	  
	
				
				
		
		
		///////////////////////////////debug///////////////////////////////
			//	motor(500,0,stepping_angle,0,stepping_angle,1,stepping_angle,1,stepping_angle);//ǰ��
	
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,1,stepping_angle,1,stepping_angle,1,stepping_angle);//ԭ����ת
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,1,stepping_angle,0,stepping_angle,0,stepping_angle);//����
		//		delay_ms(10000);
		//		motor(500,0,stepping_angle,1,stepping_angle,1,stepping_angle,0,stepping_angle);//��ƽ��
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,0,stepping_angle,0,stepping_angle,1,stepping_angle);//��ƽ��
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,1,stepping_angle,1,stepping_angle,1,stepping_angle);//ԭ����ת
		//		delay_ms(10000);
		//		motor(500,0,stepping_angle,0,stepping_angle,0,stepping_angle,0,stepping_angle);//ԭ����ת
		//		delay_ms(10000);
		//	  motor(500,0,stepping_angle,0,0,1,stepping_angle,0,0);//��ǰ�ƶ�
		//		delay_ms(10000);
		//		motor(500,0,0,0,stepping_angle,0,0,1,stepping_angle);//��ǰ�ƶ�
		//    delay_ms(10000);
		//		motor(500,0,0,1,stepping_angle,0,0,0,stepping_angle);//����ƶ�
		//		delay_ms(10000);
		//		motor(500,1,stepping_angle,0,0,0,stepping_angle,0,0);//�Һ��ƶ�
		//		delay_ms(10000);
		///////////////////////////////debug///////////////////////////////
		
    }
}




