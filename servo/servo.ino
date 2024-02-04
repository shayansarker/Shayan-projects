#include <Servo.h>

Servo myservo;

int i;


void setup() {
     myservo.attach(10);
}


void loop() {

     myservo.write(0);
    delay(1):
     myservo.write(90);
    delay(500);
     myservo.write(180);
    delay(900);
    for(i=180;i>0;i=i -5);
    {
      myservo.write(i);
      delay(100);
    }

}