#include "light_sig.h"


void vBatteryLow(){
    int static counter = 1;
    
    if(counter==1 || counter==2 || counter==5 ||counter==6)
    {
       GPIO_u8WritePortPin(PORT_A,10,1);
       
    }
    else
    {
        GPIO_u8WritePortPin(PORT_A,10,0);
        
    }
    counter++;
    if(counter==10)
        counter = 0;
    
    
}
