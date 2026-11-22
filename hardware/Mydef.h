#ifndef __MYDEF_H
#define __MYDEF_H

typedef enum 
{
  DL_OK       = 0x00U,
  DL_ERROR    = 0x01U,
  DL_BUSY     = 0x02U,
  DL_TIMEOUT  = 0x03U
}DL_StatusTypeDef;



#include "ti_msp_dl_config.h"
#include "main.h"
#include "stdio.h"
#include "math.h"


#include "mod1.h"
#include "mod2.h"
#include "mod3.h"
#include "mod4.h"
#include "mod5.h"



#include "OLED.h"
#include "Delay.h"
#include "timer.h"
#include "Pwm.h"
#include "motor.h"
#include "screen.h"
#include "Key.h"
#include "Encoder.h"
#include "Pid.h"
#include "ADC.h"
#include "LinePatrol.h"
#include "bluetooth.h"
#include "ServoMotor.h"
#include "PTZ.h"


#define encoder_Data 2150










#endif
