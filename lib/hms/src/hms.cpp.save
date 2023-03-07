#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <HCSR04.h>
#include <STM32LowPower.h>
#include "hms.hpp"
#include <pulseSensor.h>

PulseSensor pulse(pulse_sensor);

LiquidCrystal lcd (PC14, PC15, PA0, PA1, PA2, PA3);

HCSR04 ultra (PB0, PB1);


void wakeUpAction()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Just woke up.");
}


void hms_init(void)
{
  pinMode(sleepBtn, INPUT_PULLUP);
  LowPower.begin();
  LowPower.attachInterruptWakeup(sleepBtn, wakeUpAction, RISING, IDLE_MODE);
  lcd.begin(20, 4);
  pulse.begin();
  lcd.clear();
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("   Eichen (R)    ");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print(" Health Monitoring  ");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("      System        ");
  delay(500);
  lcd.setCursor(0, 2);
  lcd.print("with IoT integration");
  delay(500);
  lcd.setCursor(0, 3);
  lcd.print(" ");
  delay(1500);
  lcd.clear();
}


