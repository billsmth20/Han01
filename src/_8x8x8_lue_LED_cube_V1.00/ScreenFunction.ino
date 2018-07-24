volatile int8_t screen[28][3]={
  {0,7},{0,6},{0,5},{0,4},{0,3},{0,2},{0,1},
  {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},
  {7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6},
  {7,7},{6,7},{5,7},{4,7},{3,7},{2,7},{1,7},
  };
volatile int8_t content[]={

  B11111111,
  B10111110,
  B00000000,
  B11111110,
  B11111111
};

void Screen01(){
int yy,zz,suby,subz;
int m,o,p=0,q;
  for(int n=0;n<28;n++){
    o=n;
    for(int i=0;i<28;i++){
      yy=screen[i][0];
      zz=screen[i][1];
      cube[yy][zz]=0xFF;
    }
      
    if(o<=5){
      p=0;
      for(;o>0;o--){
        yy=screen[o][0];
        zz=screen[o][1];
        cube[yy][zz]=content[p];
        p++;
      }
    }else{
      q=o-5;
      p=0;
      for(;o>q;o--){
        yy=screen[o][0];
        zz=screen[o][1];
        cube[yy][zz]=content[p];
        p++;
      }
    }
    delay(100);
  }
}
