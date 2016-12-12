/* TP Ledfondu durant le Formation Arduino
   Club Scientifique ENSA Marrakech, SciENSA */

// Variable pour la valeur de PWM.
int value = 0;
// La broche branchee a la DEL.
int ledpin = 9;

void setup()
{
        pinMode(9,OUTPUT);
}

void loop()
{
        //Fade in.
        for(value = 0 ; value <= 255; value+=5)
        {
                analogWrite(ledpin, value);
                delay(30);
        }

        // Fade out.
        for(value = 255; value >=0; value-=5)
        {
                analogWrite(ledpin, value);
                delay(30);
        }
}
