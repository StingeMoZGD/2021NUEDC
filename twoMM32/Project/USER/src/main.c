/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,逐飞科技
* All rights reserved.
* 技术讨论QQ群：一群：179029047(已满)  二群：244861897
*
* 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
* 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
*
* @file				main
* @company			成都逐飞科技有限公司
* @author			逐飞科技(QQ3184284598)
* @version			查看doc内version文件 版本说明
* @Software			IAR 8.3 or MDK 5.24
* @Target core		MM32SPIN2XPs
* @Taobao			https://seekfree.taobao.com/
* @date				2020-11-23
********************************************************************************************************************/

#include "headfile.h"

// *************************** explain group ***************************
// 例程说明
// 
// 测试需要准备逐飞科技MM32SPIIN27PS核心板一块
// 
// 调试下载需要准备逐飞科技CMSIS-DAP或Jlink调试下载器一个
// 
// 本例程是个空工程 用来给同学们移植使用
// 
// 打开新的工程或者工程移动了位置务必执行以下操作
// 第一步 关闭上面所有打开的文件
// 第二步 project  clean  等待下方进度条走完
// 
// *************************** explain group ***************************

// **************************** define group ****************************

// **************************** define group ****************************

// **************************** value group ****************************
//uint16 loop_count = 0;
//uint8 io_input_state = 0;
#define Crossjudge h2==1&&h3==1&&h4==1&&h5==1
#define stopjudge  h1==0&&h2==0&&h3==0&&h4==0&&h5==0&&h6==0
#define Yao           C2                   //药引脚
#define hong          C5                   //红灯引脚
#define lv            D7                   //绿灯引脚

// **************************** value group ****************************
int h1,h2,h3,h4,h5,h6;
int a=0;
int coderA,coderB=0;
int pre_motorA,pre_motorB=0;
int last_motorA,motorA,motorB,last_motorB=0;
int Last_duty,duty=0;
int zhidaoflag,stopflag,crossflag=0;
int time=0;
float error=0;
float ML=1.0;
float MR=1.0;
float MML=3.0;
float MMR=3.0;
int b1=0;         //数字
int b2=0;
int stopjiance=0;
int stopok=0;
int daocheflag=0;
int daochestop=0;
float OUTPUT=0;
int daochestar=0;
int dirA=0;
int dirB=0;
int starcross=0;
int crossout=0; 
int stopcount=0;
int k=0;
int fuck=0;
int yao=0;
int HONG=0;
int zhuangyao=0;
int crosscount1=0;
int crosscount2=0;
int crosscount3=0;
int crosscount4=0;
uint8 uart1_get_buffer;
uint8 uart2_get_buffer;
int time1=0;
// **************************** code group ****************************
int main(void)
{
	ALL_CONFIG();
	uart_init(UART_1, 115200, UART1_TX_A09, UART1_RX_A10);							// UART1 已经在 board_init(true); 初始化过了
//	uart_init(UART_2, 115200, UART2_TX_A02, UART2_RX_A03);							// 默认初始化 UART1 用以支持 printf 输出
	uart_rx_irq(UART_1, ENABLE);	

  gpio_init(A0, GPI_FL, 0);
	gpio_init(A2, GPI_FL, 0);
	gpio_init(A3,GPI_FL, 0);
	gpio_init(A5,GPI_FL, 0);
	gpio_init(A6,GPI_FL, 0);
	gpio_init(A7,GPI_FL, 0);
	gpio_init(Yao,GPI_PU, 0);  //药
	gpio_init(hong,GPO_PP, 0);  //红灯
	gpio_init(lv,GPO_PP, 0);  //绿灯
	gpio_init(A15,GPO_PP,1);
	pwm_init (TIM_2, TIM_2_CH1_A11, 15000, 0);	// 初始化 debug 输出串口
	pwm_init (TIM_2, TIM_2_CH2_A12, 15000, 0);
	pwm_init (TIM_2, TIM_2_CH3_C09, 15000, 0);
	pwm_init (TIM_2, TIM_2_CH4_B11, 15000, 0);
	
//	pre_motorA=-250;
//	pre_motorB=-250;
	
//	pwm_duty_updata (MOTORM, MOTORA, 13000);
//	pwm_duty_updata (MOTORM, MOTORa, 0);
//	pwm_duty_updata (MOTORM, MOTORB, 13000);
//	pwm_duty_updata (MOTORM, MOTORb, 0);
	//此处编写用户代码(例如：外设初始化代码等)
	tim_interrupt_init (TIM_14, 100, 0);
	tim_interrupt_init (TIM_17, 50, 1);
	//此处编写用户代码(例如：外设初始化代码等)
  tim_interrupt_init (TIM_16, 200, 2);
	while(1)
	{
		//此处编写需要循环执行的代码
		if(b1==0)
		{
			time1+=1;
			 if(uart_query(UART_1, &uart1_get_buffer))
		   {			// 查询是否收到数据
		     if(uart1_get_buffer==0x01)	
			   {
				   b1=1;
				   gpio_set(A15,0);
			   }
			   else if(uart1_get_buffer==0x02)
				 {
					 b1=2;
					 gpio_set(A15,0);
				 }
				 
				 
				 else
					 b1=0;
			  }
			 if(time1>=70)
			 {
				 b1=3;
				 gpio_set(A15,0);
				 time1=0;
			 }
		 
			 
			 
			 
			 
		}
		   
		LCD_init();
		//此处编写需要循环执行的代码
	}
}
// **************************** code group ****************************

