#ifndef _WEATHER_OBSERVER_H_
#define _WEATHER_OBSERVER_H_

#include <list>
#include "weather.h"
#include "weatherBoard.h"

class CWeatherObserver {
public:
  CWeatherObserver();
  ~CWeatherObserver();
  int registerWB(CWeatherBoard *p);
  int unRegisterWB(CWeatherBoard *p);

private:
  //不考虑竞争的问题
  std::list<CWeatherBoard *> mBoards;
  CWeather *mWeather=nullptr;
};

#endif
