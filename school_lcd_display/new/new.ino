//By Shayan Sarker
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//By Shayan Sarker
void setup() {
  lcd.backlight();  // Turn on the backlight
}

//By Shayan Sarker
void loop() {
  static const char staticText[] = "By Shayan Sarker";
  static char scrollingText[] = "Grade:IV Section:A(boys)";

  // Display static text on the first line
  lcd.setCursor(0, 0);
  lcd.print(staticText);

  // Scroll the text on the second line
  for (int i = 0; i < strlen(scrollingText) + 16; i++) {
    lcd.setCursor(max(0, 15 - i), 1);
    lcd.print(scrollingText + max(0, i - 16));
    delay(400);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(staticText);
  }
}
//By Shayan Sarker
