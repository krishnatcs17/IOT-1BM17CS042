#include<Servo.h>
Servo myservo;
int sensorPin = A0, sensorVal;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(7);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);
  if(sensorVal >= 800) {
    digitalWrite(13, HIGH);
    for(pos=0; pos< 180; pos +=2) {
      myservo.write(pos);
      delay(50);
    }
    for(pos=180; pos >=0; pos -=2) {
      myservo.write(pos);
      delay(50);
    }
  }
  else
  {
    digitalWrite(13, LOW);
  }
  delay(1000);
}
