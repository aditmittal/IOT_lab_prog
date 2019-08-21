int ledpin = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =0 ;i<256;i++)
  {
    analogWrite(ledpin,i);
    delay(40);
  }
  for(int j = 255;j>=0;j--)
  {
    analogWrite(ledpin,j);
    delay(49);
  }
}
