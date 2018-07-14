void sound(){
  tone(8, NOTE_G7);
  delay(50);
  noTone(8);
}
void endSound(){
  sound();
  delay(50);
  sound();
  delay(50);
  sound();
}
