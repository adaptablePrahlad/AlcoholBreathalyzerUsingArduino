#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 
int pinForLed = 10;
int pinForSensor = A0;
int val;
 
void setup()
{
Serial.begin(9600);
lcd.begin(16,2);
pinMode(pinForLed,OUTPUT);
}
void loop() 
{
int Value = analogRead(pinForSensor);
val = analogRead(A0);
lcd.print("Alcohol Level is :-");
lcd.print(val);
Serial.print(val);
if (val > 200) 
 
{
    digitalWrite(pinForLed,HIGH);
     lcd.setCursor(0, 2);
     lcd.print("Alert! You're Drunk");
    Serial.print ("Alert");   
  } 
  else {
    digitalWrite(pinForLed,LOW); 
      lcd.setCursor(0, 2);
      lcd.print("No Worries..!");
    Serial.print("Normal");
  }
 
delay(500);
lcd.clear();
}