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


//VARIABLES DE TRANSMISION DE MENSAJES
String mensaje = "";
String Temp = "";

//MESSAGE
String message = "OrdenNuevo"; // Replace instead for your message
int sizeOfMessage = message.length();


void setup() {
  Serial.begin(9600);
pinMode(conexionArdOutput, OUTPUT);
pinMode(conexionNexOutput, OUTPUT);

}

void loop() {
  
   while(Serial.available() > 0){
      //STEP 1: Reading a Byte and saving the Byte in other place
      char recibido = Serial.read();
      //STEP 2: Concatenate Byte with Byte
      mensaje = Temp + recibido;
      //STEP 3: Saving the complete message in other place
      Temp = mensaje;
      //STEP 4: Preparing the variables, for the other Byte (Cleaning)
      mensaje = "";
      //STEP 5: Wait 50 Milli Seconds ITS NECESSARY
      delay(50);
      //STEP 6: Quit blank space and car return
          Temp.trim();
   }
   


      if(Temp.length() == sizeOfMessage){
        
          if(Temp.equals(message)){
              Serial.println("CORRECT");
              
            }else{
              Serial.println("ERROR");
              Temp = "";
        }
        Temp = "";
      }//FIN SIZE OF THE MESSAGE
      else{
//        Serial.println("ERROR");
          Temp = "";
      }

}//fin loop

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