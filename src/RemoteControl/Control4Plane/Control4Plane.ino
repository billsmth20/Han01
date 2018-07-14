#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define JoyStick_X A0
#define JoyStick_Y A1
#define enginValPin A2
#define btnPowerPin 4
#define Btn_A A7
#define Btn_B A6

int btnState=0;
int x,y,enginVal,a=0,b=0;
byte data[2],dataRet[2],dataOld[2];
boolean sendFlg=false;
int cnt=0;
char *curCmd;
  
void setup()
{
    Serial.begin(9600);

    Mirf.cePin = 8;   //设置CE引脚为D8
    Mirf.csnPin = 7; //设置CE引脚为D7
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();  //初始化nRF24L01   
    //设置接收标识符"Con01"
    Mirf.setRADDR((byte *)"Ctrl01");
    //设置一次收发的字节数，这里发一个整数，写sizeof(unsigned int)，实际等于2字节
    Mirf.payload = sizeof(unsigned int);
    //发送通道，可以填0~128，收发必须一致。
    Mirf.channel = 3;
    Mirf.config();

  //注意一个Arduino写Sender.ino，另一个写Receiver.ino。
  //这里标识写入了Sender.ino
    Serial.println("I'm Sender...");

    pinMode(JoyStick_X,INPUT);
    pinMode(JoyStick_Y,INPUT);
    pinMode(enginValPin,INPUT);
    pinMode(Btn_A,INPUT);
    pinMode(Btn_B,INPUT);
}
void loop()
{
  createCommand();
  doSendMessage();
  delay(110);
}
void doSendMessage(){
  //设置向"serv1"发送数据
  Mirf.setTADDR((byte *)"Plane01");
  Mirf.send(data);
  //while死循环等待发送完毕，才能进行下一步操作。
  while(Mirf.isSending()) {}
  Serial.print("data0=");
  Serial.print(data[0]);
  Serial.print(" data1=");
  Serial.print(data[1]);
  Serial.println("");
}
void createCommand(){
  
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  enginVal=analogRead(enginValPin);

  if(digitalRead(btnPowerPin)==1){
    delay(50);
    if(digitalRead(btnPowerPin)==1){
      a=1;
    }
  }else{
    a=0;
  }
  enginVal=map(enginVal,0,1023,0,15);
  data[0]=a<<4|enginVal;

  x=map(x,0,1023,0,15);
  y=map(y,0,1023,0,15);
  data[1]=x<<4|y;
}
