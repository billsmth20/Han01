//显示盒子
//delayTime:延迟时间
void ShowCube(int delayTime){
  CubeAllOff();
  for (int8_t z=3; z<5; z++) {
    for (int8_t x=3; x<5; x++) {
      for (int8_t y=3; y<5; y++) {
        SetDot(x,y,z); 
      }
    }
  }
  delay(delayTime);
  for (int8_t z=2; z<6; z++) {
    for (int8_t x=2; x<6; x++) {
      for (int8_t y=2; y<6; y++) {
        SetDot(x,y,z); 
      }
    }
  }
  for (int8_t z=3; z<5; z++) {
    for (int8_t x=3; x<5; x++) {
      for (int8_t y=3; y<5; y++) {
        ClearDot(x,y,z); 
      }
    }
  }
  delay(delayTime);
  for (int8_t z=1; z<7; z++) {
    for (int8_t x=1; x<7; x++) {
      for (int8_t y=1; y<7; y++) {
        SetDot(x,y,z); 
      }
    }
  }
  for (int8_t z=2; z<6; z++) {
    for (int8_t x=2; x<6; x++) {
      for (int8_t y=2; y<6; y++) {
        ClearDot(x,y,z); 
      }
    }
  }
  delay(delayTime);
  for (int8_t z=0; z<8; z++) {
    for (int8_t x=0; x<8; x++) {
      for (int8_t y=0; y<8; y++) {
        SetDot(x,y,z); 
      }
    }
  }
  for (int8_t z=1; z<7; z++) {
    for (int8_t x=1; x<7; x++) {
      for (int8_t y=1; y<7; y++) {
        ClearDot(x,y,z); 
      }
    }
  }
  delay(delayTime);
  CubeAllOff();
  for (int8_t z=1; z<7; z++) {
    for (int8_t x=1; x<7; x++) {
      for (int8_t y=1; y<7; y++) {
        SetDot(x,y,z); 
      }
    }
  }
  for (int8_t z=2; z<6; z++) {
    for (int8_t x=2; x<6; x++) {
      for (int8_t y=2; y<6; y++) {
        ClearDot(x,y,z); 
      }
    }
  }
  delay(delayTime);
  CubeAllOff();
  for (int8_t z=2; z<6; z++) {
    for (int8_t x=2; x<6; x++) {
      for (int8_t y=2; y<6; y++) {
        SetDot(x,y,z); 
      }
    }
  }
  for (int8_t z=3; z<5; z++) {
    for (int8_t x=3; x<5; x++) {
      for (int8_t y=3; y<5; y++) {
        ClearDot(x,y,z); 
      }
    }
  }
  delay(delayTime);
  CubeAllOff();
  for (int8_t z=3; z<5; z++) {
    for (int8_t x=3; x<5; x++) {
      for (int8_t y=3; y<5; y++) {
        SetDot(x,y,z); 
      }
    }
  }
  delay(delayTime);
  CubeAllOff();
  delay(delayTime);
}
// 从下到上，repitTime:重复次数，delayTime:延迟时间毫秒数,delay时间变化:毫秒数
void Bottom2Up(int repitTime,int delayTime, int addTime){
  for(int j=0;j<repitTime;j++){
    CubeAllOff();
    for(int i=0;i<8;i++){
      DrawXYZLayer(i,-1,-1);
      delay(delayTime);
    }
    delayTime=delayTime+addTime;
  }
  CubeAllOff();
}
