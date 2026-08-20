#include <Servo.h>
#define ValorDelServo1 A0
#define ValorDelServo2 A1
#define ValorDelSensorM1 2
#define ValorDelSensorM2 4
#define ValorDelBozzer 3
#define ValorLuz 12
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define B3 247
#define Cb4 277
#define F4 349
#define A4 440
#define C4 262

// VARIABLES
Servo Servo1;
Servo Servo2;
bool ValorSensorMovimiento1;
bool ValorSensorMovimiento2;
int ValorFotoresistencia;


//==========================================================================================================================

const int midi1[5][3] = {
 {B3, 136, 136},
 {Cb4, 136, 136},
 {B3, 136, 136},
 {Cb4, 136, 136},
 {B3, 136, 0},
};
const int midi2[5][3] = {
 {F4, 136, 273},
 {B3, 136, 409},
 {A4, 136, 136},
 {F4, 136, 273},
 {C4, 136, 0},
};


void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void SeAbrenLasPuertas(bool Movimiento){
  playMidi(3, midi1, ARRAY_LEN(midi1));
  Servo1.write(180);
  Servo2.write(180);
  
}
void ServosCerrados(){
  HayLuz();
  Servo1.write(90);
  Servo2.write(90);
}
void VerificarMovimiento(){
  if (ValorSensorMovimiento1 == HIGH){
    SeAbrenLasPuertas(ValorSensorMovimiento1);
  	}
  if (ValorSensorMovimiento2 == HIGH){
    playMidi(3, midi2, ARRAY_LEN(midi1));
    ServosCerrados();
	}
  if (ValorSensorMovimiento1 == LOW && ValorSensorMovimiento2 == LOW){
    ServosCerrados();
  	}
}
void HayLuz(){
    ValorFotoresistencia = analogRead(A2); 
  if (ValorFotoresistencia > 500){
    digitalWrite(ValorLuz,HIGH);
  }
  else{
    digitalWrite(ValorLuz,LOW);
  }  
}
void setup()
{
// VALORES DE LOS SERVOS 
 Servo1.attach(ValorDelServo1);
 Servo2.attach(ValorDelServo2);
 Servo1.write(0);
 Servo2.write(0);
//======================================================================================  
// VALORES DE LOS PINES (INPUT/OUTPUT)  
  pinMode(ValorDelServo1,INPUT);
  pinMode(ValorDelServo2,INPUT);
  pinMode(ValorDelSensorM1,INPUT);
  pinMode(ValorDelSensorM2,INPUT);
  pinMode(ValorDelBozzer,INPUT);
  pinMode(ValorLuz,OUTPUT);
  pinMode(A2,INPUT);	
//======================================================================================  
}






void loop()
{
ValorSensorMovimiento1 = digitalRead(ValorDelSensorM1);
ValorSensorMovimiento2 = digitalRead(ValorDelSensorM2);
ValorFotoresistencia = analogRead(A2);  
// FUNCION QUE VERIFICA SI HAY MOVIMIENTO  
 VerificarMovimiento();
 HayLuz();
}