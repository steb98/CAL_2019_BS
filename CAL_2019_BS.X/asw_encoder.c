#include"asw_encoder.h"
#include "rte.h"

void ASW_MoveCentimeter(T_U16 cent)
{
    static T_S16 counterCent=0;
    counterCent =counterCent + (T_F16)QEI_s16getElapsed()/100;

    if(counterCent<0){
        GPIO_u8WritePortPin(PORT_A,10,1);
    }else{
        GPIO_u8WritePortPin(PORT_A,10,0);
    }
    
    if(counterCent>cent)
    {
        RTE_vsetMotorSpeed(0);
        
    }else{
        RTE_vsetMotorSpeed(20);
    }

    
     
}
