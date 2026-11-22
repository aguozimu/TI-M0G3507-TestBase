#include "Mydef.h"

float pid_place_last_error=0,pid_place_speed_ki=0;


float pid_Get_motor_1 (float point_Data,float real_Data){

	float kp=1, ki=0.5, kd=0;
	float speed_ki_line=150;//积分限幅
	float Data_line=100;//总输出限幅
	float speed_kp=0 ,speed_kd=0 ,error=0;
	static  float  last_error=0,speed_ki=0,Data=0;
	
	
	static uint32_t last_tick=0;
	uint32_t tick_new=tim6;
	if(tick_new-last_tick<10)return Data;
	last_tick=tim6;
		
	
	
	
	error=point_Data-real_Data;
	
	
	speed_kp=error;//基础
	speed_ki=speed_ki+error;//积分
	speed_kd=error-last_error;//微分
	
	
if (speed_ki>speed_ki_line)speed_ki=speed_ki_line;
else if(speed_ki<-speed_ki_line)speed_ki=(-speed_ki_line);

Data=speed_kp*kp+speed_ki*ki+speed_kd*kd;
	
		
	
if (Data>Data_line)Data=Data_line;
else if(Data<-Data_line)Data=(-Data_line);



last_error=error;
return Data;
}




float pid_Get_motor_2 (float point_Data,float real_Data){
	
	
	
	float kp=1, ki=0.5, kd=0;
	float speed_ki_line=150;//积分限幅
	float Data_line=100;//总输出限幅
	float speed_kp=0 ,speed_kd=0 ,error=0;
	static  float  last_error=0,speed_ki=0,Data=0;
	
	
	
	
		static uint32_t last_tick;
	uint32_t tick_new=tim6;
	if(tick_new-last_tick<10)return Data;
	last_tick=tim6;
	
	
	
	error=point_Data-real_Data;
	
	
	speed_kp=error;//基础
	speed_ki=speed_ki+error;//积分
	speed_kd=error-last_error;//微分
	
	
if (speed_ki>speed_ki_line)speed_ki=speed_ki_line;
else if(speed_ki<-speed_ki_line)speed_ki=(-speed_ki_line);

Data=speed_kp*kp+speed_ki*ki+speed_kd*kd;
	
		
	
if (Data>Data_line)Data=Data_line;
else if(Data<-Data_line)Data=(-Data_line);



last_error=error;
return Data;
}




float pid_Get_place (float point_Data,float real_Data){
	
	float kp=1, ki=0.000057, kd=0.10;
	//float kp=0.82, ki=0.000056, kd=0.66;
	float speed_ki_line=508000;//积分限幅
	float Data_line=80;//总输出限幅
	float speed_kp=0 ,speed_kd=0 ,error=0;
	static  float Data=0;
		
	static uint32_t last_tick;
	uint32_t tick_new=tim6;
	if(tick_new-last_tick<10)return Data;
	last_tick=tim6;
	
	
	
	error=point_Data-real_Data;
	
	// if(ADC_Data_Linepatrol[2]==1){pid_place_speed_ki=0;};
	
	speed_kp=error;//基础
	pid_place_speed_ki=pid_place_speed_ki+error;//积分
	speed_kd=error-pid_place_last_error;//微分
	
	
if (pid_place_speed_ki>speed_ki_line)pid_place_speed_ki=speed_ki_line;
else if(pid_place_speed_ki<-speed_ki_line)pid_place_speed_ki=(-speed_ki_line);

Data=speed_kp*kp+pid_place_speed_ki*ki+speed_kd*kd;
	
		
	
if (Data>Data_line)Data=Data_line;
else if(Data<-Data_line)Data=(-Data_line);



pid_place_last_error=error;
return Data;
}
















