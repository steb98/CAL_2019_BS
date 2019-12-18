#include "light_sig.h"

/******************************************************
 * Function name:   vBatteryLow
 * Description:     1.Flashing light on low battery
 *                    To be set on 100ms Task
 * List of arguments: void
 *****************************************************/
void vBatteryLow(){
    int static counter = 1;
    
    if(counter==13)
        counter = 0;
    
    if(counter==1 || counter==2 || counter==5 || counter==6 || counter==9 ||counter==10)
    {
       GPIO_u8WritePortPin(PORT_A,10,1);
       
    }
    else
    {
        GPIO_u8WritePortPin(PORT_A,10,0);
        
    }
    counter++;
    
    
    
}
