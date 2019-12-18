/* 
 * File:   hal_line.h
 * Author: Buggy
 *
 * Created on December 8, 2019, 5:46 PM
 */

#include "general_types.h"
#include "mcal_gpio.h"

#ifndef HAL_LINE_H
#define	HAL_LINE_H


void Hal_vSetDirLineFollower(BOOL bDir);
void Hal_vWriteLineFollower();
T_U8 Hal_u8GetValueLineFollower();


#endif	/* HAL_LINE_H */

