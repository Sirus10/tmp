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
#define SENSOR_LEVEL_0_PIN 0		// SENSOR LEVEL 0
#define SENSOR_LEVEL_1_PIN 1		// SENSOR LEVEL 1
#define SENSOR_LEVEL_2_PIN 2		// SENSOR LEVEL 2
#define SENSOR_LEVEL_3_PIN 3		// SENSOR LEVEL 3
#define RF_OUT 4					// OUTPUT RF 

x10rf myx10 = x10rf(RF_OUT,0,5);
int level = 0;

void setup() {
  // SETING UP THE I/O PINS
  pinMode(SENSOR_LEVEL_0_PIN, INPUT);
  pinMode(SENSOR_LEVEL_1_PIN, INPUT);
  pinMode(SENSOR_LEVEL_2_PIN, INPUT);
  pinMode(SENSOR_LEVEL_3_PIN, INPUT);
  pinMode(RF_OUT, OUTPUT);

  // MYX10 INITIALIZATION
  myx10.begin();          
  
}

void loop() {
// THE LOOP
get_and_sent_water_level();
delay(5000);
}


/*
      FUNCTION
      get_and_sent_water_level
*/
int get_and_sent_water_level(){

// INTERNAL PULL-UP DESABLING TO AVOID ELECTROLYSE 
digitalWrite(SENSOR_LEVEL_0_PIN, HIGH); 
digitalWrite(SENSOR_LEVEL_1_PIN, HIGH); 
digitalWrite(SENSOR_LEVEL_2_PIN, HIGH); 
digitalWrite(SENSOR_LEVEL_3_PIN, HIGH); 

delay(100);
/*
Serial.print(" LEVELLEVELLEVEL  : ");
Serial.println(digitalRead(SENSOR_LEVEL_0_PIN));
Serial.print(" LEVELLEVELLEVEL  : ");
Serial.println(digitalRead(SENSOR_LEVEL_1_PIN));
Serial.print(" LEVELLEVEL  : ");
Serial.println(digitalRead(SENSOR_LEVEL_2_PIN));
Serial.print(" LEVEL  : ");
Serial.println(digitalRead(SENSOR_LEVEL_3_PIN));  
*/
int level = (1-digitalRead(SENSOR_LEVEL_1_PIN)) + (1-digitalRead(SENSOR_LEVEL_2_PIN)) + (1-digitalRead(SENSOR_LEVEL_3_PIN)) + (1-digitalRead(SENSOR_LEVEL_4_PIN)) ;
/*
Serial.print(" LEVEL OF WATER  : ");
Serial.println(level);  
*/

// INTERNAL PULL-UP DESABLING TO AVOID ELECTROLYSE 
digitalWrite(SENSOR_LEVEL_0_PIN, HIGH); 
digitalWrite(SENSOR_LEVEL_1_PIN, HIGH); 
digitalWrite(SENSOR_LEVEL_2_PIN, HIGH); 
digitalWrite(SENSOR_LEVEL_3_PIN, HIGH); 

// SENDING THE LEVEL OVER RF
myx10.RFXmeter(12,0,level);

}
