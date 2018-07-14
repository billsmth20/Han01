#include <Servo.h>




Servo motor;
int y=0;

char val; // Data received from the serial port


int ledPin = 13; // Set the pin to digital I/O 13
boolean ledState = LOW; //to toggle our LED
void setup() 
{
pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
//initialize serial communications at a 9600 baud rate
Serial.begin(9600);
establishContact(); // send a byte to establish contact until receiver responds 
motor.attach(9);


}
void loop()
{
if (Serial.available() > 0) { // If data is available to read,
val = Serial.read(); // read it and store it in val


if(-1 != val) //if we get a 1
{
if('j'==val)
{
y=120;
motor.write(y);
delay(15);
}
if('k'==val)
{
y=y-2;
if(y<=0)
{y=0;}
motor.write(y);
delay(15);
}
if('l'==val)
{
y=-120;
motor.write(y);
delay(15);
}

ledState = !ledState; //flip the ledState
digitalWrite(ledPin, ledState); 
}
delay(100);
} 
else {
Serial.println("Hello, world!"); //send back a hello world
delay(50);
}
}


void establishContact() {
while (Serial.available() <= 0) {
Serial.println("A"); // send a capital A
delay(300);
}
}
