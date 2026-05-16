/*
===================================================================
               README: AIR QUALITY MONITORING SYSTEM
===================================================================
  Developed By : ShaynShark

  LICENSE:     MIT License

  Target Board : Arduino Uno (ATmega328P)
===================================================================
*/

// //By:ShaynShark for Atmostech

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Configuration
const uint8_t LCD_ADDR = 0x27;
const uint8_t LCD_COLS = 16;
const uint8_t LCD_ROWS = 2;

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

// Scrolling configuration
const String SCROLL_TEXT = "By: Shayan Rafid Tawsif Faizan";
const unsigned long SCROLL_SPEED = 250; // Milliseconds per step

void setup() {
  lcd.init();
  lcd.backlight();

  // shaynshark hardware initialization splash
  lcd.setCursor(0, 0);
  lcd.print("Atmosech sys..");
  delay(1000);
  lcd.clear();

  // Print static team header
  lcd.setCursor(0, 0);
  lcd.print(" Team AtmosTech");
}

void loop() {
  // Pad text with spaces so it clears nicely at the end
  String paddedText = SCROLL_TEXT + "                "; 
  int textLength = paddedText.length();

  for (int i = 0; i < textLength - LCD_COLS + 1; i++) {
    lcd.setCursor(0, 1);
    
    // Extract and print exactly 16 characters to prevent screen flicker
    String currentFrame = paddedText.substring(i, i + LCD_COLS);
    lcd.print(currentFrame);
    
    delay(SCROLL_SPEED);
  }
}
