int input = A0;
int ledpin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(0,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr_V = analogRead(input);
  Serial.println(ldr_V);
  int threshhold = 550;
  if(ldr_V<threshhold)
    {
      digitalWrite(ledpin,HIGH);
    }
    else
    {
      digitalWrite(ledpin,LOW);
    }
    delay(100);
}
