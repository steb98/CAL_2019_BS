#include "hal_onstacle.h"

BOOL hal_checkObstacle()
{
    if(interrupt_obstacleFlag == 1)
    {
        GPIO_u8WritePortPin(PORT_A,10,1);
        return TRUE;
    }else{
        GPIO_u8WritePortPin(PORT_A,10,0);
        return FALSE;
    }
}
