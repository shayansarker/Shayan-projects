/* www.electronicsprojectshub.com */
/*Import following Libraries*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 10, 4);

void setup() 
{

lcd.begin();//Initializing display

lcd.backlight();//To Power ON the back light
//lcd.backlight();// To Power OFF the back light

}

void loop() 
{

lcd.scrollDisplayRight();

lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("By:Shayan Sarker");
delay(700);//Delay used to give a dynamic effect
lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("Class:IV (Sec:A)");




}
