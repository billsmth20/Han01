#include <NOKIA5110LIB.h>

float distance;
int cnt=0; 
String length;
char buffer[32];
 
// 执行以下语句,buffer里面就保存了f转换的结果

void setup() 
{   
  initUltrasonic();
  lcd_init();//初始化液晶 
} 
void loop() 
{ 
  checkDistance(500);
  dtostrf(distance,1,0,buffer); 
  strcat(buffer," cm");
  doDisplay(buffer);
}
void doDisplay(char *buffer){
  
  
  lcd_clear(); 
  lcd_write_english_string(0,0," -Ultrasonic- ");
  lcd_write_english_string(0,2,"Distance:"); 
  lcd_write_english_string(25,4,buffer); 
}
