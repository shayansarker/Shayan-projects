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
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// OLED Configuration
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire);

// Pin Definitions
#define MQ135_PIN A0

#define GREEN_LED 2
#define YELLOW_LED 3
#define RED_LED 4

#define BUZZER 5
#define FAN 6

int airValue = 0;

// Returns custom status strings based on 10-bit ADC thresholds
String getStatus(int val) {
  if (val < 250)
    return "Good";
  else if (val < 500)
    return "Moderate";
  else
    return "Bad";
}

void setup() {
  Serial.begin(9600);

  // Pin Initializations
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  // OLED Initialization
  if(!display.begin(0x3C, true)) {
    Serial.println(F("SH1106 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  // BRANDED STARTUP SCREEN
  display.setTextSize(2);
  display.setCursor(10, 5);
  display.println(F("ATMOSTECH"));
  
  display.setTextSize(1);
  display.setCursor(10, 30);
  display.println(F("Air Quality System"));
  display.setCursor(10, 45);
  display.println(F("By: AtmosTech"));
  
  display.display();
  delay(3000); // 3-second splash screen display
}

void loop() {
  airValue = analogRead(MQ135_PIN);
  
  // Branded Serial Monitor Stream
  Serial.print(F("[Atmostech] AQI Value: "));
  Serial.println(airValue);

  // ===== OLED LIVE DISPLAY =====
  display.clearDisplay();

  // Header Branding
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Atmostech AQI Monitor"));
  display.drawFastHLine(0, 10, 128, SH110X_WHITE); // Visual divider line

  // AQI Value Readout
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(F("AQI:"));
  display.println(airValue);

  // Status Label
  display.setTextSize(1);
  display.setCursor(0, 42);
  display.print(F("Status: "));
  display.println(getStatus(airValue));

  // Footer Branding
  display.setCursor(0, 56);
  display.println(F("By: AtmosTech"));

  display.display();

  // ===== AIR SAFETY LOGIC =====

  // GOOD AIR
  if (airValue < 250) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);

    digitalWrite(FAN, LOW);
    noTone(BUZZER);
  }

  // MODERATE AIR
  else if (airValue < 500) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    digitalWrite(FAN, HIGH);

    // Alert Beep
    tone(BUZZER, 1000);
    delay(200);
    noTone(BUZZER);
  }

  // BAD AIR
  else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    digitalWrite(FAN, HIGH);
    tone(BUZZER, 2000); // Continuous emergency tone
  }

  delay(500);
}
