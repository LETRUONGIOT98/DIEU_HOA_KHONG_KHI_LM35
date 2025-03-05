#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define khilanh 4
#define hoinong 5
#define tang 2
#define giam 3
#define sensor A0
float set = 36;
void setup() {
  // put your setup code here, to run once:
pinMode(khilanh, OUTPUT);
pinMode(hoinong, OUTPUT);
pinMode(tang, INPUT_PULLUP);
pinMode(giam, INPUT_PULLUP);
lcd.init();                      // initialize the lcd 
 lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(tang) == 0){
  set = set+0.5;
  delay(100);
}
if(digitalRead(giam) == 0){
  set = set-0.5;
  delay(100);
}
float nhietdo = (5.0*analogRead(A0)*100.0/1024.0);
Serial.println(nhietdo);
lcd.setCursor(0, 0);
  lcd.print("NOW:         *C");
  lcd.setCursor(6, 0);
  lcd.print(nhietdo);
  lcd.setCursor(0, 1);
  lcd.print("SET:         *C");
  lcd.setCursor(6, 1);
  lcd.print(set);
  delay(100);
if(nhietdo < set-0.5){
  digitalWrite(hoinong, HIGH);
}
else{digitalWrite(hoinong, LOW);}
if(nhietdo > set+0.5){
  digitalWrite(khilanh, HIGH);
}
else{digitalWrite(khilanh, LOW);}
if(nhietdo == set){
digitalWrite(hoinong, LOW);
digitalWrite(khilanh, LOW);
}
}
