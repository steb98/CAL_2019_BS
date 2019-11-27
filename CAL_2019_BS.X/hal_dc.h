/* 
 * File:   hal_dc.h
 * Author: student
 *
 * Created on November 20, 2019, 6:15 PM
 */

#ifndef HAL_DC_H
#define	HAL_DC_H

#include "mcal_pwm.h"

void Hal_vMotorInit();
void Hal_vSetMotorSpeed(T_F16 speed);
void Hal_vSetMotDir(BOOL dir);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* HAL_DC_H */

