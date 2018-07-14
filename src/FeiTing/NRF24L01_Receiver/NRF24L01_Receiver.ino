#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

//定义一个变量adata存储最终结果,oldadata存储旧结果，防止相同结果刷屏。
unsigned int adata = 0, oldadata = 0;

byte data[2],retData[2];;
String receiveData = "";

void setup()
{
    Serial.begin(9600);

    //---------初始化部分，不可随时修改---------
    Mirf.cePin = 8;     //设置CE引脚为D8//test//
    Mirf.csnPin = 7;   //设置CE引脚为D7
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();  //初始化nRF24L01

    //---------配置部分，可以随时修改---------
    //设置接收标识符"Ship01"
    Mirf.setRADDR((byte *)"Ship01");
    //设置一次收发的字节数，这里发一个整数，
    //写sizeof(unsigned int)，实际等于2字节
    Mirf.payload = sizeof(unsigned int);
    //发送通道，可以填0~128，收发必须一致。
    Mirf.channel = 3;
    Mirf.config();

    //注意一个Arduino写Sender.ino，另一个写Receiver.ino。
    //这里用来辨别写入了Receiver.ino程序
//    Serial.println("I'm Receiver...");
}

void loop()
{
    //定义一个暂存数组，大小为Mirf.payload。
    
    if(Mirf.dataReady())    //等待接收数据准备好
    {
        Mirf.getData(data);    //接收数据到data数组
        checkCommand();
        //data[1]<左移8位与data[0]并，重组数据。
//        adata = (unsigned int)((data[1] << 8) | data[0]);
//        data[0] = adata & 0xFF;   //低八位给data[0]，
//        data[1] = adata >> 8;
//        //与上一次结果比较，避免相同结果刷屏,降低串口流量
//        if(adata != oldadata)
//        {
//            oldadata = adata; //本次结果作为历史结果。
//            //Serial.print输出数据
//            Serial.print("A0=");
//            Serial.println(adata);
//            //也可以输出双字节数据
//            Serial.print("D:");
//            Serial.write(data[0]);
//            Serial.print("  data1:");
//            Serial.write(data[1]);
//            Serial.println();
//        }
      
      returnMsg();
    }
    
}
void returnMsg(){
  while (Serial.available() > 0)  {
    receiveData += char(Serial.read());
    delay(2);
  }
  if(receiveData!=""){
    Mirf.setTADDR((byte *)"Ctrl01");
    retData[0]=receiveData.charAt(0);
    retData[1]=receiveData.charAt(1);
    Mirf.send(retData);
    //while死循环等待发送完毕，才能进行下一步操作。
    while(Mirf.isSending()) {}
    receiveData="";
//      Serial.print(receiveData);
//      Serial.println();
//      delay(4000);
  }
}
void checkCommand(){
  if(data[0]==15){
//    Serial.print("Directon:");
//    Serial.println();
    doAction(data[1]);
  }
}
void doAction(byte d){
  // 停
  if(d==48){
    Serial.print("STOP");
  // 向前
  }else if(d==24){
    Serial.print("FRONT");
  // 向后
  }else if(d==25){
    Serial.print("BACK");
  // 向左
  }else if(d==26){
    Serial.print("LEFT");
  // 向右
  }else if(d==27){
    Serial.print("RIGHT");
  // 向左前
  }else if(d==49){
    Serial.print("FRONT-LEFT");
  // 向右前
  }else if(d==50){
    Serial.print("FRONT-RIGHT");
  // 向左后
  }else if(d==51){
    Serial.print("BACK-LEFT");
  // 向右后
  }else if(d==52){
    Serial.print("BACK-RIGHT");
  // 按钮A
  }else if(d==53){
    Serial.print("BNT-A");
  // 按钮B
  }else if(d==54){
    Serial.print("BNT-B");
  }
}
