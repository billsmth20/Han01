int pbIn = 0;                  // 定义中断引脚为0，也就是D2引脚
int ledOut = A0;                // 定义输出指示灯引脚
volatile int state = LOW;      // 定义默认输入状态

void setup()
{               
  // 置ledOut引脚为输出状态
  pinMode(ledOut, OUTPUT);

  // 监视中断输入引脚的变化
  attachInterrupt(pbIn, stateChange, LOW );
   Serial.begin(9600);
}

void loop()                     
{
  // 模拟长时间运行的进程或复杂的任务。
  for (int i = 0; i < 100; i++)
  {
    // 什么都不做，等待10毫秒
    delay(100);
    Serial.print("i:");
    Serial.println(i,DEC);
  }
}

void stateChange()
{
  if(state==HIGH){
    state=LOW;
  }else{
    state=HIGH;
  }
  digitalWrite(ledOut, state);  
  Serial.println("----stateChange----");
}
