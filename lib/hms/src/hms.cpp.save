#include <Arduino.h>
#include "LiquidCrystal.h"
#include "Wire.h"
#include "HCSR04.h"
#include "MAX30100_PulseOximeter.h"
#include "STM32LowPower.h"

void hms_init(void)
{
  pinMode(sleep_btn, INPUT_PULLUP);
  LowPower.begin();
  LowPower.attachInterruptWakeup(PB13, msg, FALLING, IDLE_MODE);
  lcd.begin(20, 4);
  pox.begin();
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
  dist = 0;

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
//  pox.setOnBeatDetectedCallback(onBeatDetected);
}
