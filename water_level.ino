#include <x10rf.h>


#define RF_OUT 4            // OUTPUT RF 
#define ALIM_NIVEAU_EAU_PIN 8     // Alim Capteur niveau bas
#define NIVEAU_BAS_1_PIN 0          // CAPTEUR  NIVEAU BAS
#define NIVEAU_BAS_2_PIN 1          // CAPTEUR  NIVEAU BA
#define NIVEAU_BAS_3_PIN 2          // CAPTEUR  NIVEAU BA
#define NIVEAU_BAS_4_PIN 3          // CAPTEUR  NIVEAU BA

x10rf myx10 = x10rf(RF_OUT,0,5);
int niveau = 0;

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  pinMode(NIVEAU_BAS_1_PIN, INPUT);
  pinMode(NIVEAU_BAS_2_PIN, INPUT);
  pinMode(NIVEAU_BAS_3_PIN, INPUT);
  pinMode(NIVEAU_BAS_4_PIN, INPUT);
 //pinMode(ALIM_NIVEAU_EAU_PIN, OUTPUT);
  pinMode(RF_OUT, OUTPUT);
 digitalWrite(NIVEAU_BAS_1_PIN, HIGH); // Activation du pull-up interne
 digitalWrite(NIVEAU_BAS_2_PIN, HIGH); // Activation du pull-up interne
 digitalWrite(NIVEAU_BAS_3_PIN, HIGH); // Activation du pull-up interne
 digitalWrite(NIVEAU_BAS_4_PIN, HIGH); // Activation du pull-up interne
  myx10.begin();          // For water level
  
}

void loop() {
// put your main code here, to run repeatedly:
get_and_sent_water_level();
delay(5000);
}


/*
      FUNCTION
      get_and_sent_water_level
*/
int get_and_sent_water_level(){
//digitalWrite(ALIM_NIVEAU_EAU_PIN, HIGH);
delay(100);
/*Serial.print(" Niveau  : ");
Serial.println(digitalRead(NIVEAU_BAS_1_PIN));
Serial.print(" Niveau  : ");
Serial.println(digitalRead(NIVEAU_BAS_2_PIN));
Serial.print(" Niveau  : ");
Serial.println(digitalRead(NIVEAU_BAS_3_PIN));
Serial.print(" Niveau  : ");
Serial.println(digitalRead(NIVEAU_BAS_4_PIN));  
*/
int niveau = (1-digitalRead(NIVEAU_BAS_1_PIN)) + (1-digitalRead(NIVEAU_BAS_2_PIN)) + (1-digitalRead(NIVEAU_BAS_3_PIN)) + (1-digitalRead(NIVEAU_BAS_4_PIN)) ;
/*Serial.print(" Niveau d'eau  : ");
Serial.println(niveau);  */
myx10.RFXmeter(12,0,niveau);
//digitalWrite(ALIM_NIVEAU_EAU_PIN, HIGH);
}
