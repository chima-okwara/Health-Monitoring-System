#ifndef __HMS2025__
#define __HMS2025__

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DFRobot_MAX30102.h>

#define ONE_WIRE_BUS PA1
#include <OneWire.h>
#include <DallasTemperature.h>


#define initsuccess 0x00
#define maxinitfail 0x01

extern LiquidCrystal_I2C lcd;





class HMS
{
    private:
        int8_t initstatus;


        DFRobot_MAX30102 *max30102;
        DallasTemperature *tempSensor;

        int32_t SPO2;
        int8_t SPO2Valid;
        int32_t heartRate;
        int8_t heartRateValid;

        bool max30100init();


    public:
        HMS(DFRobot_MAX30102*, DallasTemperature*);
        int8_t init();
        bool getInitStatus() { return(initstatus); }

        bool readmax30102();
        int32_t getSPO2() { return ( (SPO2Valid) ? SPO2 : 0); }
        int32_t getHeartRate() {return ( (heartRateValid) ? heartRate : 0); }

};

extern HMS hms;



    extern bool maxreadstatus;
    void readmax();
    void displaymax();

#endif
