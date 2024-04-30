# Plataforma para desenvolvimento de protótipos móveis

## Objetivo

O LabPRO dispõe de uma plataforma que auxília o desenvolvimento de protótipos móveis tais como robô seguidor de linha, robô sumô e outros. Os códigos e informações disponibilizados neste repositório são para uso nesta plataforma e servem de base para adição de novas funcionalidades.

## A plataforma

A plataforma é composta por:

* 1 Arduino Nano V3
* 1 ShieldRoboV3
  - 1 Ci Ponte H L293D
  - 1 Socket DIP 16
  - 2 Barra de Pino Femea 180 graus
  - 1 Barra de Pino Macho 180 graus
* 10 Jumper Femea-Femea 20cm
* 4 Servo Motor MG995r (Alterados p/ Motor DC e rotação 360 graus)
* 1 Sensor Ultrasonico HC-SR04
* 2 Módulo Sensor Ótico TCRT5000
* 1 Case Para 2 Baterias de Lítio ICR18650 (2x3,7v) 7,4V Sem Plug Com Botão On/Off
* 2 Bateria LI-ION ICR18650 3,7v 1800 mAH
* 1 Chassis personalizado em alumínio

## Foto da plataforma

|Vista Lateral 1|Vista Interna|Vista Lateral 3|
|---|---|---|
|<img alt="foto" width="200" height=auto src="imgs/side1.jpeg"> | <img alt="foto" width="200" height=auto src="imgs/foto.png">| <img alt="foto" width="200" height=auto src="imgs/side2.jpeg">|

## Esquemático das conexões da plataforma

<img alt="Esquemático" width="500" height=auto src="imgs/esquema.jpeg">

## Projeto da placa controladora ShieldRoboV3

[Projeto da placa de controle para KiCad ](files/kicad.rar)

## Requisitos para uso

* Biblioteca Ultrasonic para Arduino de Erick Simões. Esta biblioteca pode ser adquirida por meio da sua IDE de preferência.

## Códigos disponíveis

* ```carrorobo.ino```: código contendo a movimentação básica do robô. A lógica de movimentação é simples e considera movimentação em uma arena. O robô move para frente até encontrar o fim da arena. A arena tem a cor preta, e a borda branca, portanto ao detectar a borda, a leitura do sensor TCRT5000 mudará de 0 para 1. Nesta situação, o robô anda para trás e muda de direção. A direção do giro depende de qual sensor disparou a leitura, se o esquerdo ou o direito. Enquanto se move para frente, o robô faz a leitura do sensor de ultrassom e imprime a saída na interface serial, ou seja, nenhuma decisão é tomada com base nos dados deste sensor.
