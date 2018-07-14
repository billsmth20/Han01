// 琉璃世界（Glass world）

unsigned long nowtime=millis();
// durationTime 每次时长（单位秒）
// interval间隔时间
// loopTime 重复次数
void action2(int durationTime, int interval, int loopTime){
  int row=0;
  int col=0;
  for (int j=0; j<ROW_SIZE; j++) {
    strips[j].begin();
  }
  for(int j=0;j<loopTime;j++){
    nowtime=millis()+durationTime*1000;
    while(true){
      row=random(ROW_SIZE);
      col=random(COLUMN_SIZE);
      strips[row].setPixelColor(col, strip.Color(random(200), random(200), random(200)));
  
      row=random(ROW_SIZE);
      col=random(COLUMN_SIZE);
      strips[row].setPixelColor(col, strip.Color(0, 0, 0));
      
      strips[row].show();
      delay(30);
      if(nowtime<millis()){
        break;
      }
    }
    delay(interval*1000);
  }
}
