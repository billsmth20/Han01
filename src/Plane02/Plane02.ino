#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <Servo.h>

#define servoPowerPin 9
#define servoLeftPin 5
#define servoRightPin 6
Servo servoPower;
Servo servoWingRight;
Servo servoWingLeft;
int powerVal; 
int wingAngle=0;
int diffAngle=0;
int startVal=0;
int state=0;
int planeStatus=0;
boolean btnState=false;
byte data[2],retData[2];
int autoDriveDiffAngle=0;
int autoDriveWingAngle=0;

double Xg,Yg,Zg;




void setup() {
  Serial.begin(9600);
  servoWingLeft.attach(servoLeftPin);
  servoWingRight.attach(servoRightPin);
  
  //---------初始化部分，不可随时修改---------
  Mirf.cePin = 8;     //设置CE引脚为D8//test//
  Mirf.csnPin = 7;   //设置CE引脚为D7
  resetMirf();
  Serial.println("init over");
  ADXL345_setup();
  planeStatusCheck();
}

void loop() {

  if(Mirf.dataReady()){
    Mirf.getData(data);    //接收数据到data数组
    delay(2);
//    Serial.print("data0=");
//    Serial.print(data[0]);
//    Serial.print(" data1=");
//    Serial.print(data[1]);
//    Serial.println("");
//    delay(10);
  }
//  delay(100);
  orderCheck();
}

void orderCheck(){

  powerVal=data[0]&15;
  startVal=data[0]>>4&15;
  diffAngle=data[1]&15;
  wingAngle=data[1]>>4&15;
  //data[1]=119;
//  Serial.print("powerVal:");
//  Serial.print(powerVal);
//  Serial.print("  startVal:");
//  Serial.print(startVal);
//  Serial.print("  wingAngle:");
//  Serial.print(wingAngle);
//  Serial.print("  diffAngle:");
//  Serial.print(diffAngle);
//  Serial.print("  Xg:");
//  Serial.print(Xg);
//  Serial.print("  Yg:");
//  Serial.print(Yg);
//  wingAngle=analogRead(wingAnglePin);
//  diffAngle=analogRead(wingAngleDiffPin);
//  powerVal = analogRead(powerPin);
  if(startVal==1){
      planeStatus=1;
      powerOn();
//  }else{
//    if(planeStatus==1){
//      planeStatus=0;
//      powerOff();
//      delay(3000);
//    }
  }
  if(planeStatus==1){
    servopulse(powerVal);
  }
  if(wingAngle==7&&diffAngle==7){
//    Serial.println("wingAngle==7&&diffAngle==7");
    ADXL345_Action();
    if(Xg>30||Xg<-30||Yg>30||Yg<-30){
//      Serial.println("Xg>30||Xg<-30||Yg>30||Yg<-30");
      autoDrive();
      delay(50);
    }
  }else{
    wingAction(wingAngle, diffAngle);
    delay(50);
  }
}
void resetMirf(){
  Serial.println("reset Mirf");
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();  //初始化nRF24L01
  
  //---------配置部分，可以随时修改---------
  //设置接收标识符"Plane01"
  Mirf.setRADDR((byte *)"Plane01");
  //设置一次收发的字节数，这里发一个整数，
  //写sizeof(unsigned int)，实际等于2字节
  Mirf.payload = sizeof(unsigned int);
  //发送通道，可以填0~128，收发必须一致。
  Mirf.channel = 3;
  Mirf.config();
}
void autoDrive(){
  if(Zg>150){
    autoDriveDiffAngle=0;
  }else if(Zg<-150){
    autoDriveDiffAngle=15;
  }else{
    autoDriveDiffAngle=map(Zg,-150,150,15,0);
  }
  if(Yg>150){
    autoDriveWingAngle=-7;
  }else if(Yg<-150){
    autoDriveWingAngle=7;
  }else{
    autoDriveWingAngle=map(Yg,-150,150,7,-7);
  }
  
  wingAction(7+autoDriveWingAngle, autoDriveDiffAngle);
}

