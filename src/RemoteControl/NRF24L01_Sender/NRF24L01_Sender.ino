
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
//#include <NOKIA5110LIB.h>

#define JoyStick_X A0
#define JoyStick_Y A1
#define JoyStick_Z A2
#define Btn_A A4
#define Btn_B A5
#define Btn_C A6
#define Btn_D A7

const int Btn_Delay=100;
const int COMM_DELAY=60;

int x,y,z,btn=0;
byte data[2],dataRet[2],dataOld[2];
boolean sendFlg=false;
  
void setup()
{
    Serial.flush();
    Serial.begin(9600);

    Mirf.cePin = 8;   //设置CE引脚为D8
    Mirf.csnPin = 7; //设置CE引脚为D7
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();  //初始化nRF24L01   
//    lcd_init();//初始化液晶 
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
    pinMode(JoyStick_Z,INPUT);
    pinMode(Btn_A,INPUT);
    pinMode(Btn_B,INPUT);
    pinMode(Btn_C,INPUT);
    pinMode(Btn_D,INPUT);
}


void loop()
{
    doSenderAction();
//    doDisplay();
}
void doSenderAction(){
  // 接收高度信息
//  while(Mirf.dataReady()){
//    Mirf.getData(dataRet);
//    if(dataRet[0]!=0&&dataRet[1]!=0){
//      dataOld[0]=dataRet[0];
//      dataOld[1]=dataRet[1];
//      dataRet[0]=0;
//      dataRet[1]=0;
//    }
//  }
  
  // 发送命令
  createCommand();
//  if(data[1]==48&&btn==0){
//    if(!sendFlg){
//      sendFlg=true;
//      doSendMessage();
//    }
//  }else{
//    sendFlg=false;
    doSendMessage();
//  }
  delay(COMM_DELAY);
}

void doSendMessage(){
  //设置向"serv1"发送数据
  Mirf.setTADDR((byte *)"Ship01");
  Mirf.send(data);
  //while死循环等待发送完毕，才能进行下一步操作。
  while(Mirf.isSending()) {}
  Serial.print("data=");
  Serial.print(data[0]);
  Serial.print(data[1]);
  Serial.println("");
}

