#include "Mydef.h"

uint16_t Battery_value=0,Temp_value=0,Support_value=0;






float Battery_getVddValue(){






    DL_ADC12_enableConversions(ADC12_0_INST);
    DL_ADC12_startConversion(ADC12_0_INST); 







return  ((Battery_value / 4095.0f) * 3.3f * 4.3f)+1;

}









float Temp_getValue(){




    DL_ADC12_enableConversions(ADC12_1_INST);
    DL_ADC12_startConversion(ADC12_1_INST); 



uint32_t cal_code = DL_SYSCTL_getTempCalibrationConstant();






return  30.0f + 0.461f * ((float)cal_code - (float)Temp_value);


}








float Support_getVddValue(){



    DL_ADC12_enableConversions(ADC12_1_INST);
    DL_ADC12_startConversion(ADC12_1_INST); 




return  Support_value * 2.5f * 3.0f / 4096.0f;


}












void ADC12_0_INST_IRQHandler(){



switch ((uint32_t)DL_ADC12_getPendingInterrupt(ADC12_0_INST)) {
    case DL_ADC12_IIDX_MEM0_RESULT_LOADED://0号内存

Battery_value=DL_ADC12_getMemResult(ADC12_0_INST,ADC12_0_ADCMEM_0);

    break;


}



}


void ADC12_1_INST_IRQHandler (){



switch ((uint32_t)DL_ADC12_getPendingInterrupt(ADC12_1_INST)) {
    case DL_ADC12_IIDX_MEM0_RESULT_LOADED://0号内存


Temp_value=DL_ADC12_getMemResult(ADC12_1_INST,ADC12_1_ADCMEM_0);



    break;

    case DL_ADC12_IIDX_MEM1_RESULT_LOADED://1号内存


Support_value=DL_ADC12_getMemResult(ADC12_1_INST,ADC12_1_ADCMEM_1);

    break;
}


}



