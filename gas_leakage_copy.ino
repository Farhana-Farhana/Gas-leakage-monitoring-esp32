#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 
const int gasPin = 34; 
void setup() { 
  lcd.init(); 
  lcd.backlight(); 
  lcd.setCursor(0, 0); 
  lcd.print("Gas Level:"); 
} 
void loop() { 
  int gasValue = analogRead(gasPin); 
  int percentage = map(gasValue, 0, 4095, 0, 100); 
  lcd.setCursor(0, 1); lcd.print("Value: "); 
  lcd.print(percentage); 
  lcd.print("% "); 
  delay(500); 
}