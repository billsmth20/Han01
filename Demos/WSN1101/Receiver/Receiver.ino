#include <NOKIA5110LIB.h>
char buffer1[10]="skdfd";
char buffer2[10];
String gg="";
String gg2="";
int i=0;
void setup() 
{   
  Serial.begin(9600);
  lcd_init();//初始化液晶 
} 
void loop() 
{ 
  while (Serial.available()>0)  {
//    gg += char(Serial.read());
    buffer1[i]=char(Serial.read());
    i++;
    delay(2);
  }
  buffer1[i]=0;
  i=0;
//  if (gg.length() > 0){
//    gg.toCharArray(buffer1,10);
//    if(gg=="abcd"){
//      buffer1[0]='a';
//      buffer1[1]='b';
//      buffer1[2]='c';
//      buffer1[3]='d';
//      buffer1[4]=0;
//      doDisplay(buffer1);
//      }
//    
//    gg = "";
//  }
//  if(gg!=""){
//    //gg.toCharArray(buffer,gg.length()+1);
//    buffer1[0]='a';
//    buffer1[1]='b';
//    buffer1[2]='c';
//    buffer1[3]='d';
////    buffer1[4]=0;
////    strcat(buffer2,buffer1);
//    gg=String(buffer1);
//  }
//  gg2=gg;
//  gg2.toCharArray(buffer1,10);
//  delay(500);
//  if(gg2=="abcd"){
//    doDisplay("equal");
//  }else{
    doDisplay(buffer1);
    delay(1000);
//  }
  gg="";
//for(int i = 0; i < gg.length() ; i++)
//{
//  buffer1[i]=gg[i];
//  }
//doDisplay(buffer1);
//  gg="";
}

void doDisplay(char *bufStr){
  
  lcd_clear(); 
  lcd_write_english_string(0,0," -Ultrasonic- ");
  lcd_write_english_string(0,2,bufStr);
  delay(20);
}


