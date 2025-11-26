#include <Arduino.h>
#include "pulseSensor.h"

PulseSensor::PulseSensor(const uint8_t& _sensorPin)  :pin(_sensorPin), oldChange(), oldValue(), change()
{

}

void PulseSensor::begin()
{
  pinMode(pin, INPUT_ANALOG);
}

const double& PulseSensor::read()
{
  static double value = analogRead(pin);
  value = alpha * oldValue + (1 - alpha) * value;
  oldValue = value;
  return value;
}

