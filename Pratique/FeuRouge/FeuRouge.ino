/* 
	TP Feu de signalisation Routière, durant le Formation Arduino
	Club Scientifique ENSA Marrakech, SciENSA
*/

unsigned int red_1 = 12;
unsigned int red_2 = 7;

unsigned int green_1 = 10;
unsigned int green_2 = 8;

unsigned int orange_1 = 11;
unsigned int orange_2 = 9;

int state = LOW;
int i = 0;

void setup() {
                  
  pinMode(red_1, OUTPUT);
  pinMode(red_2, OUTPUT);
  pinMode(green_1, OUTPUT);
  pinMode(green_2, OUTPUT);
  pinMode(orange_1, OUTPUT);
  pinMode(orange_2, OUTPUT);
}

void loop() {
  
  digitalWrite(red_1, HIGH);
  digitalWrite(red_2, LOW);

  digitalWrite(green_1, LOW);
  digitalWrite(green_2, HIGH);

  digitalWrite(orange_1, LOW);
  digitalWrite(orange_2, LOW);

  delay(10000);
  digitalWrite(green_2, LOW);
  for (i = 0; i < 10; ++i)
  { 
    state = !state ;
    digitalWrite(orange_2, state);
            delay(500);
  }
  digitalWrite(red_1, LOW);
  digitalWrite(green_1 , HIGH);

  digitalWrite(red_2 , HIGH);
  digitalWrite(orange_2, LOW);

  delay(10000);
  digitalWrite(green_1 , LOW);
  for (i = 0; i < 10; ++i)
  { 
    state = !state ;
    digitalWrite(orange_1, state);
            delay(500);
  }
}
