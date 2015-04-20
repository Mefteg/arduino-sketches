
#define LED 13
#define TRANSMITTER 2

#define RECEIVER A0

unsigned int value;
unsigned int data;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(TRANSMITTER, OUTPUT);
  
  //pinMode(RECEIVER, INPUT);
  
  value = 0;
  data = 0;
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /*if (value == 0)
  {
    digitalWrite(LED, HIGH);
    
    value = 1;
  }
  else
  {
    digitalWrite(LED, LOW);
    
    value = 0;
  }*/
  
  for (unsigned int i=0; i<10; ++i)
  {
    digitalWrite(LED, HIGH);
    delay(2);
  }
  
  delay(100);
  
  data = analogRead(RECEIVER);
  
  Serial.print(value);
  Serial.print(": ");
  Serial.println(data);
  
  delay(1000);
}
