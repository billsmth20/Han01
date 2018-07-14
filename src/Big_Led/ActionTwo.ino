typedef const unsigned char prog_char;
const int BREATH_TIME=200;
const int INC_FREQUENCY=2000;
const int PLAY_TIME=4;

int LedTable[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
int ledIndex=0;
boolean overFlg=false;
int colorDes=130;
int colorInc=0;

void actionTwo(){
  unsigned long EndTime;
  EndTime = millis() + ((unsigned long) PLAY_TIME) * 60*1000;
  while ( millis() < EndTime ) {
    int row=random(16);
    int col=random(8);
    int coloRandomr=random(150);
    if(ledIndex>48){
      overFlg=true;
      ledIndex-=48;
    }
    if(overFlg){
      colorDes=LedTable[ledIndex+2];
      do{
        colorDes-=10;
        if(colorDes<15){
          colorDes=0;
        }
        strips[LedTable[ledIndex]].begin();
        strips[LedTable[ledIndex]].setPixelColor(LedTable[ledIndex+1], strips[LedTable[ledIndex]].Color(0, 0, colorDes));
        strips[LedTable[ledIndex]].show();
        delay(BREATH_TIME);
      }while(colorDes>0);
    }else{
      strips[row].begin();
    }
      
    LedTable[ledIndex]=row;
    LedTable[ledIndex+1]=col;
    LedTable[ledIndex+2]=coloRandomr;
    colorInc=0;
    
    do{
      colorInc+=10;
      if(colorInc>coloRandomr){
        colorInc=coloRandomr;
      }
      strips[row].setPixelColor(col, strips[col].Color(0, 0, colorInc));
      strips[row].show();
      delay(BREATH_TIME);
    }while(colorInc<coloRandomr);
    
    ledIndex+=3;
    delay(INC_FREQUENCY);
  }
}
