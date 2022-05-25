#ifndef _DEFINE_H_
#define _DEFINE_H_

#include "headfile.h"

#define CODERB  TIM_1, TIM_1_ENC1_A08, TIM_1_ENC2_A01   //�������궨��
#define CODERA  TIM_8, TIM_8_ENC1_C00, TIM_8_ENC2_C01


#define L7  ADC1_CH03_A03         //ADC��к궨��
#define L6  ADC1_CH00_A00
#define L5  ADC1_CH02_A02
#define L4  ADC1_CH05_A05
#define L3  ADC1_CH07_A07
#define L2  ADC1_CH11_B10
#define L1  ADC1_CH06_A06


#define SERVOM   TIM_3              //���ʹ�ö�ʱ��
#define SERVO    TIM_3_CH2_C07        //�������
#define SERVOHz  50                //���Ƶ�� 
#define SERVOMid 4220              //�������


#define MOTORM   TIM_2              //���ʹ�ö�ʱ��
#define MOTORA   TIM_2_CH1_A11     //���PWM-A
#define MOTORa   TIM_2_CH2_A12     //���PWM-a
#define MOTORB   TIM_2_CH3_C09     //���PWM-B
#define MOTORb   TIM_2_CH4_B11     //���PWM-b
#define MOTORHz  15000            //���Ƶ��


void ALL_CONFIG(void);

#endif
