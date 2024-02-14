const int ledPin = D1; 

void setup() 
{
  
}

void loop() 
{  
  for(int dutyCycle = 0; dutyCycle < 255; dutyCycle++)
  {     
    analogWrite(ledPin, dutyCycle);   
    delay(10);
  }  
  for(int dutyCycle = 255; dutyCycle > 0; dutyCycle--)
  {
    analogWrite(ledPin, dutyCycle);
    delay(10);
  }
}
