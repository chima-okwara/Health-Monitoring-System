////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       hms.hpp
//*FILE DESC:       Header source file for hms library.
//*FILE VERSION:    1.2.7e
//*FILE AUTHOR:     Chimaroke Okwara (chima-okwara)
//*LAST MODIFIED:   Friday, 18 October, 2024
//*LICENSE:         GNU LGPL v2.1
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___HMS___
#define ___HMS___
#include <Arduino.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <HCSR04.h>
#include <HX711_ADC.h>
#include <DFRobot_MAX30102.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <HardwareTimer.h>
#include <WString.h>
#include <elapsedMillis.h>
#include <eichen_lib.h>
//#include <STM32LowPower.h>
#include <../../../include/hms_defs.h>

//GPIO Pins:
#define sleepBtn
#define DO PB5
#define SCK PB4
#define led LED_BUILTIN
#define TEMPSENSE PA1
#define ECHO PA4
#define TRIG PA5
#define SW2 PA6
#define SW1 PA7
#define SIMRST PB1
#define SIMRX PB10
#define SIMTX PB11
#define R1 PA11
#define R2 PA10
#define R3 PA9
#define R4 PA8
#define C1 PB15
#define C2 PB14
#define C3 PB13
#define C4 PB12


//Return values
#define SUCCESS 0
#define POXFAIL 1
#define HX711FAIL 2
#define TEMPSENSEFAIL 3
#define SIMFAIL 4

//Constants:
#define REF_HEIGHT 204.2
#define AVG 10
#define SIM_DELAY 5000

#define BLANK2 "  "
#define BLANK3 "   "
#define CLEAR "                    "


#define PORT 80
#define MTN_APN "web.gprs.mtnnigeria.et"
#define AIRTEL_APN "internet.gprs.airtel.g"
#define CONTENT_TYPE "application/x-www-form-urlencoded"
#define TEXT_CONTENT_TYPE "text/plain"


#ifndef SERVER
    #define SERVER "www.norahlinks.com"
#endif // SERVER

#ifndef APIKEY
    #define APIKEY "NL_HHMS_076"
#endif // APIKEY

//Attributes:
typedef const uint8_t& pin_t;

extern elapsedMillis displayTime, runTime;
extern elapsedSeconds _time;
extern OneWire oneWire;
extern LiquidCrystal_I2C lcd;
extern Keypad keypad;

extern char httpData[50];
extern HardwareSerial sim800l;

extern char userID[7];
extern char key;

extern float wt, ht, temp, _bmi;
extern int32_t _spo2, _htRt;

extern DFRobot_MAX30102 particleSensor;

class HMS
{
public:
    //Constructors:
    HMS() = default;
    HMS(HCSR04*, DFRobot_MAX30102*, HX711_ADC*, DallasTemperature*);

    uint8_t init();
    bool measureHeight();
    bool measureWeight();
    bool measureHeartRate();
//    bool measureSpo2();
    bool measureTemperature();

    const float &getWeight() { return (weight); }
    const float &getHeight() { return (height); }
    const float &getTemperature() { return (temperature); }
    const float &getBmi() { return (bmi = (weight) / (height * height)); }
    //    Underweight: BMI less than 18.5, Normal weight: BMI between 18.5 and 24.9;    Overweight: BMI between 25.0 and 29.9     Obese: BMI 30.0 or higher

    int32_t getSpo2() { return (spo2); }
    int32_t getHeartRate() { return (heartRate); }



private:
    //Modules:
    HCSR04 *ultrasonic;
    DFRobot_MAX30102 *max30102;

    int32_t spo2;
    int8_t SPO2Valid;
    int32_t heartRate;
    int8_t heartRateValid;

    HX711_ADC *scale;
    DallasTemperature *tempSensor;


    //Variables:
    float weight, height, temperature, bmi;

    //Methods:
//    void updateMovingAverage(int&);
    const float &getAvgWt(uint8_t samples);
    const float &getAvgHt(uint8_t samples);
};


class MobileTerm
{
public:
    MobileTerm () = default;
    MobileTerm (HardwareSerial*);

    uint8_t init(void);
    bool sendHTTPData(void);
    bool enableGPRS(const bool&);
    bool checkDataBalance();

    const String& getReply() { return (reply); }

private:
    bool checkReply(const char*);
    void formatHTTPData();
    bool startGPRS();
    bool endGPRS();
    bool dialNum(String);

    String getUSSDCode();
    String getPhoneNum();

    String command, reply;
    HardwareSerial* _sim;
    char httpData[250];
};

extern HMS hms;
extern MobileTerm sim;

void setup();
void loop();


void lcdInit();
//void enterSleepMode();
//void wakeUpAction();
void displayWt(const float&);
void displayHt(const float&);
void displayBPM(const int&);
void displaySpo2(const int&);
void displayTemp(const float&);
void displayBMI(const float&);


void hmsFn();
void dataChkFn();








#endif

