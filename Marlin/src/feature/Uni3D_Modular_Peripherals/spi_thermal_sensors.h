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
#pragma once

#include "../../inc/MarlinConfigPre.h"

#if USES_SPI_THERMAL_SENSORS
  #define SPI_SENSOR_NUM_CHANNELS 6


  #if !WITHIN(SENSOR_0_THERMISTOR_CHANNEL,-1,SPI_SENSOR_NUM_CHANNELS-1)
    #error "SENSOR_0_THERMISTOR_CHANNEL must be between -1 and  SPI_SENSOR_NUM_CHANNELS-1"
  #endif
  #if !WITHIN(SENSOR_1_THERMISTOR_CHANNEL,-1,SPI_SENSOR_NUM_CHANNELS-1)
    #error "SENSOR_1_THERMISTOR_CHANNEL must be between -1 and  SPI_SENSOR_NUM_CHANNELS-1"
  #endif
  #if !WITHIN(SENSOR_2_THERMISTOR_CHANNEL,-1,SPI_SENSOR_NUM_CHANNELS-1)
    #error "SENSOR_2_THERMISTOR_CHANNEL must be between -1 and  SPI_SENSOR_NUM_CHANNELS-1"
  #endif
  #if !WITHIN(SENSOR_3_THERMISTOR_CHANNEL,-1,SPI_SENSOR_NUM_CHANNELS-1)
    #error "SENSOR_3_THERMISTOR_CHANNEL must be between -1 and  SPI_SENSOR_NUM_CHANNELS-1"
  #endif
  #if !WITHIN(SENSOR_4_THERMISTOR_CHANNEL,-1,SPI_SENSOR_NUM_CHANNELS-1)
    #error "SENSOR_4_THERMISTOR_CHANNEL must be between -1 and  SPI_SENSOR_NUM_CHANNELS-1"
  #endif
  #if !WITHIN(SENSOR_5_THERMISTOR_CHANNEL,-1,SPI_SENSOR_NUM_CHANNELS-1)
    #error "SENSOR_5_THERMISTOR_CHANNEL must be between -1 and  SPI_SENSOR_NUM_CHANNELS-1"
  #endif
  #if !WITHIN(SENSOR_BED_THERMISTOR_CHANNEL,-1,SPI_SENSOR_NUM_CHANNELS-1)
    #error "SENSOR_BED_THERMISTOR_CHANNEL must be between -1 and  SPI_SENSOR_NUM_CHANNELS-1"
  #endif
  #if !WITHIN(SENSOR_CHAMBER_THERMISTOR_CHANNEL,-1,SPI_SENSOR_NUM_CHANNELS-1)
    #error "SENSOR_CHAMBER_THERMISTOR_CHANNEL must be between -1 and  SPI_SENSOR_NUM_CHANNELS-1"
  #endif



void spi_thermal_sensors_init();

void check_module_connection();

void spi_thermal_sensors_update_raw();


extern uint16_t spi_thermal_sensor_raw[];
#endif