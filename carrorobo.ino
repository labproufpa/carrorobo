#include <Ultrasonic.h>

Ultrasonic ultrassom(15,16); // define o nome do sensor ultrasonico(ultrassom) onde o trig esta ligado a porta analogica A0 = D14 e o echo porta analogica A1 = D15

int MotorE1 = 6; // Input 1 dos Motores da Esquerda // Pino 2 do L293 e D6 do Arduino Nano
int MotorE2 = 7; // Input 2 dos Motores da Esquerda // Pino 7 do L293 e D7 do Arduino Nano
int MotorD1 = 18; // Input 3 dos Motores da Direita // Pino 10 do L293 e A4 do Arduino Nano (A4 do Arduino Nano = D18 do Arduino Nano)
int MotorD2 = 17; // Input 4 dos Motores da Direita // Pino 15 do L293 e A3 do Arduino Nano (A3 do Arduino Nano = D17 do Arduino Nano)
int EnableE = 5; // Enable 1 dos motores da esquerda // Pino 1 do L293 e D5 do Arduino Nano
int EnableD = 9; // Enable 2 dos motores da Direita // Pino 9 do L293 e D9 do Arduino Nano
int sensorD = 0; // Sensor TCRT5000 da Direita, Pino D9 do Arduino Nano
int sensorE = 0; //Sensor TCRT5000 da Direita D9 do Arduino Nano
int contador = 0;

void setup() {
  pinMode(MotorE1, OUTPUT);
  pinMode(MotorE2, OUTPUT);
  pinMode(EnableE, OUTPUT);
  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);
  pinMode(EnableD, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  delay(1000);
}

//Referência: Estando atrás do robô
void vai_frente() {
  digitalWrite(EnableE, 1);
  digitalWrite(EnableD, 1);
  digitalWrite(MotorE1, 0);
  digitalWrite(MotorE2, 1);
  digitalWrite(MotorD1, 0);
  digitalWrite(MotorD2, 1);
}

//Referência: Estando atrás do robô
void vai_atras() {
  digitalWrite(EnableE, 1);
  digitalWrite(EnableD, 1);
  digitalWrite(MotorE1, 1);
  digitalWrite(MotorE2, 0);
  digitalWrite(MotorD1, 1);
  digitalWrite(MotorD2, 0);
}

//Referência: Estando atrás do robô
void vai_esquerda() {
  digitalWrite(EnableE, 1);
  digitalWrite(EnableD, 1);
  digitalWrite(MotorE1, 0);
  digitalWrite(MotorE2, 1);
  digitalWrite(MotorD1, 1);
  digitalWrite(MotorD2, 0);
}

//Referência: Estando atrás do robô
void vai_direita() {
  digitalWrite(EnableE, 1);
  digitalWrite(EnableD, 1);
  digitalWrite(MotorE1, 1);
  digitalWrite(MotorE2, 0);
  digitalWrite(MotorD1, 0);
  digitalWrite(MotorD2, 1);
}

void procura() {
  vai_frente();
  delay(1000);
  vai_esquerda();
  delay(1000);
  vai_direita();
  delay(2000);
}

void sensorEsquerda() //Teste Sensor de Linha da Esquerda
{
    sensorE = digitalRead(2);  
    if (sensorE == 1)  
    {
       vai_atras();
       delay(1500);
       vai_direita();
       delay(2000);
       Serial.println("Linha Detectada na Esquerda");
    }  
    else  
    { 
      procura(); 
      Serial.println("Linha Não Detectada na Esquerda"); 
    }    
}

void sensorDireita() //Teste Sensor de Linha da Direita
{
    sensorD = digitalRead(3);  
    if (sensorD == 1)  
    {
       vai_atras();
       delay(1500);
       vai_esquerda();
       delay(2000);
       Serial.println("Linha Detectada na Direita");
    }  
    else  
    { 
      procura();
      Serial.println("Linha Não Detectada na Direita"); 
    }    
}

void ataque(){
  long distancia = ultrassom.read();
    {
     vai_frente();
    }
  Serial.println("Distancia em cm: ");
  Serial.println(distancia);
}

void loop() {
  sensorEsquerda();
  sensorDireita();
  ataque();
}
