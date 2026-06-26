#define PO A0
#define rojo 11
#define azul 10
#define verde 6
int potenciometro;
int valorpotenciometrotransformado;
int aleatorio;
void setup()
{
  Serial.begin(9600);
   pinMode(rojo,OUTPUT);
   pinMode(azul,OUTPUT);
   pinMode(verde,OUTPUT);
  randomSeed(analogRead(A1));
}

void loop()
{
  potenciometro = analogRead(A0);
  valorpotenciometrotransformado = map((potenciometro),0, 1023, 100, 0);
  	Serial.println(valorpotenciometrotransformado);
  if (valorpotenciometrotransformado <= 20){
aleatorio = random(1, 11);
    ejercicio1();
    delay(1000);
  }
  else if(valorpotenciometrotransformado > 20 && valorpotenciometrotransformado <= 40){
    ejercicio2();
    delay(1000);
  }
  else if (valorpotenciometrotransformado > 40 && valorpotenciometrotransformado <= 60){
    ejercicio3();
    delay(1000);
  }
  else if (valorpotenciometrotransformado > 60 && valorpotenciometrotransformado <= 80){
    ejercicio4();
    delay(1000);
  
  }
  else{
    ejercicio5();
    delay(1000);
  }
} 
  void ejercicio1(){
    int listadenumeros[3] = {1,2,3};
    
    int largovector  = sizeof(listadenumeros)/sizeof(listadenumeros[0]);
    int nuevalistadenumeros[3];
    for (int x = 0; x < largovector; x++){ 
      nuevalistadenumeros[x] = listadenumeros[x] * aleatorio;
      delay(1000);
      analogWrite(rojo,nuevalistadenumeros[x]);
      analogWrite(azul,nuevalistadenumeros[x]);
      analogWrite(verde,nuevalistadenumeros[x]);
      delay(1000);
      analogWrite(rojo,0);
      analogWrite(azul,0);
      analogWrite(verde,0);
      delay(1000);
    }

  }
void ejercicio2(){
  int notas[10] = {5,6,7,8,2,5,1,6,4,2};
  int sumadenotas = 0;
  int promediodenotas;
  int largovector2  = sizeof(notas)/sizeof(notas[0]);
  for (int x = 0; x < largovector2; x++){
    sumadenotas = sumadenotas + notas[x];
  }
  promediodenotas = sumadenotas / 10;
  if (promediodenotas < 5){
   analogWrite(rojo,255);
  }
  else if (promediodenotas >= 6 && promediodenotas <= 8){
      analogWrite(verde,255);
  }
  else{
   analogWrite(azul,255); 
  }
}
void ejercicio3(){
  int numeros[15] = {4, 7, 9, 2, 6, 8, 5, 3, 10, 1, 6, 7, 4, 8, 5};
   int largovector3  = sizeof(numeros)/sizeof(numeros[0]);
  for (int x = 0; x < largovector3; x++){
    analogWrite(verde, 0);
    analogWrite(rojo, 0);
    delay(200);  
   if (numeros[x] % 2 == 0){
     
      analogWrite(verde,255);
      delay(1000);
    }
    else{
     
      analogWrite(rojo,255);
      delay(1000);
    }  
  }
   analogWrite(verde, 0);
  analogWrite(rojo, 0);
}
void ejercicio4(){
  int numeros[30];
  int max1 = -1;   
  int max2 = -1;   
  int max3 = -1;  

 
  for (int x = 0; x < 30; x++) {
    numeros[x] = random(0, 256); 
  }


  for (int x = 0; x < 30; x++) {
    if (numeros[x] > max1) {
      max3 = max2;         
      max2 = max1;         
      max1 = numeros[x]; 
    }
    else if (numeros[x] > max2) {
      max3 = max2;        
      max2 = numeros[x];   
    } 
    else if (numeros[x] > max3) {
      max3 = numeros[x];   
    }
  }

  
  analogWrite(rojo, max1);
  analogWrite(verde, max2);
  analogWrite(azul, max3);
  
  delay(3000); 
}
void ejercicio5(){
  int numeros[30]; 
  
  
  int min1 = 256;  
  int min2 = 256;   
  int min3 = 256;   

  
  for (int x = 0; x < 30; x++) {
    numeros[x] = random(0, 256);
  }

 
  for (int x = 0; x < 30; x++) {
    if (numeros[x] < min1) {
      min3 = min2;         
      min2 = min1;         
      min1 = numeros[x];   
    } 
    else if (numeros[x] < min2) {
      min3 = min2;         
      min2 = numeros[x];   
    } 
    else if (numeros[x] < min3) {
      min3 = numeros[x];   
    }
  }

  analogWrite(rojo, min1);
  analogWrite(verde, min2);
  analogWrite(azul, min3);
  
  delay(3000); 
}