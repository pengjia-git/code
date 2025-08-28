#include "control.h"
#include "goods.h"

int main()
{
    CLight light;
    CLigntOnCommand lon(light);
    CLigntOffCommand loff(light);

    CControl ctrl;
    ctrl.attachCommand(1,&lon,&loff);

    ctrl.press(1,true);
    ctrl.press(1,false);
    return 0;
}
