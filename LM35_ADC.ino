float vref = 3.3;
float resolution = vref/1023;

void setup() 
{  
 Serial.begin(9600);  
}

void loop() 
{  
 float temperature = analogRead(A0); 
 temperature = (temperature*resolution); 
 temperature = temperature*100; 
 Serial.print(temperature); 
 Serial.println(" Degree celcius");
 delay(1000);
}
