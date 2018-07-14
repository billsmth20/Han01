#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

int input1 = 5; // 定义uno的pin 5 向 input1 输出
int input2 = 6; // 定义uno的pin 6 向 input2 输出
int input3 = 9; // 定义uno的pin 9 向 input3 输出
int input4 = 10; // 定义uno的pin 10 向 input4 输出

//int input_A = 12;
//int input_B = 8;
//int input_C = 11;
//int input_D = 7;
int CNT_SPEED=100;
const int TrigPin = 2;
const int EchoPin = 3;


boolean AUTO_DRIVE=false;
//定义一个变量adata存储最终结果,oldadata存储旧结果，防止相同结果刷屏。
unsigned int adata = 0, oldadata = 0;
float destince;
byte data[2],retData[2];;

void setup() {
  Serial.begin (9600);
  //初始化各IO,模式为OUTPUT 输出模式
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);

  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.println("MANUAL DRIVE");
  Serial.println("STOP");

  //---------初始化部分，不可随时修改---------
  Mirf.cePin = 8;     //设置CE引脚为D8//test//
  Mirf.csnPin = 7;   //设置CE引脚为D7
  resetMirf();
  Serial.println("init over");
}

void loop() {
  if(Mirf.dataReady()){
    Mirf.getData(data);    //接收数据到data数组
    delay(2);
    Serial.print("data=");
    Serial.print(data[0]);
    Serial.print(data[1]);
    checkCommand();
//    if(data[0]!=15){
//      resetMirf();
//    }
  }
  autoDrive();
}

void resetMirf(){
  Serial.println("reset Mirf");
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();  //初始化nRF24L01
  
  //---------配置部分，可以随时修改---------
  //设置接收标识符"Ship01"
  Mirf.setRADDR((byte *)"Car01");
  //设置一次收发的字节数，这里发一个整数，
  //写sizeof(unsigned int)，实际等于2字节
  Mirf.payload = sizeof(unsigned int);
  //发送通道，可以填0~128，收发必须一致。
  Mirf.channel = 3;
  Mirf.config();
}

