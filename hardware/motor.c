#include "Mydef.h"

uint8_t speedid_flag=0;



/**
  * @brief  自由移动
  * @param  1号马达速度 范围：100~-100
  * @param  2号马达速度 范围：100~-100
  * @param  1号运行时长 范围：0~floatMAX
  * @param  2号运行时长 范围：0~floatMAX
  * @retval 马达速度为对应占空比,运行时长单位(S)
  */


//free	run	//左马达	//右马达	//左马达运行时长(s)	//右马达运行时长(s) 两位小数   马达范围（0，100）			
DL_StatusTypeDef motor_freerun  (float motor1,float motor2,float motor1times,float motor2times){
																			//		左	中	右
	                                                                        //前	1		2
						                                                    //中		5
	                                                                        //后	3		4	
static	uint8_t flag=0,flag1=0,flag2=0;											
if(flag==0){                                                                 	
	                                                                     	
															
		tim6=0;

	Pwm_Motor_1(speedid (motor1,1));
	Pwm_Motor_2(speedid (motor2,2));

	
	flag++;
};
	
if(tim6>=(uint16_t)(motor1times*1000.0)){

Pwm_Motor_1(speedid (0,1));
	flag1=1;
};

if(tim6>=(uint16_t)(motor2times*1000.0)){

Pwm_Motor_2(speedid (0,2));
flag2=1;};


//todo fmq
if(flag1==1&&flag2==1){

tim6=0;
flag1=0;flag2=0;
flag=0;
		
return DL_OK;
}else return DL_BUSY;


}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
  * @brief  使用速度PID以时间(S)为单位的自由移动
  * @param  1号马达速度 范围：100~-100
  * @param  2号马达速度 范围：100~-100
  * @param  1号运行时长 范围：0~floatMAX
  * @param  2号运行时长 范围：0~floatMAX
  * @retval 马达速度为对应占空比,运行时长单位(S)
  */


//free	run	//左马达	//右马达	//左马达运行时长(s)	//右马达运行时长(s) 两位小数   马达范围（0，100）			
DL_StatusTypeDef motor_freerun_PID_T  (float motor1,float motor2,float motor1times,float motor2times){
																			//		左	中	右
	                                                                        //前	1		2
						                                                    //中		5
	                                                                        //后	3		4	
static	uint8_t flag=0,flag1=0,flag2=0;											
if(flag==0){                                                                 	
	                                                                     														
		tim6=0;

	flag++;
};


	Pwm_Motor_1(speedid (pid_Get_motor_1(motor1,encoder_getspeed_1()),1));
	Pwm_Motor_2(speedid (pid_Get_motor_2(motor2,encoder_getspeed_2()),2));


	
if(tim6>=(uint16_t)(motor1times*1000.0)){

Pwm_Motor_1(speedid (0,1));
	flag1=1;
};

if(tim6>=(uint16_t)(motor2times*1000.0)){

Pwm_Motor_2(speedid (0,2));
flag2=1;};


//todo fmq
if(flag1==1&&flag2==1){

tim6=0;
flag1=0;flag2=0;
flag=0;
		
return DL_OK;
}else return DL_BUSY;


}
//////////////////////////////////////////////////////////////////////////////////////////////

/**
  * @brief 使用速度PID以时间(S)为单位巡线
  * @param 马达速度 范围：100~-100
  * @param 运行时长 范围：0~floatMAX
  * @retval 马达速度为对应占空比,运行时长单位(S)
  */


DL_StatusTypeDef motor_Linepatrol_PID_T (float speed,float time){


static	uint8_t flag=0;
	float place_PID=0,Motor1_speed=0,Motor2_speed=0;											
if(flag==0){                                                                 	
	                                                                     																
	tim6=0;
	flag++;
};

	place_PID=pid_Get_place(0,Linepatrol_getDataPlace());
	Motor1_speed=speed-place_PID;
	Motor2_speed=speed+place_PID;



	Pwm_Motor_1(speedid (pid_Get_motor_1(Motor1_speed,encoder_getspeed_1()),1));
	Pwm_Motor_2(speedid (pid_Get_motor_2(Motor2_speed,encoder_getspeed_2()),2));



if(tim6>=(uint16_t)(time*1000.0)){
	Pwm_Motor_1(speedid(0,1));
	Pwm_Motor_2(speedid(0,2));
	tim6=0;
	pid_place_last_error=0;
	pid_place_speed_ki=0;
	Linepatrol_place=0;
	flag=0;
		
return DL_OK;
}else return DL_BUSY;






}




























float  speedid (float fast,uint8_t motorX){          			 	//		左	中	右
																	//前	1		2
																	//中		5
																	//后	3		4
			
 	       
																//motor5——fast为单脉冲触发间隔时间
																//SET为顺时针，RESET为逆时针
																//fast>0为顺时针，fast<0为逆时针，fast==0为停止
	
	
	
	if(motorX==1){				

 if(fast==0){
	speedid_flag=0;
	 DL_TimerA_setCaptureCompareValue(PWM_0_INST, 0, DL_TIMER_CC_0_INDEX);
      DL_TimerA_setCaptureCompareValue(PWM_0_INST, 0, DL_TIMER_CC_2_INDEX);

	return 0;
	}else if(fast<0){//反转
 speedid_flag=2;
  DL_TimerA_setCaptureCompareValue(PWM_0_INST, 0, DL_TIMER_CC_0_INDEX);

  return -fast;
}else if(fast>0){//正转
	speedid_flag=1;
  DL_TimerA_setCaptureCompareValue(PWM_0_INST, 0, DL_TIMER_CC_2_INDEX);

  return fast;
 
  };
}else if(motorX==2){



if(fast==0){
		 DL_TimerA_setCaptureCompareValue(PWM_0_INST, 0, DL_TIMER_CC_1_INDEX);
      DL_TimerA_setCaptureCompareValue(PWM_0_INST, 0, DL_TIMER_CC_3_INDEX);
	return 0;
	}else if(fast<0){//反转
 speedid_flag=2;
  DL_TimerA_setCaptureCompareValue(PWM_0_INST, 0, DL_TIMER_CC_3_INDEX);
	
  return -fast;
}else if(fast>0){
    speedid_flag=1;
	 DL_TimerA_setCaptureCompareValue(PWM_0_INST, 0, DL_TIMER_CC_1_INDEX);
  return fast;
 


};




 }else if(motorX==5){//fast为单脉冲触发间隔时间
					//SET为顺时针，RESET为逆时针
 
 
 if(fast==0){
	
	Pwm_StepMotorCmd(false);
	StepMotorDIR=0;
	return 0;
	}else if(fast<0){
			Pwm_StepMotorCmd(true);
			DL_GPIO_clearPins(StepMotor_CTRL_PORT, StepMotor_CTRL_StepMotor_1_CTRL_PIN);
			StepMotorDIR=-1;
	
  return -fast;
}else if(fast>0){
			Pwm_StepMotorCmd(true);
			DL_GPIO_writePins(StepMotor_CTRL_PORT, StepMotor_CTRL_StepMotor_1_CTRL_PIN);

			StepMotorDIR=1;
    
  return fast;
 
 };
 
 
 
 
 
 
 
 
 };

}

