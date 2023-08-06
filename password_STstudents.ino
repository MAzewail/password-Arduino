#include <Keypad.h>
const byte ROWS=4;
const byte COL=4;
char keys[ROWS][COL]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
}
byte rowPins[ROWS]={2,3,4,5};
byte colPins[COL]={6,7,8,9};
Keypad mykey = Keypad mykey(makeKeymap(keys),rowPins,colPins,ROWS,COL); 
char mypas[4]={'1','2','3','4'};
//char aux[sizeof(mypas)]={0};
byte c=0;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  }
void loop() {
 char key=mykey.getKey();
 if(key){
  if(key!=mypas[c]){
    c=-1;
    lcd.clear();
    lcd.print("     Error      ");
  }
  else if(c>=3){
    lcd.clear();
    lcd.print("     Okay      ");
    c=-1;
  }
  Serial.println(key); 
 c++;
 }
}
