#include <Servo.h>

#define servoPowerPin 9
Servo servoPower;
int valueAnalog=0;
int myangle;
void setup() {
  Serial.begin(9600);
  pinMode(servoPowerPin,OUTPUT);
  Serial.println("init over");
  delay(3000);
  powerOn();
}

void loop() {
  valueAnalog = analogRead(A0);
//  for(int i=0;i<=50;i++)//给予舵机足够的时间让它转到指定角度
//  {
      servopulse(valueAnalog);//引用脉冲函数
//  }
}
