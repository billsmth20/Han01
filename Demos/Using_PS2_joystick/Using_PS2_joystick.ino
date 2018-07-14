//x,y,z轴接在模拟输入的A1，A0,A2
#define JoyStick_X 0
#define JoyStick_Y 1
#define JoyStick_Z 2
//SW引脚按下去时输出0，不按时在0-5V间跳动
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x,y,z;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=analogRead(JoyStick_Z);
  Serial.print("X=");
  Serial.print(x); 
  Serial.print("\tY=");   
  Serial.print(y);
  
  if(analogRead(JoyStick_Z)==0){
    Serial.println("\tButton=On");
    
  }else{
    Serial.println("\tButton=Off");
  }

  delay(1000);
}
