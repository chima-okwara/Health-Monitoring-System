#include <Arduino.h>
#include "hms.hpp"
#include "LiquidCrystal.h"
#include "Wire.h"
#include "HCSR04.h"
#include "MAX30100_PulseOximeter.h"
#include "STM32LowPower.h"

#define REPORTING_PERIOD_MS  1000

void setup();
void loop();
void msg();

LiquidCrystal lcd (PC14, PC15, PA0, PA1, PA2, PA3);

HCSR04 ultra (PB0, PB1);

PulseOximeter pox;

float dist;



void setup()
{
  hms_init();
}


void loop()
{
  delay(1000);
  dist = ultra.getDistcm();
  lcd.setCursor(0, 0);
  lcd.print("Distance:                  ");
  lcd.setCursor(10, 0);
  lcd.print(dist);
  delay(1000);

  lcd.setCursor(0, 1);
  pox.update();
  lcd.print("Heart Rate:                     ");
  lcd.setCursor(11, 1);
  lcd.print(pox.getHeartRate());
  delay(1000);


  lcd.clear();
  delay(500);
  lcd.home();
  lcd.print("Going to sleep...");
  delay(2000);

  lcd.clear();

  LowPower.idle();
}

void msg()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Just woke up.");
}


