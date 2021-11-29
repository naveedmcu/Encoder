#include <30F4011.h>
#device ICSP=1
#use delay(crystal=20000000)

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES CKSFSM                	//Clock Switching is enabled, fail Safe clock monitor is enabled
#FUSES NOBROWNOUT            	//No brownout reset


#use spi(SLAVE, CLK=PIN_E2, DI=PIN_E0, DO=PIN_E1, MODE=0, BITS=8, ENABLE=PIN_E3, stream=MT1)


