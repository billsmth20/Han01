#include <MirfHardwareSpiDriver.h>
#include <Adafruit_NeoPixel.h>

#include "avr/pgmspace.h"

#define PIN 3
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, PIN, NEO_GRB + NEO_KHZ800);

int input1 = 5; // 定义uno的pin 5 向 input1 输出
int input2 = 6; // 定义uno的pin 6 向 input2 输出
int input3 = 9; // 定义uno的pin 9 向 input3 输出
int input4 = 10; // 定义uno的pin 10 向 input4 输出

int CNT_SPEED=200;
int i=0;
int dataIndex=0;

// 0:stop
// 1:forward
// 2:back
// 3:left
// 4:right
// 5:colorWipe
//  51      colorWipe(strip.Color(255, 0, 0), 500); // Red
//  52      colorWipe(strip.Color(0, 255, 0), 500); // Green
//  53      colorWipe(strip.Color(0, 0, 255), 500); // Blue
// 6:theaterChase
//  61      theaterChase(strip.Color(127, 127, 127), 50); // White
//  62      theaterChase(strip.Color(127,   0,   0), 50); // Red
//  63      theaterChase(strip.Color(  0, 127,   0), 50); // Green
//  64      theaterChase(strip.Color(  0,   0, 127), 50); // Blue
//  65      theaterChase(strip.Color(  0,   127, 127), 50);
//  66      theaterChase(strip.Color(  127,   127, 0), 50);
//  67      theaterChase(strip.Color(  127,   0, 127), 50);
// 7:rainbow
// 8:rainbowCycle
// 9:theaterChaseRainbow
typedef const unsigned char prog_uchar;
int actionTable[] = {
  3,30,
  9,30,
  0,30,
  8,30,
  4,30,
  7,3000,
  0,30,
  51,30,
  52,30,
  53,30,
  1,3000,
  0,30,
  52,30,
  2,3000,
  0,30,
  61,30,
  3,30,
  62,30,
  4,30,
  62,30,
  0,30,
  63,30,
  64,30,
  65,30,
  66,30,
  3,30,
  67,30,
  1,3000,
  4,1500,
  1,3000,
  4,1500,
  1,3000,
  4,1500,
  1,3000,
  4,1500,
  0,30,
  7,30,
  8,30,
  9,30,
  2,2000,
  3,1000,
  2,2000,
  3,1000,
  2,2000,
  3,1000,
  2,2000,
  3,1000,
  0,30,
  52,30,
  53,30,
  3,30,
  9,30,
  4,30,
  8,30,
  1,3000,
  2,3000,
  0,30
  };

void setup() {
  Serial.begin (9600);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  
  strip.begin();
  strip.show();

  Serial.println("init over");
}

void loop() {
  
  int dir=0;
  int delayTime=0;
  int len;
  len=sizeof(actionTable)/sizeof(actionTable[0]);

  for(dataIndex=0;dataIndex<len;){
    
    dir=actionTable[dataIndex];
    delayTime=actionTable[dataIndex+1];
    
    Serial.println(dir);
    Serial.println(delayTime);
    Serial.println(i);
    switch(dir){
      case 0:
        stop();
        break;
      case 1:
        forwardWithSpeed();
        break;
      case 2:
        back();
        break;
      case 3:
        left();
        break;
      case 4:
        right();
        break;
      case 51:
        colorWipe(strip.Color(255, 0, 0), 500); // Red
        break;
      case 52:
        colorWipe(strip.Color(0, 255, 0), 500); // Green
        break;  
      case 53:
        colorWipe(strip.Color(0, 0, 255), 500); // Blue
        break;
      case 61:
        theaterChase(strip.Color(127, 127, 127), 50); // White
        break;
      case 62:
        theaterChase(strip.Color(127,   0,   0), 50); // Red
        break;
      case 63:
        theaterChase(strip.Color(  0, 127,   0), 50);// Green
        break;
      case 64:
        theaterChase(strip.Color(  0,   0, 127), 50);// Blue
        break;
      case 65:
        theaterChase(strip.Color(  0,   127, 127), 50);
        break;
      case 66:
        theaterChase(strip.Color(  127,   127, 0), 50);
        break;
      case 67:
        theaterChase(strip.Color(  127,   0, 127), 50);
        break;
      case 7:
        rainbow(20);
        break;
      case 8:
        rainbowCycle(20);
        break;
      case 9:
        theaterChaseRainbow(50);
        break;
    }
    
    delay(delayTime);
    dataIndex+=2; 
    i++;
  }
}
//void doAction(int PatternTable[]){
//  int dir=0;
//  int delayTime=0;
//  int len;
//  len=sizeof(PatternTable)/sizeof(PatternTable[0]);
//
//  for(dataIndex=0;dataIndex<len;){
//    
//    dir=PatternTable[dataIndex];
//    delayTime=PatternTable[dataIndex+1];
//    
//    Serial.println(dir);
//    Serial.println(delayTime);
//    Serial.println(i);
//    switch(dir){
//      case 0:
//        stop();
//        break;
//      case 1:
//        forwardWithSpeed();
//        break;
//      case 2:
//        back();
//        break;
//      case 3:
//        left();
//        break;
//      case 4:
//        right();
//        break;
//    }
//    
//    delay(delayTime);
//    dataIndex+=2; 
//    i++;
//  }
//}

