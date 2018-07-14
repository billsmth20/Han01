#include <MsTimer2.h>
#define  Value 1.02101761  //计算周长的常量
 
//volatile int state = HIGH;
 
int u_left = 3;//定义U型测速端口
int u_right = 2;
 
int leftCW=5;//连接电机1转向端口到数字接口4
int rightCW=10;//连接电机2转向端口到数字接口7
int leftPWM=6; //连接电机1调速端口到数字接口5     
int rightPWM=9;  //连接电机2调速端口到数字接口6 
 
int r_wheel = 0; //记录U型测速模块的次数
int l_wheel = 0;
float r_velocity=0;//速度;
float l_velocity=0;
 
float velocity(int n)
{
  //(n/20)轮子装的圈数,轮子直径是65mm
  //速度的计算公式应该为  （n/20）×(65×10-1×π)  即n*1.02101761
  //后面的计算得常数
  float vel =Value*(n/20);
  return vel;
}
void flash() 
{//noInterrupts();
  //String s1="";
 // String s2="";
  int r,l;
  r=r_wheel;l=l_wheel;
  //noInterrupts();
  r_velocity=velocity(r);
  l_velocity=velocity(l);
  //Serial.print(r_velocity);
 // Serial.print("\0");
 // itoa (r_wheel,buffer1,10);
  //itoa (l_wheel,buffer2,10);
  //s1+=r;
  //s2+=l;
  
  Serial.print(l_velocity);
   Serial.print("cm/s(L)");
  Serial.print(" ");
  // Serial.print(l_velocity);
  // Serial.print("\0");
  Serial.print(r_velocity);
   Serial.println("cm/s(R)");
  r_wheel = 0;
  l_wheel = 0;
//  interrupts();
}
 
 
void setup ()
{
  Serial.begin(9600);
   
  attachInterrupt(0,RCount, FALLING);
  attachInterrupt(1,LCount, FALLING);
   
  pinMode(leftCW,OUTPUT);
  pinMode(leftPWM,OUTPUT);
  pinMode(rightCW,OUTPUT);
  pinMode(rightPWM,OUTPUT);
   
  MsTimer2::set(1000, flash);        // 中断设置函数，每 1s 进入一次中断
  MsTimer2::start();
   
}
 
void loop()
{
  analogWrite( leftPWM,30);//电机1全速前进
  analogWrite(rightPWM,30);//电机2全速前进
  digitalWrite(leftCW,HIGH);//电机1正转
  digitalWrite(rightCW,HIGH);//电机2正转
   
  while (1)
  {
 //   digitalWrite(13, state);
  }
   
}
void LCount()
{
  l_wheel++;
 // state=!state;
   
}
void RCount()
{
  r_wheel++;
}
