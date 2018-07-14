int buzzer = 8; //设置控制蜂鸣器的数字IO 脚
void setup()
{
  pinMode(buzzer, OUTPUT);
}
void loop()
{
  unsigned char i, j; //定义变量
  while (1)
  {
//    for (i = 0; i < 80; i++)
//      //辒出一个频率的声音
//    {
//      digitalWrite(buzzer, HIGH); //发声音
//      delay(1);//延时1ms
//      digitalWrite(buzzer, LOW); //不发声
//      delay(1);//延时ms
//    }
    for (i = 0; i < 100; i++)
      //辒出另一个频率癿声音
    {
      digitalWrite(buzzer, HIGH); //发声
      delay(4);//延时2ms
      digitalWrite(buzzer, LOW); //不发声
      delay(4);//延时2ms
    }
  }
}
