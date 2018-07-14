#include <Adafruit_NeoPixel.h>

#define PIN6 6
#define PIN7 7

Adafruit_NeoPixel  strips[2]={Adafruit_NeoPixel(11, PIN6, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(11, PIN7, NEO_GRB + NEO_KHZ800)};
//Adafruit_NeoPixel strip=strips[0];

void setup() {
  Serial.begin(9600);
  strips[0].begin();
  strips[0].show();
}


void loop() {
  int r=random(255);
  int g=random(255);
  int b=random(255);
  colorWipe(strips[0], strips[0].Color(r, g, b), 500);
}
void colorWipe(Adafruit_NeoPixel strip, uint32_t c, uint8_t wait) {
  uint16_t i=0;
  strip.begin();
  for(; i<strip.numPixels(); i++) {
    Serial.print("i:");
    Serial.print(i);
    Serial.print("  c:");
    Serial.println(c);
      strip.setPixelColor(i, c);
      if(i-5>=0){
        strip.setPixelColor(i-5, strip.Color(0, 0, 0));
      }
      strip.show();
      delay(wait);
  }
  for(; i<strip.numPixels()+5; i++) {
    Serial.print("i:");
    Serial.println(i);
      strip.setPixelColor(i-5, strip.Color(0, 0, 0));
      strip.show();
      delay(wait);
  }
  Serial.print("end i:");
    Serial.println(i);
  
//  for(uint16_t i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, strip.Color(0, 0, 0));
//      strip.show();
//      delay(wait);
//  }
}
