/*
* File:   initLab0.c
* Author:   Arminda Estrada
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

void initLEDs(){
    //Initialize the pin connected to the LEDs as outputs

             _TRISB15 = ON;
             _TRISB14 = ON;
             _TRISB13 = ON;
             _TRISB12 = ON;


    

    //TODO: Turn each LED OF
         LED4 = OFF;
         LED5 = OFF;
         LED6 = OFF;
         LED7 = OFF;


}

void initSW1(){
    // Initialize the pin connected to the switch as an input.
       TRISBbits.TRISB5 = 1;
                 _CNIF = 0;  
                 _CNIE = 1;
                 _CN27IE = 1; 
 


}


void initTimer1(){
// Initialize the timer
 unsigned int PRVal = (FCY* TIME_DELAY)/256.0 - 1;
      PR1 = PRVal;
     _TCKPS = 0b11; //prescalar 256
     _T1IE = 1;     // Enable the interrupt
     _T1IF = 0;     // Put the interrupt flag down
     _TON = 1;      // Turn the timer 1 on

    
}

