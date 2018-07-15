void LayerRotate(int time){
  CubeAllOff();
  DrawXYZLayer(0,-1,-1);
  
  for(int i=time;i>0;){
    delay(i);
    CubeAllOff();
    DrawXYZLayer(0,7,-1);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(7,7,-1);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(7,0,-1);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(0,0,-1);
    i=i-20;
  }
  CubeAllOff();
  DrawXYZLayer(-1,-1,0);
  
  for(int i=0;i<time;){
    delay(i);
    CubeAllOff();
    DrawXYZLayer(-1,7,0);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(-1,7,7);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(-1,0,7);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(-1,0,0);
    i=i+20;
  }
  CubeAllOff();
  DrawXYZLayer(0,-1,-1);
  
  for(int i=time;i>0;){
    delay(i);
    CubeAllOff();
    DrawXYZLayer(0,-1,0);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(7,-1,0);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(7,-1,7);
    delay(i);
    CubeAllOff();
    DrawXYZLayer(0,-1,7);
    i=i-20;
  }
  CubeAllOff();
}

