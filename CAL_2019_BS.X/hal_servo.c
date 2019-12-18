#include "hal_servo.h"


T_F16 resolution = 0.1170;
int angleMin = 60;
int offset = 4;
T_U8 servoChannel = 1;

//Maxim angle = 130
void Hal_vSetServoAngle(T_F16 angle){
    
    if(angle<85) angle=85;
    if(angle>105) angle=105;
    
        
    T_F16 duty;
    duty = (angle-angleMin)*resolution + offset ; 
    
    
    PWM1_vSetDuty(duty, servoChannel);

}