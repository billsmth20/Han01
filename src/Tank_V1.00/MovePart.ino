int input1 = 3; // 定义uno的pin 3 向 input1 输出
int input2 = 5; // 定义uno的pin 5 向 input2 输出
int input3 = 6; // 定义uno的pin 6 向 input3 输出
int input4 = 9; // 定义uno的pin 9 向 input4 输出


void movePart_init(){
  
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
}

void stop() {
  //stop 停止
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
  delay(1);
}
void back() {
  //back 向后转
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);
  delay(50);
  Serial.println("back");
  stop();
}
//void forwardWithSpeed(int speed) {
//  //forward 向前转
//  analogWrite(input1, speed); //给高电平
//  digitalWrite(input2, LOW); //给低电平
//  analogWrite(input3, speed); //给高电平
//  digitalWrite(input4, LOW); //给低电平
//  delay(50);
//  Serial.println("forwardWithSpeed");
//  stop();
//}
void forward() {
  //forward 向前转
  digitalWrite(input1, HIGH); //给高电平
  digitalWrite(input2, LOW); //给低电平
  digitalWrite(input3, HIGH); //给高电平
  digitalWrite(input4, LOW); //给低电平
  delay(50);
  Serial.println("forward");
  stop();
}

void turnLeft() {
  digitalWrite(input1, HIGH);
//  analogWrite(input1, CNT_SPEED); //给高电平
  digitalWrite(input2, LOW); //给低电平
  digitalWrite(input3, LOW);
//  analogWrite(input4, CNT_SPEED);
  digitalWrite(input4, HIGH);
  delay(50);
  Serial.println("turnLeft");
  stop();
}
void turnRight() {
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input3, HIGH);
//  analogWrite(input2, CNT_SPEED);
//  analogWrite(input3, CNT_SPEED); //给高电平
  digitalWrite(input4, LOW); //给低电平
  delay(50);
  Serial.println("turnRight");
  stop();
}

