#include "pitches.h"

const int firePin=3;

void setup() {
  pinMode(firePin,INPUT);
}
int val=0;
void loop() {
  val=digitalRead(firePin);
  if(val==0){
    tone(8, NOTE_G7);
    delay(5000);
    noTone(8);
  }
  delay(50);
}
