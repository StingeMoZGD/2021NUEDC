/*
 * PCIReInit.c
 *
 *  Created on: 2021��11��4��
 *      Author: ASUS
 */
#include"PCIReInit.h"
#include"headfile.h"
#include"MotoDrives.h"

void BasicsInit()
{
    lcd_init();

    lcd_showstr(0,0,"ENCODER");
    lcd_showstr(0,1,"Initializing...");
    mt9v03x_init();
    lcd_showstr(0,1,"     OK...     ");
    systick_delay_ms(300);

    lcd_showstr(0,2,"ENCODER");
    lcd_showstr(0,3,"Initializing...");
    encoder_init_spi(C9);//��������ʼ��
    encoder_init_spi(C8);
    timer_pit_interrupt_ms(TIMER_4, 2);
    lcd_showstr(0,3,"     OK...     ");
    systick_delay_ms(300);

    lcd_clear(WHITE);

    lcd_showstr(0,4,"WHEEL");
    lcd_showstr(0,5,"Initializing...");
    MotoInit();
    lcd_showstr(0,5,"     OK...     ");
    systick_delay_ms(300);

    pwm_init(PWM3_CH2_C7,333,0);   // �岥һ�������ʼ��
    pwm_duty(PWM3_CH2_C7,400);     //5400
//    timer_pit_interrupt_ms(TIMER_1, 3);
//    timer_pit_interrupt_ms(TIMER_3, 3);
//    timer_pit_interrupt_ms(TIMER_2, 3);
    systick_delay_ms(300);
//�����ı�Ҫ�����ĳ�ʼ��

    lcd_showstr(0 , 6, "hello world!\0");
    systick_delay_ms(500);
    lcd_clear(WHITE);
}
