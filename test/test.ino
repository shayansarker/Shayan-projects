#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address, columns, rows

const int potPin = A0;
const int targetNumber = 17;
const int targetNumber =  26;
const int targetNumber = 56;
const int targetNumber = 42;
const int targetNumber = 35;
const int targetNumber = 41;
const int targetNumber = 93;
const int targetNumber = 123; // You can change this to any number you like


void setup() {
  lcd.print("Guess the Number");
  lcd.setCursor(0, 1);
  lcd.print("Use Potentiometer");
  delay(2000);
  lcd.clear();
  randomSeed(analogRead(0));
}

void loop() {
  int sensorValue = analogRead(potPin);
  int guess = map(sensorValue, 0, 1023, 1, 100);

  lcd.clear();
  lcd.print("Your guess: ");
  lcd.print(guess);

  if (guess == targetNumber) {
    lcd.setCursor(0, 1);
    lcd.print("Congratulations!");
    delay(2000);
    lcd.clear();
    lcd.print("Play again...");
    delay(1000);

  } else {
    lcd.setCursor(0, 1);
    lcd.print("Try again...");
    delay(500);
  }
}