float myabs_f(float dat)
{
  if(dat>=0)  return dat;
  else        return -dat;
}


void motor_init(void)
{
	if(yao==1||zhuangyao==1)
	{
		dirA=0;
	  dirB=0;
	  pre_motorA=-200;
	  pre_motorB=-200;
		zhuangyao=1;
	}
   pid_param_t motorA_pid = PID_CREATE(10, 3, 0, 1, 1000, 1000, 130);
	//motor =last_motor + bangbang_pid_solve(&motor_pid, coder-pre_motor);
	 motorA=last_motorA+increment_pid_solve(&motorA_pid, coderA-pre_motorA);
	 pid_param_t motorB_pid = PID_CREATE(10, 3, 0, 1, 1000, 1000, 130);
	//motor =last_motor + bangbang_pid_solve(&motor_pid, coder-pre_motor);
	 motorB=last_motorB+increment_pid_solve(&motorB_pid, coderB-pre_motorB);
	last_motorA=motorA;
	last_motorB=motorB;
	if(stopjudge)
	{
		if(stopok==1)
		{
			motorA=0;
			motorB=0;
		}
	}
	else;
	if(crossflag==1)
	{
		
		
			if(b1==1||b1==3)
			{
				dirA=50000;
				motorA=5000;
			}
			  //motorA=0;
		  else
			{
				dirB=50000;
				motorB=16000;
			}
		
		
			
	}
	else;
	if(crossout==1)
	{
		crossout=0;
		if(b1==1||b1==3)
			{
				dirA=0;
				motorA=8000;
			}
			  //motorA=0;
		  else
			{
				dirB=0;
				motorB=8000;
			}
	
			
	}
  else;
	if(motorA>=20000)
		motorA=20000;
	else;
	if(motorB>=20000)
		motorB=20000;
	else;
	 pwm_duty_updata (MOTORM, MOTORA, motorA);
	 pwm_duty_updata (MOTORM, MOTORa, dirA);
	 pwm_duty_updata (MOTORM, MOTORB, motorB);
	 pwm_duty_updata (MOTORM, MOTORb, dirB);
	
}

#define B_  190.0f//车后轮间距
#define CL_  120.0f//前后轮距
#define Servo_maxdeg   5100   //左 
#define Servo_maxdegR  3800  //右
/*
阿克曼电子差速
输入期望速度
根据舵机偏移量得到对应的左右差速
*/
float Servo_deg;
float R_l, R_m, R_r;
  int Motor_L, Motor_R;
