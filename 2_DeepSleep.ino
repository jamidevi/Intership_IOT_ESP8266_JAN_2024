void setup() 
{  
  Serial.begin(9600);  
  Serial.setTimeout(2000);  
  while(!Serial) 
  { 

  } 
  Serial.println("I'm awake, but I'm going into deep sleep mode until RESET pin is connected to a LOW signal");
  ESP.deepSleep(0); 

}

void loop() 
{

}