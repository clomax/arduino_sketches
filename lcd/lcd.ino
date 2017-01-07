#include <LiquidCrystal.h> 

LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);

void setup() 
{
	lcd.begin(16,2);
	lcd.setCursor(0,2);
	lcd.print("Arduino, bitches!");	
}

void loop()
{

}
