#define TIMECONST 20
struct ColorSpot{
    unsigned char spotType;
    int posIndex;
    unsigned char cl_r;
    unsigned char cl_g;
    unsigned char cl_b;
    int delayTime;
};
//当前图形显示的终了时间
unsigned long EndTime;
//LEDDATA.le
File myFile;

//数组图案（Array Picture）
// cnt:循环次数
void action1(int cnt){
  if (!myFile) {
    Serial.println("error opening LEDDATA.le");
    return;
  }
  
  int times=0;
  String dataStr="";
  unsigned char rawByte;
  for (int j=0; j<ROW_SIZE; j++) {
    strips[j].begin();
  }
  while (true) {
    DataLine:
    if(myFile.available()){
      rawByte=myFile.read();
      if(rawByte==';'){
        //C,0,247,150,70,0;C,1,255,255,0,0;
        struct ColorSpot cs;
        int index = 0;
        String temp[6];
        for(int struIndex=0;struIndex<6; struIndex++){
          int index2 = dataStr.indexOf(',',index);
          temp[struIndex]=dataStr.substring(index,index2);
          index = index2+1;
        }
        cs.spotType=char(temp[0].charAt(0));
        cs.posIndex=temp[1].toInt();
        cs.cl_r=temp[2].toInt();
        cs.cl_g=temp[3].toInt();
        cs.cl_b=temp[4].toInt();
        cs.delayTime=temp[5].toInt();
        doDisplay(cs);
        dataStr="";
        //读取了一个像素点的显示数据，去读取下一个
        goto DataLine;
      }else{
        dataStr+=char(rawByte);
      }
    }else{
      myFile.seek(0);
      if(++times>cnt)break;
    }
  }
}
//初始化 Action1
void action1_Init(){
  EndTime=millis();
  while (!Serial) {
    ;
  }
  if (!SD.begin(SD_Pin)) {
    Serial.println("init failed!");
    return;
  }
  Serial.println("init done.");
  myFile = SD.open("LEDDATA.le");
  if (!myFile) {
    Serial.println("error opening LEDDATA.le");
    return;
  }
}
void doDisplay(struct ColorSpot csIn){
  int pIndex, rIndex, cIndex;
  if(csIn.spotType=='T'){
    while ( millis() < EndTime ) {
      delayMicroseconds( PLANETIME );
    }
    for (int j=0; j<ROW_SIZE; j++) {
      strips[j].show();
    }
    EndTime = millis() + ((unsigned long) csIn.delayTime) * TIMECONST;
    for (int k=0; k<ROW_SIZE; k++) {
      for(int m=0;m<COLUMN_SIZE;m++){
        strips[k].setPixelColor(m, strips[k].Color(0, 0, 0));
      }
    }
  }else if(csIn.spotType=='C'){
    pIndex=csIn.posIndex;
    rIndex=pIndex/COLUMN_SIZE;
    cIndex=pIndex%COLUMN_SIZE;
    strips[rIndex].setPixelColor(cIndex, strips[rIndex].Color(csIn.cl_r, csIn.cl_g, csIn.cl_b));
  }
}
