   #include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 16, 2);
int run;
int buttonPin;

void setup()
{
   run = 0; //starts stopped
   buttonPin = 7; //whatever pin your button is plugged into

   pinMode(buttonPin, INPUT_PULLUP);

      lcd.begin();//Initializing display

   lcd.backlight();//To Power ON the back light
}

void loop()
{
   //code you always run here; you can leave this section blank if you want the entire program to stop and start, or add code here if you want it to always run

   //check button press here and if it is pressed then toggle run variable between 0 and 255; REQUIRED!
   if(digitalRead(buttonPin) == LOW) //funcitons based off of button pulling input pin LOW
   {
      if(run == 0)
      {
          run = 255;
      }
      else
      {
          run = 0;
      }
   }

   if(run > 0)
   {
      //code you only run if button was pressed, stops running when button pressed again, so forth...
          lcd.setCursor(0,0); //Defining positon to write from first row,first column .
    lcd.print("starting_program"); //You can write 16 Characters per line .
    delay(10000);//Delay used to give a dynamic effect
    lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
    lcd.print("nasa_hacked_]^");
   }
}