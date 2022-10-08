/* Copyright 2019 dnsnrk 
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

#define RGBLIGHT_LAYERS
#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 230
#define RGBLIGHT_EFFECT_BREATHING

#define IGNORE_MOD_TAP_INTERRUPT //helps with homerow mods
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

#define TAPPING_TERM 165

#define COMBO_COUNT 3
#define COMBO_TERM 30