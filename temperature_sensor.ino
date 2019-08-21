int outputpin = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rawVoltage = analogRead(outputpin);
  float millivolts = (rawVoltage/1024.0)*5000;
  float celcius = millivolts/10;
  Serial.print(celcius);
  Serial.println("degree celcius");
  Serial.print((celcius*9)/5+32);
  Serial.println("degree Farenhiet");
  delay(1000);
}
