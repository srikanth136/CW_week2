
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// This file must define:
// base monitor struct
// function signature for CRC calculation
// function signature for getting system tick value (100 us step)
#include "canmonitorutil.h"



// def @MOTOR_CURRENT CAN Message (800)
#define MOTOR_CURRENT_IDE (0U)
#define MOTOR_CURRENT_DLC (4U)
#define MOTOR_CURRENT_CANID (0x320U)
typedef struct
{

  uint16_t FRONT_CURRENT;                   //      Bits=16.  [ -30000, 30000  ]  Unit:'mA'   

  uint16_t REAR_CURRENT;                    //      Bits=16.  [ -30000, 30000  ]  Unit:'mA'   
} MOTOR_CURRENT_t;

// def @AI_DRIVE_REQUEST CAN Message (1313)
#define AI_DRIVE_REQUEST_IDE (0U)
#define AI_DRIVE_REQUEST_DLC (6U)
#define AI_DRIVE_REQUEST_CANID (0x521U)
// signal: @STEERING_REQUEST
#define AI_DRIVE_REQUEST_STEERING_REQUEST_CovFactor (0.01)
// conversion value to CAN signal
#define AI_DRIVE_REQUEST_STEERING_REQUEST_toS(x) ((int16_t)((x) / 0.01))
// conversion value from CAN signal
#define AI_DRIVE_REQUEST_STEERING_REQUEST_fromS(x) ((x) * 0.01)

typedef struct
{

  int16_t FRONT_TRQ_REQUEST;                //  [-] Bits=16.  [ -32768, 32767  ]  Unit:'Nm'   

  int16_t STEERING_REQUEST;                 //  [-] Bits=16.  [ -0.35 , 0.35   ]  Unit:'rad'   Factor= 0.01  

  int16_t REAR_TRQ_REQUEST;                 //  [-] Bits=16.  [ -32768, 32767  ]  Unit:'Nm'   
} AI_DRIVE_REQUEST_t;

// def @VCU_WHEEL_SPEEDS CAN Message (1317)
#define VCU_WHEEL_SPEEDS_IDE (0U)
#define VCU_WHEEL_SPEEDS_DLC (8U)
#define VCU_WHEEL_SPEEDS_CANID (0x525U)
// signal: @FL_WHEEL_SPEED
#define VCU_WHEEL_SPEEDS_FL_WHEEL_SPEED_CovFactor (0.1)
// conversion value to CAN signal
#define VCU_WHEEL_SPEEDS_FL_WHEEL_SPEED_toS(x) ((uint16_t)((x) / 0.1))
// conversion value from CAN signal
#define VCU_WHEEL_SPEEDS_FL_WHEEL_SPEED_fromS(x) ((x) * 0.1)

// signal: @FR_WHEEL_SPEED
#define VCU_WHEEL_SPEEDS_FR_WHEEL_SPEED_CovFactor (0.1)
// conversion value to CAN signal
#define VCU_WHEEL_SPEEDS_FR_WHEEL_SPEED_toS(x) ((uint16_t)((x) / 0.1))
// conversion value from CAN signal
#define VCU_WHEEL_SPEEDS_FR_WHEEL_SPEED_fromS(x) ((x) * 0.1)

// signal: @RL_WHEEL_SPEED
#define VCU_WHEEL_SPEEDS_RL_WHEEL_SPEED_CovFactor (0.1)
// conversion value to CAN signal
#define VCU_WHEEL_SPEEDS_RL_WHEEL_SPEED_toS(x) ((uint16_t)((x) / 0.1))
// conversion value from CAN signal
#define VCU_WHEEL_SPEEDS_RL_WHEEL_SPEED_fromS(x) ((x) * 0.1)

// signal: @RR_WHEEL_SPEED
#define VCU_WHEEL_SPEEDS_RR_WHEEL_SPEED_CovFactor (0.1)
// conversion value to CAN signal
#define VCU_WHEEL_SPEEDS_RR_WHEEL_SPEED_toS(x) ((uint16_t)((x) / 0.1))
// conversion value from CAN signal
#define VCU_WHEEL_SPEEDS_RR_WHEEL_SPEED_fromS(x) ((x) * 0.1)

typedef struct
{

  uint16_t FL_WHEEL_SPEED;                  //      Bits=16.  [ 0     , 65535  ]  Unit:'rpm'   Factor= 0.1   

  uint16_t FR_WHEEL_SPEED;                  //      Bits=16.  [ 0     , 65535  ]  Unit:'rpm'   Factor= 0.1   
  
  uint16_t RL_WHEEL_SPEED;                  //      Bits=16.  [ 0     , 65535  ]  Unit:'rpm'   Factor= 0.1   

  uint16_t RR_WHEEL_SPEED;                  //      Bits=16.  [ 0     , 65535  ]  Unit:'rpm'   Factor= 0.1   
} VCU_WHEEL_SPEEDS_t;

// def @VCU_BATTERY CAN Message (1318)
#define VCU_BATTERY_IDE (0U)
#define VCU_BATTERY_DLC (2U)
#define VCU_BATTERY_CANID (0x526U)
// signal: @VOLTAGE
#define VCU_BATTERY_VOLTAGE_CovFactor (0.001)
// conversion value to CAN signal
#define VCU_BATTERY_VOLTAGE_toS(x) ((uint16_t)((x) / 0.001))
// conversion value from CAN signal
#define VCU_BATTERY_VOLTAGE_fromS(x) ((x) * 0.001)

typedef struct
{

  uint16_t VOLTAGE;                         //      Bits=16.  [ 0     , 13     ]  Unit:'V'     Factor= 0.001 
} VCU_BATTERY_t;

uint32_t Unpack_MOTOR_CURRENT_candata(MOTOR_CURRENT_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_MOTOR_CURRENT_candata(const MOTOR_CURRENT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_AI_DRIVE_REQUEST_candata(AI_DRIVE_REQUEST_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_AI_DRIVE_REQUEST_candata(const AI_DRIVE_REQUEST_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_VCU_WHEEL_SPEEDS_candata(VCU_WHEEL_SPEEDS_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_VCU_WHEEL_SPEEDS_candata(const VCU_WHEEL_SPEEDS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_VCU_BATTERY_candata(VCU_BATTERY_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_VCU_BATTERY_candata(const VCU_BATTERY_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);

#ifdef __cplusplus
}
#endif

