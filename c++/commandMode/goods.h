#include <iostream>

#include "command.h"

class CLight{
    public:
        void on(){std::cout<<"light on"<<std::endl;}
        void off(){std::cout<<"light off"<<std::endl;}
};


class CFan{
    public:
        void on(){std::cout<<"fan on"<<std::endl;}
        void off(){std::cout<<"fan off"<<std::endl;}
};


class CLigntOnCommand:public CCommand{
    public:
        CLigntOnCommand(CLight & light):mLight(light){}
        int execute(){mLight.on();return 0;}
        int undo(){mLight.off();return 0;}
    private:
        CLight &mLight;
};


class CLigntOffCommand:public CCommand{
    public:
        CLigntOffCommand(CLight & light):mLight(light){}
        int execute(){mLight.off();return 0;}
        int undo(){mLight.on();return 0;}
    private:
        CLight &mLight;
};
