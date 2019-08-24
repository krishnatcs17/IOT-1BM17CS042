int ledOut = 9;
int val, newval;
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
 newval = map(val, 0, 1024, 255, 0);
 analogWrite(ledOut, newval);
}
