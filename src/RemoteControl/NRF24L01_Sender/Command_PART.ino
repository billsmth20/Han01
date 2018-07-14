void createCommand(){
  
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=analogRead(JoyStick_Z);
  
  if(analogRead(Btn_A)==0){
    if(btn!=53){
      btn=53;
    }else if(btn==53){
      delay(Btn_Delay);
      btn=0;
    }
  }else if(analogRead(Btn_B)==0){
    if(btn!=54){
      btn=54;
    }else if(btn==54){
      delay(Btn_Delay);
//      btn=0;
    }
  }else if(analogRead(Btn_C)==0){
    if(btn!=55){
      btn=55;
    }else if(btn==55){
      delay(Btn_Delay);
      btn=0;
    }
  }else if(analogRead(Btn_D)==0){
    if(btn!=56){
      btn=56;
    }else if(btn==56){
      delay(Btn_Delay);
      btn=0;
    }
  }else{
    btn=0;
  }
  data[0] = 15;
  
  // A  
  if(btn==53){
    data[1] =53 ;
  // B  
  }else if(btn==54){
    data[1] =54 ;
  // c
  }else if(btn==55){
    data[1] =55 ;
  // d
  }else if(btn==56){
    data[1] =56 ;
  // 停
  }else if(x>450 && x<550 && y>450 && y<550){
    data[1] =48;
  // 向前
  }else if(x>550 && y<550 && y>450){
    data[1] =25 ;
  // 向后
  }else if(x<450 && y<550&&y>450){
    data[1] =24 ;
  // 向左
  }else if(x>450 && x<550 && y<450){
    data[1] =27 ;
  // 向右
  }else if(x>450 && x<550 && y>550){
    data[1] =26 ;  
  // 向左前
  }else if(x>550 && y<450){
    data[1] =52 ;  
  // 向右前
  }else if(x>550 && y>550){
    data[1] =51 ;    
  // 向左后
  }else if(x<450 && y<450){
    data[1] =50 ;    
  // 向右后
  }else if(x<450 && y>550){
    data[1] =49 ;    
  }else{
    data[1] =48;
    sendFlg=true;
  }
}
