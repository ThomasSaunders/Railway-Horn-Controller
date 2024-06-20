#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Pins for Solenoid control
const int LOW_HORN = 2;
const int HIGH_HORN = 3;

// Pins for High/Low manual control buttons
const int LOW_CONTROL = 4;
const int HIGH_CONTROL = 5;

static LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);

  // Use built in LED for status checking 
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(LOW_HORN, OUTPUT);
  pinMode(HIGH_HORN, OUTPUT);

  pinMode(LOW_CONTROL, INPUT);
  pinMode(HIGH_CONTROL, INPUT);

  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.print("Railway Horn Controller");
}

void loop() {

 manualControl();

 delay(1500);

}

void manualControl() {
  lcd.clear();

  lcd.print("Manual Control");
  lcd.setCursor(1, 0);

  while(true) {
    if(digitalRead(LOW_CONTROL) == HIGH){
      lcd.print("Low Horn");
      digitalWrite(LOW_HORN, HIGH);
    } else if (digitalRead(HIGH_CONTROL) == HIGH) {
      lcd.print("High Horn");
      digitalWrite(HIGH_HORN, HIGH);
    } else {
      lcd.setCursor(0, 0);
      lcd.write("Manual Control");
      lcd.setCursor(1, 0);

      digitalWrite(LOW_HORN, LOW);
      digitalWrite(HIGH_HORN, LOW);
    }

    delay(250);
  }
}