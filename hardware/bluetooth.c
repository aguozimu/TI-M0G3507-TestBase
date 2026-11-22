#include "Mydef.h"

uint8_t bluetooth_DmaData[36]={0};
uint8_t bluetooth_Data[12]={0};
uint8_t bluetooth_Data_speed[2]={0};
uint8_t bluetooth_Data_Hight[3]={0};
uint8_t bluetooth_Data_PTZ[3]={0};

void bluetooth_DmaInit (void){

/* 从哪里*/
DL_DMA_setSrcAddr(DMA, DMA_CH0_CHAN_ID,  (uint32_t )&UART_0_INST->RXDATA);

/*搬运到哪里*/

DL_DMA_setDestAddr(DMA, DMA_CH0_CHAN_ID, (uint32_t )bluetooth_DmaData);

/*启动DMA*/

DL_DMA_enableChannel(DMA, DMA_CH0_CHAN_ID);


}

void bluetooth_GetData (void){


uint8_t cache [36]={0};

//数据转运
for(uint8_t i=0 ; i<36 ; i++){

cache[i]=bluetooth_DmaData[i];

};

for(uint8_t j=0;j<36;j++){//在前24个里面找包头
if(cache[j]==0xFF){

for(uint8_t k=0;k<12;k++){//转移数据
bluetooth_Data[k]=cache[j+k];



};
break;//跳出循环
};

}

}





void bluetooth_getData_speed (void)
{


bluetooth_Data_speed[0]=bluetooth_Data[1];
bluetooth_Data_speed[1]=bluetooth_Data[2];	

}

void bluetooth_getData_Hight(void){

bluetooth_Data_Hight[0]=bluetooth_Data[4];
bluetooth_Data_Hight[1]=bluetooth_Data[5];
bluetooth_Data_Hight[2]=bluetooth_Data[6];



}


void bluetooth_getData_PTZ(void){
bluetooth_Data_PTZ[0]=bluetooth_Data[8];
bluetooth_Data_PTZ[1]=bluetooth_Data[9];
bluetooth_Data_PTZ[2]=bluetooth_Data[10];


}

