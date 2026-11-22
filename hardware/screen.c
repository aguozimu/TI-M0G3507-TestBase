#include "Mydef.h"




void screen_ctrl(void){

OLED_Clear();

switch (MODA) {

    case 0:
    OLED_ShowString(1, 4, "MOD:order");
        switch (MODB) {
            case 0:
            OLED_ShowString(2, 3, "Status:OFF");
            
            break;
            case 1:

            OLED_ShowString(2, 3, "Status:ON  ");

            break;
        }
    break;
    case 1:
    OLED_ShowString(1, 4, "MOD:BT        ");
        switch (MODB) {
            case 0:
            OLED_ShowString(2, 3, "Status:OFF");
          
            break;
            case 1:
            OLED_ShowString(2, 3, "Status:ON  ");


            break;
        }

    break;
    case 2:
            OLED_ShowString(1, 4, "MOD:speed");
        switch (MODB) {
            case 0:
            OLED_ShowString(2, 3, "Status:OFF");

            break;
            case 1:
            OLED_ShowString(2, 3, "Status:ON  ");
            break;
        }

    break;
    case 3:


    break;
    case 4:


    break;

}












}













