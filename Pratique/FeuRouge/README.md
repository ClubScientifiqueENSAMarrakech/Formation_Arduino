# Club Scientifique ENSA Marrakech - SciENSA

### TP: Feu de signalisation Routière

Une simple réalisation d'un Feu de signalisation Routière Miniaturisé pour
gérer la circulation d'une intersection à deux voies.

## Montage Arduino
![Imgur](http://i.imgur.com/lHMhjlT.jpg "Feu Rouge")
---
## 
![Imgur](http://i.imgur.com/tiQqttn.jpg "Circuit Feu Rouge")
---
## Diagramme de fonctionnement

les deux Feu de signalisation TL1 et TL2 fonctionnent comme suite * :

![Imgur](http://i.imgur.com/CCmFWKW.png "Diagram")

\* la LED orange clignote.

## Code Arduino

````c
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
````
