#include <Arduino.h>
#include "LiquidCrystal.h"
#include "Wire.h"
#include "HCSR04.h"
#include "MAX30100_PulseOximeter.h"
#include "STM32LowPower.h"

#define sleep_btn PC13

typedef const uint8_t& pin_t

extern LiquidCrystal lcd;
extern HCSR04 ultra;
extern PulseOximeter pox;
extern float dist;


void hms_init(pin_t lcd_col, pin_t lcd_row, pin_t );

