////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       hms.hpp
//*FILE DESC:       Main source file for hms project.
//*FILE VERSION:    1.2.7e
//*FILE AUTHOR:     Chimaroke Okwara (chima-okwara)
//*LAST MODIFIED:   Friday, 18 October, 2024
//*LICENSE:         GNU LGPL v2.1
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <hms.hpp>
elapsedMillis displayTime;
elapsedSeconds _time = 0;

HCSR04 ultra (TRIG, ECHO);
OneWire oneWire (TEMPSENSE);
DallasTemperature tempSense(&oneWire);
DFRobot_MAX30102 particleSensor;

HardwareSerial sim800l (USART3);
MobileTerm sim (&sim800l);

HX711_ADC LoadCell (DO, SCK);

HMS hms (&ultra, &particleSensor, &LoadCell, &tempSense);

char key { }, userID[7] { }, httpData [50] { };

char keymap [4] [4] =
{
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { '*', '0', '#', 'D' }
};

uint8_t cols [4] = { C4, C3, C2, C1 },
        rows [4] = { R4, R3, R2, R1 };
Keypad keypad (makeKeymap(keymap), rows, cols, 4, 4);

LiquidCrystal_I2C lcd (0x27, 20, 4);

float wt { }, ht { }, temp { }, _bmi { };
int32_t _spo2 { }, _htRt { };


void setup()
{
    uint8_t report = hms.init();

    lcd.clear();

    if(report != SUCCESS)
    {
        switch(report)
        {
            case POXFAIL:
            {
                lcd.home();
                lcd.print("MAX30100 error!");
                delay(1000);
                break;
            }

            case HX711FAIL:
            {
                lcd.home();
                lcd.print("HX711 error!");
                delay(1000);
                break;
            }

            case TEMPSENSEFAIL:
            {
                lcd.home();
                lcd.print("DS18B20 error!");
                delay(1000);
                break;
            }

            default:
            {
                lcd.home();
                lcd.print("Unkn error!");
                delay(1000);
                break;
            }
        }
    }

    else
    {
        lcd.home();
        lcd.print("Sensors Init!");
        delay(1000);
    }

    report = sim.init();
    if(report != SUCCESS)
    {
        lcd.home();
        lcd.print("SIM800L Error!");
        delay(1000);
    }

    else
    {
        lcd.home();
        lcd.print("SIM800L Init!");
        delay(1000);
    }
}

void loop()
{
    _time = 0;
    lcd.clear();
    lcd.home();
    lcd.print("Press button.");
    lcd.setCursor(0, 1);
    lcd.print("A=HMS Fn|B=Chk Data");
    lcd.setCursor(0, 2);
    lcd.print("C=Print values");
    key = '\0';

    while(!key && _time < 10)
    {
        key = keypad.getKey();
        if(key || _time >= 10)
            break;
    }

    if(key)
    {
        _time = 0;
        switch(key)
        {
            case 'A':
            {
                hmsFn();
                break;
            }

            case 'B':
            {
                dataChkFn();
                break;
            }

            case 'C':
            {
                break;
            }

            case 'D':
            {
                break;
            }

            case '#':
            {
                break;
            }

            default:
            {
                break;
            }
        }

    }

    if(_time >= 60)
    {
//        enterSleepMode();
    }
}


