/* 
 * File:   rte.h
 * Author: student
 *
 * Created on November 20, 2019, 6:32 PM
 */

#ifndef RTE_H
#define	RTE_H

#include "hal_dc.h"
#include "hal_servo.h"
#include "hal_line.h"


#define RTE_vSetMotorDir Hal_vSetMotDir
#define RTE_vsetMotorSpeed Hal_vSetMotorSpeed
#define RTE_vMotorInit Hal_vMotorInit

//Servo motor angle
#define CENTER 90
//Servo motor angle
#define LLEFT 75
//Servo motor angle
#define HLEFT 65
//Servo motor angle
#define LRIGHT 105
//Servo motor angle
#define HRIGHT 115

#define RTE_vLineFollowingRegulator Asw_vLineFollowingRegulator


// Angle to be set between 65 an 115
#define RTE_vSetWheelPosition Hal_vSetServoAngle
//Stop the car on black line
#define RTE_vStopOnLine Asw_vStopOnLine



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* RTE_H */

