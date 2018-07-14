#define redPin 11
#define greenPin 6
#define bluePin 9
#define RED_COLOR 1
#define YELLOW_COLOR 2
#define BLUE_COLOR 5

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  flashColor(RED_COLOR);
  delay(500);
  flashColor(YELLOW_COLOR);
  delay(500);
  flashColor(GREEN_COLOR);
  delay(500);
  flashColor(BLUE_COLOR);
  delay(500);
}
void flashColor(int color){
  switch (color){
    case RED_COLOR:
      analogWrite(redPin,200);
      break;
    case YELLOW_COLOR:
      analogWrite(redPin,250);
      analogWrite(greenPin,40);
      break;
    case GREEN_COLOR:
      analogWrite(greenPin,200);
      break;
    case BLUE_COLOR:
      analogWrite(bluePin,200);
      break;
  }
  delay(1000);
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);
}
