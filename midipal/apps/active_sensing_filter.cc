// Copyright 2011 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------------------------
//
// Active Sensing filter app.

#include "midipal/apps/active_sensing_filter.h"

#include "midipal/ui.h"

namespace midipal { namespace apps {

const prog_uint8_t active_sensing_filter_factory_data[1] PROGMEM = {
  1,
};

/* static */
uint8_t ActiveSensingFilter::enabled_;

/* static */
const prog_AppInfo ActiveSensingFilter::app_info_ PROGMEM = {
  &OnInit, // void (*OnInit)();
  NULL, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnNoteAftertouch)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnAftertouch)(uint8_t, uint8_t);
  NULL, // void (*OnControlChange)(uint8_t, uint8_t, uint8_t);
  NULL, // void (*OnProgramChange)(uint8_t, uint8_t);
  NULL, // void (*OnPitchBend)(uint8_t, uint16_t);
  NULL, // void (*OnSysExByte)(uint8_t);
  NULL, // void (*OnClock)();
  NULL, // void (*OnStart)();
  NULL, // void (*OnContinue)();
  NULL, // void (*OnStop)();
  NULL, // uint8_t (*CheckChannel)(uint8_t);
  &OnRawByte, // void (*OnRawByte)(uint8_t);
  NULL, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  NULL, // void (*OnInternalClockTick)();
  NULL, // void (*OnInternalClockStep)();
  NULL, // uint8_t (*OnIncrement)(int8_t);
  NULL, // uint8_t (*OnClick)();
  NULL, // uint8_t (*OnPot)(uint8_t, uint8_t);
  NULL, // uint8_t (*OnRedraw)();
  NULL, // void (*OnIdle)();
  NULL, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, // uint8_t (*GetParameter)(uint8_t);
  NULL, // uint8_t (*CheckPageStatus)(uint8_t);
  1, // settings_size
  SETTINGS_0XFE_FILTER, // settings_offset
  &enabled_, // settings_data
  active_sensing_filter_factory_data, // factory_data
  STR_RES_0XFE_FLT, // app_name
};  
  
/* static */
void ActiveSensingFilter::OnInit() {
  ui.AddPage(STR_RES_FLT, STR_RES_OFF, 0, 1);
}

/* static */
void ActiveSensingFilter::OnRawByte(uint8_t byte) {
  if (byte != 0xfe || !enabled_) {
    app.SendNow(byte);
  }
}

} }  // namespace midipal::apps
