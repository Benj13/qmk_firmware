/* Copyright 2020 gtips
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
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define FR_CCED  RALT(KC_COMM)
#define SE_ARNG  RALT(KC_W)
#define SE_ODIA  RALT(KC_P)
#define SE_ADIA  RALT(KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer - QWERTY
  * ,-----------------------------------------+         +-----------------------------------------.
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |         |   Y  |   U  |   I  |   O  |   P  |   '  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * | Shift|   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   ;  | Bksp |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * | Ctrl |   Z  |   X  |   C  |   V  |   B  |         |   N  |   M  |   ,  |   .  |   /  | Enter|
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             | Lower|  GUI |  Space  |  Alt | Raise|
  *                             +-------------/         \-------------+
  */
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_QUOT,
    KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  RSFT_T(KC_BSPC),
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
                                            LOWER,  KC_RGUI,    KC_SPC, KC_LALT,     RAISE
  ),

  /* Lower Layer - Symbols
  * ,-----------------------------------------+         +-----------------------------------------.
  * |  Esc |   !  |   @  |   #  |   $  |   %  |         |   ^  |   &  |   *  |   (  |   )  |  Del |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |   -  |   =  |   [  |   ]  |   |  |         | Left | Down |  Up  | Right|   `  |   ~  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |   ç  |   Å  |   Ä  |   Ö  |         | Home |  End | PgUp | PgDn |      |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |      |      |  Space  |      |      |
  *                             +-------------/         \-------------+
  */
  [_LOWER] = LAYOUT_reviung41(
    KC_ESC,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  FR_CCED,  SE_ARNG,  SE_ADIA,  SE_ODIA,   _______,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  _______,  _______,
                                            _______,   _______,  KC_SPC,   _______,  _______
  ),

  /* Raise Layer - Number and FN
  * ,-----------------------------------------+         +-----------------------------------------.
  * |  Esc |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  |  Del |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |         |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |      |      |      |      |         |      |      |      |      |      |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             | Raise|  GUI |  Space  |  Alt | Lower|
  *                             +-------------/         \-------------+
  */  
  [_RAISE] = LAYOUT_reviung41(
     KC_ESC,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
      KC_F1,  KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                            _______,   _______,  KC_SPC,   _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  _______,   RGB_TOG,            _______,  _______,  _______,  _______,  _______,  _______,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______, _______,  _______,  _______,   _______,            QK_BOOT,  _______,  _______,  _______,  _______,  _______,
                                            _______,   _______,  _______,  _______,  _______
  ),
};

#ifdef RGBLIGHT_ENABLE
  // RGB LED Indicators
  const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      {0, 11, HSV_SPRINGGREEN}    // Light 1 LED, starting with LED 0
  );

  const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      {0, 11, HSV_WHITE}  // Light 1 LED, starting with LED 1
  );

  // RGB LED Indicators
  const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      {0, 11, HSV_YELLOW}    // Light 1 LED, starting with LED 0
  );

  // RGB LED Indicators
  const rgblight_segment_t PROGMEM my_ADJUST_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      {0, 11, HSV_CYAN}    // Light 1 LED, starting with LED 0
  );

  // Now define the array of layers. Later layers take precedence
  const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
      my_base_layer,          // 0
      my_lower_layer,         // 1
      my_raise_layer,         // 2
      my_ADJUST_layer         // 3
  );

  // Enable the LED layers
  void keyboard_post_init_user(void) {
      rgblight_layers = my_rgb_layers;
  }

  // Acitvate the default rgb layer when the _QWERTY layer is enabled
  layer_state_t default_layer_state_set_user(layer_state_t state) {
      rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
      return state;
  }
  
  layer_state_t layer_state_set_user(layer_state_t state) {
      state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
      rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
      rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
      rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
      return state;
  }

 #endif
