#include "BluetoothSerial.h"

#define pin1 23
#define pin2 22
#define pin3 21
#define pin4 19


BluetoothSerial SerialBT;
char comando;
void setup() {
  Serial.begin(9600);
  SerialBT.begin("Carrinho");


  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
  Serial.println("Fim Setup");
  delay(2000);
}
void loop() {
  if (SerialBT.available()) {
    comando = SerialBT.read();
  }


  switch (comando) {
    case 'S':
      {  //move frente
        Serial.printf("Parado \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
      }
    case 'F':
      {  //move frente
        Serial.printf("Frente \n");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
      }
    case 'B':
      {  //move frente
        Serial.printf("Frente \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      }
    case 'L':
      {  //move frente
        Serial.printf("Frente \n");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      }
    case 'R':
      {  //move frente
        Serial.printf("Frente \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
      }
    case 'Q':
      {  //move frente
        Serial.printf("Frente \n");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
      } 
    case 'E':
      {  //move frente
        Serial.printf("Frente \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
      } 
    case 'C':
      {  //move frente
        Serial.printf("Frente \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      } 
    case 'Z':
      {  //move frente
        Serial.printf("Frente \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
      }    
  }
}










































/*
 case 'I': {//frente direita

 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, LOW);

 digitalWrite(pin3, LOW);
 digitalWrite(pin4, HIGH);
 break;
 }
case 'G': {//frente esquerda

 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);

 digitalWrite(pin3, HIGH);
 digitalWrite(pin4, LOW);
 break;
 }
 case 'R': {//direita

 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, LOW);

 digitalWrite(pin3, LOW);
 digitalWrite(pin4, LOW);
 break;
 }
 case 'L': {//esquerda

 digitalWrite(pin1, LOW);
 digitalWrite(pin2, LOW);

 digitalWrite(pin3, HIGH);
 digitalWrite(pin4, LOW);
 break;
 }
 case 'B': {// ré

 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);

 digitalWrite(pin3, LOW);
 digitalWrite(pin4, HIGH);
 break;
 }
case 'H': {// ré esquerda

 digitalWrite(pin1, LOW);
 digitalWrite(pin2, LOW);

 digitalWrite(pin3, LOW);
 digitalWrite(pin4, HIGH);
 break;
 }
 case 'J': {//ré direita
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);

 digitalWrite(pin3, LOW);
 digitalWrite(pin4, LOW);
 break;
 }
default: {
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, LOW);

 digitalWrite(pin3, LOW);
 digitalWrite(pin4, LOW);
 break;
 }
 */
