#include <Servo.h>
#define PinServo A0
#define PinBoton 2
#define PinLed 4
#define PinSensorLuz A1
Servo Servo1;
bool Boton;
int SensorLuz;
void setup()
{
  Serial.begin(9600);
  Servo1.attach(PinServo);
  pinMode(PinBoton,INPUT);
  pinMode(PinLed,OUTPUT);
}

void loop()
{
 Boton = digitalRead(PinBoton);
  SensorLuz = analogRead(PinSensorLuz);
  SensorLuz = map(SensorLuz,207,1012,100,0);
  Serial.println(SensorLuz);
  if (Boton == LOW && SensorLuz <= 50){
    digitalWrite(PinLed,HIGH);
  }
  if (Boton == LOW){
    Servo1.write(180);
  }
  else{
    Servo1.write(0);
    digitalWrite(PinLed,LOW);
  }
  
}