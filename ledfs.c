/***********************************************************/
// function for LEDs
// File: ledf.c
// Author: Arminda Estrada
//
/************************************************************/


#include "p24fj64ga002.h"
#include "initLab0.h"
#include "ledfs.h"
void turnOnLED(int Led){
    if(Led == 4){
        LED4 = ON;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = OFF;
    }
    else if(Led == 5){
        LED4 = OFF;
        LED5 = ON;
        LED6 = OFF;
        LED7 = OFF;
    }
    else if(Led == 6){
        LED4 = OFF;
        LED5 = OFF;
        LED6 = ON;
        LED7 = OFF;
    }
    else if(Led == 7){
        LED4 = OFF;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = ON;
    }
}
