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
  val=map(val,0,15,0,180);
  servoPower.write(val);
  delay(15);
}
//void servopulse(int sp1,int val1)
//{
//  myangle1=map(val1,0,180,500,2480);
//  digitalWrite(sp1,HIGH);
//  delayMicroseconds(myangle1);
//  digitalWrite(sp1,LOW);
//  delay(20-val1/1000);
//}

