#include <VirtualWire.h>

#define LED 13
#define RECEIVER 12
#define TRANSMITER 11
#define TRANSMIT_EN_PIN 3

#define SERIAL_SPEED 2000

void setup() {
  delay(1000);
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

  vw_set_tx_pin(TRANSMITER);
  vw_set_rx_pin(RECEIVER);
  vw_set_ptt_pin(TRANSMIT_EN_PIN);
  
  vw_set_ptt_inverted(true); // Configure the "push to talk" polarity. Required for DR3100 (-> TODO : TEST IF NEEDED)
  
  vw_setup(SERIAL_SPEED);
  
  vw_rx_start();
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    
    if(buf[0] == '1')
    {   
      digitalWrite(LED, HIGH);
      delay(2000);
      digitalWrite(LED, LOW);
    }  
  }
  
  delay(1);
}
