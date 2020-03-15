#include"asw_encoder.h"
#include "rte.h"

void ASW_MoveCentimeter(T_U16 cent)
{
    static T_U16 counterCent=0;
    counterCent += QEI_s16getElapsed();
    if(counterCent>cent)
    {
        RTE_vsetMotorSpeed(0);
    }else{
        RTE_vsetMotorSpeed(20);
    }
}
