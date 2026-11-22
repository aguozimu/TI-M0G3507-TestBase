#include "Mydef.h"



void mod3(void){

		static uint8_t count=0;
		static int16_t motor1_count=0,motor2_count=0;
		static float COUNT=0;


    if(MODB==0){
				
				
				OLED_ShowSignedNum(3,1,(int16_t)encoder_getspeed_1(),4);
				OLED_ShowSignedNum(3,10,(int16_t)encoder_getspeed_2(),4);
				OLED_ShowNum(4,1,motor1_count,4);
				OLED_ShowNum(4,6,motor2_count,4);
				OLED_ShowNum(4,12,COUNT,4);

				
																							  
    }else if(MODB==1){


				switch (count) {
                    case 0:
                        motor1_count=0;
                        motor2_count=0;
                        COUNT=0;
				        Pwm_Motor_1(speedid (0,1));
				        Pwm_Motor_2(speedid (0,2));
                        Delay_s(1);
				        Pwm_Motor_1(speedid (100,1));
				        Pwm_Motor_2(speedid (100,2));
				        Delay_ms(500);
                        DL_Timer_setTimerCount(Encoder_1_INST, 0);
                        DL_Timer_setTimerCount(Encoder_2_INST, 0);
                       count++;
                    break;
                    case 1:
                        Delay_s(1);
                        count++;
                    break;
                    case 2:
                    	Pwm_Motor_1(speedid (0,1));
				        Pwm_Motor_2(speedid (0,2));
                        motor1_count=(int16_t)DL_Timer_getTimerCount(Encoder_1_INST);
                        motor2_count=(int16_t)DL_Timer_getTimerCount(Encoder_2_INST);
                    
                        COUNT=(motor1_count+motor2_count)/2.0;
                        count++;



                    break;
                    default:


                       count=0;
                       MODB--;
                    break;
                }













            }





}




