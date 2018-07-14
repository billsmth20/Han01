//清屏幕
// 清楚显示的色电
void cleanScreen(){
  for (int k=0; k<ROW_SIZE; k++) {
    strips[k].begin();
    for(int m=0;m<COLUMN_SIZE;m++){
      strips[k].setPixelColor(m, strips[k].Color(0, 0, 0));
    }
    strips[k].show();
  }
}
