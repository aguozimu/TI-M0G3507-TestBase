#include "Mydef.h"
volatile int Motor1_Turn=1,Motor2_Turn=1;
// #include "ti_msp_dl_config.h"
// float encoder_getspeed_1(void){
// // DL_Timer_getCaptureCompareValue ();


// }


float encoder_getspeed_1(void){
    static float speed = 0;
    static uint32_t last_time=0;

	if(DL_GetTick()-last_time<10){//延迟
	return speed;
	}

	last_time=DL_GetTick();

    speed = (Motor1_Turn*(((int16_t)DL_Timer_getTimerCount(Encoder_1_INST)) / (encoder_Data / 100.0) * 100.0));
    DL_Timer_setTimerCount(Encoder_1_INST, 0);
DL_GPIO_enableInterrupt(GPIOB, Encoder1_Encoder1_ACL_PIN);


    return speed;



}






float encoder_getspeed_2(void){
    static float speed = 0;
    static uint32_t last_time=0;

	if(DL_GetTick()-last_time<10){//延迟
	return speed;
	}

	last_time=DL_GetTick();

    speed = (Motor2_Turn*(((int16_t)DL_Timer_getTimerCount(Encoder_2_INST)) / (encoder_Data / 100.0) * 100.0));
     DL_Timer_setTimerCount(Encoder_2_INST, 0);
    DL_GPIO_enableInterrupt(GPIOB, Encoder2_Encoder2_ACL_PIN);

    
    return speed;



}















void GROUP1_IRQHandler(void){


uint32_t GPIOB_INT_Status  = DL_GPIO_getEnabledInterruptStatus(GPIOB,
    Encoder1_Encoder1_ACL_PIN | Encoder2_Encoder2_ACL_PIN);


// DL_GPIO_readPins(KEY_PORT,KEY_KEY_1_PIN);
// DL_GPIO_readPins(KEY_PORT,KEY_KEY_2_PIN);


if((GPIOB_INT_Status&Encoder1_Encoder1_ACL_PIN)==Encoder1_Encoder1_ACL_PIN){
static uint8_t count=0;
    if((DL_GPIO_readPins(Encoder1_PORT,Encoder1_Encoder1_BCL_PIN)&Encoder1_Encoder1_BCL_PIN)!=0){
        Motor1_Turn=-1;    

    }else {

        Motor1_Turn=1;   

    };


DL_GPIO_clearInterruptStatus(GPIOB,Encoder1_Encoder1_ACL_PIN );

if(count>=1){
 DL_GPIO_disableInterrupt(GPIOB, Encoder1_Encoder1_ACL_PIN);
 count=0;
}else {
count++;
};

 }






if((GPIOB_INT_Status&Encoder2_Encoder2_ACL_PIN)==Encoder2_Encoder2_ACL_PIN){
static uint8_t count=0;
    if((DL_GPIO_readPins(Encoder2_PORT,Encoder2_Encoder2_BCL_PIN)&Encoder2_Encoder2_BCL_PIN)!=0){
        Motor2_Turn=1;
    //这里经常进不来
    }else {
         Motor2_Turn=-1;

    };




 DL_GPIO_clearInterruptStatus(GPIOB,Encoder2_Encoder2_ACL_PIN );   

if(count>=1){
 DL_GPIO_disableInterrupt(GPIOB, Encoder2_Encoder2_ACL_PIN);
 count=0;
}else {
count++;
};


}





}





