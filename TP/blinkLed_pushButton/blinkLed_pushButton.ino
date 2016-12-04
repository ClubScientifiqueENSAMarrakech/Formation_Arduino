const int buttonPin_2 = 2;
const int ledPin_11 = 11;
const int ledPin_12 = 12;

int ledState = LOW;

unsigned long previousMillis = 0;

const long interval = 1000;

void setup() {

  pinMode(ledPin_11, OUTPUT);
  pinMode(ledPin_12, OUTPUT);
  pinMode(buttonPin_2, INPUT);
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin_11, ledState);
  }

  int state = digitalRead(buttonPin_2);
  if(state)
    digitalWrite(ledPin_12, HIGH);
  else
    digitalWrite(ledPin_12, LOW);
  
}
