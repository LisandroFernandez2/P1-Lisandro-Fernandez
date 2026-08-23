#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
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
Adafruit_LiquidCrystal lcd1(0);
Servo Servo1;
Servo Servo2;
bool ValorMovimiento1;
bool ValorMovimiento2;
bool EstaAbierta = LOW;
int ValorFotoresistencia;

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

void VerificarMovimiento()
{
   ValorMovimiento1 = digitalRead(ValorDelSensorM1);
 ValorMovimiento2 = digitalRead(ValorDelSensorM2);
  
  if (ValorMovimiento1 == HIGH && EstaAbierta == LOW)
  {
   abrir();
   EstaAbierta = HIGH;
  }
  else if (ValorMovimiento1 == HIGH && EstaAbierta == HIGH)
  {
   cerrar();
   EstaAbierta = LOW;
  }
  delay(2000);
  if (ValorMovimiento2 == HIGH && EstaAbierta == LOW)
  {
   abrir();
   EstaAbierta = HIGH;
  }
  else if (ValorMovimiento2 == HIGH && EstaAbierta == HIGH)
  {
   cerrar(); 
   EstaAbierta = LOW;
  }
}

void HayLuz(){
 ValorFotoresistencia = analogRead(A2); 
  if (ValorFotoresistencia > 500){
    digitalWrite(ValorLuz, HIGH);
  }
  else{
    digitalWrite(ValorLuz, LOW);
  }  
}

void abrir(){
  playMidi(3, midi1, ARRAY_LEN(midi1));
  Servo1.write(180);
  Servo2.write(180);
  delay(1000);
}

void cerrar(){
  playMidi(3, midi2, ARRAY_LEN(midi2));
  Servo1.write(90);
  Servo2.write(90);
  delay(1000);
}

void setup()
{
  Servo1.attach(ValorDelServo1);
  Servo2.attach(ValorDelServo2);
  Servo1.write(90);
  Servo2.write(90);
  lcd1.begin(16,2);
  
  pinMode(ValorDelSensorM1, INPUT);
  pinMode(ValorDelSensorM2, INPUT);
  pinMode(A2, INPUT);	
  
  pinMode(ValorDelBozzer, OUTPUT);
  pinMode(ValorLuz, OUTPUT);
  
  Serial.begin(9800);
}

void LcdAbiertoOCerrado(){
     if (EstaAbierta == LOW){
    lcd1.setCursor(0,0);
     lcd1.print("Cerrado");
  }
    else{
      lcd1.setCursor(0,0);
      lcd1.print("Abierto");
    }
}
void loop()
{  
  VerificarMovimiento();
  HayLuz();
  LcdAbiertoOCerrado();
}
