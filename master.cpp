#include <Wire.h>

#define tempoSemaforo 6000 // valor a ser multiplicado  de acordo com quant de carros que passam

#define SLAVE1 1
#define SLAVE2 2
#define SLAVE3 3
#define SLAVE4 4

int i = 0;

void setup() {
    Wire.begin();
    Serial.begin(9600);
    delay(600); // Esperar Slaves inicializarem
}

void loop() {
    for (int slave = SLAVE1; slave <= SLAVE4; slave++) {
        Wire.beginTransmission(slave);
        int command = ((slave + i) % 2 == 0) ? 1 : 0; // 1 para Slaves pares, 0 para ímpares
        Wire.write(command); // Envia o comando para o Slave
        Wire.endTransmission();
        
        Serial.print("Comando enviado para o Slave ");
        Serial.print(slave);
        Serial.print(": ");
        Serial.println(command);

        
        delay(50); // Delay para garantir que o Slave tenha tempo para processar
    }
    i++;
    if (i > 9 ){
        i = 0;
    }
  delay(tempoSemaforo);
}