#include <LiquidCrystal.h>
#include<EEPROM.h>
#include <Keypad.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.autoscroll();
  lcd.print("ABC");
  delay(500);
}
