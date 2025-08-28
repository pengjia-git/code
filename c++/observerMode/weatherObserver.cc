#include "weatherObserver.h"

int CWeatherObserver::registerWB(CWeatherBoard *p)
{
    mBoards.push_back(p);
    return 0;
}


int CWeatherObserver::unRegisterWB(CWeatherBoard *p)
{
    for(auto it=mBoards.begin();it != mBoards.end();it++)
    {
        if(*it == p)
            mBoards.erase(it);
    }
    return 0;
}

CWeatherObserver::CWeatherObserver() {
  mWeather = new CWeather();
  mWeather->setCB([this]() {
    float temp = this->mWeather->getTemperature();
    float humidity = this->mWeather->getHumidity();
    float pressure = this->mWeather->getPressure();
    for (auto it : mBoards)
      it->updateUi(temp, humidity, pressure);
  });
}


CWeatherObserver::~CWeatherObserver() {
    delete mWeather;
}
