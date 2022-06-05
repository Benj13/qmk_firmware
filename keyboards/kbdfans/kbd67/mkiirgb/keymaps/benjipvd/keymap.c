/*   Copyright 2021 Jonavin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

// LAYERS
enum custom_user_layers {
    _BASE,
    _FN1,
    _LOWER
};

#define ARRAYSIZE(arr)  sizeof(arr)/sizeof(arr[0])

#define FR_CCED  RALT(KC_COMM)
#define SE_ARNG  RALT(KC_W)
#define SE_ODIA  RALT(KC_P)
#define SE_ADIA  RALT(KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base layer
	* ,--------------------------------------------------------------------------------------------------.
	* | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | PgUp |
	* |-------------------------------------------------------------------------------------------+------+
	* | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | PgDn |
	* |-------------------------------------------------------------------------------------------+------+
	* | Caps     |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | End  |
	* |-------------------------------------------------------------------------------------------+------+
	* | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | Del  |
	* +-------------------------------------------------------------------------┬---┬-------------+------+
	* | LCtrl | LGUI | LAlt |               Space                | RAlt | MO(1) |   | Left  | Dn  | Rght |
	* `-------------------------------------------------------------------------┘   └-------------+------´
	*/
    [_BASE] = LAYOUT_65_ansi_blocker(
					KC_ESC,         KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_PGUP,
					KC_TAB,         KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGDN,
					LT(2, KC_CAPS), KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_END,
					KC_LSFT,        KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_DEL,
					KC_LCTL,        KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT,           MO(1),    KC_LEFT,           KC_DOWN,   KC_RIGHT),
	/* FN and International layer
	* ,--------------------------------------------------------------------------------------------------.
	* |     |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  | F8 | F9 | F10 | F11 | F12 |  DEL  | Sleep |
	* |-------------------------------------------------------------------------------------------+------+
	* |        |     |     |     |     |     |     |     |     |     |     |  Å  |     |          |      |
	* |-------------------------------------------------------------------------------------------+------+
	* |          |     |     |     |     |     |     |     |     |     |  Ö  |  Ä  |              |      |
	* |-------------------------------------------------------------------------------------------+------+
	* |            |     |     |  ç  |     |     |     |     |     |     |     |            |     |      |
	* +-------------------------------------------------------------------------┬---┬-------------+------+
	* |       |      |      |                                    |      |       |   |       |     |      |
	* `-------------------------------------------------------------------------┘   └-------------+------´
	*/
	[_FN1] = LAYOUT_65_ansi_blocker(
					_______,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_SLEP,
					_______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, SE_ARNG, _______, _______, _______,
					_______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, SE_ODIA, SE_ADIA,          _______, _______,
					_______, _______,  _______, FR_CCED, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
					_______, _______,  _______,                   _______,                   _______,          _______,          _______, _______, _______),
    /* RGB, Volume and Rese
	* ,--------------------------------------------------------------------------------------------------.
	* |     |      |      |      |      |      |      |      |    |     |     |     |    | Reset   | Boot |
	* |-------------------------------------------------------------------------------------------+------+
	* |        | RGB | MOD | RMOD |     |     |     |     |     |     |     |     |     |           |      |
	* |-------------------------------------------------------------------------------------------+------+
	* |          | HUI | HUD | SAI | SAD | VAI | VAD |     |     |     |     |     |               |      |
	* |-------------------------------------------------------------------------------------------+------+
	* |            |     |     |     |     |     |     |     |     |     |     |    Play    | VolU | Stop |
	* +-------------------------------------------------------------------------┬---┬-------------+------+
	* |       |      |      |                                    |      |       |   | Prev  | VolD | Next |
	* `-------------------------------------------------------------------------┘   └-------------+------´
	*/
	[_LOWER] = LAYOUT_65_ansi_blocker(
					_______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  EE_CLR, QK_BOOT,
					_______, RGB_TOG, RGB_MOD, RGB_RMOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
					_______, RGB_HUI, RGB_HUD,  RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,          _______, _______,
					_______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPLY, KC_VOLU, KC_MSTP,
					_______, _______, _______,                    _______,                   _______,          _______,          KC_MPRV, KC_VOLD, KC_MNXT)
};

#ifdef RGB_MATRIX_ENABLE
    // Capslock, Scroll lock and Numlock indicator
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        switch(get_highest_layer(layer_state)){  // special handling per layer
        case _FN1:  // on Fn layer select what the encoder does when pressed
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_FN); i++) {
                rgb_matrix_set_color(LED_LIST_FN[i], RGB_GOLD);
            }
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_SW); i++) {
                rgb_matrix_set_color(LED_LIST_SW[i], RGB_TEAL);
            }
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_FR); i++) {
                rgb_matrix_set_color(LED_LIST_FR[i], RGB_CORAL);
            }
            break;
        case _LOWER:
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_BOOT); i++) {
                rgb_matrix_set_color(LED_LIST_BOOT[i], RGB_RED);
            }
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MEDIA); i++) {
                rgb_matrix_set_color(LED_LIST_MEDIA[i], RGB_GREEN);
            }
            for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_RGB); i++) {
                rgb_matrix_set_color(LED_LIST_RGB[i], RGB_BLUE);
            }
            break;
        default:
            break;
        }
    }
#endif

void keyboard_post_init_keymap(void) {
    // keyboard_post_init_user() moved to userspace
    #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    #endif
}
