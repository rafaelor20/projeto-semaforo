#include <Wire.h>

#define SLAVE_ADDRESS 1 // Alterar conforme necessário

#define LED_GREEN 2
#define LED_YELLOW 3
#define LED_RED 4

#define LED_D_GREEN 5
#define LED_D_YELLOW 6
#define LED_D_RED 7

#define LED_P_GREEN 8
#define LED_P_RED 9

#define P_BUTTON 10
#define V_SENSOR 11

void setup() {
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);

    pinMode(LED_D_GREEN, OUTPUT);
    pinMode(LED_D_YELLOW, OUTPUT);
    pinMode(LED_D_RED, OUTPUT);

    pinMode(LED_P_GREEN, OUTPUT);
    pinMode(LED_P_RED, OUTPUT);

    pinMode(P_BUTTON, INPUT);
    pinMode(V_SENSOR, INPUT);
  
    VGreen();
    DGreen();
    PGreen();
    delay(200);
    VYellow();
    DYellow();
    delay(200);
    VRed();
    DRed();
    PRed();
    delay(200);

    Wire.begin(SLAVE_ADDRESS);
    Serial.begin(9600);
    Serial.print("Slave iniciado no endereço ");
    Serial.println(SLAVE_ADDRESS);

    Wire.onReceive(receiveEvent);
}

void loop() {
    
}

// Handle data received from the master
void receiveEvent(int bytes) {
    int command = Wire.read(); // Read the command sent by the master

    if (command == 1) {
        VGreen();
        DGreen();
        PRed();
    } else if (command == 0) {
        VRed();
        DRed();
        PGreen();
    }
}

void VGreen(){
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
}

void VYellow(){
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
}

void VRed(){
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
}

void DGreen(){
    digitalWrite(LED_D_GREEN, HIGH);
    digitalWrite(LED_D_YELLOW, LOW);
    digitalWrite(LED_D_RED, LOW);
}

void DYellow(){
    digitalWrite(LED_D_GREEN, LOW);
    digitalWrite(LED_D_YELLOW, HIGH);
    digitalWrite(LED_D_RED, LOW);
}

void DRed(){
    digitalWrite(LED_D_GREEN, LOW);
    digitalWrite(LED_D_YELLOW, LOW);
    digitalWrite(LED_D_RED, HIGH);
}

void PGreen(){
    digitalWrite(LED_P_GREEN, HIGH);
    digitalWrite(LED_P_RED, LOW);
}

void PRed(){
    digitalWrite(LED_P_GREEN, LOW);
    digitalWrite(LED_P_RED, HIGH);
}