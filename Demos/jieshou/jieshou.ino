#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

byte data[2],retData[2];

void setup() {
  Serial.begin(9600);
 Serial.println("reset Mirf");
  Mirf.cePin = 8;     //设置CE引脚为D8//test//
  Mirf.csnPin = 7;
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
  delay(2000);
}

void loop() {
  if(Mirf.dataReady()){
    Mirf.getData(data);    //接收数据到data数组
    delay(2);
    Serial.print("data0=");
    Serial.print(data[0]);
    Serial.print(" data1=");
    Serial.print(data[1]);
    Serial.println("");
    delay(50);
//    checkCommand();
  }
  delay(100);

}
