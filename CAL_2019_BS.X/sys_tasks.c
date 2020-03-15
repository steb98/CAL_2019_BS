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

#include "asw_battery.h"

#include "hal_onstacle.h"
#include "asw_encoder.h"



void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL ,OUTPUT); //Pentru lumini
    RTE_vMotorInit();//Initializare servo si motor
    RTE_vsetMotorSpeed(30);
    RTE_vSetWheelPosition(CENTER);
    
}

void TASK_1ms()
{
    //RTE_vStopOnLine();
    
}

void TASK_5ms()
{
    
}

void TASK_10ms()
{   
    RTE_vLineFollowingRegulator();
   // RTE_vsetMotorSpeed(20);
    
}

void TASK_100ms()
{   
    //vBatteryLow();
  
    
}

void TASK_500ms()
{ 
    //vBlinkBattery();
    //int a =Hal_Tens2Procent(Hal_ValAdc2Tensiune());
   // ASW_MoveCentimeter(4);
}

void TASK_1000ms()
{
    
   // RTE_vSetWheelPosition(85);
   // RTE_vSetAngle(90);
   // Asw_vCycleAngle();
    
}