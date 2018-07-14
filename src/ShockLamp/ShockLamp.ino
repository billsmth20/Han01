
int led1 = 9; // Red Pin
int led2 = 10; // Green Pin
int led3 = 11; // Blue pin

int SensorINPUT0 = 2;
int SensorINPUT1 = 3;
int r=0;
int g=0;
int b=0;
int val=0;
int state=0;

void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

  pinMode(SensorINPUT0, INPUT);        //震动开关为输入模式
  pinMode(SensorINPUT1, INPUT);
  Serial.begin(9600);
  attachInterrupt(1, blink,  RISING);  
  attachInterrupt(0, blink, RISING);  
}

void setColor(int red,int green,int blue)
{
  analogWrite(led1,red);
  analogWrite(led2,green);
  analogWrite(led3,blue);
}

void loop()
{
  if(state!=0){              // 如果state不是0时
    state = -1;
    val = analogRead(SensorINPUT1);
    Serial.println(val);
    r=random(256);
    g=random(256);
    b=random(256);
    setColor(r,g,b);
    delay(800);
    state = 0;
    }
}

//中断函数blink()
void blink(){                
  if(state==-1){
    return;
  }
  state++;
}
