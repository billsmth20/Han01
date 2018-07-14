char ss;
int i=10;
int led1Pin=8;
int led2Pin=9;

void setup(){
  
  Serial.begin(9600); //设置串口速度
  pinMode(led1Pin,OUTPUT);//一般13口上都有一个已经接好的LED，所以用这个口子，少接些元件
   pinMode(led2Pin,OUTPUT);
}

void loop(){
  
  //启动时的开关信号，这样可以避免主程序陷入死循环
  if(i>0){
    
    Serial.print('a');//先向从机发一个‘a’，
    i=0;
  }
  
  ss=Serial.read();//再读串口，接受从机的字符‘b’
  if(ss=='b'){
    
    digitalWrite(led2Pin, LOW);
    digitalWrite(led1Pin, HIGH);
  }else if(ss=='c'){
    
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    i=10;
  }
}
