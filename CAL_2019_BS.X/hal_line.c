#include "hal_line.h"

/******************************************************
 * Function name:   vSetDirLineFollower
 * Description:     1.Sets pins C0...C5 on PORT_C
 *                    to INPUT/OUTPUT
 *                  2.Don't use in tasks,use getValueLF
 * List of arguments: bDir: select direction:
 *                    bDir = INPUT/OUTPUT
 *****************************************************/
void Hal_vSetDirLineFollower(BOOL bDir){
    T_U8 pin=0;
    
    do
    {
        GPIO_u8SetPortPin(PORT_C,pin,DIGITAL,bDir);
        pin=pin+1;
    } while(pin<6);
}   



/******************************************************
 * Function name:   vWriteLineFollower
 * Description:     1.Apply voltage over pins C0...C5
 *                  2.Don't use in tasks,use getValueLF
 * List of arguments: void
 *****************************************************/
void Hal_vWriteLineFollower(){
//    T_U8 pin=0;
//    Hal_vSetDirLineFollower(OUTPUT);
//    do
//    {
//    GPIO_u8WritePortPin(PORT_C,pin,TRUE);
//    pin=pin+1;
//    }while(pin<6);
    
    Hal_vSetDirLineFollower(INPUT);
    GPIO_vWritePort(PORT_C,63);
    
}
/********************************************************
 * Function name:   u8GetValueLineFollower
 * Description:     1.Returns value on PORT_C pins0...5
 *                    as an T_U8
 * List of arguments: void
 ********************************************************/
T_U8 Hal_u8GetValueLineFollower(){
    T_U8 portValue;
    T_U8 MASK = 63;
    
    Hal_vSetDirLineFollower(OUTPUT);//setare ca output
    Hal_vWriteLineFollower();//scriere
    
    __delay_us(10); 
      
    Hal_vSetDirLineFollower(INPUT);//setare ca input
    
    __delay_us(500);//asteptare reflexie
    
    
    portValue= GPIO_u16ReadPort(PORT_C);//citire reflexie
   
    
     //x=(portValue & 63);
     return (T_U8)(portValue&MASK);
}