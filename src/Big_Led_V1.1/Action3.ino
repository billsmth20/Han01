// 彩虹瀑布（rainbow waterfall）

void action3(uint8_t wait){
  rainbowCycle4Array(wait);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void rainbowCycle4Array(uint8_t wait){
  uint16_t i, j, q;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strips[0].numPixels(); i++) {
      for(q=0; q<ROW_SIZE; q++) {
        strips[q].setPixelColor(i, Wheel(((i * 256 / strips[q].numPixels()) + j) & 255));
      }
    }
    for(q=0; q<ROW_SIZE; q++) {
      strips[q].show();
    }
    delay(wait);
  }
}
