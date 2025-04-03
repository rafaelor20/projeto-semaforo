### Aluno: Rafael Oliveira Rosário

### Projeto: Semáforo Inteligente
### Link para o projeto no Tinkercad:

https://www.tinkercad.com/things/2MNBBfQc62d-semaforo-inteligente?sharecode=ajXtGmocL1wko_xPfZG3Ry3RFCWylDxeTzO703K_i_8

### Descrição:

Este projeto simula o funcionamento de um cruzamento entre duas ruas utilizando um sistema de semáforos inteligentes controlados por Arduinos. O objetivo é garantir um fluxo de trânsito eficiente e seguro para pedestres e veículos.

### Estrutura do Sistema

Semáforos para Veículos: Cada sentido da rua possui:

    1 semáforo para seguir em frente.

    1 semáforo para virar à direita.

Semáforos para Pedestres: Cada rua possui um semáforo exclusivo para pedestres.

Sensores de Movimento: Presentes em cada semáforo de veículos para detectar o fluxo e ajustar automaticamente o tempo do sinal verde.

### Funcionamento

Quando o botão do pedestre é pressionado, o sistema aguarda o sinal de veículos ficar vermelho para liberar a passagem dos pedestres.

A virada à direita é bloqueada enquanto o semáforo de pedestres estiver verde.

Os sensores de movimento detectam o fluxo de veículos e ajustam automaticamente o tempo do sinal verde para melhorar a fluidez do trânsito.

O Arduino Central coordena a comunicação e sincronização entre os semáforos, monitorando a comunicação com os Slaves.

Em caso de falha na comunicação, todos os semáforos piscam em amarelo como alerta.

### Materiais Utilizados

5 Arduinos UNO: 1 Central e 4 Slaves (cada Slave controla os semáforos de uma rua).

LEDs: Para simular os semáforos (vermelho, verde e amarelo).

Botões: Para o controle do semáforo de pedestres.

Sensores de Movimento: Para detectar o fluxo de veículos.

Fios e Resistores: Para conexões e ajustes de circuito.
