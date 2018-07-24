#include <MsTimer2.h>

// 8x8x8x Blue LED Cube
// by Hari Wiguna 2014
//
// v03 - blinks all 512
// v04 - more test patterns.  Uses TimerOne library.
// v06 - Using MsTimer2
// v07 - Don't turn off previous layer until the very last moment for brighter display

//-- Shift Register pins --
int latchPin = 13;
int clockPin = 12;
int dataPin  = 11;

//-- Globals --
volatile int8_t cube[8][8]; // byte bits = X, 1st index=Y, 2nd index = Z
volatile int8_t gZ = 0;

void SetupPins()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i=0; i<8; i++) {
    pinMode(2+i, OUTPUT);
  }
}

void setup(void) {
  SetupPins();
  CubeAllOff();
  RunTests();
  SetupTimer();
}

void SetupTimer()
{
  MsTimer2::set(2,Refresh); // was 2
  MsTimer2::start();
}

void RunTests()
{
  Serial.begin(9600);

  Serial.print("TestCubeAllOff = ");
  Serial.println(TestCubeAllOff());

  Serial.print("TestDrawLayer = ");
  Serial.println(TestDrawLayer());    // 8052 micro seconds

  Serial.print("TestRefresh = ");
  Serial.println(TestRefresh());    // 8052 micro seconds

  Serial.end();
}

long TestCubeAllOff()
{
  long start = micros();
  CubeAllOff();
  long finish = micros();
  return finish-start;
}

long TestRefresh()
{
  long start = micros();
  Refresh();
  long finish = micros();
  return finish-start;
}

long TestDrawLayer()
{
  long start = micros();
  DrawLayer(gZ);
  long finish = micros();
  return finish-start;
}


void TestPattern3()
{
  CubeAllOff();
  delay(500);
  CubeAllOn();
  delay(500);
}

void loop(void) {
//    //随机闪烁
//    RandomOnorOff(5);
//    //显示盒子，延迟500
//    ShowCube(500);
//    //下雨，雨滴数量：32
//    Rainning(32);
//    //呼吸灯，延迟2，重复4
//    LedBreath(2,4);
//    //旋转
//    LayerRotate(150);
//    //随机线，15条，间隔300毫秒
//    RandomLine(15,200);
//    //随机亮层，重复25次，间隔200毫秒
//    RandomLayer(25,200);
//    //从下到上，重复3次，延迟100毫秒,递增-25
//    Bottom2Up(3,150,-45);

      Screen01();
      delay(1000); 
      CubeAllOff();
      
//    Rotate();
//    delay(1000);
//  CubeAllOff();
//  CubeUp();  delay(1000);
//  CubeAllOff();
//  CubeLeftRight();  delay(1000);
//  TestPattern2_Scan_one_layer();  delay(1000);
//  TestPattern4_Scan_one_wall();  delay(1000);
//  TestPattern5_swipe_wall_up();  delay(1000);
//  BottomCorner(); delay(1000);
//  RightCorner(); delay(1000);
//  BottomRow(); delay(1000);
//  CubeAllOn();  delay(1000);
//  BottomUp();  delay(1000);
//  LeftRight();delay(1000);
//  OneWall();  delay(1000);
//  CubeAllOn();  delay(1000);
}
void BottomUp()
{
  for (int8_t z=0; z<8; z++) {
    for (int8_t x=0; x<8; x++) {
      for (int8_t y=7; y<8; y++) {
        SetDot(x,y,z); 
      }
    }
    delay(64);
    CubeAllOff();
  }
}


void OneWall()
{
  for (int8_t z=0; z<8; z++) {
    for (int8_t x=0; x<8; x++) {
      for (int8_t y=7; y<8; y++) {
        SetDot(x,y,z); 
      }
    }
  }
}

void LeftRight()
{
  for (int8_t x=0; x<8; x++) {
    for (int8_t z=0; z<8; z++) {
      for (int8_t y=7; y<8; y++) {
        SetDot(x,y,z); 
      }
    }
    delay(64);
    CubeAllOff();
  }
}

void TestPattern1()
{
  //int8_t y = 7;
  for (int8_t x=0; x<8; x++) {
    for (int8_t y=0; y<8; y++) {
      SetDot(x,y,0); 
      SetDot(7-x,y,1);
    }

    delay(20);

    for (int8_t y=0; y<8; y++) {
      ClearDot(x,y,0); 
      ClearDot(7-x,y,1);
    }
  }
}

void TestPattern2_Scan_one_layer()
{
  for (int8_t y=0; y<8; y++) {
    for (int8_t x=7; x>=0; x--) {
      SetDot(x,y,0);
      delay(64);
      ClearDot(x,y,0);
    }
  }
}

void TestPattern4_Scan_one_wall()
{
  for (int8_t z=0; z<8; z++) {
    for (int8_t x=7; x>=0; x--) {
      SetDot(x,7,z);
      delay(64);
      ClearDot(x,7,z);
    }
  }
}

void TestPattern5_swipe_wall_up()
{
  for (int8_t z=0; z<8; z++) {
    SetLayer(z,0xFF);
    //for (int8_t x=0; x<8; x++) SetDot(x,7,z);
    //for (int8_t y=3; y<8; y++) for (int8_t x=0; x<8; x++) SetDot(x,y,z);
    delay(64);
    //SetLayer(z,0x00);
    CubeAllOff();
    //for (int8_t x=0; x<8; x++) ClearDot(x,7,z);
    //for (int8_t y=3; y<8; y++) for (int8_t x=0; x<8; x++) ClearDot(x,y,z);
  }
}

