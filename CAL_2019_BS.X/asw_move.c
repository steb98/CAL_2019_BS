#include "asw_move.h"
#include "general_types.h"
#define REF 12
#define Kp 6

T_S8 error;
T_S8 proportionalP;
T_U8 lineValue;
void Asw_vLineFollowingRegulator(){
    
    lineValue = Hal_u8GetValueLineFollower();
    
    //calcul grad eroare(deviatie de la pozitia de echilibru)
    switch(lineValue){
        case 12:
            error = 0;
            break;
        
        case 4:
            error = 1;
            break;
        case 6:
            error = 2;
            break;
        case 2:
            error = 3;
            break;
        case 3:
            error = 4;
            break;
        case 1:
            error = 5;
            break;
        case 8:
            error = -1;
            break;
        case 24:
            error = -2;
            break;
        case 16:
            error = -3;
            break;
        case 48:
            error = -4;
            break;
        case 32:
            error = -5;
            break;
        default:
            
            break;
        
        
    }
     
  proportionalP =Kp*error;//calcul element proportional(P)
  

  RTE_vSetWheelPosition(CENTER + proportionalP);//determinare unghi
    
}


T_U8 angle = 65;
int dir = 1;
T_U8 pas = 10;
/*
 * Cycle the wheels position
 */
void Asw_vCycleAngle()
{
    switch (dir)
    {

        case 1:
            RTE_vSetWheelPosition(angle);
            if(angle >= 105)
            {
                dir = 0;
                break;
            }
            angle=angle+pas;
            break;
            
        case 0:
            RTE_vSetWheelPosition(angle);
            if(angle <= 85)
            {
                dir = 1;
                break;
            }
            angle=angle-pas;
            break;
          
        default:
            break;

    }
            
      
}

/*
 * Stop the car when encountering 
 * a black line
 */
void Asw_vStopOnLine(){
    T_U8 line = Hal_u8GetValueLineFollower();
    if(line!=0)
    {
        Hal_vSetMotorSpeed(0);
    }
    
}
