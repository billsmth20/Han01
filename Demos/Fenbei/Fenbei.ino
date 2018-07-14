#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7
#define pin8 8
#define pin9 9
#define pin10 10
#define pin11 11

int val;
int potentialVal=0;
int oldVal=0;
const int interval=5000;
const int subStepVal=2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  pinMode(pin9,OUTPUT);
  pinMode(pin10,OUTPUT);
  pinMode(pin11,OUTPUT);
  pinMode(13,OUTPUT);
  potentialVal=analogRead(A1);
  Serial.println(potentialVal);
  delay(1000);
  oldVal=200;
}

void loop() {
  // put your main code here, to run repeatedly:
  val =analogRead(A0);
  potentialVal=analogRead(A1);
  Serial.println(val);
  val=map(val-potentialVal,0,1023-potentialVal,0,100);
  if(oldVal<val){
    oldVal=val;
  }
  Serial.print("val:");
  Serial.print(val);
  Serial.print("  oldVal:");
  Serial.println(oldVal);
  if(oldVal>=5){
    digitalWrite(pin1,HIGH);
  } else if(oldVal<5){
    digitalWrite(pin1,LOW);
  }
  if(oldVal>=10){
    digitalWrite(pin2,HIGH);
  } else if(oldVal<10){
    digitalWrite(pin2,LOW);
  }
  if(oldVal>=20){
    digitalWrite(pin3,HIGH);
  } else if(oldVal<20){
    digitalWrite(pin3,LOW);
  }
  
  if(oldVal>=30){
    digitalWrite(pin4,HIGH);
  } else if(oldVal<30){
    digitalWrite(pin4,LOW);
  }
  if(val>=40){
    digitalWrite(pin5,HIGH);
  } else if(val<40){
    digitalWrite(pin5,LOW);
  }
  if(oldVal>=50){
    digitalWrite(pin6,HIGH);
  } else if(oldVal<50){
    digitalWrite(pin6,LOW);
  }
  if(oldVal>=60){
    digitalWrite(pin7,HIGH);
  } else if(oldVal<60){
    digitalWrite(pin7,LOW);
  }
  if(oldVal>=70){
    digitalWrite(pin8,HIGH);
  } else if(oldVal<70){
    digitalWrite(pin8,LOW);
  }
  if(oldVal>=80){
    digitalWrite(pin9,HIGH);
  } else if(oldVal<80){
    digitalWrite(pin9,LOW);
    }
  oldVal-=subStepVal;
}
