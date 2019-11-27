/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"

#include "mcal_init.h"
#include "asw_com.h"
#include "asw_move.h"
#include "light_sig.h"
#include "mcal_gpio.h"
#include "rte.h"



void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL ,OUTPUT);
    RTE_vMotorInit();
    
//    RTE_vsetMotorSpeed(1);
}

void TASK_1ms()
{
    
}

void TASK_5ms()
{

}

void TASK_10ms()
{   

}

void TASK_100ms()
{   
    vBatteryLow();
}

void TASK_500ms()
{ 
    
}

void TASK_1000ms()
{
    //Asw_vCycleAngle();
    RTE_vSetAngle(60);
    
}