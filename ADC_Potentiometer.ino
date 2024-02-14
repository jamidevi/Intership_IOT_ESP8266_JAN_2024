const int analogInPin = A0; 
int POTValue = 0;  

void setup() 
{  
  Serial.begin(9600);
}

void loop()
{  
  sensorValue = analogRead(analogInPin);   
  Serial.print("sensor: ");
  Serial.println(POTValue);  
  delay(1000);
}