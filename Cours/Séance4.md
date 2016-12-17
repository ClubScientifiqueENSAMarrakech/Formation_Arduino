# Club Scientifique ENSA Marrakech - SciENSA

## Arduino en Pratique - Séance 3

### Les Entrées / Sorties Numériques

## TP: Feu de signalisation Routière

Une simple réalisation d'un Feu de signalisation Routière Miniaturisé pour
gérer la circulation d'une intersection à deux voies.

### Montage Arduino
![Imgur](http://i.imgur.com/lHMhjlT.jpg "Feu Rouge")
---
### Schématique
![Imgur](http://i.imgur.com/tiQqttn.jpg "Circuit Feu Rouge")
---
### Diagramme de fonctionnement

les deux Feu de signalisation TL1 et TL2 fonctionnent comme suite * :

![Imgur](http://i.imgur.com/CCmFWKW.png "Diagram")

\* la LED orange clignote.

### Code

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
---

## Arduino en Pratique - Séance 4

### Les Entrées Analogiques

![sparkfun](https://cdn.sparkfun.com/assets/d/d/5/c/4/5114013ece395f527e000000.jpg)

## TP1: Analog In, Out Serial

Cet exemple montre comment lire une broche d'entrée analogique, mapper le résultat à une plage de 0 à 255, utiliser ce résultat pour régler la Modulation de Largeur d'Impulsion (PWM) d'une broche de sortie pour diminuer ou éclairer une LED et imprimer les valeurs sur Le moniteur en série du logiciel Arduino (IDE).

### Matériel requis

* Conseil Arduino ou Genuino
* Potentiomètre
* LED rouge
* Résistance 220 ohm

### Montage Arduino

![arduino.cc](https://www.arduino.cc/en/uploads/Tutorial/analoginoutseria1_bb.png)

### Schématique

![arduino.cc](https://www.arduino.cc/en/uploads/Tutorial/analoginoutserial_sch.png)

### Code

```c

const int analogInPin = A0; 
const int LED = 9;

int sensorValue = 0;        
int outputValue = 0;        

void setup() {
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(LED, outputValue);

  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  delay(2);
}
```

### Diviseurs de tension

Un diviseur de tension est un circuit simple , qui transforme une tension élevée dans une plus petite. En utilisant seulement deux résistances en série et une tension d'entrée, on peut créer une tension de sortie qui est une fraction de l'entrée.

![sparkfun](https://cdn.sparkfun.com/assets/4/0/3/a/e/511948ffce395f7f47000000.png)

L'équation de diviseur de tension suppose que vous savez trois valeurs du circuit ci - dessus: la tension d'entrée (V in ), et les deux valeurs de résistance (R 1 et R 2 ). Compte tenu de ces valeurs, nous pouvons utiliser cette équation pour trouver la tension de sortie (V out ):

![sparkfun](https://cdn.sparkfun.com/assets/e/7/6/3/c/511968d9ce395f7c54000000.png)

##### Applications

diviseurs de tension ont des tonnes d'applications, voici quelques-uns des nombreux endroits où vous trouverez des diviseurs de tension.

* **résistance variable**
	* Potentiomètre
	* Photorésistance / LDR
	* ...

## TP2: Analog Input

Dans cet exemple, nous utilisons une résistance variable (un potentiomètre ou une photorésistance), nous lisons sa valeur en utilisant une entrée analogique d'une carte Arduino et nous changeons le taux de clignotement de la LED intégré en conséquence. La valeur analogique de la résistance est lue comme une tension, car ceci est la façon dont les entrées analogiques fonctionnent.


### Matériel requis

* Arduino
* Potentiomètre
* photorésistance 10K ohms et résistance de 10K ohm
* LED rouge
* Résistance 220 ohm

### Montage Arduino

##### Potentiomètre :

![arduino.cc](https://www.arduino.cc/en/uploads/Tutorial/if_noLED.png)

##### Photorésistance / LDR :

![arduino.cc](https://www.arduino.cc/en/uploads/Tutorial/PhotoCellA0.png)

### Schématique

##### Potentiomètre :

![arduino.cc](https://www.arduino.cc/en/uploads/Tutorial/AnalogReadSerial_sch.png)

##### Photorésistance / LDR :

![arduino.cc](https://www.arduino.cc/en/uploads/Tutorial/PhotoResistorA0_schem.png)

### Code

```c

int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
```

---

## TP3: L298N Dual H-Bridge Motor Controller

### Pont en H (H-Bridge)

Le pont en H est une structure électronique servant à contrôler la polarité aux bornes d'un dipôle. Il est composé de quatre éléments de commutation généralement disposés schématiquement en une forme de H d'où le nom. Les commutateurs peuvent être des relais, des transistors, ou autres éléments de commutation en fonction de l'application visée.


![Imgur](http://i.imgur.com/dgQN42C.png)</br>
Structure of an H bridge (highlighted in red) - en.wikipedia.org

![Imgur](http://i.imgur.com/LooKwHO.png)</br>
The two basic states of an H bridge - en.wikipedia.org

**Table de vérité** : 

![Imgur](http://i.imgur.com/wOM8QdE.jpg)</br>
source : en.wikipedia.org


### les Broches d'un L298N

![Imgur](http://i.imgur.com/lGGiyRo.jpg)

### Montage Arduino

![Imgur](http://i.imgur.com/OTIYBID.jpg)

### Code

```c
// Moteur A
int enA = 9;
int in1 = 7;
int in2 = 6;

// Moteur B
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup()
{

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void Moteur_TEST()
{
  
  // Moteur A en marche
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  analogWrite(enA, 200);
  
  // Moteur B en marche
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
  analogWrite(enB, 200);
  delay(2000);
  
  // Changement de directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(2000);
  
  // 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop()
{
  Moteur_TEST();
  delay(1000);
}
```

## C'est fini pour aujourd'hui, à la prochaine.
#### Réalisé par : Imad Hsissou GRT1 - ENSA Marrakech UCA


