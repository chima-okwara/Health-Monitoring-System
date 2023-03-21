#ifndef ___HMS___
#define ___HMS___
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <HCSR04.h>
#include <STM32LowPower.h>
#include <pulseSensor.h>
#include <xlwg.hpp>

#define sleepBtn PB12
#define pulse_sensor PA5
#define led LED_BUILTIN

typedef const uint8_t& pin_t;

extern LiquidCrystal lcd;
extern HCSR04 ultra;
//extern PulseOximeter pox;
extern double dist;
extern double heartRate;
extern PulseSensor pulse;
//extern xlwg idGen;



void hms_init();
void msg(void);
void setup();
void loop();



#endif

