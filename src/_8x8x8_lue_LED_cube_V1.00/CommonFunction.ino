void Refresh(void) // WITHOUT the added delayMicroseconds, this routine takes 8052 microseconds
{
//  noInterrupts();

  //-- Compute new layer --
  int8_t prevLayer = gZ;
  gZ++; 
  if (gZ>=8) gZ=0;

  // Prepare for data. Shift data to shift registers but do not reflect it on the outputs yet.
  digitalWrite(latchPin, LOW);

  //-- Spit out the bits --
  DrawLayer(gZ);

  //-- Turn off previous layer --
  digitalWrite(2+prevLayer,LOW); // Turn off prev layer

  // All data ready. Instantly reflect all 64 bits on all 8 shift registers to the led layer.
  digitalWrite(latchPin, HIGH);

  //-- Turn on this layer --
  digitalWrite(2+gZ,HIGH); // Turn on this layer
  
//  interrupts();
}

void TurnOnLayer(int8_t z)
{
  int8_t prev = z==0 ? 7 : z-1;

  // Prepare for data. Shift data to shift registers but do not reflect it on the outputs yet.
  digitalWrite(latchPin, LOW);

  //-- Spit out the bits --
  DrawLayer(z);

  //-- Turn off previous layer --
  digitalWrite(2+prev,LOW); // Turn off prev layer
}

void TurnOffLayer(int8_t z)
{
  // All data ready. Instantly reflect all 64 bits on all 8 shift registers to the led layer.
  digitalWrite(latchPin, HIGH);

  //-- Turn on this layer --
  digitalWrite(2+z,HIGH); // Turn on this layer
}

void DrawLayer(int8_t z)
{
  // Spit out all 64 bits for the layer.
  for (int8_t y=0; y<8; y++) {
    shiftOut(dataPin, clockPin, MSBFIRST, cube[y][z]); // Push Most significant BYTE first   
  }  
}
void CubeUp()
{
  for (int8_t z=0; z<8; z++) {
    SetLayer(z, 0xFF);
    delay(64);
    SetLayer(z, 0x00);
  }  
}

void CubeLeftRight()
{
  for (int8_t x=0; x<8; x++) {
    SetXPlane(x);
    delay(64);
    CubeAllOff();
  }  
}

//Draw Layer X，Y，Z, if -1 no draw.
void DrawXYZLayer(int8_t x, int8_t y, int8_t z){
  if(x!=-1){
    for (int8_t z=0; z<8; z++) {
      for (int8_t y=0; y<8; y++) {
        bitClear(cube[y][z], x);
      }
    }
  }
  if(y!=-1){
    for (int8_t z=0; z<8; z++) {
      for (int8_t x=0; x<8; x++) {
        bitClear(cube[y][z], x);
      }
    }
  }
  if(z!=-1){
    for (int8_t y=0; y<8; y++) {
      for (int8_t x=0; x<8; x++) {
        bitClear(cube[y][z], x);
      }
    }
  }
}

void SetXPlane(int8_t x)
{
  x = Wrap(x);
  int8_t xPattern = 1 << x;
  for (int8_t z=0; z<8; z++) {
    for (int8_t y=0; y<8; y++) {
//      cube[y][z] = xPattern;
      bitClear(cube[y][z], xPattern);
    }
  }
}
void SetDot(int8_t x,int8_t y,int8_t z)
{
  //noInterrupts();
  bitClear(cube[y][z], x);
  //interrupts();
}

void ClearDot(int8_t x,int8_t y,int8_t z)
{
  bitSet(cube[y][z], x);
}

void SetLayer(int8_t z, int8_t xByte)
{
  //z = Wrap(z);
  for (int8_t y=0; y<8; y++) {
    cube[y][z] = xByte;
    //for (int8_t x=0; x<8; x++) {
    //  if (xByte==0) ClearDot(x,y,z); else SetDot(x,y,z);
    //}
  }
}

int8_t Wrap(int8_t val)
{
  if (val>7)
    return 0;
  else if (val<0)
    return 7;
  else
    return val;
}

void RightCorner()
{
  for (int8_t z=0; z<8; z++) {
    for (int8_t x=4; x<8; x++) {
      for (int8_t y=0; y<8; y++) {
        SetDot(x,y,z); 
      }
    }
  }
}

void BottomCorner()
{
  for (int8_t z=0; z<4; z++) {
    for (int8_t x=4; x<8; x++) {
      for (int8_t y=0; y<8; y++) {
        SetDot(x,y,z); 
      }
    }
  }
}

void BottomRow()
{
  for (int8_t z=0; z<4; z++) {
    for (int8_t x=0; x<8; x++) {
      for (int8_t y=0; y<8; y++) {
        SetDot(x,y,z); 
      }
    }
  }
}

void CubeAllOn()
{
      for (int8_t x=0; x<8; x++) {
    for (int8_t y=0; y<8; y++) {
  for (int8_t z=0; z<8; z++) {
        SetDot(x,y,z);
      }  
    }  
  }  
}

void CubeAllOff()
{
  for (int8_t z=0; z<8; z++) {
    SetLayer(z, 0xFF);
  }  
}
