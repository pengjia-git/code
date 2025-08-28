#ifndef _WEATHER_BOARD_H_
#define _WEATHER_BOARD_H_

class CWeatherBoard{
    public:
        virtual void updateUi(float temp,float humitity,float pressure) =0;
};

class CStatiticBoard:public CWeatherBoard{
    public:
         void updateUi(float temp,float humitity,float pressure);
};
#endif
