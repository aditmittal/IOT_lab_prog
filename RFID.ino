#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int count=0;
char input[12];
char check[12] = "0900970C8517";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if(mySerial.available()){
    count=0;
    while(mySerial.available() && count<12)
    {
      input[count]=mySerial.read();
      count++;
      delay(5);
    }
    boolean flag = 0;
    Serial.print(input);
    count=0;
    for(int i=0;i<12;i++){
      if(check[i]!=input[i]){
        Serial.print("Access denied");
        flag=1;
        break;
        i++;
      }
    }
    if(flag==0){
    Serial.print("Accepted");
    }
  }
  // put your main code here, to run repeatedly:

}
