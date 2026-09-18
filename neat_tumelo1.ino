#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
#define PinBoton 7
#define PinServo A0
#define PinPotenciometro A1
#define PinBuzzer 6
#define PinAzul 2
#define PinVerde 3
#define PinRojo 4
#define PinTemperatura A2
//definiciones del buzzer
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220
//variables
Servo servo;
bool bot1;
int Potenciometro, temperatura;
Adafruit_LiquidCrystal lcd1(0);
void setup()
{
  pinMode(PinBoton,INPUT);
  pinMode(PinBuzzer,OUTPUT);
  pinMode(PinAzul,OUTPUT);
  pinMode(PinVerde,OUTPUT);
  pinMode(PinRojo,OUTPUT);
  Serial.begin(9600);
  lcd1.begin(16,2);
  servo.attach(PinServo);
}
const int midi1[10][3] = {
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 115},
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 0},
};
void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void CuantoEsperaElServo(){
 bot1 = digitalRead(PinBoton);
  if (bot1 == LOW){
    for (int i = 0; i < 2; i++){
      Potenciometro = analogRead(PinPotenciometro);
       Potenciometro = map((Potenciometro),0,1023,100,0);
      lcd1.setCursor(0,0);
      lcd1.print("SERVO MOVIENDOSE");
      servo.write(0);
      if (Potenciometro < 25){ 
        delay(2000);
        servo.write(90);
        delay(2000);
      }
      else if (Potenciometro > 25 && Potenciometro < 50){
       delay(5000);
        servo.write(90);
        delay(5000);
      }
      else{
        delay(8000);
        servo.write(90);
        delay(8000);
      }
    } 
    lcd1.setCursor(0,0);
    lcd1.print("                ");
    digitalWrite(PinVerde,HIGH);
    delay(1000);
    lcd1.setCursor(0,0);
    lcd1.print("MELODIA");
    playMidi(6, midi1, ARRAY_LEN(midi1));  
    lcd1.setCursor(0,0);
    lcd1.print("       ");
    digitalWrite(PinVerde,LOW);
  }
}
void PrenderLedTemperatura(){
  temperatura = analogRead(PinTemperatura);
  temperatura = map(((temperatura - 20) * 3.04),0,1023,-40,125);
  if (temperatura > 40){
    digitalWrite(PinRojo,HIGH);
    digitalWrite(PinAzul,LOW);
  }
  else{
    digitalWrite(PinAzul,HIGH);
    digitalWrite(PinRojo,LOW);
  }
}
void loop()
{
CuantoEsperaElServo();
PrenderLedTemperatura();
}