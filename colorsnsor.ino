const int s0 = 8;
const int s0 = 8;
const int s0 = 8;
const int s0 = 8;
const int out  = 10;
int r = 2;
int g= 3;
int b = 4;
int red = 0;
int green = 0;
int blue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(s0,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  pinMode(b,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(r,OUTPUT);
  digitalWrite(s1,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  color();
  Serial.print("R Intensity: ");
  Serial.print(red,DEC);//to get output in decimal form
  Serial.print("G intensity: ");
  Serial.print(green,DEC);
  Serial.print("B intensity: ");
  Serial.print(blue,DEC);
  if(red<blue && red<green)
  {
    Serial.println("Red COLOR");
    digitalWrite(r,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
  }
  else if(blue<red && blue<green)
  {
    Serial.println("Red COLOR");
    digitalWrite(b,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(r,LOW);
  }
  else if(green<blue && green<red)
  {
    Serial.println("Red COLOR");
    digitalWrite(g,HIGH);
    digitalWrite(r,LOW);
    digitalWrite(b,LOW);
  }
  else
  {
    delay(299);
    digitalWrite(g,LOW);
    digitalWrite(r,LOW);
    digitalWrite(b,LOW);
  }
}

void color()
{
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  r = pulseIn(out,digitalWrite(out) == HIGH?LOW:HIGH);
  digitalWrite(s3,HIGH);
  b = pulseIn(out,digitalWrite(out) == HIGH?LOW:HIGH);
  digitalWrite(s2,HIGH);
  g = pulseIn(out,digitalWrite(out) == HIGH?LOW:HIGH);
  
}
