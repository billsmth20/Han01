
unsigned long nowtime=millis();

void action5(int durationTime, int interval, int loopTime){
  int row=0;
  int col=0;
  int r=0;
  int g=0;
  int b=0;

  for(int j=0;j<loopTime;j++){
    nowtime=millis()+durationTime*1000;
    while(true){
      row=random(8);
      col=random(16);
      r=random(150);
      g=random(150);
      b=random(150);
      strips[col].begin();
      strips[col].setPixelColor(row, strip.Color(r, g, b));
  
      row=random(8);
      strips[col].setPixelColor(row, strip.Color(0, 0, 0));
      col=random(16);
      
      strips[col].show();
      delay(20);
      if(nowtime<millis()){
        break;
      }
    }
    delay(interval*1000);
  }
  
}
