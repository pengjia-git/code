#include "weather.h"
#include <iostream>
#include <thread>
#include <unistd.h>

CWeather::CWeather() {
  std::thread([this]() {
    while (1) {
      mTemp += 0.01;
      mHumidity += 0.01;
      mPressure += 0.01;
      measurementsChanged();
      sleep(1);
    }
  }).detach();
}

float CWeather::getTemperature() { return mTemp; }
float CWeather::getHumidity() { return mHumidity; }
float CWeather::getPressure() { return mPressure; }
void CWeather::measurementsChanged() {
  std::cout << "measurementsChanged be called" << std::endl;
  if(mCB != nullptr)
      mCB();
}

void CWeather::setCB(WeatherCB cb) { mCB = cb; }
