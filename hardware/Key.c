#include "Mydef.h"

uint8_t key_1=0;
uint8_t key_2=0;

uint8_t key_1_Last;
uint8_t key_2_Last;

void Key_Ctrl (void){

    static uint32_t last_time=0;

	if(DL_GetTick()-last_time<10){//防抖
	return ;
	}
	last_time=DL_GetTick();





key_1=DL_GPIO_readPins(KEY_PORT,KEY_KEY_1_PIN);
key_2=DL_GPIO_readPins(KEY_PORT,KEY_KEY_2_PIN);


if(key_1==0&&key_1_Last!=0){//按下





MODA++;
MODA%=5;



DL_GPIO_writePins(BUZZER_PORT, BUZZER_BUZZER_1_PIN);
Delay_ms(100);
DL_GPIO_clearPins(BUZZER_PORT, BUZZER_BUZZER_1_PIN);





screen_ctrl();

}else if(key_2==0&&key_2_Last!=0){//按下

switch (MODA) {

    case 0:

        MODB++;
        MODB%=2;

    break;
    case 1:
        MODB++;
        MODB%=2;

    break;
    case 2:

        MODB++;
        MODB%=2;
    break;
    case 3:

        MODB++;
        MODB%=2;
    break;
    case 4:
        MODB++;
        MODB%=2;

    break;








}


DL_GPIO_writePins(BUZZER_PORT, BUZZER_BUZZER_1_PIN);
Delay_ms(100);
DL_GPIO_clearPins(BUZZER_PORT, BUZZER_BUZZER_1_PIN);

screen_ctrl();

}






key_1_Last=key_1;
key_2_Last=key_2;











}








