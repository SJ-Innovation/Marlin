/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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
#include "../../module/motion.h"
#include "../../module/tool_change.h"
#include "../../module/probe.h"
#include "../../module/planner.h"
#include "../../feature/bedlevel/bedlevel.h"
#include "../gcode.h"

#if ENABLED(AUTO_NOZZLE_Z_OFFSET_CAL)

void GcodeSuite::G8() {
#if HAS_LEVELING
  const bool was_enabled = planner.leveling_active;
  set_bed_leveling_enabled(false);
#endif

  uint8_t old_active_extruder = active_extruder;
  float relative_z_offsets[EXTRUDERS];

  HOTEND_LOOP() { // Blank out the current z offsets
    hotend_offset[Z_AXIS][e] = 0;
    relative_z_offsets[e] = 0;
  };

  HOTEND_LOOP() { // Probe all of the extruders
    if (active_extruder != e) {
      tool_change(e, false);
    }

    //  setup_for_endstop_or_probe_move();
    relative_z_offsets[e] = probe.probe_at_point(safe_homing_xy, ProbePtRaise::PROBE_PT_NONE, 0, 0);
    //  clean_up_after_endstop_or_probe_move();
    if (isnan(relative_z_offsets[e])) { // Probing Failure
      break;
    }
  }

  tool_change(old_active_extruder, false);

  SERIAL_ECHOPGM("New Offsets: ");
  HOTEND_LOOP() {
    hotend_offset[Z_AXIS][e] = relative_z_offsets[e] - relative_z_offsets[0]; // First extruder ends up 0, others end up relative to first
    SERIAL_ECHO(hotend_offset[Z_AXIS][e]);
    SERIAL_ECHOPGM(" ");
  }
  SERIAL_ECHOLNPGM("");
#if HAS_LEVELING
  set_bed_leveling_enabled(was_enabled);
#endif
}

#endif
