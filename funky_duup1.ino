void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop()
{
delay(1000);
analogWrite(10,255);
delay(1000);   // se prende y se apaga el primer led
analogWrite(10,0);
delay(1000);
 
for (int x = 1;x <= 4; x++) {
    
      analogWrite(11,20);
    analogWrite(10,255);
    
    analogWrite(3,255);
	analogWrite(6,20);
    
	analogWrite(4,255);
    analogWrite(9,20);
    
    
    delay(100);
    
    analogWrite(11,0);
    analogWrite(4,0);
    analogWrite(9,0);
    analogWrite(10,0);
    digitalWrite(3,0);
    analogWrite(6,0); 
    delay(100);
  }
  
  
    delay(1000);
    digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
    delay(1000);      // se prende y se apaga el segundo led
    digitalWrite(3,LOW);
    digitalWrite(7,LOW);
    delay(1000); 
 for (int x = 1;x <= 4; x++) {
    
   analogWrite(11,20);
    analogWrite(10,255);
    
    analogWrite(3,255);
	analogWrite(6,20);
    
	analogWrite(4,255);
    analogWrite(9,20);
    
    
    delay(100);
    
    analogWrite(11,0);
    analogWrite(4,0);
    analogWrite(9,0);
    analogWrite(10,0);
    digitalWrite(3,0);
    analogWrite(6,0); 
    delay(100);
  }
    delay(1000);
    analogWrite(9,20);
    analogWrite(5,20);
    delay(1000);  // se prende y se apaga el tercer led
    analogWrite(9,0);
    analogWrite(5,0);
    delay(1000);
  for (int x = 1;x <= 4; x++) {
    
      analogWrite(11,20);
    analogWrite(10,255);
    
    analogWrite(3,255);
	analogWrite(6,20);
    
	analogWrite(4,255);
    analogWrite(9,20);
    
    
    delay(100);
    
    analogWrite(11,0);
    analogWrite(4,0);
    analogWrite(9,0);
    analogWrite(10,0);
    digitalWrite(3,0);
    analogWrite(6,0); 
    delay(100);
  }
    delay(1000); 
}