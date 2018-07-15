//下雨
//rainCnt：雨滴数量
void Rainning(int rainCnt)
{
  int xArray[rainCnt][3];
  for(int i=0;i<rainCnt;i++){
    xArray[i][0]=random(0,8);
    xArray[i][1]=random(0,8);
    xArray[i][2]=random(0,8);
  }
  for(int n=0;n<200;n++){
    for(int i=0;i<rainCnt;i++){
      SetDot(xArray[i][0],xArray[i][1],xArray[i][2]);
    }
    delay(64);
    for(int i=0;i<rainCnt;i++){
      ClearDot(xArray[i][0],xArray[i][1],xArray[i][2]);
    }
    
    for(int m=0;m<rainCnt;m++){
      xArray[m][0]=xArray[m][0]-1;
      if(xArray[m][0]<0){
        xArray[m][0]=7;
        xArray[m][1]=random(0,8);
        xArray[m][2]=random(0,8);
      }
    }
  }
}

