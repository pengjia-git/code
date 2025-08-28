#include "control.h"

CControl::CControl()
{

    for(auto c:mCommands)
        *c=&mNoCommand;
}

void CControl::attachCommand(int index,CCommand *on,CCommand *off)
{
   mCommands[index][0]=on; 
   mCommands[index][1]=off; 
}

void CControl::press(int index,bool onOff)
{
    CCommand *p;
    if(onOff)
        p=mCommands[index][0];
    else
        p=mCommands[index][1];
    p->execute();
}
