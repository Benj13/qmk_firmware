/* Copyright 2021 projectcain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 8
#    define COMBO_TERM 30
#endif

#define IGNORE_MOD_TAP_INTERRUPT //helps with homerow mods
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

#define RGB_DI_PIN D5
#ifdef RGB_DI_PIN
  #define RGBLED_NUM 14
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#endif