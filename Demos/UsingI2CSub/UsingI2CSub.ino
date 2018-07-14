#include <Wire.h> 
int LED = 2; 
void setup() 
{ 
  Wire.begin(4);                    // 设置从机地址为 4 
  Wire.onReceive(receiveEvent);     //从机接收主机发来的数据  
  pinMode(LED,OUTPUT);              // 设置IO口为输出模式 
} 
void loop() 
{ 
  delay(100); 
} 
void receiveEvent(int howMany)   // 接收从主机发过来的数据 
{ 
    int c = Wire.read();      // 接收单个字节 
    if(c==1) 
      {  
         digitalWrite(LED,HIGH); // 如果为 1 开LED 
      } 
    else if(c==0) 
      { 
         digitalWrite(LED,LOW);  // 如果为 0 关LED 
      }  
}
