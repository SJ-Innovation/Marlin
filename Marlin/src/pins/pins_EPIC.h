#pragma once


#define ENCODER_1_TIMER_NUM 1 // Optionally used for INTERNAL_CLOSED_LOOP_CONTROLLER
#define ENCODER_2_TIMER_NUM 4
#define ENCODER_3_TIMER_NUM 5
#define ENCODER_4_TIMER_NUM 8

enum class TIMER_1_ENCODER_PINS {
  A = PE9,
  B = PE11
};

enum class TIMER_2_ENCODER_PINS {
  A = PA15,
  B = PB3
};

enum class TIMER_3_ENCODER_PINS {
  A = PA6,
  B = PA7
};

enum class TIMER_4_ENCODER_PINS {
  A = PD12,
  B = PD13
};

enum class TIMER_5_ENCODER_PINS {
  A = PA0,
  B = PA1
};

enum class TIMER_8_ENCODER_PINS {
  A = PC6,
  B = PC7
};

#define _ENCODER_PINS(TIMER_NUM) TIMER_ ## TIMER_NUM ## _ENCODER_PINS
#define ENCODER_PINS(TIMER_NUM) _ENCODER_PINS(TIMER_NUM)

#if TIMER_SANITY_CHECK(ENCODER_1)
  #error ENCODER_1 currently used by a critical system
#elif TIMER_SANITY_CHECK(ENCODER_2)
  #error ENCODER_2 currently used by a critical system
#elif TIMER_SANITY_CHECK(ENCODER_3)
  #error ENCODER_3 currently used by a critical system
#elif TIMER_SANITY_CHECK(ENCODER_4)
  #error ENCODER_4 currently used by a critical system
#endif

// Closed Loop Encoders

#define X_ENCODER_TIMER_NUM ENCODER_1_TIMER_NUM
#define Y_ENCODER_TIMER_NUM ENCODER_3_TIMER_NUM
#define SPA_ENCODER_TIMER_NUM ENCODER_3_TIMER_NUM
#define SPB_ENCODER_TIMER_NUM ENCODER_4_TIMER_NUM

//typedef struct {
//  uint8_t Pin_A = PC0
//} EncoderSetup_t;

// Motors
#define X_DIR_PIN PE2
#define X_STEP_PIN PE3
#define X_ENABLE_PIN PE4
#define X_CS_PIN PE5

#define Y_DIR_PIN PE6
#define Y_STEP_PIN PC13
#define Y_ENABLE_PIN PC14
#define Y_CS_PIN PC15

#define Z_DIR_PIN PF0
#define Z_STEP_PIN PF1
#define Z_ENABLE_PIN PF3
#define Z_CS_PIN PF2

#define Z2_DIR_PIN PF4
#define Z2_STEP_PIN PF5
#define Z2_ENABLE_PIN PF7
#define Z2_CS_PIN PF6

#define E0_DIR_PIN PF8
#define E0_STEP_PIN PF9
#define E0_ENABLE_PIN PF10
#define E0_CS_PIN PC0

#define E1_DIR_PIN PC1
#define E1_STEP_PIN PC2
#define E1_ENABLE_PIN PC3
#define E1_CS_PIN PA2

#define E2_DIR_PIN PF11
#define E2_STEP_PIN PF12
#define E2_ENABLE_PIN PF13
#define E2_CS_PIN PF15

#define E3_DIR_PIN PF15
#define E3_STEP_PIN PG0
#define E3_ENABLE_PIN PG1
#define E3_CS_PIN PE7

// Mini-Drives
#define DRV_A0_PIN PD7
#define DRV_A1_PIN PG9
#define DRV_A2_PIN PG10
//#define DRV_A3_PIN Doesn't Exist

#define DRV_B0_PIN PD3
#define DRV_B1_PIN PD4
#define DRV_B2_PIN PD5
#define DRV_B3_PIN PD6

#define DRV_C0_PIN PC12
#define DRV_C1_PIN PD0
#define DRV_C2_PIN PD1
#define DRV_C3_PIN PD2

#define DRV_D0_PIN PC11
#define DRV_D1_PIN PC10
#define DRV_D2_PIN PA12
#define DRV_D3_PIN PA15



// Switches
#define SW_A0_PIN PB7
#define SW_A1_PIN PB6
#define SW_A2_PIN PB5
#define SW_A3_PIN PB4
#define SW_A4_PIN PB3

#define SW_B0_PIN PG11
#define SW_B1_PIN PG12
#define SW_B2_PIN PG13
#define SW_B3_PIN PG14
#define SW_B4_PIN PG15

// Expansion Headers
#define EXP1_1_PIN PE12
#define EXP1_2_PIN PE13
#define EXP1_3_PIN PE14
#define EXP1_4_PIN PE15
#define EXP1_5_PIN PB10
#define EXP1_6_PIN PB11
#define EXP1_7_PIN PB12
#define EXP1_8_PIN PB13
//#define EXP1_9_PIN Gnd
//#define EXP1_10_PIN +5v

//#define EXP2_1_PIN SPI_MISO
//#define EXP2_2_PIN SPI_SCK
#define EXP2_3_PINP PB14
#define EXP2_4_PIN PB15
#define EXP2_5_PIN PD8
//#define EXP2_6_PIN SPI_MOSI
#define EXP2_7_PIN PD9
#define EXP2_8_PIN PD10
//#define EXP2_9_PIN Gnd
#define EXP2_10_PIN PD11



// BS PINS FTTB

#define HEATER_0_PIN 1
#define TEMP_0_PIN 1
#define X_MIN_PIN 1
#define Y_MIN_PIN 1
#define Z_MIN_PIN 1
