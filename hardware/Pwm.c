#include "Mydef.h"


void Pwm_Motor_1 (float speed){//到小数点后两位
	
if(speed>100)speed=100;
	if(speed<-100)speed=-100;
	speed*=100;
	
	


if(speedid_flag==1){//正转




 DL_TimerA_setCaptureCompareValue(PWM_0_INST, (uint16_t)speed, DL_TIMER_CC_0_INDEX);

}else if(speedid_flag==2){//反转

 DL_TimerA_setCaptureCompareValue(PWM_0_INST, (uint16_t)speed, DL_TIMER_CC_2_INDEX);



};






}
void Pwm_Motor_2 (float speed){//到小数点后两位
	
if(speed>100)speed=100;
	if(speed<-100)speed=-100;
	speed*=100;
	
	
if(speedid_flag==1){//正转




 DL_TimerA_setCaptureCompareValue(PWM_0_INST, (uint16_t)speed, DL_TIMER_CC_3_INDEX);

}else if(speedid_flag==2){//反转

 DL_TimerA_setCaptureCompareValue(PWM_0_INST, (uint16_t)speed, DL_TIMER_CC_1_INDEX);



};





}



//42步进200次一圈
void Pwm_StepMotor_1 (float speed){//修改触发翻转速度//单位r/S//最高1.193046470833333(h)
		float ARR=0;
	// if(speed>=(65536/1000000.00))speed=(65536/1000000.00);
	
		ARR=(1000000.0/(200.0*16.0*speed));
// __HAL_TIM_SET_AUTORELOAD(&TIM2_PWM,(uint16_t)speed-1);

DL_TimerG_setLoadValue(StepMotor_INST, ARR-1);
DL_TimerA_setCaptureCompareValue(StepMotor_INST, (ARR-1)/10, DL_TIMER_CC_0_INDEX);

}

void Pwm_StepMotorCmd (bool cmd){

		if(cmd==true){

      	DL_TimerA_startCounter(StepMotor_INST);
		}else {
		DL_TimerA_stopCounter(StepMotor_INST);
		};
		
}
