#include "define.h"

void ALL_CONFIG()
{
	lcd_init();
  lcd_clear(WHITE);
	
	tim_encoder_init(CODERA);   //编码器初始化
	tim_encoder_init(CODERB);   //编码器初始化
	
	pwm_init(MOTORM , MOTORA, MOTORHz, 0);										// 电机初始化
  pwm_init(MOTORM , MOTORa, MOTORHz, 0);	                  // 电机初始化
  pwm_init(MOTORM , MOTORB, MOTORHz, 0);										// 电机初始化
  pwm_init(MOTORM , MOTORb, MOTORHz, 0);                   // 电机初始化 
	
	pwm_init(SERVOM , SERVO , SERVOHz , SERVOMid);           //舵机初始化                   //舵机初始化
	
	lcd_init();                                                 //LCD初始化
	lcd_clear(WHITE);                                           
  adc_init(ADC_1,L1,ADC_12BIT);                               //adc初始化
	adc_init(ADC_1,L2,ADC_12BIT);
	adc_init(ADC_1,L3,ADC_12BIT);
	adc_init(ADC_1,L4,ADC_12BIT);
	adc_init(ADC_1,L5,ADC_12BIT);
	adc_init(ADC_1,L6,ADC_12BIT);
	adc_init(ADC_1,L7,ADC_12BIT);
	
	seekfree_wireless_init();                        //串口初始化
	uart_init(1,115200,UART1_TX_A10,UART1_RX_A09);
	
	systick_delay_ms(1000);                 //上电
	 
	
	
}