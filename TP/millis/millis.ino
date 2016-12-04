/* TP Millis durant le Formation Arduino
   Club Scientifique ENSA Marrakech, SciENSA */

const int ledPin =  13;

bool ledState = 0;          

unsigned long previousMillis = 0;

const long interval = 1000;          

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    previousMillis = currentMillis;
  }
}