void Speed_set(int speed_exp)
{

  Servo_deg = ((float)(SERVOMid / 5 - duty / 5)) * Servo_maxdeg / 180.0f;
  
  if(myabs_f(Servo_deg) < 1.0f)
  {
    R_l = 20000.0f;
    R_r = 20000.0f;
    R_m = 20000.0f;
  }
  else if(Servo_deg < 0.0f)
  {
    R_l = CL_ * myabs_f(1.0f / tan(Servo_deg * 3.1415926f / 180.0f));
    R_r = R_l + B_;
  }
	/*if(duty<4800&&duty>3880)
	{
		 Motor_L = speed_exp;
     Motor_R = speed_exp;
	}*/
  else
  {
    R_r = CL_ * myabs_f(1.0f / tan(Servo_deg * 3.1415926f / 180.0f));
    R_l = R_r + B_;
  }
  R_m = (R_l + R_r) / 2.0f;
  
   Motor_L = (int)(speed_exp * R_l / R_m);
   Motor_R = (int)(speed_exp * R_r / R_m);
   
   if(Motor_L > Motor_R)
   {
     Motor_L = (int)(Motor_L * 1.3f);
     Motor_R = (int)(Motor_R / 1.3f);
   }
   else if(Motor_L < Motor_R)
   {
     Motor_L = (int)(Motor_L / 1.3f);
     Motor_R = (int)(Motor_R * 1.3f);
   }
	 else
	 {
		 Motor_L = speed_exp;
     Motor_R = speed_exp;
	 }
   pre_motorB=Motor_L;
	 pre_motorA=Motor_R;
   motor_init();
	 
	 
}

int daochejiesu=0;

void direction_init(void)
{
	if(crossflag ==0)
	{
		if(h3==1&&h4==1)
		  error=(ML-MR)/(MML+MMR+ML+MR);
	  else if(h3==1)
		  error=(ML)/(MML+MMR+ML+MR);
	  else if(h4==1)
		  error=-(ML)/(MML+MMR+ML+MR);
	  else if(h2==1&&h3==1)
		  error=(MML)/(MML+MMR+ML+MR);
	  else if(h4==1&&h5==1)
		  error=-(MML)/(MML+MMR+ML+MR);
	  else if(h2==1)
		  error=(MML+ML)/(MML+MMR+ML+MR);
	  else if(h5==1)
		  error=-(MML+ML)/(MML+MMR+ML+MR);
	  else;
	}
	else if(crossflag==1)
	{
		//daocheflag=1;
	
			if(b1==1||b1==3)   //1号病房
		  {
			  error=1;
		  }
		  else
		  {
			  error=-1;
		  }
	}
	 
}



void jiance_init(void)
{
	if(crossflag==1)
	{
		
		
			time+=1;
		  if(time>=40)
		  {
			  if(h3==1)
			  {
					
					//fuck=1;
				  //if(fuck==1&&h2==1)
					//{
						time=0;
				    stopjiance=1;
				    crossflag=0;
				  //daochejiesu=0;
				    zhidaoflag=1;
					
					  crossout=1;
					//}
			  }
		  }
		
	}
	//else if(stopflag==1)
		//stopflag =1;
	else
	{
		if(Crossjudge)
		{
			if(b1==3)
			{
				  if(crosscount3==1)
					{
						
							
							crosscount4=1;
						  crosscount3=0;
						
					}
					else;
          if(crosscount2==1)
					{
						crosscount3=1;
						crosscount2=0;
					}
					else;
					if(crosscount1==1)
					{
						crosscount2=1;
						crosscount1=0;
					}
		      else
				  {
					  time+=1;
				    if(time>=7)						{
							crosscount1=1;
							time=0;
						}
				    else;
				  }
					if(crosscount2==1||crosscount3==1)
					{
						if(starcross==0)
			      {
				      crossflag=1;
			        zhidaoflag=0;
			        if(daocheflag==1)
			        {
				        daocheflag =0;
				        daochestop=1;
			        } 
						}
					}
				
				
				
			}
			else
			{
				if(starcross==0)
			  {
				  crossflag=1;
			    zhidaoflag=0;
			    if(daocheflag==1)
			    {
				    daocheflag =0;
				    daochestop=1;
			    }
				}
			}
				
				
			
		}
	  else if(stopjudge)
		{
			if(stopok==1)
			{
				stopflag=1;
				zhidaoflag=0;
			}
		}
	  else
		{
			zhidaoflag=1;
			crossflag=0;
		}
		if(stopjiance==1)
		{
			if((h1==1||h6==1)&&(h3==1||h4==1||h5==1||h2==1))
			{
				stopok=1;
			}
		}
	}
}

void Run_PID_init(void)
{
	Last_duty=duty;
	pid_param_t Run1_pid = PID_CREATE(1.7, 0, 0, 1, 15, 5, 15); //PID
	OUTPUT=pid_solve(&Run1_pid,error);
	

	if(OUTPUT>=1)
		OUTPUT=1;
	else if(OUTPUT<=-1)
		OUTPUT=-1;
	else
		OUTPUT=OUTPUT;
	
	duty=4220-OUTPUT*840;
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}

