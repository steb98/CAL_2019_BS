/* 
 * File:   hal_battery.h
 * Author: buggy
 *
 * Created on February 19, 2020, 6:42 PM
 */

#ifndef HAL_BATTERY_H
#define	HAL_BATTERY_H
#include "general_types.h"

T_F16 Hal_ValAdc2Tensiune();
int Hal_Tens2Procent(T_F16 tensiune);





#endif	/* HAL_BATTERY_H */

