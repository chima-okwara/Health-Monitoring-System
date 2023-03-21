#ifndef __PLS___
#define __PLS___
#define alpha 0.75

#include <Arduino.h>
class PulseSensor
{
public:
  PulseSensor(const uint8_t& _sensorPin);
  PulseSensor() = default;
  void begin();
  const double& read();

private:
  const uint8_t& pin;
  double oldChange;
  double oldValue;
  double change;


};
#endif // __PLS___

