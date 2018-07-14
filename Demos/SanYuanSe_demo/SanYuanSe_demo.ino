
#define LED_R_PIN A0
#define LED_G_PIN A1
#define LED_B_PIN A2
#define LED_R 3
#define LED_G 5
#define LED_B 6

int val_R=0;
int val_G=0;
int val_B=0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R_PIN,INPUT);
  pinMode(LED_R_PIN,INPUT);
  pinMode(LED_R_PIN,INPUT);

  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);
}

void loop() {
  
  val_R = analogRead(LED_R_PIN);    //读取AD值
  val_G = analogRead(LED_G_PIN);
  val_B = analogRead(LED_B_PIN);
  Serial.println("-----------------------");
  Serial.println(val_R);
  Serial.println(val_G);
  Serial.println(val_B);
  val_R = map(val_R, 0, 1023, 0, 255);
  val_G = map(val_G, 0, 1023, 0, 255);
  val_B = map(val_B, 0, 1023, 0, 255);
  if(val_R<20){
    val_R=0;
  }else if(val_R>235){
    val_R=255;
  }
  if(val_G<20){
    val_G=0;
  }else if(val_G>235){
    val_G=255;
  }
  if(val_B<20){
    val_B=0;
  }else if(val_B>235){
    val_B=255;
  }
  Serial.println(val_R);
  Serial.println(val_G);
  Serial.println(val_B);
  analogWrite(LED_R,255-val_R);
  analogWrite(LED_G,255-val_G);
  analogWrite(LED_B,255-val_B);
//  delay(1000);
}
