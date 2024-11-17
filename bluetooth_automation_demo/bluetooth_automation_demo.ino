char data =0;
 #define led 10
 #define fan 9
 void setup(){
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  }

 void loop(){
  if (Serial.available()>0){
    data=Serial.read();
    Serial.print(data);
    if(data == '1')
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
  }
      else if (data == '0'){
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
    }
    delay(10);
  }
