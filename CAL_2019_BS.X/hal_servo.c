#include "hal_servo.h"


T_F16 resolution = 0.04375;
int angleMin = 10;
int offset = 4;
T_U8 servoChannel = 1;

//Maxim angle = 130
void Hal_vSetServoAngle(T_F16 angle){
    PWM1_vInit();
    T_F16 duty;
    duty = (angle-angleMin)*resolution + offset ; 
    
    if(duty>6.15) duty = 6.15;  //limitare la dreapta
    if(duty<8.81) duty = 8.81;    //limitare la stg
    
    PWM1_vSetDuty(duty, servoChannel);

}