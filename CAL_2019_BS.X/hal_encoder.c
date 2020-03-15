#include "hal_encoder.h"

T_S16 HAL_s16distanceMoved()
{
    T_S16 s16Count;
    s16Count=QEI_s16getElapsed();
    return s16Count/100;
}
