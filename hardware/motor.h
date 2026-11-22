#ifndef __MOTOR_H
#define __MOTOR_H



extern uint8_t speedid_flag;


float  speedid (float fast,uint8_t motorX);

DL_StatusTypeDef  motor_freerun  (float motor1,float motor2,float motor1times,float motor2times);
DL_StatusTypeDef motor_freerun_PID_T  (float motor1,float motor2,float motor1times,float motor2times);


DL_StatusTypeDef motor_Linepatrol_PID_T (float speed,float time);






#endif
