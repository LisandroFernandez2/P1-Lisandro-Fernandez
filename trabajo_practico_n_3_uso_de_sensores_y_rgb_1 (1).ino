
#define R 3
#define A 2
#define V 4
int valorluz;
int valortemp;
int celsius;
int realvalorluz;
void setup()
{

  Serial.begin(9800);
  pinMode(R,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(V,OUTPUT);
}

void loop()
{
  valorluz = analogRead(A0);
  valortemp = analogRead (A1);
  Serial.println("El nivel de luz actual es ");
  realvalorluz = map(valorluz,0,1017,0,100);
  Serial.println(realvalorluz);
  Serial.println("y la temperatura actual: ");
  celsius = map(((valortemp - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(celsius);
  delay(1000);
  if (realvalorluz > 30 && realvalorluz < 70){
  	if (celsius > 90) {
    analogWrite(R,255);
     delay(1000);
      analogWrite(R,0);
  	}
  	else if (celsius <= 18){
   	analogWrite(A,255); 
      delay(1000);
      analogWrite(A,0);
  	}
  	else if (celsius > 18 && celsius <= 90){
   	analogWrite(V,255);
       delay(1000);
      analogWrite(V,0);
  	}
  }
}

