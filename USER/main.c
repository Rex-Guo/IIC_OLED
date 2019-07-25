#include "stm32f4xx.h"
#include "systick.h"
#include "uart.h"
#include "chinese.h"
#include "oled.h"

int main(void)
{
	int ret;	
	
	/****************** Ӳ����ʼ�� ********************/
	Systick_Init();
	UART1_Init(115200); 
	Led_Init();
	OLED_Clear();
	printf("HardWare Init Success!\r\n");
	
/****************** ʵ�ֵĹ��� ********************/
	
/****************** �������� **************************/
#if 0
	
	/*
	*		������: test1
	*	����˵��: ��Ļˮƽ������ʾ������Լ���
	*	���Խ��: true
	*/
	Out_Oled(0x2F,MOC_Commend);//�������
	for(ret = 0; ret < 4; ret++){
			Show_Zh( ret*16, 0, Chinese, ret);
	}
	
	while(1)
	{
		
	}
#elif 1
	
	/*
	*		������: test2
	*	����˵��: ��Ļ��ʾ5-4-3-2-1-0����ʱ
	*	���Խ��: true
	*/
	Out_Oled(0xD6,MOC_Commend); //�Ŵ�
	Out_Oled(0x01,MOC_Commend); 
	
	for(ret = 0; ret <= 6; ret++){
		ret %= 6;
		Show_Zh( 48, 1, Chinese_Num, ret);
		delay_ms(500);
		OLED_Clear();
		delay_ms(500);
		
	}
	
#endif
	

	
		
	
}
