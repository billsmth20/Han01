//呼吸灯
//delaytime:延迟时间
//repeat:重复次数
void LedBreath(int delaytime, int repeat)
{
  for (int x=0; x<repeat; x++) {
    RandomOn(delaytime);
    RandomClearDot(delaytime);
  }
}
//随机闪烁
//delaytime:延迟时间
void RandomOnorOff(int delaytime){
  for (int x=0; x<2048; x++) {
    ClearDot(random(0,8),random(0,8),random(0,8));
    SetDot(random(0,8),random(0,8),random(0,8));
    delay(delaytime);
  } 
}
void RandomOn(int delaytime)
{
  for (int x=0; x<1024; x++) {
        SetDot(random(0,8),random(0,8),random(0,8));
        delay(delaytime);
  }  
}
void RandomClearDot(int delaytime)
{
  for (int x=0; x<1024; x++) {
        ClearDot(random(0,8),random(0,8),random(0,8));
        delay(delaytime);
  }  
}

