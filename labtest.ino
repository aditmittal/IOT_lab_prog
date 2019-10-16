#include<Servo.h>
Servo s;
int out = 9;
//int in = 8;

void setup()
{
   Serial.begin(9600);
   pinMode(out,OUTPUT);
  // pinMode(in,INPUT);
   s.attach(out);
   delay(1000);
}

void loop()
{
   int i,j,state;
  if(Serial.available()>0)
 {
    state = Serial.read();
    if(state=='1')
    {
       for(j=0;j<180;j++)
    {
      s.write(j);
      delay(30);    
    }
    for(i=180;i>0;i--)
    {
      s.write(i);
      delay(30);
    }
    }
    else if(state == '0')
    {
      while(state!='1')
      {
        s.write(0);
      }
    }
 } 
}
