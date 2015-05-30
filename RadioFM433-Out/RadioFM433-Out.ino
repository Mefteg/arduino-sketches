#include <VirtualWire.h>

#define LED 13
#define RECEIVER 12
#define TRANSMITTER 11

#define SERIAL_SPEED 2000

char* g_value;

void setup() {
  delay(1000);
  
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  
  vw_set_ptt_inverted(true);
  
  vw_set_rx_pin(RECEIVER);
  vw_set_tx_pin(TRANSMITTER);
  
  vw_setup(SERIAL_SPEED);
}

void loop() {
  g_value = "1";
  vw_send((uint8_t *) g_value, strlen(g_value));
  vw_wait_tx(); // Wait until the whole message is gone
  
  digitalWrite(LED, HIGH);
  delay(5000);
  digitalWrite(LED, LOW);

  delay(1000);
}
