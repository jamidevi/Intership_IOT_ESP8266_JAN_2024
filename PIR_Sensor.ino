#define timeSeconds 5

const int led = D6;
const int motionSensor = D5;

unsigned long now = millis();
unsigned long lastTrigger = 0;
boolean startTimer = false;

ICACHE_RAM_ATTR void detectsMovement()
{
  Serial.println("MOTION DETECTED!!!");
  digitalWrite(led, HIGH);
  startTimer = true;
  lastTrigger = millis();
}

void setup() 
{
  Serial.begin(9600);  
  pinMode(motionSensor, INPUT);
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() 
{
  now = millis();
  if(startTimer && (now - lastTrigger > (timeSeconds*1000))) 
  {
    Serial.println("Motion stopped...");
    digitalWrite(led, LOW);
    startTimer = false;
  }
}