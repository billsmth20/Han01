#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>

#define PIN6 6
#define PIN7 7

Adafruit_NeoPixel strips[16]={Adafruit_NeoPixel(8, 2, NEO_GRB + NEO_KHZ800), 
                              Adafruit_NeoPixel(8, 3, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 4, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 5, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 7, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 8, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 9, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 10, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 11, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 12, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 13, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 14, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 15, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 16, NEO_GRB + NEO_KHZ800),
                              Adafruit_NeoPixel(8, 17, NEO_GRB + NEO_KHZ800)};
Adafruit_NeoPixel stripT[3]={strips[0],strips[5],strips[9]};
Adafruit_NeoPixel strip=Adafruit_NeoPixel(8, 2, NEO_GRB + NEO_KHZ800);
void setup() {
  Serial.begin(9600);
//  action4_setUp();
}


void loop() {
  // 数组图案（Array Picture）
  actionOne();
  // 繁星（Clusters of stars）
//  actionTwo();
  // 彩虹瀑布（rainbow waterfall）
  actionThree(20);
//  action4();
  // 琉璃世界（Glass world）
  action5(10,20,10);
}


