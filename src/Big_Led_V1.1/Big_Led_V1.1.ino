#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>
#include <SPI.h>
#include <SD.h>

#define SD_Pin 14
#define COLUMN_SIZE 16
#define ROW_SIZE 8
#define PLANETIME 3333 

Adafruit_NeoPixel strips[8]={ Adafruit_NeoPixel(16, 3, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 4, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 5, NEO_GRB + NEO_KHZ800), 
                              Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 7, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 8, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16, 9, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(16,10, NEO_GRB + NEO_KHZ800)
                              };
Adafruit_NeoPixel strip=Adafruit_NeoPixel(16, 5, NEO_GRB + NEO_KHZ800);

unsigned char color_red=0;
unsigned char color_green=0;
unsigned char color_blue=0;

void setup() { 
  Serial.begin(9600);
//  strips[1].begin();
//  strips[1].setPixelColor(1, strips[1].Color(255, 0, 0));
//  strips[1].show();
  delay(1000);
  Serial.println("Big led started!");
  action1_Init();
}
void loop() {
  
  //数组图案（Array Picture）
  action1(2);
  // 琉璃世界（Glass world）
  action2(15,5,3);
  // 彩虹瀑布（rainbow waterfall）
  action3(10);
  // 繁星（Clusters of stars）
  action4();
}
