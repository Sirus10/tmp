/******************************************
# This script aim at reporting tack water level
# Site    : http://domotique.web2diz.net/
# Detail  : http://domotique.web2diz.net/?p=596
#
# License : CC BY-SA 4.0
#
# This script use the x10rf library 
# See source here : 
# https://github.com/p2baron/x10rf
#
#
/*******************************************/
// including x10rf library
#include <x10rf.h>

// define I/O PINS
#define NIVEAU_BAS_0_PIN 0          // SENSOR LEVEL 0
#define NIVEAU_BAS_1_PIN 1          // SENSOR LEVEL 1
#define NIVEAU_BAS_2_PIN 2          // SENSOR LEVEL 2
#define NIVEAU_BAS_3_PIN 3          // SENSOR LEVEL 3
#define RF_OUT 4                    // OUTPUT RF 

x10rf myx10 = x10rf(RF_OUT,0,5);
int level = 0;

void setup() {
  // seting up the I/O PINS
  pinMode(NIVEAU_BAS_0_PIN, INPUT);
  pinMode(NIVEAU_BAS_1_PIN, INPUT);
  pinMode(NIVEAU_BAS_2_PIN, INPUT);
  pinMode(NIVEAU_BAS_3_PIN, INPUT);
  pinMode(RF_OUT, OUTPUT);
  
  // INTERNAL PULL-UP ACTIVATION 
  digitalWrite(NIVEAU_BAS_0_PIN, HIGH); // Activation du pull-up interne
  digitalWrite(NIVEAU_BAS_1_PIN, HIGH); // Activation du pull-up interne
  digitalWrite(NIVEAU_BAS_2_PIN, HIGH); // Activation du pull-up interne
  digitalWrite(NIVEAU_BAS_3_PIN, HIGH); // Activation du pull-up interne

  myx10.begin();          // For water level
  
}

void loop() {
get_and_sent_water_level();
delay(5000);
}


/*
      FUNCTION
      get_and_sent_water_level
*/
int get_and_sent_water_level(){
delay(100);
/*
Serial.print(" LEVELLEVELLEVEL  : ");
Serial.println(digitalRead(NIVEAU_BAS_0_PIN));
Serial.print(" LEVELLEVELLEVEL  : ");
Serial.println(digitalRead(NIVEAU_BAS_1_PIN));
Serial.print(" LEVELLEVEL  : ");
Serial.println(digitalRead(NIVEAU_BAS_2_PIN));
Serial.print(" LEVEL  : ");
Serial.println(digitalRead(NIVEAU_BAS_3_PIN));  
*/
int level = (1-digitalRead(NIVEAU_BAS_1_PIN)) + (1-digitalRead(NIVEAU_BAS_2_PIN)) + (1-digitalRead(NIVEAU_BAS_3_PIN)) + (1-digitalRead(NIVEAU_BAS_4_PIN)) ;
/*Serial.print(" LEVEL OF WATER  : ");
Serial.println(level);  */
// SENDING THE LEVEL OVER RF
myx10.RFXmeter(12,0,level);

}
