#include "light_sig.h" 


void vBatteryLow(){
    int static counter = 1;
   
    if(counter%2==0)
    {
        GPIO_u8WritePortPin(PORT_A,10,FALSE);
        return;
    }
   GPIO_u8WritePortPin(PORT_A,10,FALSE);
      
}
