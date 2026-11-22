#ifndef __PTZ_H
#define __PTZ_H


float PTZ_Angle (void);
float PTZ_AngleEx (void);
DL_StatusTypeDef PTZ_AngleCTRL(float point,float speed);

extern uint32_t StepMotorCount;
extern volatile int8_t StepMotorDIR;

#endif

