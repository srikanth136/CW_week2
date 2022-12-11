
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com4

#include "candata.h"
#include "can_wrap.h"

// --------------------------------------------------------------------------
uint32_t Unpack_MOTOR_CURRENT_candata(MOTOR_CURRENT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->FRONT_CURRENT = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->REAR_CURRENT = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  return MOTOR_CURRENT_CANID;
}

uint32_t Pack_MOTOR_CURRENT_candata(const MOTOR_CURRENT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < MOTOR_CURRENT_DLC; _d[i++] = 0);

  _d[0] |= (_m->FRONT_CURRENT & (0xFFU));
  _d[1] |= ((_m->FRONT_CURRENT >> 8) & (0xFFU));
  _d[2] |= (_m->REAR_CURRENT & (0xFFU));
  _d[3] |= ((_m->REAR_CURRENT >> 8) & (0xFFU));
  *_len = 4; *_ide = 0;
  return MOTOR_CURRENT_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_AI_DRIVE_REQUEST_candata(AI_DRIVE_REQUEST_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->FRONT_TRQ_REQUEST = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->STEERING_REQUEST = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->REAR_TRQ_REQUEST = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return AI_DRIVE_REQUEST_CANID;
}

uint32_t Pack_AI_DRIVE_REQUEST_candata(const AI_DRIVE_REQUEST_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < AI_DRIVE_REQUEST_DLC; _d[i++] = 0);

  _d[0] |= (_m->FRONT_TRQ_REQUEST & (0xFFU));
  _d[1] |= ((_m->FRONT_TRQ_REQUEST >> 8) & (0xFFU));
  _d[2] |= (_m->STEERING_REQUEST & (0xFFU));
  _d[3] |= ((_m->STEERING_REQUEST >> 8) & (0xFFU));
  _d[4] |= (_m->REAR_TRQ_REQUEST & (0xFFU));
  _d[5] |= ((_m->REAR_TRQ_REQUEST >> 8) & (0xFFU));
  *_len = 6; *_ide = 0;
  return AI_DRIVE_REQUEST_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_VCU_WHEEL_SPEEDS_candata(VCU_WHEEL_SPEEDS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->FL_WHEEL_SPEED = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->FR_WHEEL_SPEED = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->RL_WHEEL_SPEED = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  _m->RR_WHEEL_SPEED = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
  return VCU_WHEEL_SPEEDS_CANID;
}

uint32_t Pack_VCU_WHEEL_SPEEDS_candata(const VCU_WHEEL_SPEEDS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < VCU_WHEEL_SPEEDS_DLC; _d[i++] = 0);

  _d[0] |= (_m->FL_WHEEL_SPEED & (0xFFU));
  _d[1] |= ((_m->FL_WHEEL_SPEED >> 8) & (0xFFU));
  _d[2] |= (_m->FR_WHEEL_SPEED & (0xFFU));
  _d[3] |= ((_m->FR_WHEEL_SPEED >> 8) & (0xFFU));
  _d[4] |= (_m->RL_WHEEL_SPEED & (0xFFU));
  _d[5] |= ((_m->RL_WHEEL_SPEED >> 8) & (0xFFU));
  _d[6] |= (_m->RR_WHEEL_SPEED & (0xFFU));
  _d[7] |= ((_m->RR_WHEEL_SPEED >> 8) & (0xFFU));
  *_len = 8; *_ide = 0;
  return VCU_WHEEL_SPEEDS_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_VCU_BATTERY_candata(VCU_BATTERY_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->VOLTAGE = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  return VCU_BATTERY_CANID;
}

uint32_t Pack_VCU_BATTERY_candata(const VCU_BATTERY_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < VCU_BATTERY_DLC; _d[i++] = 0);

  _d[0] |= (_m->VOLTAGE & (0xFFU));
  _d[1] |= ((_m->VOLTAGE >> 8) & (0xFFU));
  *_len = 2; *_ide = 0;
  return VCU_BATTERY_CANID;
}

int main( int argc, char* argv[] )
{
    const char* canChannel = "vcan0";
    const int canSocket = can_connect( canChannel, false );

    for( int c=0; c<100; ++c )
    {
        struct can_frame frame;
        if( can_read( canSocket, &frame ) )
        {
            printf("0x%X [%X]", frame.can_id, frame.can_dlc );
            for( int i=0; i<frame.can_dlc; ++i )
                printf( " %02X", frame.data[i] );
            printf("\n");
        }
    }

	can_close( canSocket );

	return 0;
}

