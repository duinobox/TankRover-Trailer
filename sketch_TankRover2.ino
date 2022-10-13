// Usando o bluetooth para controlar o Infravermelho
// os codigos com arduino ja estao funcionando ok
// OBS: a versão do IRremote tem que ser a 2.8.0 na Ide Arduino
// Codigo funcionando perfeito ok!!!!!


#include <SoftwareSerial.h>

// pin emissor por padrao é pino 3

#include <IRremote.h>

IRsend irsend;

int subirBase1 = 20; // mudar pino A6 D20
int descerBase1 = 21; // mudar pino A7 D21
int desligarBase1 = 7;
int setaE1 = 8;
int setaD1 = 9;
int ledRadar1 = 10;
///// pinos de controle do tank /////
int pinIN1 = 11;
int pinIN2 = 12; // pino A0 D14
int pinIN3 = 13;
int pinIN4 = 14;
int MotorPWM1 = 5;
int MotorPWM2 = 6;
int MotorSpeed = 150;

SoftwareSerial btSerial(2,4); //RX e TX

void setup() {
  
  Serial.begin(9600);    
  btSerial.begin(9600);
  pinMode(subirBase, INPUT);
  pinMode(descerBase, INPUT);
  pinMode(desligarBase , INPUT);
  pinMode(ledRadar1 , INPUT);
  digitalWrite(setaE, INPUT);
  digitalWrite(setaD, INPUT);
  pinMode(pinIN1, OUTPUT);  // pino 9
  pinMode(pinIN2, OUTPUT);  // pino 10
  pinMode(pinIN3, OUTPUT);  // pino 11
  pinMode(pinIN4, OUTPUT);  // pino 12 
}

void loop() {
  char c=btSerial.read();
  if(c=='U'){subirBase();}
  else if(c=='B'){descerBase();}
  else if(c=='O'){desligarBase();}
  else if(c=='L'){setaE();}
  else if(c=='R'){setaD();}
  else if(c=='X'){ledRadar();}
  else if(c=='F'){pFrente();}
  else if(c=='T'){pTras();}
  else if(c=='S'){pStop();}
  else if(c=='E'){pEsquerda();}
  else if(c=='D'){pDireita();}
  
  delay(100);
}

void subirBase(){
  irsend.sendNEC(0x4329, 32);
 // irsend.sendRC5(0x20F100, 12);
  Serial.println("Subir a Base");
  }
void descerBase(){
    irsend.sendNEC(0x4584, 32); 
    Serial.println("Desligar a Base");
}
void desligarBase(){
    irsend.sendNEC(0x4839, 32); 
    Serial.println("Desligar a Base");
}
void setaE(){
  irsend.sendNEC(0x5349, 32);
  Serial.println("Vira p Esquerda");
}
void setaD(){
  irsend.sendNEC(0x5604, 32);
  Serial.println("Vira p Direita");
}
void ledRadar(){
  irsend.sendNEC(0x5859, 32);
  Serial.println("Led Radar");
}

// Funcoes do movimento do Tank //

void pFrente(){
  analogWrite(MotorPWM1,MotorSpeed);
  analogWrite(MotorPWM2,MotorSpeed);
  digitalWrite(pinIN1,HIGH);
  digitalWrite(pinIN3,HIGH);
}
void pTras(){
 analogWrite(MotorPWM1,MotorSpeed);
 analogWrite(MotorPWM2,MotorSpeed);
 digitalWrite(pinIN2,HIGH);
 digitalWrite(pinIN4,HIGH);
}
void pStop(){
 analogWrite(MotorPWM1,MotorSpeed);
 analogWrite(MotorPWM2,MotorSpeed);
 digitalWrite(pinIN1,LOW);
 digitalWrite(pinIN2,LOW);
 digitalWrite(pinIN3,LOW);
 digitalWrite(pinIN4,LOW);
}
void pEsquerda(){
 analogWrite(MotorPWM1,MotorSpeed);
 analogWrite(MotorPWM2,MotorSpeed);
 digitalWrite(pinIN2,HIGH);
 digitalWrite(pinIN3,HIGH);
}
void pDireita(){
 analogWrite(MotorPWM1,MotorSpeed);
 analogWrite(MotorPWM2,MotorSpeed);
 digitalWrite(pinIN1,HIGH);
 digitalWrite(pinIN4,HIGH);
}
