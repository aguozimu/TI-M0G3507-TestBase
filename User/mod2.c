#include "Mydef.h"




void mod2(void){

// char Battery_Vdd[20],LINE_4[20];
// // char Support_Vdd[20];
// sprintf(Battery_Vdd, "%0.2fV,%0.2fV", Battery_getVddValue(),Support_getVddValue());
// OLED_ShowString(3,1,Battery_Vdd );

// sprintf(LINE_4, "%0.2fC", Temp_getValue());
// OLED_ShowString(4,1,LINE_4 );
// Delay_ms(500);
bluetooth_GetData();
bluetooth_getData_speed();
bluetooth_getData_Hight();
bluetooth_getData_PTZ();


          OLED_ShowSignedNum(3, 1,(int32_t)PTZ_AngleEx(), 5);
       //     OLED_ShowSignedNum(4, 1,(int8_t)bluetooth_Data_speed[1], 3); 

         //   OLED_ShowSignedNum(3, 5,bluetooth_Data_Hight[3], 3);
        //    OLED_ShowSignedNum(4, 5,((bluetooth_Data_Hight[0]<<8)|bluetooth_Data_Hight[1])/100.0, 3);  


Pwm_Motor_1(speedid (pid_Get_motor_1((int8_t)bluetooth_Data_speed[0],encoder_getspeed_1()),1));
Pwm_Motor_2(speedid (pid_Get_motor_2((int8_t)bluetooth_Data_speed[1],encoder_getspeed_2()),2));


ServoMotor_POSHightRTOS(bluetooth_Data_Hight[2]*10,bluetooth_Data_Hight[2],((bluetooth_Data_Hight[0]<<8)|bluetooth_Data_Hight[1])/100.0);

// Pwm_StepMotor_1(speedid(((int8_t)bluetooth_Data_PTZ[2]*5/100.0),5));

PTZ_AngleCTRL(((int16_t)((bluetooth_Data_PTZ[0]<<8)|bluetooth_Data_PTZ[1]))/100.0,(int8_t)bluetooth_Data_PTZ[2]*5/100.0);

}











