#include<SoftwareSerial.h>

SoftwareSerial mySerial(9,10);

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    switch(Serial.read())
    {
      case 's';
        sendmsg();
        break;
       case 'r':
        recievemsg();
        break;
    }
    if mySerial.available()>0)
    {
      Serial.write(mySerial.read());
    }
  }
}
void sendmsg()
{
  mySerial.println("AT+CMGF = 1");
  delay(1000);
  mySerial.println("AT+CMGS =\"+91 xxxxxxxxxx\"\r");
  delay(1000);
  mySerial.println("I am sms from gsm module");
  delay(1000);
  mySerial.println((char)26);
  delay(1000);
}

void recievemsg()
{
  mySerial.println("AT+CNMI = 2,2,0,0,0");
  delay(1000);
}

