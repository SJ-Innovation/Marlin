#include "../../inc/MarlinConfig.h"

#if USES_SPI_CLOSEDLOOP

#include "spi_closedloop_controller.h"
#include "../../module/planner.h"
#include "../../gcode/parser.h"


struct CLPinData_t {
  uint16_t cs_pin;
  uint16_t attnreqd_pin;
  uint16_t clok_pin;
};

struct CLTransferPacket_t {
  bool ClEnabled; //RW
  int32_t curr_pos; //RW
  int16_t motor_spr; //RW
  int16_t encoder_spr;  //RW
  uint8_t near_correction_integral;  //RW
  uint8_t far_correction_acc;  //RW
  uint8_t close_far_thresh;  //RW
  int16_t pos_err; //R
};


const uint8_t NumClosedLoops = (0 +

                                #ifdef HAS_X_SPI_CLOSEDLOOP
                                +1
                                #endif
                                #ifdef HAS_X2_SPI_CLOSEDLOOP
                                +1
                                #endif
                                #ifdef HAS_Y_SPI_CLOSEDLOOP
                                + 1
#endif
#ifdef HAS_Y2_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_Z_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_Z2_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_Z3_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_E0_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_E1_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_E2_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_E3_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_E4_SPI_CLOSEDLOOP
  +1
#endif
#ifdef HAS_E5_SPI_CLOSEDLOOP
  +1
#endif
);

