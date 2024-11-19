const int PIR =A1;
int sensorvalue = 0;

void setup(){
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT); 
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
digitalWrite(1, LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);

pinMode(PIR,INPUT);
Serial.begin(9600);
}
void detected(){
  int i=2;
  for (i=2;i<13;i++){
    digitalWrite(i,HIGH);
    delay(100);
    }
  }
void loop(){
  int value = digitalRead(PIR);
  sensorvalue = analogRead(A0);
  if (sensorvalue<900){
    if (value == HIGH)
     detected();
     }
     else{
      int i = 0;
      for (i=2;i<=13;i++){
        digitalWrite(i,LOW);
        delay(200);
        }
      
      }
}









  
  
  
