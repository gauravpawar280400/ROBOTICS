#include <Keypad.h>         // we have to include 3 libraries
#include <Servo.h>
#include <LiquidCrystal.h>

#define Password_length 5

Servo myservo;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); //define which is connected of lcd to analog pin
int pos = 0;

char Data[Password_length];
char Master[Password_length] = "1234";  // giving the password
byte data_count = 0, master_count = 0;   // how many time the data is been save and how many time the data is given to computer


/*bool   BOOL(BOOLEAN) GIVES US TRUE AND FALSE IT DOESNOT SHOWS 1 AND 0.

True= HIGH = 1
False= LOW = 0

*/

bool Pass_is_good;
bool door = false;
char customKey;

const byte ROWS = 4; // IN THS WE HAVE TO DEFINE ARDUINO ALL THE KEYS AND ROWS AND COLUMNS BY WRITING IT.
const byte COLS = 4;
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  }

  ;byte rowPins[ROWS] = {'0','1','2','3'};  // this are pin no. which are connected to arduino to keypads
  byte colsPins[COLS] = {'4','5','6','7'};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colsPins, ROWS, COLS);

  void setup(){
    myservo.attached(9,2000,2400);
    ServoClose();  // $$$$$$$$$$$$$$$$$$$$$$$
    lcd.begin(16,2);
    lcd.print("Protected DOOR");
    loading("loading"); // this is not a function so we have to create it
    lcd.clear();
    }

 void loop(){
  if (door == true){
    customKey = customKey.getKey();
    if (customKey == '#'){
      lcd.clear();
      ServoClose();  //this is not a function this is one we defined or user defined funtion . SO THERE IS THREE TYPE OF FUNCTION 1)BUILD IN FUNCTION,2) THE FUNCTION WHICH CAN BE IMPORT FROM LIB. 3). USER DEFINED FUNCTION  
      lcd.print("Door is Closed");
      delay(3000);
      door = false;
      }
      }
  else
  Open();
  
  }
 void loading(char msg[]){
  lcd.set(0,1);
  lcd.print(msg);
  
  for(int i =0; i< 9;i++){
    dlay(1000);
    lcd.print(".");
    } 
  }

 void clearData(){
  while(data_count !=0);{  //! this means not equal to. 
  Data[data_count--] = 0;
  
  }
  return;
 }

void ServoClose(){      // for motor
  for(pos = 90; pos>=0;pos -=10){
    myservo.write(pos);}
  }


void ServoOpen(){    // for motor
  for(pos= 0,pos<=90,pos +=10){
    myservo.write(pos);
    }
  }
void open(){
  lcd.setCursor(0,0);
  lcd.print("Enter password");
  


  customKey=customKeypad.getKey();
  if(customKey){
    Data[data_count]=cstomKey;
    lcd.setCursor(data_count1);
    lcd.print(data[data_count]);
    data_count++;
    }

    if(data_count == Password_lenght -1);{
    if(!strcmp(Data,Master));   //???????????????????????
    {
      lcd.clear();
      ServoOpen()
      lcd.print("door is open");
      door = true
      delay(5000);
      loading("waiting");
      lcd.clear();
      lcd.print("time is over");
      delay(1000);
      ServoClose;
      door=false;
       }
      else
      {
        lcd.clear();
        lcd.print("wrong Password");
        door = false;
        } 
      delay(1000);
      lcd.clear();
      clear.Data();

}
