#include "IRremoteInt.h"
void setup()
{
  Serial.begin(9600);
  pinMode(IR_IN,INPUT_PULLUP);//设置红外接收引脚2为输入
  Serial.flush(); //清除串口缓冲器内容函数。
  timer1_init(); //定时器初始化
}
void loop()
{
  remote_decode(); //译码
  Deal_Print(); //解码
}
void Deal_Print()//此处只识别了+和-，用户可以根据adrL_code识别更多按键。
{
  if( adrL_code == 0x07 )
  Serial.println("-");
  else if( adrL_code == 0x15)
  Serial.println("+");
  adrL_code = 0x00; adrH_code = 0x00; ir_code = 0x00;//清0
}
