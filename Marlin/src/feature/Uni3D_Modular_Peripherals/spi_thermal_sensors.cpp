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

#include "../../inc/MarlinConfig.h"


#if USES_SPI_THERMAL_SENSORS

#include "../../Marlin.h"
#include "../../module/thermistor/thermistors.h"
#include "spi_thermal_sensors.h"

uint16_t spi_thermal_sensor_raw[0
                                #if ENABLED(SENSOR_0_USES_SPI_CONTROLLER)
                                + 1
                                #endif
                                #if ENABLED(SENSOR_1_USES_SPI_CONTROLLER)
                                + 1
                                #endif
                                #if ENABLED(SENSOR_2_USES_SPI_CONTROLLER)
                                + 1
                                #endif
                                #if ENABLED(SENSOR_3_USES_SPI_CONTROLLER)
                                + 1
                                #endif
                                #if ENABLED(SENSOR_4_USES_SPI_CONTROLLER)
                                + 1
                                #endif
                                #if ENABLED(SENSOR_5_USES_SPI_CONTROLLER)
                                + 1
                                #endif
                                #if ENABLED(SENSOR_BED_USES_SPI_CONTROLLER)
                                + 1
#endif
#if ENABLED(SENSOR_CHAMBER_USES_SPI_CONTROLLER)
  +1
#endif
];

enum class CL_COMMANDS {
  GET_ALL
};

void GetLatestTemps() {
  WRITE(SPI_THERMALCON_CS_PIN, LOW);
  spiInit(SPI_FULL_SPEED);
  spiSend((uint8_t) CL_COMMANDS::GET_ALL);

  spiHardWaitForSlave(SPI_THERMALCON_ATTNREQ_PIN, HIGH, 100);

  uint16_t AllData[SPI_SENSOR_NUM_CHANNELS];
  spiRead((uint8_t *) AllData, sizeof(AllData));
  WRITE(SPI_THERMALCON_CS_PIN, HIGH);

  uint8_t cidx = 0;
#ifdef SENSOR_0_USES_SPI_CONTROLLER
  spi_thermal_sensor_raw[cidx++] = AllData[SENSOR_0_THERMISTOR_CHANNEL];
#endif
#ifdef SENSOR_1_USES_SPI_CONTROLLER
  spi_thermal_sensor_raw[cidx++] = AllData[SENSOR_1_THERMISTOR_CHANNEL];
#endif
#ifdef SENSOR_2_USES_SPI_CONTROLLER
  spi_thermal_sensor_raw[cidx++] = AllData[SENSOR_2_THERMISTOR_CHANNEL];
#endif
#ifdef SENSOR_3_USES_SPI_CONTROLLER
  spi_thermal_sensor_raw[cidx++] = AllData[SENSOR_3_THERMISTOR_CHANNEL];
#endif
#ifdef SENSOR_4_USES_SPI_CONTROLLER
  spi_thermal_sensor_raw[cidx++] = AllData[SENSOR_4_THERMISTOR_CHANNEL];
#endif
#ifdef SENSOR_5_USES_SPI_CONTROLLER
  spi_thermal_sensor_raw[cidx++] = AllData[SENSOR_5_THERMISTOR_CHANNEL];
#endif
#ifdef SENSOR_BED_USES_SPI_CONTROLLER
  spi_thermal_sensor_raw[cidx++] = AllData[SENSOR_BED_THERMISTOR_CHANNEL];
#endif
#ifdef SENSOR_CHAMBER_USES_SPI_CONTROLLER
  spi_thermal_sensor_raw[cidx++] = AllData[SENSOR_CHAMBER_THERMISTOR_CHANNEL];
#endif
}


void spi_thermal_sensors_init() {
  WRITE(SPI_THERMALCON_CS_PIN, HIGH);
}

void spi_thermal_sensors_update_raw() {
  GetLatestTemps();
}

void check_module_connection() {

}


#endif