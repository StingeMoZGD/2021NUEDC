/*
 * MotoDrives.c
 *
 *  Created on: 2021年11月4日
 *      Author: ASUS
 */
#include"MotoDrives.h"
#include"headfile.h"
#include<stdio.h>


static MotoValue LeftOne,RightOne,MidOne;     //两个电机的pwm的控制系数，和输出结构
static vuint16 encoder_data[2];

void MotoInit(void)
{
    MotoValue *Pointer;
    Pointer = &LeftOne;
    Pointer->Bottom = 0;
    Pointer->BasicValueA = BSPD;
    Pointer->BasicValueB = ISPD;
    Pointer->FirstValue = 0;
    Pointer->SecondValue = 0;
    Pointer->GroupValue = 0;
    Pointer->OPValue = 0;

    Pointer =& RightOne;
    Pointer->Bottom = 0;
    Pointer->BasicValueA = BSPD;
    Pointer->BasicValueB = ISPD;
    Pointer->FirstValue = 0;
    Pointer->SecondValue = 0;
    Pointer->GroupValue = 0;
    Pointer->OPValue = 0;

    Pointer =&MidOne;
    Pointer->Bottom = 0;
    Pointer->BasicValueA = SBTS;
    Pointer->BasicValueB = IBTS;
    Pointer->FirstValue = 0;
    Pointer->SecondValue = 0;
    Pointer->GroupValue = 0;
    Pointer->OPValue = 0;

    gpio_init(B_L_W_D, GPO, 1, GPIO_PIN_CONFIG);
    pwm_init(B_L_W,13000,0);
    gpio_init(B_R_W_D, GPO, 1, GPIO_PIN_CONFIG);
    pwm_init(B_R_W,13000,0);
}

int16 MOtoSetUp(MotoValue Keys)
{
    MotoValue *Pter;

    Pter =& Keys;
    Pter->GroupValue = Pter->BasicValueA + Pter->BasicValueB*Pter->Bottom - encoder_data[0];
    Pter->OPValue= Pter->OPValue + Kp*Pter->GroupValue + Kd*(Pter->OPValue - 2*Pter->FirstValue + Pter->SecondValue);
    Pter->SecondValue = Pter->FirstValue;
    Pter->FirstValue = Pter->GroupValue;
    return Pter->OPValue;
}

void MotoRide(void)
{
    int16 PotA,PotB;
    PotA = MOtoSetUp(LeftOne);
    PotB = MOtoSetUp(RightOne);

    if(PotA > 0){
        gpio_set(B_L_W_D, 0);
        pwm_duty(B_L_W, PotA);
    }else {
        gpio_set(B_L_W, 1);
        pwm_duty(B_L_W, -PotA);
          }

    if(PotB > 0){
         gpio_set(B_R_W_D, 0);
         pwm_duty(B_R_W, PotB);
    }else {
         gpio_set(B_R_W, 1);
         pwm_duty(B_R_W, -PotB);
          }
}
