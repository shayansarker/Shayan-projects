#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// OLED
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire);

// Pins
#define MQ135_PIN 32

#define GREEN_LED 19
#define YELLOW_LED 18
#define RED_LED 23

#define BUZZER 25
#define FAN 26

// PWM Channel for Buzzer (ESP32 native tone replacement)
#define BUZZER_CHANNEL 0

int airValue = 0;

String getStatus(int val) {
  if (val < 1000)
    return "Clean";
  else if (val < 2000)
    return "MODERATE";
  else
    return "DANGER!";
}

void setup() {
  Serial.begin(115200);

  // LEDs
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Outputs
  pinMode(FAN, OUTPUT);
  
  // Setup ESP32 PWM for Buzzer
  ledcAttachChannel(BUZZER, 2000, 8, BUZZER_CHANNEL); 

  // OLED Initialization (Uses default ESP32 I2C pins: SDA=21, SCL=22)
  if(!display.begin(0x3C, true)) {
    Serial.println("SH1106 allocation failed");
    for(;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  // Startup Screen
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("AQI SYS");
  display.display();

  delay(2000);
}

void loop() {
  airValue = analogRead(MQ135_PIN);
  Serial.print("AQI Value: ");
  Serial.println(airValue);

  // ===== OLED =====
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Clean Air System");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("AQI:");
  display.println(airValue);

  display.setTextSize(1);
  display.setCursor(0, 52);
  display.println(getStatus(airValue));

  display.display();

  // ===== AIR LOGIC =====

  // GOOD AIR
  if (airValue < 1000) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);

    digitalWrite(FAN, LOW);
    
    ledcWriteTone(BUZZER, 0); // Turn off buzzer
  }

  // MODERATE
  else if (airValue < 2000) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    digitalWrite(FAN, HIGH);

    // Beep pattern using non-blocking delays
    ledcWriteTone(BUZZER, 1000);
    delay(200);
    ledcWriteTone(BUZZER, 0);
  }

  // DANGER
  else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    digitalWrite(FAN, HIGH);

    ledcWriteTone(BUZZER, 2000); // Continuous tone
  }

  delay(500);
}
