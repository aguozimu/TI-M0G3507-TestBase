#include "Mydef.h"

volatile uint8_t ServoMotor_RX_DAta[4],ServoMotor_RX_Count=0;
static uint8_t Run_flag=0;


DL_StatusTypeDef ServoMotor_Zero (void){
    static uint8_t Run_flag=0;

if(!Run_flag){
uint8_t TX_Data[5]={0x01,0x9A,0x02,0x00,0x6B};
for (int i=0;i<5;i++){
DL_UART_transmitDataBlocking(video_INST, TX_Data[i]);

};

Run_flag=1;

}else{

if(ServoMotor_RX_DAta[2]==0x9f){
ServoMotor_RX_DAta[2]=0x00;
Run_flag=0;
return DL_OK;
}else {
Run_flag=1;
return DL_BUSY;
}

}

return DL_BUSY;

	
}



DL_StatusTypeDef  ServoMotor_POSSpeed (uint16_t RPM,uint8_t ACC,float angle){//位置模式

/*方向01，零点绝对方向*/




if(!Run_flag){
uint8_t TX_Data [13];
uint32_t FREQ;
FREQ=(uint32_t)(angle*3200.0/360.0);


TX_Data[0]=0x01;/*地址号*/
TX_Data[1]=0xFD;/*功能号*/
TX_Data[2]=0x01;/*逆时针坐标方向*/
TX_Data[3]=(uint8_t)(RPM>>8);/*速度高8位*/
TX_Data[4]=(uint8_t)(RPM&0XFF); /*速度低8位*/
TX_Data[5]=ACC;
TX_Data[6]=(uint8_t)(FREQ >> 24);/*速度高8位*/
TX_Data[7]=(uint8_t)(FREQ >> 16);/*速度高16位*/
TX_Data[8]=(uint8_t)(FREQ >> 8);/*速度高24位*/
TX_Data[9]=(uint8_t)(FREQ&0XFF);/*速度高32位*/
TX_Data[10]=0X01;/*绝对坐标模式*/
TX_Data[11]=0x00;/*非同步*/
TX_Data[12]=0x6B;/*校验码*/


for (int i=0;i<13;i++){
DL_UART_transmitDataBlocking(video_INST, TX_Data[i]);

};
Run_flag=1;

}else{


if(ServoMotor_RX_DAta[2]==0x9f) {
ServoMotor_RX_DAta[2]=0x00;
Run_flag=0;
return DL_OK;
}else {
    
Run_flag=1;
return DL_BUSY;

};



};

return DL_BUSY;
}

DL_StatusTypeDef ServoMotor_POSHight(uint16_t RPM,uint8_t ACC,float Hight){/*单位mm*//*最大128mm*/
float angle;

angle=Hight*180.0;


if(!ServoMotor_POSSpeed(RPM,ACC,angle))
return DL_OK;
else return DL_BUSY;

}

DL_StatusTypeDef ServoMotor_POSHightRTOS(uint16_t RPM,uint8_t ACC,float Hight){/*单位mm*//*最大128mm*//*实时改变*/
float angle;
static uint16_t Last_RPM=0;
static uint8_t Last_ACC=0;
static float Last_Hight=0;

angle=Hight*180;
if(Last_RPM!=RPM||Last_ACC!=ACC||Last_Hight!=Hight){
Run_flag=0;
};
Last_RPM=RPM;
Last_ACC=ACC;
Last_Hight=Hight;
if(RPM!=0){
if(!ServoMotor_POSSpeed(RPM,ACC,angle))
return DL_OK;
else return DL_BUSY;
};

return DL_ERROR;

}


void video_INST_IRQHandler(void){

 switch (DL_UART_getPendingInterrupt(video_INST)) {
        case DL_UART_IIDX_RX:
                 ServoMotor_RX_Count%=4;

                ServoMotor_RX_DAta[ServoMotor_RX_Count] = DL_UART_receiveData(video_INST);

                ServoMotor_RX_Count++;

            break;
        default:
             break;

 		}



}


