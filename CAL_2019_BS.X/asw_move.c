#include "asw_move.h"
#include "general_types.h"

T_F16 angle = 60;
int dir = 1;

void Asw_vCycleAngle()
{
    switch (dir)
    {

        case 1:
            RTE_vSetAngle(angle);
            
            if(angle >= 130)
            {
                dir = 0;
                break;
            }
            angle=angle+30;
            break;
        case 0:
            RTE_vSetAngle(angle);
            
            if(angle <= 10)
            {
                dir = 1;
                break;
            }
            angle=angle+-30;
            break;
            break;
          
        default:
            break;

    }
            
    //RTE_vSetAngle(angle);
      
}
