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
 Serial.println(val);
  if(val <= 500)
   digitalWrite(ledOut, HIGH);
  else
   digitalWrite(ledOut, LOW); 
}
