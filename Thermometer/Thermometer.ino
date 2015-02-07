/*********************************************
 **              THERMOMETER                **
 *********************************************
 ** Display temperature in base 2 with LEDS **
 ** (Works between -63ºC and 63ºC)          **
 *********************************************/

#define ANALOG_TO_MV (5.0f / 1024.0f)

#define PIN_TEMP 0

#define NB_LED 6
#define PIN_OFFSET 2
#define PIN_SIGN (PIN_OFFSET + NB_LED)

int pinLED[NB_LED];

// the setup function runs once when you press reset or power the board
void setup() {
  for (int i=0; i<NB_LED; ++i) {
    pinLED[i] = PIN_OFFSET + i;
    pinMode(pinLED[i], OUTPUT);
  }
  
  pinMode(PIN_SIGN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  long temperature = getTempInCelcius(PIN_TEMP);

  if (temperature < 0) {
    digitalWrite(PIN_SIGN, HIGH);
    temperature *= -1;
  } else {
    digitalWrite(PIN_SIGN, LOW);
  }
  
  unsigned long absoluteTemp = temperature;
  
  for (int i=0; i<NB_LED; ++i) {
    digitalWrite(pinLED[i], getBit(absoluteTemp, i));
  }
  
  delay(10000);
}

float getTempInCelcius(int pin) {
  float mv = analogRead(pin) * ANALOG_TO_MV;
  float celcius = (mv - 0.5f) * 100.0f;
  
  return celcius;
}

unsigned short getBit(int value, int k) {
  int mask =  1 << k;
  int masked_n = value & mask;
  return masked_n >> k;
}
