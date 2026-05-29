#define valorboton 2
#define luz A0
#define movi 5
#define rojo 3
#define azul 6
// VARIABLES:
bool boton;
bool movimiento;
int valorluz;
int realvalorluz;
void setup()
{
  pinMode(valorboton, INPUT);
   pinMode(rojo ,OUTPUT);
   pinMode(azul,OUTPUT);
  pinMode(movi,INPUT);
  Serial.begin(9800);
}

void loop()
{
// DEFINO VALOR DE VARIABLES
boton = digitalRead(valorboton);
valorluz = analogRead(luz);
movimiento = digitalRead(movi);
// IMPRIMO EL VALOR DE LA LUZ PARA QUE EL USUARIO SEPA CUANTO VALE
Serial.println("El valor de la luz es de: ");
Serial.println(realvalorluz);
realvalorluz = map(valorluz,22,671,0,100);
// IF QUE HACE FUNCIONAR A TODO
  if (boton == LOW && realvalorluz > 50){
  if (movimiento == HIGH){
    analogWrite(rojo,255);
    analogWrite(azul,255);
  }
  else if (movimiento == LOW){
    analogWrite(rojo,0);
    analogWrite(azul,0);
  }
}
}
