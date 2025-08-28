#ifndef _WEATHER_H_
#define _WEATHER_H_

#include <functional>

class CWeather {
  typedef std::function<void()> WeatherCB;

public:
  CWeather();
  float getTemperature();
  float getHumidity();
  float getPressure();
  void measurementsChanged();
  void setCB(WeatherCB cb);

private:
  float mTemp = 0;
  float mHumidity = 0;
  float mPressure = 0;
  WeatherCB mCB=nullptr;
};
#endif
