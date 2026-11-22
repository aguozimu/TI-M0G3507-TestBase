#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H



void bluetooth_DmaInit (void);
void bluetooth_GetData (void);
void bluetooth_getData_speed (void);
void bluetooth_getData_Hight (void);
void bluetooth_getData_PTZ(void);

extern uint8_t bluetooth_DmaData[];
extern uint8_t bluetooth_Data[];
extern uint8_t bluetooth_Data_speed[];
extern uint8_t bluetooth_Data_Hight[];
extern uint8_t bluetooth_Data_PTZ[];

#endif
