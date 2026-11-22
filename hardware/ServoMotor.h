#ifndef __SERVOMOTOR_H
#define __SERVOMOTOR_H






DL_StatusTypeDef ServoMotor_Zero (void);

DL_StatusTypeDef  ServoMotor_POSSpeed (uint16_t RPM,uint8_t ACC,float angle);


DL_StatusTypeDef ServoMotor_POSHight(uint16_t RPM,uint8_t ACC,float Hight);
DL_StatusTypeDef ServoMotor_POSHightRTOS(uint16_t RPM,uint8_t ACC,float Hight);


#endif

