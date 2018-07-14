#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <NOKIA5110LIB.h>

#define JoyStick_X A0
#define JoyStick_Y A1
#define JoyStick_Z A2
#define Btn_A A7
#define Btn_B A6

int x,y,z,a=0,b=0;
byte data[2],dataRet[2],dataOld[2];
boolean sendFlg=false;
int cnt=0;
char commands[11][12]={"STOP", "FRONT", "BACK", "LEFT", "RIGHT", "FRONT-LEFT", "FRONT-RIGHT", "BACK-LEFT", "BACK-RIGHT", "BNT-A", "BNT-B"};
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
}


void loop()
{
    doDisplay();
    doSenderAction();
}
void doSenderAction(){
  
  // 发送命令
  createCommand();
  if(data[1]==48){
//    if(!sendFlg){
      sendFlg=true;
      doSendMessage();
//    }
    delay(2);
  }else{
    sendFlg=false;
    doSendMessage();
    delay(2);
  }
}
void doDisplay(){
  cnt++;
  if(cnt>10){
    cnt=0;
    lcd_clear(); 
  }
  directStr();
  lcd_write_english_string(0,0," --Micro Car-- ");
  lcd_write_english_string(0,2,curCmd); 
  delay(2);
}
void directStr(){
  switch (data[1]){
    case 48:
      curCmd=commands[0];
      break;
    case 24:
      curCmd=commands[1];
      break;
    case 25:
      curCmd=commands[2];
      break;
    case 26:
      curCmd=commands[3];
      break;
    case 27:
      curCmd=commands[4];
      break;
    case 49:
      curCmd=commands[5];
      break;
    case 50:
      curCmd=commands[6];
      break;
    case 51:
      curCmd=commands[7];
      break;
    case 52:
      curCmd=commands[8];
      break;
    case 53:
      curCmd=commands[9];
      break;
    case 54:
      curCmd=commands[10];
      break;
  }
}
void doSendMessage(){
  //设置向"serv1"发送数据
  Mirf.setTADDR((byte *)"Car01");
  Mirf.send(data);
  //while死循环等待发送完毕，才能进行下一步操作。
  while(Mirf.isSending()) {}
  Serial.print("data=");
  Serial.print(data[0]);
  Serial.print(data[1]);
  Serial.println("");
}
void createCommand(){
  
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=analogRead(JoyStick_Z);
  if(analogRead(Btn_A)==0){
    delay(50);
    if(analogRead(Btn_A)==0){
      a=1;
    }
  }else if(analogRead(Btn_B)==0){
    delay(50);
    if(analogRead(Btn_B)==0){
      b=1;
    }
  }else{
    a=0;
    b=0;
  }
  data[0] = 15;

  // A
  if(a==1){
    data[1] =53 ;
  // B  
  }else if(b==1){
    data[1] =54 ;
  // 停
  }else if(x>450 && x<550 && y>450 && y<550){
    data[1] =48;
  // 向前
  }else if(x>550 && y<550 && y>450){
    data[1] =25 ;
  // 向后
  }else if(x<450 && y<550&&y>450){
    data[1] =24 ;
  // 向左
  }else if(x>450 && x<550 && y<450){
    data[1] =27 ;
  // 向右
  }else if(x>450 && x<550 && y>550){
    data[1] =26 ;  
  // 向左前
  }else if(x>550 && y<450){
    data[1] =52 ;  
  // 向右前
  }else if(x>550 && y>550){
    data[1] =51 ;    
  // 向左后
  }else if(x<450 && y<450){
    data[1] =50 ;    
  // 向右后
  }else if(x<450 && y>550){
    data[1] =49 ;    
  }
}
