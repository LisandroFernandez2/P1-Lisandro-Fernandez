#define valorboton 2
#define valormovimiento 4
#define valortemperatura A2
#include <Servo.h>
bool boton;
bool movimiento;
int temperatura;
int celsius;
bool sigue = true;
int posicion;
int posicion2;
Servo servobase;
Servo servobase2;
void setup()
{
 pinMode (valorboton, INPUT);
  pinMode (valormovimiento, INPUT);
  servobase.attach(A0);
  servobase.write(0);
  servobase2.attach(A1);
  servobase2.write(0);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9800);
}
void semuevecientoochenta(){
  if (boton == HIGH){
    servobase.write(180); 
    servobase2.write(180);  
    delay(3000);          
    servobase.write(90);  
    servobase2.write(90);
     posicion = servobase.read();
    posicion2 = servobase2.read();
     delay(3000);
    if (movimiento == HIGH){
    servobase.write(0);
    servobase2.write(0);
    delay(6000);
  }
  if (celsius > 35){
    while(sigue){
    servobase.write(posicion);
    servobase2.write(posicion2);
    }
  }
   }
     else{
      servobase.write(45); 
    servobase2.write(45);
      }
    }
void loop()
{
  boton = digitalRead(valorboton);
  movimiento = digitalRead(valormovimiento);
  temperatura = analogRead(valortemperatura);
  celsius = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);

 semuevecientoochenta();
 
  
 }

     