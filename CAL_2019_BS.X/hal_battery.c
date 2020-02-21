#include "hal_battery.h"
#include "mcal_adc.h"
T_F16 Hal_ValAdc2Tensiune()
{
    T_F16 suma=0;
    T_U16 valADC=0.0;
    T_F16 tensCitita=0.0;
    int i;
     
    for(i=0;i<5;i++)
    {
        valADC=ADC_u16Read(0);
        tensCitita=3.07*tensCitita/4095;
        
        suma+=tensCitita;
    }
    return suma/5;
    
}
int Hal_Tens2Procent(T_F16 tensiune){
    T_F16 rezolutie;
    if(tensiune<=8.7 && tensiune>=7)
    {
        rezolutie=(100-20)/(8.4-7);
        return (8.4-7)*rezolutie+20;
    }else
    if(tensiune<7 && tensiune>=6.5)
    {
        rezolutie=(20-10)/(7-6.5);
        return (7-6.5)*rezolutie+10;
    }else
    if(tensiune<6.5 && tensiune>=6)
    {
        rezolutie=(10-0)/(6.5-6);
        return (6.5-6)*rezolutie+0;
    }
    
    return 0;
    
}

//ADC_u16Read
