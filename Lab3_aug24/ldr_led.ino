int ledOut = 9;
int val;
int ldrIn = 0;

void setup()
{
 pinMode(ledOut, OUTPUT); 
 Serial.begin(9600);
}

void loop()
{
 val = analogRead(ldrIn);
  if(val <= 500) {
    Serial.println((String)val + " Value below Threshold ");
   digitalWrite(ledOut, HIGH);
  }
  else {
    Serial.println( (String)val +" Value above Threshold");
   digitalWrite(ledOut, LOW);
  }
 delay(500); 
}
