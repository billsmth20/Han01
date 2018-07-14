void motor(char pin,char pwmpin,char state,int val)
{
    pinMode(pin, OUTPUT);   
  
  if(state==1)
  {  
    analogWrite(pwmpin,val);
    digitalWrite(pin,1);
   }
  else if(state==2)
 {  
   analogWrite(pwmpin,val);
   digitalWrite(pin,0);
 }
 else if(state==0)
 {
    analogWrite(pwmpin,0);
    digitalWrite(pin,0);
 }
}
  
void runfoward(int i)   //前进
{
  motor(4,5,1,i);
  motor(7,6,1,i);
}
void runback(int j)    //后退
{
   motor(4,5,2,j);
   motor(7,6,2,j); 
}
void turnL(int m)     //左转
{
  motor(4,5,1,m);
  motor(7,6,0,m);
}
void turnR(int n)      //右转 
{
  motor(4,5,0,n);
  motor(7,6,1,n);
}
void stop()            //停止
{
  motor(4,5,0,0);
  motor(7,6,1,0); 
}


const int input1=4;
void setup()
{
  Serial.begin(9600);
  pinMode(input1, INPUT);
 }
void loop() 
{ 
  char num1,num2,num3;
 
   num1=digitalRead(input1);
  Serial.println(num1);
   delay(2000);
//  num2=digitalRead(12);
//  num3=digitalRead(2);  
// 
//   if((num1==0)&&num2&&num3) 
//   {
//    turnL(180);          //检测到左边传感器遇到黑线，说明小车右偏了，立即往左转一点
//    delay(2);
//    while(1){
//    num2=digitalRead(12);         //循环判断中间传感器度数，
//    if(num2==1)
//    {  turnL(180);                     //如果num2==1说明还没有转到中间位置，继续左转
//     delay(2);}
//     else
//     break;                      //检测到num2==0说明转过头了，跳出循环，检测三个传感器的状态再做出相应动作
//   }                                       //后面道理相同
//   }    
//    
//  else if(num2&&num1&&(num3==0))
//   {
//    turnR(180);
//    delay(2);
//    while(1)
//    {
//     num2=digitalRead(12);
//    if(num2==1){
//      turnR(180);   
//     delay(2);}
//     else
//      break;
//    }
//   }
//  else
//  {
//    runfoward(250); 
//    delay(2);
//  } 
}