#define daoyaojieshu  1

void daoyao_init(void)
{
	if(stopflag==1)
	{
		if(yao==0)
		{
			gpio_set(C5,0);
			if(stopcount==0)
		  {
			  stopflag=0;
		    stopjiance=0;
		    stopok=0;
		    daocheflag=1;
		    daochestar=1;
		    stopcount=1;
			  motorA=0;
			  motorB=0;
		  }
		else
			gpio_set(lv,1);
		}
		else
		{
			if(stopcount==0)
				gpio_set(C5,1);
			
		}
		
	}
}

void daocheRun_PID_init(void)
{
	Last_duty=duty;
	pid_param_t Run2_pid = PID_CREATE(0.2, 0, 0, 1, 15, 5, 15); //PID
	OUTPUT=pid_solve(&Run2_pid,error);
	

	if(OUTPUT>=1)
		OUTPUT=1;
	else if(OUTPUT<=-1)
		OUTPUT=-1;
	else
		OUTPUT=OUTPUT;
	
	duty=4220-OUTPUT*870;
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}

void daochemotor_init(void)
{
	if(k==0)
	{
		motorA=0;
		motorB=0;
		k=1;
	}
	pre_motorA=180;
	pre_motorB=180;
	dirA=50000;
	dirB=50000;
   pid_param_t motorA_pid = PID_CREATE(5, 3, 0, 1, 1000, 1000, 130);
	//motor =last_motor + bangbang_pid_solve(&motor_pid, coder-pre_motor);
	 motorA=last_motorA-increment_pid_solve(&motorA_pid, coderA-pre_motorA);
	 pid_param_t motorB_pid = PID_CREATE(5, 3, 0, 1, 1000, 1000, 130);
	//motor =last_motor + bangbang_pid_solve(&motor_pid, coder-pre_motor);
	 motorB=last_motorB-increment_pid_solve(&motorB_pid, coderB-pre_motorB);
	last_motorA=motorA;
	last_motorB=motorB;
	
	if(crossflag==1)
	{
		
		
			if(b1==1||b1==3)
			{
				dirA=0;
				motorA=5000;
			}
			  //motorA=0;
		  else
			{
				dirB=0;
				motorB=5000;
			}
		
		
			
	}
	else;
	if(crossout==1)
	{
		crossout=0;
		if(b1==1||b1==3)
			{
				dirA=50000;
				motorA=8000;
			}
			  //motorA=0;
		  else
			{
				dirB=50000;
				motorB=8000;
			}
	}
	else;
	if(motorA>=20000)
		motorA=20000;
	else;
	if(motorB>=10000)
		motorB=10000;
	else;
		

	
	 pwm_duty_updata (MOTORM, MOTORA, motorA);
	 pwm_duty_updata (MOTORM, MOTORa, dirA);
	 pwm_duty_updata (MOTORM, MOTORB, motorB);
	 pwm_duty_updata (MOTORM, MOTORb, dirB);
	

}
	
void daochedirection_init(void)  
{
	if(crossflag ==0)
	{
		if(h3==1&&h4==1)
		  error=(ML-MR)/(MML+MMR+ML+MR);
	  else if(h3==1)
		  error=(ML)/(MML+MMR+ML+MR);
	  else if(h4==1)
		  error=-(ML)/(MML+MMR+ML+MR);
	  else if(h2==1&&h3==1)
		  error=(MML)/(MML+MMR+ML+MR);
	  else if(h4==1&&h5==1)
		  error=-(MML)/(MML+MMR+ML+MR);
	  else if(h2==1)
		  error=(MML+ML)/(MML+MMR+ML+MR);
	  else if(h5==1)
		  error=-(MML+ML)/(MML+MMR+ML+MR);
	  else;
	}
	else if(crossflag==1)
	{
		if(b1==1||b1==3)   //1号病房
		{
			error=1;
		}
		else
		{
			error=-1;
		}
	}
	else;
	if(daochestar==1)
	{
		error=0;
		time+=1;
		if(time>=70)
		{
			time=0;
			daochestar=0;
		}
		
	}
	 
}


