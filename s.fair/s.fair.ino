//By:Shayan Sarker
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 5; 
const int echoPin = 6; 

const int suiii = 13;

const int servoPin = 9; 

Servo myServo; 

void setup() {
    pinMode(suiii, OUTPUT);
  lcd.backlight();  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin); 
}

void loop() {


    static const char staticText[] = "No People DYING";
  static char scrollingText[] = "By: Shayan, Nawaf, Rafid, Raufur";

  
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
  
  long duration, distance;
  digitalWrite(suiii, HIGH);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  

  duration = pulseIn(echoPin, HIGH);
  
  
  distance = duration * 0.034 / 2;
  
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
 
  if (distance < 20) {
   
    myServo.write(90); 
  } else {

    myServo.write(0); 
  }
  
  delay(1000); 
}
//By:Shayan Sarker


