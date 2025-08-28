#include "command.h"
#include <array>

class CControl{
    public:
        CControl();
        void attachCommand(int index,CCommand *on,CCommand *off);
        void press(int index,bool onOff);
    private:
        CCommand* mCommands[10][2];
        CNoCommand mNoCommand;
};
