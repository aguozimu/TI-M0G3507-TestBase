#ifndef __PID_H
#define __PID_H

float pid_Get_motor_1 (float point_Data,float real_Data);
float pid_Get_motor_2 (float point_Data,float real_Data);


float pid_Get_place (float point_Data,float real_Data);


extern float pid_place_last_error,pid_place_speed_ki;

#endif

