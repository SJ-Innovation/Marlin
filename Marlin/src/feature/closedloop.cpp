/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "../inc/MarlinConfig.h"

#if ENABLED(INTERNAL_CLOSED_LOOP_CONTROLLER)

#include "closedloop.h"
#include "HardwareTimer.h"


  #define ENCODER_DEFS(ID) \
    HardwareTimer ID##_Encoder(ID##_ENCODER_TIMER_NUM);\
    int16_t ID##_ENCODER_INTS = 0;\
    inline void ID##_ENCODER_INT_HANDLER() {\
      if (ID##_Encoder.getDirection()) {\
        ID##_ENCODER_INTS++;\
      }\
      else{\
        ID##_ENCODER_INTS--;\
      }\
    }

  #define INIT_ENCODER(ID) do{\
    SET_INPUT(static_cast<int>(ENCODER_PINS(ID##_ENCODER_TIMER_NUM)::A));\
    SET_INPUT(static_cast<int>(ENCODER_PINS(ID##_ENCODER_TIMER_NUM)::B));\
    ID##_Encoder.setMode(0, TIMER_ENCODER); \
    ID##_Encoder.pause(); \
    ID##_Encoder.setPrescaleFactor(1);\
    ID##_Encoder.setOverflow(10000); \
    ID##_Encoder.setCount(0); \
    ID##_Encoder.setEdgeCounting(TIMER_SMCR_SMS_ENCODER3); \
    ID##_Encoder.attachInterrupt(0, ID##_ENCODER_INT_HANDLER); \
    ID##_Encoder.resume(); \
  } while(0);

#if HAS_X_ENCODER
ENCODER_DEFS(X);
#endif

#if HAS_Y_ENCODER
ENCODER_DEFS(Y);
#endif

#if HAS_SPA_ENCODER
ENCODER_DEFS(SPA);
#endif

#if HAS_SPB_ENCODER
ENCODER_DEFS(SPB);
#endif


void init_closedloop() {
#if HAS_X_ENCODER
  INIT_ENCODER(X);
#endif

#if HAS_Y_ENCODER
  INIT_ENCODER(Y);
#endif

#if HAS_SPA_ENCODER
  INIT_ENCODER(SPA);
#endif

#if HAS_SPB_ENCODER
  INIT_ENCODER(SPB);
#endif
}

#endif


#if ENABLED(EXTERNAL_CLOSED_LOOP_CONTROLLER)

#if !PIN_EXISTS(CLOSED_LOOP_ENABLE) || !PIN_EXISTS(CLOSED_LOOP_MOVE_COMPLETE)
  #error "CLOSED_LOOP_ENABLE_PIN and CLOSED_LOOP_MOVE_COMPLETE_PIN are required for EXTERNAL_CLOSED_LOOP_CONTROLLER."
#endif

#include "closedloop.h"

void init_closedloop() {
  OUT_WRITE(CLOSED_LOOP_ENABLE_PIN, LOW);
  SET_INPUT_PULLUP(CLOSED_LOOP_MOVE_COMPLETE_PIN);
}

void set_closedloop(const byte val) {
  OUT_WRITE(CLOSED_LOOP_ENABLE_PIN, val);
}

#endif // EXTERNAL_CLOSED_LOOP_CONTROLLER
