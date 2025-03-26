#include <Wire.h>

#define tempoSemaforo 10000 // valor a ser multiplicado  de acordo com quant de carros que passam

typedef struct {
    int id;
    int fluxo;
    int pedestre;
    int verde;
    int amarelo;
    int vermelho;
    int direitaVerde;
    int direitaAmarelo;
    int direitaVermelho;
    int pedestreVerde;
    int pedestreVermelho;
    int falha
} Slave;

void Slave_init(Slave *slave, int id) {
    slave->id = id;
    slave->fluxo = 0;
    slave->pedestre = 0;
    slave->verde = 0;
    slave->amarelo = 0;
    slave->vermelho = 0;
    slave->direitaVerde = 0;
    slave->direitaAmarelo = 0;
    slave->direitaVermelho = 0;
    slave->pedestreVerde = 0;
    slave->pedestreVermelho = 0;
    slave->falha = 0;
}


void setup() {
    Wire.begin(); // Inicializa o Arduino Central como master
    Serial.begin(9600);

    Slave slaves[4];
    for (int i = 0; i < 4; i++) {
        Slave_init(&slaves[i], i + 1);
    }
}

void loop() {


}


void semaforoVerde(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("semaforoVerde");
    Wire.endTransmission();
}

void semaforoAmarelo(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("semaforoAmarelo");
    Wire.endTransmission();
}

void semaforoVermelho(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("semaforoVermelho");
    Wire.endTransmission();
}

void semaforoDireitaVerde(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("semaforoDireitaVerde");
    Wire.endTransmission();
}

void semaforoDireitaAmarelo(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("semaforoDireitaAmarelo");
    Wire.endTransmission();
}

void semaforoDireitaVermelho(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("semaforoDireitaVermelho");
    Wire.endTransmission();
}

void semaforoPedestreVerde(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("semaforoPedestreVerde");
    Wire.endTransmission();
}

void semaforoPedestreVermelho(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("semaforoPedestreVermelho");
    Wire.endTransmission();
}

void alertaFalha(int slave) {
    Wire.beginTransmission(slave);
    Wire.write("alertaFalha");
    Wire.endTransmission();
}