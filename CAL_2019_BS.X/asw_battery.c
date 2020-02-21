#include "asw_battery.h"
#include "mcal_gpio.h"

void vBlinkBattery()
{
    int static counter=0;
    int procent = Hal_Tens2Procent(Hal_ValAdc2Tensiune());
    int blink = procent/10;
    
    
    if(counter>2*blink)
    {
        GPIO_u8WritePortPin(PORT_A,10,0);
        if(counter>2*blink+10){
            counter = 0;
        }
        return;
    }
    
    if(counter%2==0)
    {
        GPIO_u8WritePortPin(PORT_A,10,1);
    }
    else
    {
        GPIO_u8WritePortPin(PORT_A,10,0);
    }
    
    
}
