#include "Mydef.h"



uint32_t tim6=0,SYSTICK=0;







uint32_t DL_GetTick(void){
return SYSTICK;
}



void SysTick_Handler(void) {
tim6++;
SYSTICK++;
}





