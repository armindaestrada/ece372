/*
* File:   initLab0.h
* Author:   Arminda Estrada
*
* Created on December 27, 2014, 1:31 PM
*/

#ifndef INITLAB0_H
#define	INITLAB0_H


//Use defines for pin settings to make your code
#define LED4 LATBbits.LATB15    //defining the LEDS
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12

#define FCY 14745600.0
#define TIME_DELAY .1   // setting the delay to be a tenth of a second

#define PRESSED 0       // defintions of switch
#define RELEASED 1

#define OFF 1;          // definition of OFF
#define ON 0;          // defineiton of ON

void initLEDs();        // initializing LEDS
void initSW1();         //initializing the switch
void initTimer1();      // initializing the timer

#endif	/* INITLAB0_H */

