 int ldr=D6;
int ldr_led=D3;
int ir=D5;
int ir_led=D2;

void setup() 
{
  Serial.begin(9600);
  //Now I am going to mention pin and its mode
  pinMode(ldr,INPUT);
  pinMode(ldr_led,OUTPUT);
  pinMode(ir,INPUT);
  pinMode(ir_led,OUTPUT);
}

void loop() 
{
  //So here I am going to read datas from sensors and going to store it in a variable
  int ldrvalue=digitalRead(ldr);
  int irvalue=digitalRead(ir);
  
  //Now I am going to make a if condition
  //first condition is for night time
  if(ldrvalue==1) //nyt time
  //if ldr gets high, which means if it is night time
  {
    //LED has to be high
    digitalWrite(ldr_led,HIGH);
    //Now I am going to make another condition for vehicle detection
    if(irvalue==0)
    {
      digitalWrite(ir_led,HIGH);
      Serial.println("Its Night Time and vehicle detected!");
      delay(2000);
      //So if IR value == 0, here which means vehicle is detected...then LED has to be HIGH
      //And then it has to print the message like Its Night Time and vehicle detected...and I am ending with delay
    }    
  }

  //Now this condition is for no vehicle detection during night time
  if(ldrvalue==1) //nyt time
  {
    digitalWrite(ldr_led,HIGH);
    if(irvalue==1)
    {
      digitalWrite(ir_led,LOW);
      Serial.println("Its Night Time and No vehicle detected!");
      delay(2000);
    }    
  }

  //And the next condition is for day time and vehicle detection
 if(ldrvalue==0)  //day time
  {
    digitalWrite(ldr_led,LOW);
    if(irvalue==0)
    {
      digitalWrite(ir_led,HIGH);
      Serial.println("Its Day Time and vehicle detected");
      delay(2000);
    }   
  }

  //Now this condition is for No vehicle detection during day time
  if(ldrvalue==0)  //day time
  {
    digitalWrite(ldr_led,LOW);
    if(irvalue==1)
    {
      digitalWrite(ir_led,LOW);
      Serial.println("Its Day Time and No vehicle detected");
      delay(2000);
    }   
  }
}
