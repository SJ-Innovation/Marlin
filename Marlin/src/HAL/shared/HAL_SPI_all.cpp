#include "../../inc/MarlinConfig.h"
#include "../../Marlin.h"
#include "HAL_SPI.h"


void spiHardWaitForSlave(const int32_t triggerPin, const bool toGoToState, const millis_t timeout) {
  millis_t timeoutMillis = millis() + timeout;
  while (READ(triggerPin) != toGoToState && PENDING(millis(), timeoutMillis)) {
    idle();
  }
}

uint8_t spiRecWaitForSlave(const uint8_t waitWhileByte, const millis_t timeout) {
  millis_t timeoutMillis = millis() + timeout;
  uint8_t inByte;
  do {
    inByte = spiRec();
  } while (inByte == waitWhileByte && PENDING(millis(), timeoutMillis));
  return inByte;
}

