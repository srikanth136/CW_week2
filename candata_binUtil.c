
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "candata_binUtil.h"

#ifdef __DEF_CANDATA__

candata_rx_t candata_rx;

#endif

uint32_t candata_Receive(candata_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_)
{
 uint32_t recid = 0;
 if (_id >= 0x320U && _id < 0x525U) {
  if (_id == 0x320U) {
   recid = Unpack_MOTOR_CURRENT_candata(&(_m->MOTOR_CURRENT), _d, dlc_);
  } else if (_id == 0x521U) {
   recid = Unpack_AI_DRIVE_REQUEST_candata(&(_m->AI_DRIVE_REQUEST), _d, dlc_);
  }
 } else {
  if (_id == 0x525U) {
   recid = Unpack_VCU_WHEEL_SPEEDS_candata(&(_m->VCU_WHEEL_SPEEDS), _d, dlc_);
  } else if (_id == 0x526U) {
   recid = Unpack_VCU_BATTERY_candata(&(_m->VCU_BATTERY), _d, dlc_);
  }
 }

 return recid;
}

