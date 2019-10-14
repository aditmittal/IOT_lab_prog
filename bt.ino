#include <SoftwareSerial.h>
SoftwareSerial BT(2,3);
#define button 8
//int state = 20;
//int buttonState = 0;
int data;
int led1=11;
int led2=12;
int led3=13;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  //pinMode(button, INPUT);
   BT.begin(38400);
   Serial.begin(9600);
   Serial.println("Slave Bluetooth");
}

void loop() {
 if(Serial.available())
 {
  int data  = Serial.read();
  delay(100);
  if(data=="1")
  {
    digitalWrite(led3,HIGH);
  }
 }
   
}
