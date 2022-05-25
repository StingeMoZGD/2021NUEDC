#include "lcd.h"
extern int h1,h2,h3,h4,h5,h6;
extern int coderA,coderB,motorA,motorB,pre_motorA,pre_motorB,duty,daocheflag,daochestar,crossflag,crossout,stopjiance,stopok,time,b1,crosscount1,crosscount2,crosscount3,crosscount4;
extern float error;

void LCD_init(void)
{
	lcd_showint32(1,0,h1,10);
	lcd_showint32(1,1,h2,10);
	lcd_showint32(1,2,h3,10);
	lcd_showint32(1,3,h4,10);
	lcd_showint32(1,4,h5,10);
	lcd_showint32(1,5,h6,10);
	lcd_showint32(1,6,coderA,10);
	lcd_showint32(1,7,coderB,10);
	lcd_showint32(50,0,motorA,10);
	lcd_showint32(50,1,motorB,10);
	lcd_showint32(50,2,pre_motorA,10);
	lcd_showint32(50,3,pre_motorB,10);
	lcd_showfloat(50,4,error,1,3);
	lcd_showint32(50,5,duty,10);
	lcd_showint32(50,6,daocheflag,10);
	lcd_showint32(50,7,daochestar,10);
	lcd_showint32(100,7,crossflag,10);
  lcd_showint32(100,6,crossout,10);
	lcd_showint32(100,5,stopjiance,10);
	lcd_showint32(100,4,stopok,10);
	lcd_showint32(100,3,time,10);
	lcd_showint32(100,2,b1,10);
	lcd_showint32(130,0,crosscount1,10);
	lcd_showint32(130,1,crosscount2,10);
	lcd_showint32(130,2,crosscount3,10);
	lcd_showint32(130,3,crosscount4,10);
}