#include <hms.h>
#include <Keypad.h>

String userID;
int32_t heartRate;
int32_t spo2;
int32_t temperature;
int32_t height;
int32_t weight;
int32_t bmi;

int32_t postResponse;




DFRobot_MAX30102 particleSensor;
LiquidCrystal_I2C lcd(0x27, 20, 4);  // Adjust address if needed
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

HMS hms(&particleSensor);
// Variables for sensor data

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

uint8_t rowPins[ROWS] = {PA8, PA9, PA10, PA11}; //connect to the row pinouts of the keypad
uint8_t colPins[COLS] = {PB12, PB13, PB14, PB15}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Initializing sensor");


  // Initialize LCD
  char c;
  lcd.home();
  c = customKeypad.waitForKey();
  lcd.print(c);

  while(c != 'D')
  {
    c = customKeypad.waitForKey();
    lcd.print(c);
  }

    if(hms.init() != initsuccess)
    {

        if(hms.getInitStatus() == maxinitfail)
        {

            lcd.clear();
            lcd.home();
            lcd.print("Max30102 Error!");
            lcd.setCursor(0, 1);
            lcd.print("Reset MCU");
            while(1);
        }
    }

  lcd.clear();
  lcd.print("Place finger on");
  lcd.setCursor(0, 1);
  lcd.print("sensor firmly");
  delay(2000);
}

void loop()
{
  // Get sensor data
    readmax();
    displaymax();



  // Delay between readings
  delay(500);  // 3-second delay matches sensor processing time
}
