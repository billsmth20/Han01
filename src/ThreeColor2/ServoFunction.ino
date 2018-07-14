void powerOn(){
  servoPower.attach(servoPowerPin,1000,2000);
  delay(2500);    
  servoPower.writeMicroseconds(1000);   
  delay(2000);
}

void powerOff(){
  Serial.println("powerOff");
  for(int i=0;i<=20;i++)
    {
      digitalWrite(servoPowerPin,HIGH);
      delayMicroseconds(400);
      digitalWrite(servoPowerPin,LOW);
      delay(20-10/1000);
    }
}
void servopulse(int val){
  val=map(val,0,1010,500,2480);
  servoPower.write(val);
  delay(15);
}

void servopulse2(int val1)//定义一个脉冲函数
{
  myangle=map(val1,0,1023,500,2480);
  digitalWrite(servoPowerPin,HIGH);//将舵机接口电平至高
  delayMicroseconds(myangle);//延时脉宽值的微秒数
  digitalWrite(servoPowerPin,LOW);//将舵机接口电平至低
  myangle=map(val1,0,1023,0,180);
  delay(20-myangle/1000);
}

