//By:Shayan Sarker
#include <Servo.h>



const int trigPin = 5; 
const int echoPin = 6; 

const int suiii = 13;

const int servoPin = 9;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  long duration, distance;
  digitalWrite(suiii, HIGH);

  
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //By:Shayan Sarker

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
  
  delay(1500); 
}
//By:Shayan Sarker
