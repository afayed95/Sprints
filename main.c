/*
 * File:   main.c
 * Author: Toshiba
 *
 * Created on 04 ?????, 2020, 06:44 ?
 */


#include <avr/io.h>

void main(void) 
{
    /* Replace with your application code */
    LCD-Init(); // initialize LCD
    Motor_Init();  // initialize Motor
    Timer_Init();  // initialize Timer
   int Timer=0 //assigning global variable o check each time
    
    while (1) 
    {
        //Start to enter main code to set the Robot status
        if(Timer==Power_ON) // entering first mode
        {
        //Robot_Status(Power_ON);  // set Robot status
        Robot_Motor(forward,100);  //set direction & full speed
        LCD_Disp(forward); //displaying Robot direction
        Time_Start(5_seconds); //setting desired time 
        Timer+=4; // flag to switch to next event
        while(5_seconds != Timer_isFinished()); // check if time is finished
        }
        
        //Robot enters Running Mode status
        if(Timer>=Running_mode) 
        {
        //Robot_Status(Running_mode);  // set Robot status
        Robot_Motor(forward,50);  //set direction & full speed
        Time_Start(5_seconds); //setting desired time 
        Timer+=5;
        while(5_seconds != Timer_isFinished()); // check if time is finished
        }
        //Robot starts Rotating
        if(Timer>=Last_mode)
        {
        Robot_Motor(Right,0);  //set direction & full speed
        LCD_clear();
        LCD_Disp(Right);       //displaying Robot direction
        Time_Start(5_seconds); //setting desired time 
        while(5_seconds != Timer_isFinished()); // check if time is finished
        Timer=0;
        }   
        LCD_clear();
    }
}
