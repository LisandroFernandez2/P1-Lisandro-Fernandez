#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
#define pinTemp A0
#define pinServo1 A2
#define pinServo2 A3
#define pinAzul 4
#define pinRojo 2
#define pinBoton1 8
#define pinBoton2 7
#define pinBuzzer 10
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define A6 1760
#define Fb6 1480
#define Cb6 1109
#define Fb5 740
#define C5 523
#define E6 1319
#define G5 784
#define Db5 622
#define Gb6 1661

const int midi1[16][3] = {
 {A6, 136, 273},
 {Fb6, 136, 682},
 {A6, 136, 0},
 {Cb6, 136, 0},
 {Fb5, 136, 136},
 {C5, 136, 409},
 {Fb5, 136, 136},
 {Cb6, 136, 136},
 {Fb5, 136, 682},
 {E6, 136, 0},
 {G5, 136, 955},
 {Db5, 136, 682},
 {G5, 136, 136},
 {Gb6, 136, 409},
 {Fb5, 136, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}


int temperatura;
bool bot1,bot2;
bool abierto = LOW;

Servo servo1;
Servo servo2;

Adafruit_LiquidCrystal lcd1(0);
void setup()
{
  pinMode(pinAzul, OUTPUT);
  pinMode(pinRojo, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinBoton1, INPUT);
  pinMode(pinBoton2, INPUT);
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo1.write(0);
  servo2.write(0);
  Serial.begin(9600);
    lcd1.begin(16,2);

}

void loop()
{
	cerrarOabrir();
  	chequearTemp();
  	mostrarEstado();
  	delay(1000);

}

void abrir(){
  servo1.write(90);
  servo2.write(90);
  abierto = HIGH;
  playMidi(pinBuzzer, midi1, ARRAY_LEN(midi1));
}

void cerrar(){
  servo1.write(0);
  servo2.write(0);
  abierto = LOW;
  playMidi(pinBuzzer, midi1, ARRAY_LEN(midi1));
}
void cerrarOabrir(){
	bot1 = digitalRead(pinBoton1);
  	bot2 = digitalRead(pinBoton2);
  	if(bot1 == LOW){
      abrir();
  	}
  
  	if(bot2 == LOW){
      cerrar();
  	}
  
}

void mostrarEstado(){
	if(abierto == HIGH){
      lcd1.setCursor(0,0);
      lcd1.print("ABIERTO");
    }else{
      lcd1.setCursor(0,0);
      lcd1.print("CERRADO");
    }
}
void chequearTemp(){
	temperatura = analogRead(pinTemp);
    temperatura = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);  
  	if(temperatura < 10){
  		digitalWrite(pinAzul, HIGH);
      	digitalWrite(pinRojo, LOW);
    }else if(temperatura > 35){
    	digitalWrite(pinAzul, LOW);
      	digitalWrite(pinRojo, HIGH);
    }else{
    	digitalWrite(pinAzul, LOW);
      	digitalWrite(pinRojo, LOW);
    }
  	lcd1.setCursor(0,1);
    lcd1.print(temperatura);
  	delay(200);
  
}