#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <HCSR04.h>
#include <STM32LowPower.h>
#include "hms.hpp"
#include <pulseSensor.h>

void setup();
void loop();
double heartRate (0.0), dist (0.0);

PulseSensor pulse(pulse_sensor);

LiquidCrystal lcd (PC14, PC15, PA0, PA1, PA2, PA3);

HCSR04 ultra (PB0, PB1);
//PulseOximeter pox;

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
  heartRate = pulse.read();

  lcd.print("Heart Rate:                     ");
  lcd.setCursor(11, 1);
  lcd.print(heartRate);
  delay(1000);


  lcd.clear();
  delay(500);
  lcd.home();
  lcd.print("Going to sleep...");
  delay(2000);

  lcd.clear();

  LowPower.idle();
}
