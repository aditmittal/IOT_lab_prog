#include <LiquidCrystal.h>

const int trigPin = 3;
const int echoPin = 2;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, inches, cm;
  lcd.setCursor(0, 1);

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  
  //Serial.print(inches);
  //Serial.println("Inches");
  
  //Serial.print(cm);
  //Serial.println("Cm");

  lcd.print(inches);
  lcd.println("in");

  lcd.print(cm);
  lcd.println("cm");

  delay(1000);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
   return microseconds / 29 / 2;
}
