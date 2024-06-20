#include <LiquidCrystal_I2C.h>
#include <Wire.h>

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  static LiquidCrystal_I2C lcd(0x27, 20, 4);

  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.print("Railway Horn Controller");

  delay(1000);

  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:

}
