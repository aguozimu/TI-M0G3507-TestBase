#include "Mydef.h"

 float Linepatrol_place =0;

float Linepatrol_getDataPlace (void){



    uint32_t Linepatrol_A=DL_GPIO_readPins(GPIOA, Linepatrol_Linepatrol_1_PIN|Linepatrol_Linepatrol_2_PIN|Linepatrol_Linepatrol_3_PIN|Linepatrol_Linepatrol_4_PIN);
    uint32_t Linepatrol_B=DL_GPIO_readPins(GPIOB,Linepatrol_Linepatrol_5_PIN|Linepatrol_Linepatrol_6_PIN|Linepatrol_Linepatrol_7_PIN);

    uint8_t s1=(Linepatrol_A&Linepatrol_Linepatrol_1_PIN)!=0;
    uint8_t s2=(Linepatrol_A&Linepatrol_Linepatrol_2_PIN)!=0;
    uint8_t s3=(Linepatrol_A&Linepatrol_Linepatrol_3_PIN)!=0;
    uint8_t s4=(Linepatrol_A&Linepatrol_Linepatrol_4_PIN)!=0;
    uint8_t s5=(Linepatrol_B&Linepatrol_Linepatrol_5_PIN)!=0;
    uint8_t s6=(Linepatrol_B&Linepatrol_Linepatrol_6_PIN)!=0;
    uint8_t s7=(Linepatrol_B&Linepatrol_Linepatrol_7_PIN)!=0;



if(!(s1||s2||s3||s4||s5||s6||s7)){return Linepatrol_place;};

Linepatrol_place=-50*s1+-40*s2+-15*s3+0*s4+15*s5+40*s6+50*s7;




return Linepatrol_place;

}
















