#ifndef __DUCK_FLY_H__
#define __DUCK_FLY_H__

class CFlyBehavior{
    public:
        virtual void fly() =0;
};



class CFlyWithWing:public CFlyBehavior{
    public:
        void fly();
};


class CNoFly:public CFlyBehavior{
    public:
        void fly();
};
#endif
