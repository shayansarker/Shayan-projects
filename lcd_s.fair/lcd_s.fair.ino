#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Scrolling second line
String line2 = "By: Shayan Rafid Tawsif Faizan";

void setup() {

  lcd.init();
  lcd.backlight();

  // Static first line
  lcd.setCursor(0, 0);
  lcd.print(" Team AtmosTech");
}

void loop() {

  String text = line2 + "   ";

  for (int i = 0; i < text.length(); i++) {

    // Clear second line only
    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);
    lcd.print(text.substring(i));

    delay(200);
  }
}