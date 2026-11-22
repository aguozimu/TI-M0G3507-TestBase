#include "Mydef.h"

uint32_t StepMotorCount=0;
volatile int8_t StepMotorDIR=0;


float PTZ_Angle (void)/*相对开机时角度*/
{

//3200一圈
static float angle=0;
volatile float angle_BUFF=0; 


angle_BUFF=(((float)StepMotorDIR)*StepMotorCount*360/3200.0);

angle+=angle_BUFF;

StepMotorCount=0;

return angle/30.0 ;


}



float PTZ_AngleEx (void)/*相对开机时角度*//*范围-180~180*/
{

//3200一圈
static float angle=0;
volatile float angle_BUFF=0; 


angle_BUFF=(((float)StepMotorDIR)*StepMotorCount*360/3200.0)/30.0;

angle+=angle_BUFF;

StepMotorCount=0;

/*环状循环*/
if(angle>180)angle=-180;
else if(angle<-180)angle=180;


return  angle;


}


DL_StatusTypeDef PTZ_AngleCTRL(float point,float speed){
float angle;
static	float speed_CTRL;
float error;
static	uint8_t countflag;

angle=PTZ_AngleEx();

error=point-angle;





	if (error > 180.0f) {//界限限制
    error -= 360.0f;  
} 
	else if (error < -180.0f) {
    error += 360.0f; 
};

if(error<0.5&&error>-0.5){countflag++;};
 
if(speed!=0){speed_CTRL=fabsf(speed);};



if(error>0){
Pwm_StepMotor_1(speedid(speed_CTRL,5));
}else {
Pwm_StepMotor_1(speedid(-speed_CTRL,5));
};


if(countflag!=0){
	
Pwm_StepMotor_1(speedid(0,5));
	countflag=0;
return DL_OK;

}else return DL_BUSY;







}

void StepMotor_INST_IRQHandler(void)
{
    switch (DL_TimerA_getPendingInterrupt(StepMotor_INST)) {
        case DL_TIMER_IIDX_LOAD:
            
            StepMotorCount++;



            
            break;

        default:
            break;
    }
}





