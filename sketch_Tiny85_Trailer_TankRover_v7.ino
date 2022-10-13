// Tiny85 Digispark
// Usando o bluetooth para controlar o Infravermelho
// os codigos com arduino ja estao funcionando ok
// OBS: a versão do IRremote tem que ser a 2.8.0 na Ide Arduino
// Codigo funcionando perfeito ok!!!!!

#include <Servo.h>
Servo servo;
Servo servoR;

const int irPin = 4;
const int Relay1 = 2;//0
const int Relay2 = 0;//1

boolean Relay1State = false;
boolean Relay2State = false;

void setup() {
  
  //Serial.begin(115200);
  pinMode(irPin, INPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  servo.attach(3); //9
  servo.write( 0 );
  servoR.attach(1); 
  servoR.write( 8 );
}

void loop() {
  int key = getIrKey();

  if(key == 27454){// tecla 1 5858
    servoA();
   }

  if(key == 8610){ //tecla 2 6623
    servoB();
   }
   //
    if(key == 8298){ //tecla 3 3563
    servoRadarS();
   }

  if(key == 27958){ //tecla 4 3308
    servoRadarD();
   }
   ////
   if(key == 26086){// tecla 5 6368
    digitalWrite(Relay1, HIGH);
   }

  if(key == 25582){ //tecla 6 24218
    digitalWrite(Relay1, LOW);
   }
   
}

int getIrKey(){
  int len = pulseIn(irPin,LOW);
  int key, temp;
  key = 0;
  //Serial.print("len=");
  //Serial.println(len);
  if(len > 5000) {
    for(int i=1;i<=32;i++){
      temp = pulseIn(irPin,HIGH);
      if(temp > 1000)
        key = key + (1<<(i-17));
    }
  }
  if(key < 0 )
    key = -key;
  
  //if(key)
    //Serial.println(key);

    delay(250);
  return key;
}

void servoA(){
   servo.write( 180 );
   digitalWrite(Relay2, HIGH);
   delay(50);
   digitalWrite(Relay2, LOW);
}
void servoB(){
  servo.write( 0 ); 
  digitalWrite(Relay2, HIGH);
  delay(50);
  digitalWrite(Relay2, LOW);
}
//
void servoRadarS(){
   servoR.write( 158 );
   digitalWrite(Relay2, HIGH);
   delay(50);
   digitalWrite(Relay2, LOW);
}
void servoRadarD(){
  servoR.write( 8 ); 
  digitalWrite(Relay2, HIGH);
  delay(50);
  digitalWrite(Relay2, LOW);
}
