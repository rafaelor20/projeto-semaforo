#include <Wire.h>

#define SLAVE_ID 1  // Ajuste conforme o Slave (1 a 4)

#define LED_GREEN 2
#define LED_YELLOW 3
#define LED_RED 4

#define LED_D_GREEN 5
#define LED_D_YELLOW 6
#define LED_D_RED 7

#define LED_PED_GREEN 8
#define LED_PED_RED 9

#define SENSOR_VEICULOS 10 // sensor de veiculos simulado por um botão
#define BOTAO_PEDESTRE 11

void setup() {
    Wire.begin(SLAVE_ID);
    Serial.begin(9600);
    pinMode(SENSOR_VEICULOS, INPUT_PULLUP);
    pinMode(BOTAO_PEDESTRE, INPUT_PULLUP);
    
}

void loop() {
    if (Wire.available()) {
        String comando = lerComandoI2C();

        if (comando == "semaforoVerde") semaforoVerde();
        else if (comando == "semaforoAmarelo") semaforoAmarelo();
        else if (comando == "semaforoVermelho") semaforoVermelho();

        else if (comando == "semaforoPedestreVerde") semaforoPedestreVerde();
        else if (comando == "semaforoPedestreVermelho") semaforoPedestreVermelho();

        else if (comando == "alertaFalha") alertaFalha();
    }

    if (digitalRead(SENSOR_VEICULOS) == LOW) {
        enviarFluxoAoMaster();
    }

    if (digitalRead(BOTAO_PEDESTRE) == LOW) {
        enviarBotaoPedestreAoMaster();
    }
}

void semaforoVerde() {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
}

void semaforoAmarelo() {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
}

void semaforoVermelho() {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
}

void semaforoDireitaVerde() {
    digitalWrite(LED_D_GREEN, HIGH);
    digitalWrite(LED_D_YELLOW, LOW);
    digitalWrite(LED_D_RED, LOW);
}

void semaforoDireitaAmarelo() {
    digitalWrite(LED_D_GREEN, LOW);
    digitalWrite(LED_D_YELLOW, HIGH);
    digitalWrite(LED_D_RED, LOW);
}

void semaforoDireitaVermelho() {
    digitalWrite(LED_D_GREEN, LOW);
    digitalWrite(LED_D_YELLOW, LOW);
    digitalWrite(LED_D_RED, HIGH);
}

void semaforoPedestreVerde() {
    digitalWrite(LED_PED_GREEN, HIGH);
    digitalWrite(LED_PED_RED, LOW);
}

void semaforoPedestreVermelho() {
    digitalWrite(LED_PED_GREEN, LOW);
    digitalWrite(LED_PED_RED, HIGH);
}

void alertaFalha() {
    int i = 0;
    while (i < 100000) { // 100000 é um valor arbitrário
        digitalWrite(LED_YELLOW, HIGH);
        delay(500);
        digitalWrite(LED_YELLOW, LOW);
        delay(500);
        i++;
    }
}
