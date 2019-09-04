int calltime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takelowtime;
int pirPIN = 3;
int ledPIN = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirPIN,INPUT);
  pinMode(ledPIN,OUTPUT);
  digitalWrite(pirPIN,LOW);
  Serial.print("calliberating sensor");
  for(int i=0;i<calltime;i++)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("done");
  Serial.println("sensor active");
  delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pirPIN) == HIGH)
  {
    digitalWrite(ledPIN,HIGH);
    if(lockLow)
    {
      lockLow = false;
      Serial.println("----");
      Serial.print("motion DETECTED at");
      Serial.print(millis()/1000);
      Serial.println("sec");
      delay(50);
    }
    takelowtime = true;
  }
  if(digitalRead(pirPIN) == LOW)
  {
    digitalWrite(ledPIN,LOW);
    if(takelowtime){
      lowIn = millis();
      takelowtime = false;
    }
    if(!lockLow && millis() - lowIn > pause)
    {
      lockLow = true;
      Serial.print("motion ended at:");
      Serial.print((millis()-pause)/1000);
      Serial.println("sec");
      delay(50);
    }
  }
}
