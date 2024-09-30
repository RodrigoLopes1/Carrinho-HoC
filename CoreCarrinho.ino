#include <dummy.h>
#include "BluetoothSerial.h"

#define pin1 19
#define pin2 23
#define pin3 18
#define pin4 17
#define LED 4
#define auxiliar_out 32
#define auxiliar_in 33

TaskHandle_t task_movimento;
TaskHandle_t task_modulos;

BluetoothSerial SerialBT;
volatile char comando;  // Variável compartilhada

// Declarar o mutex
SemaphoreHandle_t xMutex;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("Carrinho DualCore");

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(auxiliar_out, OUTPUT);
  pinMode(auxiliar_in, INPUT);

  // Criar o mutex antes de iniciar as tasks
  xMutex = xSemaphoreCreateMutex();

  xTaskCreatePinnedToCore(Task1code, "task_movimento", 2048, NULL, 1, &task_movimento, 0);
  delay (500);
  xTaskCreatePinnedToCore(Task2code, "task_modulos", 2048, NULL, 1, &task_modulos, 1);
  delay (500);

  Serial.println("Fim Setup");
  delay(2000);
}

void Task1code(void * pvParameters){
  Serial.print("tarefa 1 rodando no core ");
  Serial.println(xPortGetCoreID());

  for(;;){  // Loop infinito
    if (SerialBT.available()) {
      // Garantir acesso exclusivo à variável comando
      if (xSemaphoreTake(xMutex, (TickType_t) 10) == pdTRUE) {
        comando = SerialBT.read();
        xSemaphoreGive(xMutex);  // Libera o mutex
      }
    }

    // Usar o comando
    switch (comando) {
      case 'S':
        Serial.printf("Parado \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
      case 'F':
        Serial.printf("Frente \n");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
      case 'B':
        Serial.printf("Ré \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      case 'L':
        Serial.printf("Esquerda \n");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      case 'R':
        Serial.printf("Direita \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
      case 'Q':
        Serial.printf("Frente esquerda \n");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
      case 'E':
        Serial.printf("Frente direita \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
      case 'C':
        Serial.printf("Tras direita \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;
      case 'Z':
        Serial.printf("Tras esquerda \n");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
      case 'X':
        Serial.printf("Ligando o led \n");
        digitalWrite(auxiliar_out, HIGH);
      case 'Y':
        digitalWrite(auxiliar_out, LOW);
    }
    vTaskDelay(100);
  }
}

void Task2code(void * pvParameters){
  Serial.print("tarefa 2 rodando no core: ");
  Serial.println(xPortGetCoreID());
  bool acionado = 0;
  bool liga_led = 0;

  int aux;

  for(;;){  // Loop infinito
    // Acessar o comando na Task 2 com o mutex
    if (xSemaphoreTake(xMutex, (TickType_t) 10) == pdTRUE) {
      Serial.printf("Comando atual: %c\n", comando);
      xSemaphoreGive(xMutex);  // Libera o mutex
    }

    
//----------------------------------------------------------
    aux = digitalRead(auxiliar_in);
    if (aux == HIGH){
      Serial.println("AAAAAAAAAAAAAAAA");
      //acionado = 1;
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
      vTaskDelay(100);
    }

    if (aux == LOW){
      Serial.println("BBBBBBBBBB");
      digitalWrite(LED, LOW);
      delay(50);
      //acionado = 0;
    }





//----------------------------------------












    delay(100);
    vTaskDelay(100);
  }
}

void loop() {
  // Não há nada no loop principal, as tasks estão rodando nos cores
}

