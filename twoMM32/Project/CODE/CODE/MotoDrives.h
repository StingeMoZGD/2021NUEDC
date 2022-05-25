/*
 * MotoDrives.h
 *
 *  Created on: 2021年11月4日
 *      Author: ASUS
 */

#ifndef CODE_MOTODRIVES_H_
#define CODE_MOTODRIVES_H_
#include"stdio.h"
#include"headfile.h"

//B_L_W_D:back left wheel direction
#define B_L_W_D   B7              //定义3电机正反转引脚
#define B_R_W_D   B3              //定义4电机正反转引脚

//B_L_W:back left wheel;
#define B_L_W   PWM4_CH1_B6        //定义3电机PWM引脚
#define B_R_W   PWM2_CH1_A15       //定义4电机PWM引脚

#define Kp      3
#define Kd      500
#define BSPD    10                  //基础速度
#define ISPD    10                  //增益速度
#define SBTS    10                  //舵机基础转速
#define IBTS    10                  //舵机增益转速

typedef struct
{
    int Bottom;
    int BasicValueA;
    int BasicValueB;
    int FirstValue;
    int SecondValue;
    int GroupValue;
    int OPValue;
}MotoValue;

void MotoInit(void);
void MotoRide(void);

#endif /* CODE_MOTODRIVES_H_ */
