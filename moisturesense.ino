#include<Servo.h>
Servo s;
int input = A0;
int output = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(output, OUTPUT);
  s.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(input);
  Serial.println(value);
  delay(500);
  int threshhold =800;
  if(value<threshhold)
  {
    for(int j=0;j<180;j++)
    {
      s.write(j);
      delay(30);    
    }
    for(int i=180;i>0;i--)
    {
      s.write(i);
      delay(30);
    }
  }
  Serial.println(value);
}
