//By Shayan Sarker
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

//By Shayan Sarker
void setup() {
  lcd.backlight();  
}

//By Shayan Sarker
void loop() {
  static const char staticText[] = "messi";
  static char scrollingText[] = "suiiiiiiiCR7";


  lcd.setCursor(0, 0);
  lcd.print(staticText);


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
