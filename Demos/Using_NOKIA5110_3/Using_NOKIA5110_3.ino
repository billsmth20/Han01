#include <NOKIA5110LIB.h>

void setup(){
  lcd_init();//初始化液晶 
}

void loop(){
       
   lcd_clear();                                  //清屏 

   lcd_write_english_string(0,0," --arduino-- ");
   lcd_write_english_string(0,2,"renge:");
   
   lcd_write_english_string(0,4,"design by Bill"); 
   lcd_write_english_string(0,5,"    2010.6    "); 

  //以下进入超声波测距

   while(1){
//      digitalWrite(outputpin, LOW); // 使发出发出超声波信号接口低电平2μs
//      delayMicroseconds(2);
//      digitalWrite(outputpin, HIGH); // 使发出发出超声波信号接口高电平10μs，这里是至少10μs
//      delayMicroseconds(10);
//      digitalWrite(outputpin, LOW);    // 保持发出超声波信号接口低电平
      int distance = 2400;//pulsein(inputpin, HIGH);  // 读出脉冲时间
      distance= distance/58;           // 将脉冲时间转化为距离（单位：厘米）
      if(distance>120){              //如果距离大于120cm
        
      
        lcd_write_english_string(35,2,"???"); //在(35, 2)坐标上显示“???”
      }else{
          lcd_write_english_string(60,2,"cm");     //如果小于120cm
          lcd_set_xy(35, 2);                       //在(35, 2)坐标上显示测出数值
          lcd_write_char( 0x30+distance/100); //显示百位数
          lcd_write_char( 0x30+distance/10);   //显示十位数
          lcd_write_char( 0x30+distance);       //显示个位数
      }
  }
}
