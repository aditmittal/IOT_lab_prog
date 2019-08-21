int input = 0;
int ledpin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  pinMode(input,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensedValue = analogRead(input);
  int convertedValue = map(sensedValue,0,1023,0,255);
  analogWrite(ledpin,convertedValue);
  delay(1000);
  Serial.println(sensedValue);
  Serial.println(convertedValue);
}
