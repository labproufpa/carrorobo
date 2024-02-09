
teste

int motor1Pin2 = 3; // pin 2 on L293D
int motor1Pin7 = 2; // pin 7 on L293D
int motor1Pin10 = 4; // pin 10 on L293D
int motor1Pin15 = 14; // pin 15 on L293D
int sensorD = 0;
int sensorE = 0;

void setup() {
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1Pin7, OUTPUT);
  pinMode(motor1Pin10, OUTPUT);
  pinMode(motor1Pin15, OUTPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT); 
  Serial.begin(9600);
}

void MoveNormal()
{
  digitalWrite(motor1Pin7, HIGH); // set pin 2 on L293D low
  digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D high
  digitalWrite(motor1Pin10, HIGH); // set pin 10 on L293D low
  digitalWrite(motor1Pin15, LOW); // set pin 15 on L293D high
  delay(1500);
  digitalWrite(motor1Pin7, HIGH); // set pin 2 on L293D low
  digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D high
  digitalWrite(motor1Pin10, LOW); // set pin 10 on L293D low
  digitalWrite(motor1Pin15, LOW); // set pin 15 on L293D high
  delay(1500);
}

void sensorDireita() //Teste Sensor de Linha da Direita
{  
  {
    sensorD = digitalRead(12);  
    if (sensorD == 0)  
    { 
       digitalWrite(motor1Pin7, LOW); // set pin 2 on L293D low
       digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D high
       digitalWrite(motor1Pin10, LOW); // set pin 10 on L293D low
       digitalWrite(motor1Pin15, LOW); // set pin 15 on L293D high
       delay(300);
       digitalWrite(motor1Pin7, LOW); // set pin 2 on L293D low
       digitalWrite(motor1Pin2, HIGH); // set pin 7 on L293D high
       digitalWrite(motor1Pin10, LOW); // set pin 10 on L293D low
       digitalWrite(motor1Pin15, HIGH); // set pin 15 on L293D high
       delay(1000);
       digitalWrite(motor1Pin7, LOW); // set pin 2 on L293D low
       digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D high
       digitalWrite(motor1Pin10, HIGH); // set pin 10 on L293D low
       digitalWrite(motor1Pin15, LOW); // set pin 15 on L293D high
       delay(1000);
      Serial.println("Linha Detectada na Direita"); 
    }  
    else  
    {  
      Serial.println("Linha Não Detectada na Direita"); 
    } 
  } 
}

void sensorEsquerda() //Teste Sensor de Linha da Direita
{  
  {
    sensorE = digitalRead(11);  
    if (sensorE == 0)  
    { 
       digitalWrite(motor1Pin7, LOW); // set pin 2 on L293D low
       digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D high
       digitalWrite(motor1Pin10, LOW); // set pin 10 on L293D low
       digitalWrite(motor1Pin15, LOW); // set pin 15 on L293D high
       delay(300);
       digitalWrite(motor1Pin7, LOW); // set pin 2 on L293D low
       digitalWrite(motor1Pin2, HIGH); // set pin 7 on L293D high
       digitalWrite(motor1Pin10, LOW); // set pin 10 on L293D low
       digitalWrite(motor1Pin15, HIGH); // set pin 15 on L293D high
       delay(1000);
       digitalWrite(motor1Pin7, HIGH); // set pin 2 on L293D low
       digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D high
       digitalWrite(motor1Pin10, LOW); // set pin 10 on L293D low
       digitalWrite(motor1Pin15, LOW); // set pin 15 on L293D high
       delay(1000);
      Serial.println("Linha Detectada na Esquerda"); 
    }  
    else  
    {  
      Serial.println("Linha Não Detectada na Esquerda"); 
    } 
  } 
}

void loop() {
  MoveNormal();
  sensorDireita();
  sensorEsquerda();
}
