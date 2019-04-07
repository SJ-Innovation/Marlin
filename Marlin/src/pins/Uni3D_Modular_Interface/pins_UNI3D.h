#pragma once
#define UNI3D_MODULAR_INTERFACE

#include "Uni3D_V0_1_PinMap.h"
#include "CheckHealth.h"
#undef BOARD_NAME
#define BOARD_NAME "Uni3D V0.1"


#define LCD_PINS_D7 EXP_1_8_PIN
#define LCD_PINS_D6 EXP_1_7_PIN
#define LCD_PINS_D5 EXP_1_6_PIN
#define LCD_PINS_D4 EXP_1_5_PIN
#define LCD_PINS_RS EXP_1_4_PIN
#define LCD_PINS_ENABLE EXP_1_3_PIN
#define BEEPER_PIN EXP_1_1_PIN
#define BTN_ENC EXP_1_2_PIN
#define BTN_EN1 EXP_2_5_PIN
#define BTN_EN2 EXP_2_3_PIN
#define SD_DETECT_PIN EXP_2_7_PIN
#define KILL_PIN EXP_2_8_PIN
#define SDSS EXP_2_4_PIN
#define LED_PIN LED_BUILTIN




#define MODULE_DISABLED 0


#include "InputModule.h"
#include "ThermalModule.h"
#include "ClosedLoopMotorModule.h"
#include "OpenLoopMotorModule.h"
#include "LowPowerControllerModule.h"



//===========================
#define UNICON_0_MODE MODULE_INPUT
#if UNICON_0_MODE != MODULE_DISABLED
  #define X_MIN_PIN BIND(UNICON_0,INPUT_0)
  #define Y_MIN_PIN BIND(UNICON_0,INPUT_1)
  #define Z_MIN_PIN BIND(UNICON_0,INPUT_2)
#endif
//===========================



//===========================
#define UNICON_1_MODE MODULE_THERMAL
#if UNICON_1_MODE != MODULE_DISABLED
  #define SPI_THERMALCON_CS_PIN BIND(UNICON_1,TCON_CS)
  #define SPI_THERMALCON_ATTNREQ_PIN BIND(UNICON_1,ATTN_REQD)

  #define HEATER_0_PIN BIND(UNICON_1,EXT_0)
  #define HEATER_1_PIN BIND(UNICON_1,EXT_1)
  #define HEATER_2_PIN BIND(UNICON_1,EXT_2)
  #define HEATER_BED_PIN BIND(UNICON_1,EXT_3)

#endif
//===========================



//===========================
#define UNICON_2_MODE MODULE_LOWPOWER
#if UNICON_2_MODE != MODULE_DISABLED
//Add your Module description here
  #define CONTROLLER_FAN_PIN BIND(UNICON_2,OUTPUT_0)
  #define E0_AUTO_FAN_PIN  BIND(UNICON_2,OUTPUT_1)
  #define E1_AUTO_FAN_PIN  BIND(UNICON_2,OUTPUT_2)
  #define E2_AUTO_FAN_PIN   BIND(UNICON_2,OUTPUT_3)
  #define FAN_PIN  BIND(UNICON_2,OUTPUT_4)
  #define FAN1_PIN BIND(UNICON_2,OUTPUT_5)
  #define FAN2_PIN BIND(UNICON_2,OUTPUT_6)
#endif
//===========================



//===========================
#define UNICON_3_MODE MODULE_MOTOR_CLOSEDLOOP
#if UNICON_3_MODE != MODULE_DISABLED
//Add your Module description here
  #define X_ENABLE_PIN BIND(UNICON_3,DRV_ENABLE)
  #define X_STEP_PIN BIND(UNICON_3,DRV_STEP)
  #define X_DIR_PIN BIND(UNICON_3,DRV_DIR)
  #define X_CS_PIN BIND(UNICON_3,DRV_CS)
  #define X_SPI_CLOSEDLOOP_CS_PIN BIND(UNICON_3,CL_CS) // TODO: Is there any way of doing this with just an Axis identifier?
  #define X_SPI_CLOSEDLOOP_CLOK_PIN BIND(UNICON_3,CL_OK)
  #define X_SPI_CLOSEDLOOP_ATTNREQ_PIN BIND(UNICON_3,ATTN_REQD)
