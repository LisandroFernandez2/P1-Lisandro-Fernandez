
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define B3 247
#define Ab3 233
#define E3 165
#define A3 220
#define G3 196
#define D4 294
#define Fb3 185
#define D3 147
#define Gb3 208
// boton definidos como boton1,2 y 3
#define boton1 2
#define boton2 4
#define boton3 5
// las otras notas 
#define B4 494
#define Ab4 466
#define A4 440
#define Gb4 415
#define G4 392
#define Fb4 370
#define B4 494
#define Ab4 466
#define A4 440
#define Gb4 415
#define G4 392
#define Fb4 370
bool valorboton;
bool valorboton2;
bool valorboton3;
const int midi1[20][3] = {
 {B3, 136, 136},
 {Ab3, 136, 0},
 {B3, 136, 0},
 {B3, 136, 136},
 {E3, 136, 0},
 {A3, 136, 136},
 {A3, 136, 0},
 {G3, 136, 136},
 {A3, 136, 136},
 {D4, 136, 136},
 {B3, 136, 0},
 {Fb3, 136, 136},
 {D3, 136, 273},
 {Ab3, 136, 273},
 {Fb3, 136, 273},
 {B3, 136, 273},
 {Gb3, 136, 409},
 {Fb3, 136, 136},
 {D4, 136, 136},
 {B3, 136, 0},
};
const int midi2[20][3] = {
 {B4, 136, 0},
 {Ab4, 136, 0},
 {A4, 136, 0},
 {Gb4, 136, 0},
 {G4, 136, 0},
 {Fb4, 136, 0},
 {G4, 136, 0},
 {Gb4, 136, 0},
 {A4, 136, 0},
 {Ab4, 136, 0},
 {A4, 136, 0},
 {Gb4, 136, 136},
 {Fb4, 136, 136},
 {Gb4, 136, 136},
 {B4, 136, 136},
 {A4, 136, 136},
 {G4, 136, 136},
 {Fb4, 136, 136},
 {Gb4, 136, 136},
 {Ab4, 136, 0},
};

const int midi3[20][3] = {
 {B4, 136, 0},
 {Ab4, 136, 0},
 {A4, 136, 0},
 {Gb4, 136, 0},
 {G4, 136, 0},
 {Fb4, 136, 0},
 {G4, 136, 0},
 {Gb4, 136, 0},
 {A4, 136, 0},
 {Ab4, 136, 0},
 {A4, 136, 0},
 {Gb4, 136, 136},
 {Fb4, 136, 136},
 {Gb4, 136, 136},
 {B4, 136, 136},
 {A4, 136, 136},
 {G4, 136, 136},
 {Fb4, 136, 136},
 {Gb4, 136, 136},
 {Ab4, 136, 0},
};
void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void setup() {
  Serial.begin(9800);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
}

void loop() {
  valorboton = digitalRead(boton1);
 valorboton2 = digitalRead(boton2);
  valorboton3 = digitalRead(boton3);
  Serial.println(valorboton3);
   if (valorboton == LOW){
  playMidi(8, midi1, ARRAY_LEN(midi1));
  }
  if (valorboton2 == LOW){
  playMidi(8, midi2, ARRAY_LEN(midi2));
  }
  if (valorboton3 == LOW){
  playMidi(8, midi3, ARRAY_LEN(midi3));
  }
}