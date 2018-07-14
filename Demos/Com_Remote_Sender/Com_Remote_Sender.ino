
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <NOKIA5110LIB.h>

int x,y,z,a=0,b=0;
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
    lcd_init();//初始化液晶 
    //设置接收标识符"Con01"
    Mirf.setRADDR((byte *)"Sender01");
    //设置一次收发的字节数，这里发一个整数，写sizeof(unsigned int)，实际等于2字节
    Mirf.payload = sizeof(unsigned int);
    //发送通道，可以填0~128，收发必须一致。
    Mirf.channel = 3;
    Mirf.config();

  //注意一个Arduino写Sender.ino，另一个写Receiver.ino。
  //这里标识写入了Sender.ino
    Serial.println("I'm Sender...");

}
void loop()
{
    doSenderAction();
    doDisplay();
}
void doSenderAction(){
  // 接收高度信息
  if(Mirf.dataReady()){
    Mirf.getData(dataRet);
    if(dataRet[0]!=0&&dataRet[1]!=0){
      dataOld[0]=dataRet[0];
      dataOld[1]=dataRet[1];
      dataRet[0]=0;
      dataRet[1]=0;
    }
  }
  // 发送命令
  createCommand();
  if(data[1]==48){
    if(!sendFlg){
      sendFlg=true;
      doSendMessage();
    }
    delay(30);
  }else{
    sendFlg=false;
    doSendMessage();
    delay(30);
  }
}
void doDisplay(){
  cnt++;
  if(cnt>15){
    cnt=0;
    //directStr();
    lcd_clear(); 
    lcd_write_english_string(0,0," --Sender-- ");
    lcd_write_english_string(0,2,"Send:"); 
    lcd_write_char(data[0]);
    lcd_write_char(data[1]);
//    lcd_write_english_string(0,4,data[1]); 
    lcd_write_english_string(0,4,"Received: ");  
    lcd_write_char(dataOld[0]); 
    lcd_write_char(dataOld[1]); 
  }
}
void doSendMessage(){
  //设置向"serv1"发送数据
  Mirf.setTADDR((byte *)"Cliend01");
  Mirf.send(data);
  //while死循环等待发送完毕，才能进行下一步操作。
  while(Mirf.isSending()) {}
//  Serial.print("data=");
//  Serial.print(data[0]);
//  Serial.print(data[1]);
//  Serial.println("");
}


