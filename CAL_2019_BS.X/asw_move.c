#include "asw_move.h"
#include "general_types.h"
#define REF 12
#define Kp 6

T_S8 error;
T_S8 proportionalP;
static T_U8 lineValue;
static BOOL reversing=FALSE;
static T_F16 setAngle;
void Asw_vLineFollowingRegulator(){
    static int counter=0;
    lineValue = Hal_u8GetValueLineFollower();
    counter++;
    if(lineValue==0 && counter==3)
    {
        reversing=TRUE;
        counter=0;
    }
    if(counter==3)
    {
        counter=0;
    }
    
    if(reversing==FALSE)
    {
        RTE_vsetMotorSpeed(30);
        RTE_vSetMotorDir(FALSE);
        
        //calcul grad eroare(deviatie de la pozitia de echilibru)
        switch(lineValue){
            case 0b00011000:
                error = 0;
                break;
                
            case 0b00001000:
                error = 1;
                break;
            case 0b00001100:
                error = 2;
                break;
            case 0b00000100:
                error = 3;
                break;
                
            case 0b00000110:
                error = 4;
                break;
            case 0b00000010:
                error = 5;
                break;
                
            case 0b00010000:
                error = -1;
                break;
            case 0b00110000:
                error = -2;
                break;
            case 0b00100000:
                error = -3;
                break;
                
            case 0b01100000:
                error = -4;
                break;
            case 0b01000000:
                error = -5;
                break;
                
            default:
                
                break;
                
                
        }
        
    }else{
        //out of line procedure
        
        if(setAngle>CENTER){
            //steering left in reverse
            RTE_vSetMotorDir(TRUE);
            RTE_vsetMotorSpeed(25);
            RTE_vSetWheelPosition(HLEFT);
            
        }else{
            //steering right in reverse
            RTE_vSetMotorDir(TRUE);
            RTE_vsetMotorSpeed(25);
            RTE_vSetWheelPosition(HRIGHT);
        }
        lineValue = Hal_u8GetValueLineFollower();
        if(lineValue==0b00001000)
        {
            reversing=FALSE;
        }
        
        
    }
    
    proportionalP =Kp*error;//calcul element proportional(P)
    
    if(reversing==FALSE){
    setAngle=CENTER+proportionalP;
    RTE_vSetWheelPosition(setAngle);//determinare unghi
    }
    
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
