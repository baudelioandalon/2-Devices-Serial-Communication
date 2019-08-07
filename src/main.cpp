#include <Arduino.h>

////////////////////////////////////////////////////////////
//COMUNICAR 2 DISPOSITIVOS A TRAVES DE 1 SOLO PUERTO SERIAL
//ESTE CODIGO ES EL COMPLEMENTO DE 1 CIRCUITO ELECTRONICO
//LINK DEL CIRCUITO: EN PROCESO
////////////////////////////////////////////////////////////

//PINES DE LOS TRANSISTORES BC547A
//TX - RX - ARDUINO TO ARDUINO (Digital pin 7)
//TX - RX - ARDUINO TO NEXTION (Digital pin 8)

int conexionArdOutput = 7;
int conexionNexOutput = 8;


void setup() {
  Serial.begin(9600);
pinMode(conexionArdOutput, OUTPUT);
pinMode(conexionNexOutput, OUTPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
}

void comunicarArduinoToArduino(){
  digitalWrite(conexionNexOutput, LOW);
  delay(50);
  digitalWrite(conexionArdOutput, HIGH);

}

void comunicarArduinoToNextion(){
  digitalWrite(conexionArdOutput, LOW);
  delay(50);
  digitalWrite(conexionNexOutput, HIGH);

}