#define COLUMN_SIZE 16
#define ROW_SIZE 8
#define PLANETIME 3333 // time each plane is displayed in us -> 100 Hz refresh
#define TIMECONST 20

void action1(int col_r,int col_g,int col_b){

  for (int ledrow=0; ledrow<ROW_SIZE; ledrow++) {
    strips[ledrow].begin();
    for (int ledcol=0; ledcol<COLUMN_SIZE; ledcol++) {
      if(col_b<flashMinVal){
        strips[ledrow].setPixelColor(ledcol, strips[ledrow].Color(0, 0, 0));
      }else{
        strips[ledrow].setPixelColor(ledcol, strips[ledrow].Color(col_r, col_g, col_b));
      }
    }
  }
  for(int ledrow=0; ledrow<ROW_SIZE; ledrow++) {
    strips[ledrow].show();
  }
  delayMicroseconds( PLANETIME );
}
