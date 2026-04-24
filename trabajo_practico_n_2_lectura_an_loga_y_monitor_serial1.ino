#define r 11
#define a 10
#define v 6
#define pr A0
#define pa A1
#define pv A2
#define boton 2
int valorrojo;
int valorverde;
int valorazul;
bool valorboton;
void setup()
{
  pinMode(boton,INPUT);
   pinMode(r,OUTPUT);
   pinMode(a,OUTPUT);
   pinMode(v,OUTPUT);
  Serial.begin(9800);
}

void loop()
{
valorboton = digitalRead(boton);
  delay(100);
  if(valorboton == LOW){
    Serial.print("Usted tiene 10 segundos para ajustar el color del led");
      delay(10000);
    valorrojo = analogRead(pr);
    valorverde = analogRead(pv);
    valorazul = analogRead(pa);
    valorrojo= map(valorrojo,0,1023,0,255);
    valorverde= map(valorverde,0,1023,0,255);
    valorazul= map(valorazul,0,1023,0,255);
    Serial.print("El led esta config: ");
    Serial.print(valorrojo);
    Serial.print(valorverde);
    Serial.print(valorazul);
    
    PrendeApaga();
  }
}
void PrendeApaga(){
  analogWrite(r,valorrojo);
  analogWrite(a,valorazul);
  analogWrite(v,valorverde);
  delay(10000);
  analogWrite(r,0);
  analogWrite(a,0);
  analogWrite(v,0);
}