#include "../../inc/MarlinConfig.h"

#if ENABLED(UNI3D_MODULAR_INTERFACE)

#include "CheckHealth.h"


#define CHECK_STAT(ID) UNICON_##ID##_MODE != MODULE_DISABLED
#define MODULE_CONNECTED_SIG 0
#define READ_STAT(ID) do{\
  SET_BIT_TO(ConnStat, ID, READ(UNICON_##ID##_CONN_PIN)); \
  SET_BIT_TO(ConnStatShouldBe, ID, MODULE_CONNECTED_SIG); \
  SET_BIT_TO(AttnReqStat, ID, READ(UNICON_##ID##_ATTN_REQD_PIN)); }while (0)


void CheckConnections() {
  uint32_t ConnStat = 0;
  uint32_t ConnStatShouldBe = MODULE_CONNECTED_SIG * ((2 ^ (sizeof(ConnStatShouldBe) * 8)) - 1);
  uint32_t AttnReqStat = 0;
#if CHECK_STAT(0)
  READ_STAT(0);
#endif
#if CHECK_STAT(1)
  READ_STAT(1);
#endif
#if CHECK_STAT(2)
  READ_STAT(2);
#endif
#if CHECK_STAT(3)
  READ_STAT(3);
#endif
#if CHECK_STAT(4)
  READ_STAT(4);
#endif
#if CHECK_STAT(5)
  READ_STAT(5);
#endif
#if CHECK_STAT(6)
  READ_STAT(6);
#endif
#if CHECK_STAT(7)
  READ_STAT(7);
#endif
#if CHECK_STAT(8)
  READ_STAT(8);
#endif
#if CHECK_STAT(9)
  READ_STAT(9);
#endif
#if CHECK_STAT(10)
  READ_STAT(10);
#endif
#if CHECK_STAT(11)
  READ_STAT(11);
#endif
#if CHECK_STAT(12)
  READ_STAT(12);
#endif

  for (uint8_t i = 0; i < (sizeof(ConnStat) * 8); i++) {
    if (TEST(ConnStat, i) != TEST(ConnStatShouldBe, i)) {
      SERIAL_ECHOPGM("UNICON CONNECTION ERROR: UNICON_");
      SERIAL_ECHOLN(i);
    }
//    if (TEST(AttnReqStat, i) != LOW) {
//      SERIAL_ECHOPGM("UNICON ATTENTION REQUIRED: ");
//      SERIAL_ECHOLN(i);
//    }
  }

}


void CheckUniconHealth() {
  static millis_t nextCheck=0;
  if(ELAPSED(millis(),nextCheck)){
    CheckConnections();
    nextCheck = millis() + 1000;
  }
}


#endif