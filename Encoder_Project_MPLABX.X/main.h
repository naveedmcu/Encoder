#include <30F4011.h>
#device ICSP=1
#use delay(internal=120MHz)
#fuses FRC_PLL16               //Internal Fast RC oscillator 7.3728Mhz with 16X PLL
#fuses FRC                    //Internal Fast RC Oscillator
#FUSES NOWDT                    //No Watch Dog Timer
#fuses NOCKSFSM    //Clock Switching is disabled, fail Safe clock monitor is disabled
#FUSES PUT64                    //Power On Reset Timer value 64ms
#FUSES BORRES                   //Reserved (do not use)
#FUSES NOBROWNOUT               //No brownout reset
#FUSES LPOL_HIGH                //Low-Side Transistors Polarity is Active-High (PWM 0,2,4 and 6)
   //PWM module low side output pins have active high output polar
#FUSES HPOL_HIGH                //High-Side Transistors Polarity is Active-High (PWM 1,3,5 and 7)
   //PWM module high side output pins have active high output polarity
#FUSES NOPWMPIN                 //PWM outputs drive active state upon Reset
#FUSES NOMCLR                     //Master Clear pin enabled
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOPROTECT                //Code not protected from reading
#fuses ICSP1       //ICD uses PGC1/PGD1 pins

#use spi(SLAVE, CLK=PIN_E2, DI=PIN_E0, DO=PIN_E1, MODE=0, BITS=8, ENABLE=PIN_E3, stream=MT1)