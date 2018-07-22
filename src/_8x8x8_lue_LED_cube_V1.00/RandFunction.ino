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
// 随机线，cnt:随机线条数，delayTime:间隔时间
void RandomLine(int cnt, int delayTime){
  int typeXYZ=0;
  for(int i=0;i<cnt;i++){
    typeXYZ=random(3);
    if(typeXYZ==0){
      DrawLine(-1,random(8),random(8));
    }else if(typeXYZ==1){
      DrawLine(random(8),-1,random(8));
    }else if(typeXYZ==2){
      DrawLine(random(8),random(8),-1);
    }
    delay(delayTime);
  }
}
//随机亮层，repeat重复次数，interval间隔毫秒数
void RandomLayer(int repeat, int interval){
  int cnt=0;
  for(int i=0;i<repeat;i++){
    cnt=random(3);
    switch(cnt){
      case 0:
        DrawXYZLayer(random(7),-1,-1);
      case 1:
        DrawXYZLayer(-1,random(7),-1);
      case 2:
        DrawXYZLayer(-1,-1,random(7));
    }
    delay(interval);
    CubeAllOff();
  }
}

