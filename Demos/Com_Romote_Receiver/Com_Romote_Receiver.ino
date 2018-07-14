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
    Mirf.setRADDR((byte *)"Cliend01");
    //设置一次收发的字节数，这里发一个整数，
    //写sizeof(unsigned int)，实际等于2字节
    Mirf.payload = sizeof(unsigned int);
    //发送通道，可以填0~128，收发必须一致。
    Mirf.channel = 3;
    Mirf.config();
}

void loop()
{
    //定义一个暂存数组，大小为Mirf.payload。
    if(Mirf.dataReady())    //等待接收数据准备好
    {
      Mirf.getData(data);    //接收数据到data数组
      //这里编写要执行的程序
      doAction();
      //这里编写要返回的程序
      returnMsg();
    }
    

}

