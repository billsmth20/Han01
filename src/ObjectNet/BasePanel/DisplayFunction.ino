void doDisplay(char *buffer){
  
    lcd_clear(); 
    lcd_write_english_string(0,0,">> Message << ");
//    lcd_write_english_string(0,4,"Height: ");  
//    lcd_write_english_string(66,4,"m.");
    lcd_write_english_string(0,1,buffer);
}
void flashColor(int color){
  flashColor(color,1);
}
void flashColor(int color,unsigned long delayTime){
  switch (color){
    case RED_COLOR:
      analogWrite(redPin,200);
      break;
    case YELLOW_COLOR:
      analogWrite(redPin,250);
      analogWrite(greenPin,40);
      break;
    case GREEN_COLOR:
      analogWrite(greenPin,200);
      break;
    case BLUE_COLOR:
      digitalWrite(bluePin,HIGH);
      break;
  }
  delay(delayTime*1000);
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  digitalWrite(bluePin,LOW);
}

