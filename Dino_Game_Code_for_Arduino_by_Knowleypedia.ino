/*
#T-Rex Run!
#Chrome Dino Game!!
#NO INTERNET GAME!!!
#Knowleypedia
#For more project related video Sbscribe my YouTube Channel
#Youtube channel link http://www.youtube.com/c/Knowleypedia
*/
#include <Servo.h>
#define threshold 150
#define unpress_angle 70 
#define press_angle 36


Servo myservo;
bool trig=true;

void setup() {          
  myservo.attach(9);
myservo.write(unpress_angle);   
}

void loop() {

 myservo.write(unpress_angle);/
 delay(1);
 if(analogRead(A0)< threshold)
 {
  
      myservo.write(press_angle);
    delay(100 );
                      
 }                     
}
