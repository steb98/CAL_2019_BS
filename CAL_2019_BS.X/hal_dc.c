#include "hal_dc.h"
#include "mcal_pwm.h"

void Hal_vMotorInit(){
      GPIO_u8SetPortPin(PORT_A, 9,DIGITAL, OUTPUT);
}

void Hal_vSetMotorSpeed(T_F16 speed){
    PWM1_vSetDuty(speed, 2);
}

void Hal_vSetMotDir(BOOL dir){
    GPIO_u8WritePortPin(PORT_A, 9, dir);
    
}