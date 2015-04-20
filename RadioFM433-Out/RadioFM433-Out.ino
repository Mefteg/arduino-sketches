void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200); // Hardware supports up to 2400, but 1200 gives longer range
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.write(15);

  delay(1000);
}
