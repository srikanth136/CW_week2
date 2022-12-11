
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include "candata.h"

// @dbccodeconf.h file should be placed in inc folder. If the user wants
// to allocate big DBC struct inside the driver - appropriate define (__DEF_xxxxx__)
// should be placed in this file
#include "dbccodeconf.h"

typedef struct
{
  MOTOR_CURRENT_t MOTOR_CURRENT;         // TX [MCU].     RX [].
  AI_DRIVE_REQUEST_t AI_DRIVE_REQUEST;   // TX [AI].      RX [Vector__XXX ].
  VCU_WHEEL_SPEEDS_t VCU_WHEEL_SPEEDS;   // TX [VCU].     RX [Vector__XXX ].
  VCU_BATTERY_t VCU_BATTERY;             // TX [VCU].     RX [Vector__XXX ].
} candata_rx_t;

// There is no any message detected with tx direction.

uint32_t candata_Receive(candata_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_);


// define @__DEF_CANDATA__ in the @dbccodeconf.h file for allocation in utility source code.
#ifdef __DEF_CANDATA__

extern candata_rx_t candata_rx;

#endif


#ifdef __cplusplus
}
#endif

