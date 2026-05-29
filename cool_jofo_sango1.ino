#define valorboton 2
#define luz A0
#define movi 5
bool boton;
bool movimiento;
int valorluz;
int realvalorluz;
void setup()
{
  pinMode(2, INPUT);
   pinMode(3 ,OUTPUT);
   pinMode(6 ,OUTPUT);
  pinMode(5,INPUT);
  Serial.begin(9800);
}

void loop()
{
boton = digitalRead(valorboton);
valorluz = analogRead(luz);
  movimiento = digitalRead(movi);
Serial.println("El valor de la luz es de: ");
  Serial.println(realvalorluz);
  Serial.println(movimiento);
 realvalorluz = map(valorluz,22,671,0,100);
if (boton == LOW && realvalorluz > 50){
  if (movimiento == HIGH){
    analogWrite(3,255);
    analogWrite(6,255);
  }
  else if (movimiento == LOW){
    analogWrite(3,0);
    analogWrite(6,0);
  }
}
}