#endif
//===========================



//===========================
#define UNICON_4_MODE MODULE_MOTOR_CLOSEDLOOP
#if UNICON_4_MODE != MODULE_DISABLED
//Add your Module description here
  #define Y_ENABLE_PIN BIND(UNICON_4,DRV_ENABLE)
  //BIND(UNICON_4,DRV_ENABLE)
  #define Y_STEP_PIN BIND(UNICON_4,DRV_STEP)
  #define Y_DIR_PIN BIND(UNICON_4,DRV_DIR)
  #define Y_CS_PIN BIND(UNICON_4,DRV_CS)
  #define Y_SPI_CLOSEDLOOP_CS_PIN BIND(UNICON_4,CL_CS)
  #define Y_SPI_CLOSEDLOOP_CLOK_PIN BIND(UNICON_4,CL_OK)
  #define Y_SPI_CLOSEDLOOP_ATTNREQ_PIN BIND(UNICON_4,ATTN_REQD)
#endif
//===========================



//===========================
#define UNICON_5_MODE MODULE_MOTOR_OPENLOOP
#if UNICON_5_MODE != MODULE_DISABLED
//Add your Module description here
  #define Z_ENABLE_PIN BIND(UNICON_5,DRV_ENABLE)
  #define Z_STEP_PIN BIND(UNICON_5,DRV_STEP)
  #define Z_DIR_PIN BIND(UNICON_5,DRV_DIR)
  #define Z_CS_PIN BIND(UNICON_5,DRV_CS)
#endif
//===========================



//===========================
#define UNICON_6_MODE MODULE_MOTOR_OPENLOOP
#if UNICON_6_MODE != MODULE_DISABLED
//Add your Module description here
  #define E0_ENABLE_PIN BIND(UNICON_6,DRV_ENABLE)
  #define E0_STEP_PIN BIND(UNICON_6,DRV_STEP)
  #define E0_DIR_PIN BIND(UNICON_6,DRV_DIR)
  #define E0_CS_PIN BIND(UNICON_6,DRV_CS)
#endif
//===========================



//===========================
#define UNICON_7_MODE MODULE_MOTOR_OPENLOOP
#if UNICON_7_MODE != MODULE_DISABLED
//Add your Module description here
  #define E1_ENABLE_PIN BIND(UNICON_7,DRV_ENABLE)
  #define E1_STEP_PIN BIND(UNICON_7,DRV_STEP)
  #define E1_DIR_PIN BIND(UNICON_7,DRV_DIR)
  #define E1_CS_PIN BIND(UNICON_7,DRV_CS)
#endif
//===========================



//===========================
#define UNICON_8_MODE MODULE_MOTOR_OPENLOOP
#if UNICON_8_MODE != MODULE_DISABLED
//Add your Module description here
  #define E2_ENABLE_PIN BIND(UNICON_8,DRV_ENABLE)
  #define E2_STEP_PIN BIND(UNICON_8,DRV_STEP)
  #define E2_DIR_PIN BIND(UNICON_8,DRV_DIR)
  #define E2_CS_PIN BIND(UNICON_8,DRV_CS)
#endif
//===========================



//===========================
#define UNICON_9_MODE MODULE_DISABLED
#if UNICON_9_MODE != MODULE_DISABLED
//Add your Module description here

#endif
//===========================



//===========================
#define UNICON_10_MODE MODULE_DISABLED
#if UNICON_10_MODE != MODULE_DISABLED
//Add your Module description here

#endif
//===========================



//===========================
#define UNICON_11_MODE MODULE_DISABLED
#if UNICON_11_MODE != MODULE_DISABLED
//Add your Module description here

#endif
//===========================



//===========================
#define UNICON_12_MODE MODULE_DISABLED
#if UNICON_12_MODE != MODULE_DISABLED
//Add your Module description here

#endif
//===========================

