int pirPin = 7;
int ledPin = 4;

int calibTime = 30;
int pirVal = 0;

boolean lockLow = true, takeLowTime;
long unsigned int pause = 5000, lowIn;

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  Serial.print("Calibrating the sensor ");
  for(int i=0; i<calibTime; i++) {
     Serial.print('.');
     delay(1000); 
  }
  Serial.println("Done..  Sensor active");
  delay(500);
}
void loop()
{
  if(digitalRead(pirPin) == HIGH)
  {
     digitalWrite(ledPin, HIGH);
     if(lockLow) {
        lockLow = false;
        Serial.println("---");
        Serial.println("Motion detected at " + (String)(millis()/1000) + "sec");
        delay(50);
     }
     takeLowTime = true;
  }
  if(digitalRead(pirPin) == LOW) {
     digitalWrite(ledPin, HIGH);
     
    if(takeLowTime) {
       lowIn = millis();
       takeLowTime = false;
    }
    
    if(!lockLow && millis() - lowIn > pause) {
        lockLow = true;
        Serial.print("motion ended at ");
        Serial.print((millis() - pause)/1000);
        Serial.println(" sec");
        delay(50);
     }
  }
  
}
