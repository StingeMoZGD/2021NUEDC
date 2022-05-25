#include "define.h"

void ALL_CONFIG()
{
	lcd_init();
  lcd_clear(WHITE);
	
	tim_encoder_init(CODERA);   //��������ʼ��
	tim_encoder_init(CODERB);   //��������ʼ��
	
	pwm_init(MOTORM , MOTORA, MOTORHz, 0);										// �����ʼ��
  pwm_init(MOTORM , MOTORa, MOTORHz, 0);	                  // �����ʼ��
  pwm_init(MOTORM , MOTORB, MOTORHz, 0);										// �����ʼ��
  pwm_init(MOTORM , MOTORb, MOTORHz, 0);                   // �����ʼ�� 
	
	pwm_init(SERVOM , SERVO , SERVOHz , SERVOMid);           //�����ʼ��                   //�����ʼ��
	
	lcd_init();                                                 //LCD��ʼ��
	lcd_clear(WHITE);                                           
  adc_init(ADC_1,L1,ADC_12BIT);                               //adc��ʼ��
	adc_init(ADC_1,L2,ADC_12BIT);
	adc_init(ADC_1,L3,ADC_12BIT);
	adc_init(ADC_1,L4,ADC_12BIT);
	adc_init(ADC_1,L5,ADC_12BIT);
	adc_init(ADC_1,L6,ADC_12BIT);
	adc_init(ADC_1,L7,ADC_12BIT);
	
	seekfree_wireless_init();                        //���ڳ�ʼ��
	uart_init(1,115200,UART1_TX_A10,UART1_RX_A09);
	
	systick_delay_ms(1000);                 //�ϵ�
	 
	
	
}