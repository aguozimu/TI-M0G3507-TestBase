#include "Mydef.h"





void mod1(void){


static	uint16_t count=0;


if(MODB==0){

OLED_ShowSignedNum(3,1,Motor1_Turn,2);
OLED_ShowSignedNum(4,1,Motor2_Turn,2);

OLED_ShowSignedNum(3,4,encoder_getspeed_1(),6);
OLED_ShowSignedNum(4,4,encoder_getspeed_2(),6);


}else if (MODB==1) {

switch (count) {
    case 0:


if(!motor_Linepatrol_PID_T(60,3))
count++;

    break;
    case 1:

if(!ServoMotor_Zero())count++;

    break;
    case 2:


if(!ServoMotor_POSSpeed(500,10,3600)) count++;


    break;
    case 3:
if(!ServoMotor_POSSpeed(500,20,7200))


    count++;
    break;
    case 4:

if(!ServoMotor_POSHight(500,20,128))

    count++;
    break;

    case 5:

if(!ServoMotor_POSSpeed(1000,50,7200)){

    count++;
};
    break;



    default:



    count=0;
    MODB--;
screen_ctrl();

    break;






}






};










}
