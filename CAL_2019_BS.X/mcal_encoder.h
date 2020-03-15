/* 
 * File:   mcal_encoder.h
 * Author: uia94881
 *
 * Created on August 14, 2018, 10:27 AM
 */

#ifndef MCAL_ENCODER_H
#define	MCAL_ENCODER_H
#include "general_types.h"
#include "general.h"

/* QEI(Quadrature Encoder Interface) function declarations */

void QEI_vInit(void);
T_U16 QEI_u16getCount(void);
void QEI_vResetCount(void);
T_S16 QEI_s16getElapsed(void);


#endif	/* MCAL_ENCODER_H */

