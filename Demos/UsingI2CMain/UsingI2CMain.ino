#include <Wire.h>

void setup() 
{ 
  Wire.begin();            //启动I2C总线，地址缺省表示为主机 
  Serial.begin(9600);      //启动串口，设置波特率为9600 
  Serial.println("Ready"); //发送字符 
} 
void loop() 
{ 
  int val; 
  if(Serial.available() > 0)  //判断串口缓冲器是否有数据装入 
   { 
      val=Serial.read();      //读串口 
      if(val==49)//1 
        { 
          Wire.beginTransmission(4);  // 与地址4的从机连接通讯 
          Wire.write(1);               // 发送数字  1 开LED  
          Wire.endTransmission();     // 停止发送 
          Serial.println("49 OK");    // 串口上显示 49 OK 表示完成，49表示为数字 1的ASCII码 
          delay(10);                  // 
        } 
      else if(val==50)//2 
        { 
          Wire.beginTransmission(4);  // 与地址4的从机连接通讯 
          Wire.write(0);               // 发送数字  0 关LED 
          Wire.endTransmission();     // 停止发送 
          Serial.println("50 OK");    // 串口上显示 50 OK 表示完成 
          delay(10);   
        }    
      else if(val==51)//3 
        { 
          Wire.beginTransmission(5);  // 与地址5的从机连接通讯 
          Wire.write(1);               // 发送数字  1 开LED 
          Wire.endTransmission();     // 停止发送 
          Serial.println("51 OK");    // 串口上显示 51 OK 表示完成 
          delay(10);   
        } 
      else if(val==52)//4 
        { 
          Wire.beginTransmission(5);  // 与地址5的从机连接通讯 
          Wire.write(0);               // 发送数字  0 关LED 
          Wire.endTransmission();     // 停止发送 
          Serial.println("52 OK");    // 串口上显示 52 OK 表示完成 
          delay(10);   
        }      
       else Serial.println(val);  
    }   
}
