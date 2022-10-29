// Include Section
#include "mbed.h"                           
#include "Grove_LCD_RGB_Backlight.h"        

// Hardware Definition Section
Grove_LCD_RGB_Backlight fred(D14,D15);     
InterruptIn RAY(D6);                        

// Global Variables
short motion_detected=0;                    

// Asynchronous Interrupt Service Routine
void ABC(void)
{
   motion_detected=1;                      
} 

int main(void)
{
                              // add code to activate interrupt on rising edge 
    fred.clear(); 
    fred.setRGB(0x00,0xff,0x00);     
    for(;;)                                 
    {
        fred.clear();
        fred.setRGB(0x00,0xff,0x00);       
        if(motion_detected == 1)            
        {
            motion_detected=0;              
            fred.setRGB(0x00,0x00,0xff);   
            wait_ms(500);                   
        }
    }     
}