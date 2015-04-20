#define LED 13

unsigned int send = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  
  Serial.begin(1200); // Hardware supports up to 2400, but 1200 gives longer range
}

void loop() {
  // put your main code here, to run repeatedly:
  if (send == 0)
  {
    digitalWrite(LED, LOW);
    
    send = 1;
  }
  else
  {
    digitalWrite(LED, HIGH);
    Serial.write(15);
    
    send = 0;
  }

  delay(1000);
}
