#include <dummy.h>
#include "BluetoothSerial.h"

#define pin1 19
#define pin2 23
#define pin3 18
#define pin4 17
#define LED 5

TaskHandle_t task_movimento;
TaskHandle_t task_modulos;


BluetoothSerial SerialBT;
char comando;

void setup() {

  Serial.begin(9600);
  SerialBT.begin("Carrinho 2");


  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
  xTaskCreatePinnedToCore(Task1code, "task_movimento", 10000, NULL, 1, &task_movimento, 0);
  delay (500);
  xTaskCreatePinnedToCore(Task2code, "task_modulos", 10000, NULL, 1, &task_modulos, 1);
  delay (500);

  Serial.println("Fim Setup");
  delay(2000);
}

void Task1code(void * pvParameters){
  Serial.print("tarefa 1 rodando no core ");
  Serial.println(xPortGetCoreID());


  for(;;){
    if (SerialBT.available()) {
    comando = SerialBT.read();
  }

  switch (comando) {
    case 'N' :
      {
        Serial.printf("Led Acesso \n");
        digitalWrite(LED, HIGH);
      }
    case 'n' : 
      {
        Serial.printf("Led Apagado \n");
        digitalWrite(LED, LOW);
      }
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
        Serial.printf("Ré \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      }
    case 'L':
      {  //move frente
        Serial.printf("Esquerda \n");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      }
    case 'R':
      {  //move frente
        Serial.printf("Direita \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
      }
    case 'Q':
      {  //move frente
        Serial.printf("Frente esquerda \n");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
      } 
    case 'E':
      {  //move frente
        Serial.printf("Frente direita \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
      } 
    case 'C':
      {  //move frente
        Serial.printf("Tras direita \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      } 
    case 'Z':
      {  //move frente
        Serial.printf("Tras esquerda \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
      }    
  }
  }
}

void Task2code(void * pvParameters){
  Serial.print("tarefa 2 rodando no core: ");
  Serial.println(xPortGetCoreID());
  
  for (;;){
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
    delay(2000);
  }
}


void loop() {
  
}
