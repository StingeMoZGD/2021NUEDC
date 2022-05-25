/*
 * MotoDrives.h
 *
 *  Created on: 2021��11��4��
 *      Author: ASUS
 */

#ifndef CODE_MOTODRIVES_H_
#define CODE_MOTODRIVES_H_
#include"stdio.h"
#include"headfile.h"

//B_L_W_D:back left wheel direction
#define B_L_W_D   B7              //����3�������ת����
#define B_R_W_D   B3              //����4�������ת����

//B_L_W:back left wheel;
#define B_L_W   PWM4_CH1_B6        //����3���PWM����
#define B_R_W   PWM2_CH1_A15       //����4���PWM����

#define Kp      3
#define Kd      500
#define BSPD    10                  //�����ٶ�
#define ISPD    10                  //�����ٶ�
#define SBTS    10                  //�������ת��
#define IBTS    10                  //�������ת��

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
