#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <BH1750.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
BH1750 lightMeter;

void setup()
{
  Wire.begin();
  lightMeter.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("Pomiar");
  lcd.setCursor(3, 1);
  lcd.print("oswietlenia");
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("BH1750");
  delay(2000);
  lcd.clear();
}

void loop()
{
  
  lcd.setCursor(5, 0);
  lcd.print("Pomiar");
  
  float lux = lightMeter.readLightLevel();
  
  lcd.setCursor(0, 1);
  lcd.print("Light:");
  lcd.setCursor(6, 1);
  lcd.print(lux);
  lcd.setCursor(14, 1);
  lcd.print("lx");
  
  delay(200);
  if( lux < 10 )
  {.
    lcd.setCursor(10, 1);
    lcd.print("    ");
  }  else if( lux < 100 )
  {
    lcd.setCursor(11, 1);
    lcd.print("   ");
  }  else if( lux < 1000 )
  {
    lcd.setCursor(12, 1);
    lcd.print("  ");
  }else if( lux < 10000 )
  {
    lcd.setCursor(13, 1);
    lcd.print(" ");
  }
  
}
