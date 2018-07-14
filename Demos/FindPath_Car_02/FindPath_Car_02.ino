//小车循迹程序
//通过3个红外传感器的判断，实现对小车的控制
int IR_right=7;//定义右红外传感器引脚
int IR_middle=4;//定义中间红外传感器引脚
int IR_left=3;//定义左红外传感器引脚


int rightPWM1=5; //连接电机1调速端口到数字接口5
int rightCW1=6;//连接电机1转向端口到数字接口6
int leftPWM2=9;  //连接电机2调速端口到数字接口9
int leftCW2=10;//连接电机2转向端口到数字接口10

void setup()
{
  //设置各个数字端口的输入输出状态
  pinMode(IR_right,INPUT);
  pinMode(IR_left,INPUT);
  pinMode(IR_middle,INPUT);
  pinMode(rightCW1,OUTPUT);
  pinMode(rightPWM1,OUTPUT);
  pinMode(leftCW2,OUTPUT);
  pinMode(leftPWM2,OUTPUT);
   Serial.begin(9600);
}
void advance()//前进程序
{   
  digitalWrite(rightPWM1,LOW);//电机1全速前进
  digitalWrite(leftPWM2,LOW);//电机2全速前进
  digitalWrite(rightCW1,HIGH);//电机1正转
  digitalWrite(leftCW2,HIGH);//电机2正转
}
void right()//右转程序
{
  analogWrite(rightPWM1,100);//电机1全速前进
  analogWrite(leftPWM2,6);//电机2缓慢转动
  digitalWrite(rightCW1,LOW);//电机1正转
  digitalWrite(leftCW2,HIGH);//电机1反转
}
void left()//左转程序
{
  analogWrite(rightPWM1,6); //电机1缓慢转动
  analogWrite(leftPWM2,100);//电机2全速前进
  digitalWrite(rightCW1,HIGH);//电机1反转
  digitalWrite(leftCW2,LOW);//电机1正转
}
  
void loop()
{
  int Right=digitalRead(IR_right);
  int Left=digitalRead(IR_left);
  int Middle=digitalRead(IR_middle); //读3红外传感器信号

  if(Middle==HIGH)
  {
    Serial.println("middle");
  }else if(Right==HIGH){
    Serial.println("right");
  }else if(Left==HIGH){
    Serial.println("left");
  }

  
  //如果中间为高电平，左、右为低电平
  //说明小车没有偏离轨道
  if(Middle==HIGH&&Right==LOW&&Left==LOW)
  {
    advance();//小车前进
  }
  //如果右边为高电平，中间、左为低电平
  //说明小车偏右
  else if(Middle==LOW&&Right==HIGH&&Left==LOW)
  {
    left();//小车左转
  }  
  //如果左边为高电平，中间、右为低电平
  //说明小车偏左
  else if(Middle==LOW&&Right==LOW&&Left==HIGH)
  {
    right();//小车右转
  }
  //小车的3红外传感器距离可能导致3传感器都为低电平或者没检测到黑线3传感器都为高电平
  //小车默认前进
  else
  {
    advance();
  }
}
