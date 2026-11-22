/*
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"
#include "Mydef.h"


uint8_t MODA=0,MODB=0;





int main(void)
{

    SYSCFG_DL_init();
    OLED_Init();
    bluetooth_DmaInit();
    
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);
    NVIC_EnableIRQ(ADC12_0_INST_INT_IRQN);
    NVIC_EnableIRQ(ADC12_1_INST_INT_IRQN);
    NVIC_EnableIRQ (video_INST_INT_IRQN); 
    NVIC_EnableIRQ (StepMotor_INST_INT_IRQN); 

    DL_TimerA_startCounter(PWM_0_INST);


    DL_TimerG_startCounter(Encoder_1_INST);
    DL_TimerG_startCounter(Encoder_2_INST);


    DL_ADC12_enableConversions(ADC12_0_INST);
    DL_ADC12_startConversion(ADC12_0_INST);  

    DL_ADC12_enableConversions(ADC12_1_INST);
    DL_ADC12_startConversion(ADC12_1_INST);  

    DL_Timer_setTimerCount(Encoder_1_INST,0);
    DL_Timer_setTimerCount(Encoder_2_INST,0);

    

screen_ctrl();

ServoMotor_Zero();

    while (1) {

        Key_Ctrl();

        switch (MODA) {
            case 0:
                mod1();
            break;
            case 1:
                mod2();
            break;
            case 2:
                mod3();
            break;
            case 3:
                mod4();
            break;
            case 4:
                mod5();  
            break;


        }


    }
}