const CLPinData_t CLPinData[NumClosedLoops] = {
#ifdef HAS_X_SPI_CLOSEDLOOP
  {X_SPI_CLOSEDLOOP_CS_PIN, X_SPI_CLOSEDLOOP_ATTNREQ_PIN, X_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_X2_SPI_CLOSEDLOOP
  {X2_SPI_CLOSEDLOOP_CS_PIN,X2_SPI_CLOSEDLOOP_ATTNREQ_PIN,X2_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_Y_SPI_CLOSEDLOOP
  {Y_SPI_CLOSEDLOOP_CS_PIN, Y_SPI_CLOSEDLOOP_ATTNREQ_PIN, Y_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_Y2_SPI_CLOSEDLOOP
  {Y2_SPI_CLOSEDLOOP_CS_PIN,Y2_SPI_CLOSEDLOOP_ATTNREQ_PIN,Y2_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_Z_SPI_CLOSEDLOOP
  {Z_SPI_CLOSEDLOOP_CS_PIN,Z_SPI_CLOSEDLOOP_ATTNREQ_PIN,Z_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_Z2_SPI_CLOSEDLOOP
  {Z2_SPI_CLOSEDLOOP_CS_PIN,Z2_SPI_CLOSEDLOOP_ATTNREQ_PIN,Z2_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_Z3_SPI_CLOSEDLOOP
  {Z3_SPI_CLOSEDLOOP_CS_PIN,Z3_SPI_CLOSEDLOOP_ATTNREQ_PIN,Z3_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_E0_SPI_CLOSEDLOOP
  {E0_SPI_CLOSEDLOOP_CS_PIN,E0_SPI_CLOSEDLOOP_ATTNREQ_PIN,E0_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_E1_SPI_CLOSEDLOOP
  {E1_SPI_CLOSEDLOOP_CS_PIN,E1_SPI_CLOSEDLOOP_ATTNREQ_PIN,E1_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_E2_SPI_CLOSEDLOOP
  {E2_SPI_CLOSEDLOOP_CS_PIN,E2_SPI_CLOSEDLOOP_ATTNREQ_PIN,E2_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_E3_SPI_CLOSEDLOOP
  {E3_SPI_CLOSEDLOOP_CS_PIN,E3_SPI_CLOSEDLOOP_ATTNREQ_PIN,E3_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_E4_SPI_CLOSEDLOOP
  {E4_SPI_CLOSEDLOOP_CS_PIN,E4_SPI_CLOSEDLOOP_ATTNREQ_PIN,E4_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
#ifdef HAS_E5_SPI_CLOSEDLOOP
  {E5_SPI_CLOSEDLOOP_CS_PIN,E5_SPI_CLOSEDLOOP_ATTNREQ_PIN,E5_SPI_CLOSEDLOOP_CLOK_PIN},
#endif
};

CLTransferPacket_t Current_CLPacket[NumClosedLoops];
CLTransferPacket_t Last_CLPacket[NumClosedLoops];

enum class CL_COMMANDS {
  GET_ALL,
  SET_ALL,
  GET_ENABLED,
  SET_ENABLED

};

void UpdateStateFromModule(const uint8_t ID) {
  WRITE(CLPinData[ID].cs_pin, LOW);
  spiSend((uint8_t) CL_COMMANDS::GET_ALL);
  spiHardWaitForSlave(CLPinData[ID].attnreqd_pin, HIGH, 100);
  spiRead((uint8_t *) (&(Current_CLPacket[ID])), sizeof(Current_CLPacket[ID]));
  WRITE(CLPinData[ID].cs_pin, HIGH);
}

void SendStateToModule(const uint8_t ID) {
  WRITE(CLPinData[ID].cs_pin, LOW);
  spiSend((uint8_t) CL_COMMANDS::SET_ALL);
  spiHardWaitForSlave(CLPinData[ID].attnreqd_pin, HIGH, 100);
  spiSend((uint8_t *) (&(Current_CLPacket[ID])), sizeof(Current_CLPacket[ID]));
  WRITE(CLPinData[ID].cs_pin, HIGH);
}

void UpdateStatesFromAllModules() {
  LOOP_L_N(i, NumClosedLoops) {
    UpdateStateFromModule(i);
  }
}

void SendStatesToAllModules() {
  LOOP_L_N(i, NumClosedLoops) {
    SendStateToModule(i);
  }
}


bool ClosedLoop_AllMovesComplete() {
  LOOP_L_N(i, NumClosedLoops) {
    if (Current_CLPacket[i].ClEnabled &&
        !READ(CLPinData[i].clok_pin)) { // If closed loop is enabled, and we dont have a high complete signal, the move is still going
      return false;
    }
  }
  return true;
}

void init_closedloop() {
  SendStatesToAllModules();
  UpdateStatesFromAllModules();
}

void closedloop_M12() {
  planner.synchronize(); // We need to be up against the end of the planner. And stopped before editing the modules.
  safe_delay(100); // Wouldn't go amiss to make sure any resonance has died away.
  bool IDsToEffect[NumClosedLoops];

  if (parser.seen_axis()) { // Didnt find an axis, affect them ALL.
    // We found an axis, sift through.
    uint8_t cidx = 0;
#ifdef HAS_X_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('X');
#endif
#ifdef HAS_X2_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('X');
#endif

#ifdef HAS_Y_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('Y');
#endif
#ifdef HAS_Y2_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('Y');
#endif

#ifdef HAS_Z_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('Z');
#endif
#ifdef HAS_Z2_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('Z');
#endif
#ifdef HAS_Z3_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('Z');
#endif

#ifdef HAS_E0_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('E');
#endif
#ifdef HAS_E1_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('E');
#endif
#ifdef HAS_E2_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('E');
#endif
#ifdef HAS_E3_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('E');
#endif
#ifdef HAS_E4_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('E');
#endif
#ifdef HAS_E5_SPI_CLOSEDLOOP
    IDsToEffect[cidx++] = parser.seen('E');
#endif
  }
  else {
    LOOP_L_N(i, NumClosedLoops) {
      IDsToEffect[i] = true;
    }
  }
  // M12 X/Y/Z/E - Narrow down commands to these specific axis
  // M12 Z - Zero The Closed Loop Module(s)
  // M12 Sx - Enable/Disable Closed Loop
  // M12 Kxxx - Set Motor SPR
  // M12 Lxxx - Set Encoder SPR
  // M12 Cxxx - Set Near_Far Threshold
  // M12 Axxx - Set Far Max Acceleration
  // M12 Ixxx - Set Near Correction Integral.

  UpdateStatesFromAllModules();
  memcpy(Last_CLPacket, Current_CLPacket, sizeof(Current_CLPacket)); // Take a copy to work out a difference later on


  LOOP_L_N(i, NumClosedLoops) {
    if (IDsToEffect[i]) { // Are we allowed to edit this module, as per the command?
      if (parser.seenval('S')) {
        Current_CLPacket[i].ClEnabled = parser.value_bool();
      }
      if (parser.seen('Z')) {
        Current_CLPacket[i].curr_pos = 0;
      }
      if (parser.seenval('K')) {
        Current_CLPacket[i].motor_spr = parser.value_ushort();
      }
      if (parser.seenval('L')) {
        Current_CLPacket[i].encoder_spr = parser.value_ushort();
      }
      if (parser.seenval('C')) {
        Current_CLPacket[i].close_far_thresh = parser.value_byte();
      }
      if (parser.seenval('A')) {
        Current_CLPacket[i].far_correction_acc = parser.value_byte();
      }
      if (parser.seenval('I')) {
        Current_CLPacket[i].near_correction_integral = parser.value_byte();
      }
    }
  }


  LOOP_L_N(i, NumClosedLoops) { // Update those with diffs
    if (memcmp(&(Last_CLPacket[i]), &(Current_CLPacket[i]), sizeof(Current_CLPacket[i])) != 0) {
      SendStateToModule(i);
    }
  }


}


#endif