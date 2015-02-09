// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:    Arminda Estrada  
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLab0.h"
#include "ledfs.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )



typedef enum stateTypeEnum{
    // Define states by name
    Led4, Led5, Led6, Led7


} stateType;

 volatile stateType currentState;  //set the current state as a statetype
 volatile double timing;            // new variable to counter


int main(void)
{

    // Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();


    // set the initial state to be led 4
    
    currentState = Led4;
    timing = 0;
    


    
    while(1)
    {
        //Use a switch statement to define the behavior based on the state
      switch(currentState){
            
          case Led4:         // turn on Led 4
              turnOnLED(4);
              break;

          case Led5:        // turn on Led 5
              turnOnLED(5);
              break;

          case Led6:         // turn on Led 6
              turnOnLED(6);
              break;

          case Led7:        // turn on Led 7
              turnOnLED(7);
              break;
              
       }
    }
    return 0;
}

void _ISR _T1Interrupt(void){
    //TODO: Put down the timer 1 flag first!
       _T1IF = 0;
// Change states if necessary.
    //Make sure if you use any variables that they are declared volatile!
   timing = timing + 1;  // iterate by adding to the counter by one

   if (_RB5 == RELEASED){ // when the switch is released
       timing = 0;
       TMR1= 0;   //Timer1 register resets
   }


    
}

void _ISR _CNInterrupt(void){
    
    _CNIF = 0;  //FLAG DOWN FIRST

     if ((_RB5 == RELEASED) && timing < 20 ){ // case in which the couter increases
        if (currentState == Led4) currentState = Led5;
        else if (currentState == Led5) currentState = Led6;
        else if (currentState == Led6) currentState = Led7;
        else if (currentState == Led7) currentState = Led4;
        timing = 0;

    }
     else if ((_RB5 == RELEASED ) && timing >= 20) { //case in which the counter is inverted

            if (currentState == Led4) currentState = Led7;
       else if (currentState == Led5) currentState = Led4;
       else if (currentState == Led6) currentState = Led5;
       else if (currentState == Led7) currentState = Led6;
               timing = 0;

   }
}