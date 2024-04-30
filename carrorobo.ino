#include <Ultrasonic.h>

Ultrasonic ultrassom(15,16); // define o nome do sensor ultrasonico(ultrassom) onde o trig esta ligado na porta analogica A0 = D16 e o echo na porta analogica A1 = D15

#define MOTOR_E1 6 // Input 1 dos Motores da Esquerda // Pino 2 do L293 e D6 do Arduino Nano
#define MOTOR_E2 7 // Input 2 dos Motores da Esquerda // Pino 7 do L293 e D7 do Arduino Nano
#define MOTOR_D1 18 // Input 3 dos Motores da Direita // Pino 10 do L293 e A4 do Arduino Nano (A4 do Arduino Nano = D18 do Arduino Nano)
#define MOTOR_D2 17 // Input 4 dos Motores da Direita // Pino 15 do L293 e A3 do Arduino Nano (A3 do Arduino Nano = D17 do Arduino Nano)
#define ENABLE_E 5 // Enable 1 dos motores da esquerda // Pino 1 do L293 e D5 do Arduino Nano
#define ENABLE_D 9 // Enable 2 dos motores da Direita // Pino 9 do L293 e D9 do Arduino Nano

int sensorE = 0; // Sensor TCRT5000 da Direita  D3 do Arduino Nano
int sensorD = 0; //Sensor TCRT5000 da Direita D2 do Arduino Nano

void setup() {
  pinMode(MOTOR_E1, OUTPUT);
  pinMode(MOTOR_E2, OUTPUT);
  pinMode(ENABLE_E, OUTPUT);
  pinMode(MOTOR_D1, OUTPUT);
  pinMode(MOTOR_D2, OUTPUT);
  pinMode(ENABLE_D, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  delay(2000); //Tempo de espera necessario apos o inicio do round
}

//Referência: Estando atrás do robô
void vai_frente() {
  digitalWrite(ENABLE_E, 1);
  digitalWrite(ENABLE_D, 1);
  digitalWrite(MOTOR_E1, 0);
  digitalWrite(MOTOR_E2, 1);
  digitalWrite(MOTOR_D1, 0);
  digitalWrite(MOTOR_D2, 1);
}

//Referência: Estando atrás do robô
void vai_atras() {
  digitalWrite(ENABLE_E, 1);
  digitalWrite(ENABLE_D, 1);
  digitalWrite(MOTOR_E1, 1);
  digitalWrite(MOTOR_E2, 0);
  digitalWrite(MOTOR_D1, 1);
  digitalWrite(MOTOR_D2, 0);
}

//Referência: Estando atrás do robô
void vai_esquerda() {
  digitalWrite(ENABLE_E, 1);
  digitalWrite(ENABLE_D, 1);
  digitalWrite(MOTOR_E1, 0);
  digitalWrite(MOTOR_E2, 1);
  digitalWrite(MOTOR_D1, 1);
  digitalWrite(MOTOR_D2, 0);
}

//Referência: Estando atrás do robô
void vai_direita() {
  digitalWrite(ENABLE_E, 1);
  digitalWrite(ENABLE_D, 1);
  digitalWrite(MOTOR_E1, 1);
  digitalWrite(MOTOR_E2, 0);
  digitalWrite(MOTOR_D1, 0);
  digitalWrite(MOTOR_D2, 1);
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
      Serial.println("Linha Não Detectada na Direita"); 
    }    
}

void ataque(){
  long distancia = ultrassom.read();
    {
      if (distancia < 30)
        vai_frente();
     Serial.println("ATACAR!!!");
    }
  Serial.println("Distancia em cm: ");
  Serial.println(distancia);
}

void loop() {
  sensorEsquerda();
  sensorDireita();
  vai_frente();
}
