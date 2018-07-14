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
