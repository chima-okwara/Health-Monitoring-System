#include <Arduino.h>
#include <hms.h>

bool maxreadstatus = false;

HMS::HMS(DFRobot_MAX30102* maxsensor, DallasTemperature* tsens) : max30102(maxsensor), tempSensor(tsens)
{
    SPO2 = 0;
    SPO2Valid = 0;
    heartRate = 0;
    heartRateValid = 0;
}

bool HMS::max30100init()
{
    if (!max30102->begin())
  {
    return (false);
  }

  // Configure sensor
  max30102->sensorConfiguration(
    /*ledBrightness=*/100,
    /*sampleAverage=*/SAMPLEAVG_8,
    /*ledMode=*/MODE_MULTILED,
    /*sampleRate=*/SAMPLERATE_800,
    /*pulseWidth=*/PULSEWIDTH_215,
    /*adcRange=*/ADCRANGE_16384
  );

  Wire.setClock(400000);  // Set I2C to 400kHz (faster than default)

  return true;
}

int8_t HMS::init()
{
    int8_t maxinit = ( max30100init() ? initsuccess : maxinitfail);

    initstatus = maxinit;


    return initstatus;
}


bool HMS::readmax30102()
{
    // Get sensor data
    max30102->heartrateAndOxygenSaturation(&SPO2, &SPO2Valid, &heartRate, &heartRateValid);

    if(!heartRateValid || !SPO2Valid)
        return false;

    else
        return true;
}

void readmax()
{
    maxreadstatus = hms.readmax30102();
}

void displaymax()
{
  if(maxreadstatus)
  {
    lcd.setCursor(0, 0);
    lcd.print("No valid reading");
    lcd.setCursor(0, 1);
    lcd.print("Adjust finger");
    lcd.setCursor(0, 2);
    lcd.print("or press harder");
  }

  // Display results
    else
    {
        lcd.clear();


        lcd.setCursor(0, 0);
        lcd.print("BPM: ");
        lcd.print(hms.getHeartRate());

        lcd.setCursor(0, 1);
        lcd.print("SPO2: ");
        lcd.print(hms.getSPO2());
        lcd.print("%");
    }
}
