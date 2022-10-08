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
 // tap dance declarations
enum {
    _TD_CTL_SFT_LEFT = 0,
    _TD_CTL_SFT_DOWN,
    _TD_CTL_SFT_UP,
    _TD_CTL_SFT_RIGHT
};

enum combo_events {
  COMBO_CUT,
  COMBO_COPY,
  COMBO_PASTE
};

#define LOWER  LT(_LOWER, KC_BSPC)
#define RAISE  LT(_RAISE, KC_SPC)
#define ADJUST LT(_ADJUST, KC_ENT)

#define FR_CCED  RALT(KC_COMM)
#define SE_ARNG  RALT(KC_W)
#define SE_ODIA  RALT(KC_P)
#define SE_ADIA  RALT(KC_Q)

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)

#define TD_CSL TD(_TD_CTL_SFT_LEFT)
#define TD_CSD TD(_TD_CTL_SFT_DOWN)
#define TD_CSU TD(_TD_CTL_SFT_UP)
#define TD_CSR TD(_TD_CTL_SFT_RIGHT)

#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_SD LSFT_T(KC_D)
#define KC_CF LCTL_T(KC_F)
#define KC_CJ RCTL_T(KC_J)
#define KC_SK RSFT_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GSCLN RGUI_T(KC_SCLN)

 // Tap Dance Definitions
 qk_tap_dance_action_t tap_dance_actions[] = {
     [_TD_CTL_SFT_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, LCTL(KC_LEFT)),
     [_TD_CTL_SFT_DOWN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, LCTL(KC_DOWN)),
     [_TD_CTL_SFT_UP] = ACTION_TAP_DANCE_DOUBLE(KC_UP, LCTL(KC_UP)),
     [_TD_CTL_SFT_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, LCTL(KC_RIGHT))
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer - QWERTY
  * ,-----------------------------------------+         +-----------------------------------------.
  * | Esc  |   Q  |   W  |   E  |   R  |   T  |         |   Y  |   U  |   I  |   O  |   P  |  Del |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * | Tab  |   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   ;  |   '  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * | Ctrl |   Z  |   X  |   C  |   V  |   B  |         |   N  |   M  |   ,  |   .  |   /  |   \  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |  GUI | Lower|  Enter  | Raise|  Alt |
  *                             +-------------/         \-------------+
  */
  [_BASE] = LAYOUT_reviung41(
     KC_ESC,   KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,            KC_Y,    KC_U,     KC_I,    KC_O,      KC_P,   KC_DEL,
     KC_TAB,  KC_GA,   KC_AS,  KC_SD,  KC_CF,   KC_G,            KC_H,   KC_CJ,    KC_SK,   KC_AL,  KC_GSCLN,  KC_QUOT,
    KC_LCTL,   KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,            KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_BSLS,
                                       ADJUST,  LOWER,  KC_ENT,  RAISE,  ADJUST
  ),

  /* Lower Layer - Symbols
  * ,-----------------------------------------+         +-----------------------------------------.
  * |      |   !  |   @  |   #  |   $  |   %  |         |   ^  |   &  |   *  |   =  |   -  |   +  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |   {  |   [  |   (  |   _  |         |   ;  |   )  |   ]  |   }  |   `  |   '  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |   Ç  |   Å  |   Ä  |   Ö  |         |   :  |      |      |      |   ~  |   \  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |      |      |  Enter  |      |      |
  *                             +-------------/         \-------------+
  */
  [_LOWER] = LAYOUT_reviung41(
    _______,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,            KC_CIRC,   KC_AMPR,  KC_ASTR,   KC_EQL,  KC_MINS,  KC_PLUS,
    _______,  _______,  KC_LCBR,   KC_LBRC,  KC_LPRN,  KC_UNDS,            KC_SCLN,   KC_RPRN,  KC_RBRC,  KC_RCBR,   KC_GRV,  _______,
    _______,  _______,  FR_CCED,  SE_ARNG,  SE_ADIA,   SE_ODIA,            KC_COLN,   _______,   _______,  _______,  KC_TILD,  _______,
                                            _______,   _______,  _______,   _______,  _______
  ),

  /* Raise Layer - Number and FN
  * ,-----------------------------------------+         +-----------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |         |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |      |      |      |      |         |      |      |      |      |      |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |      |      |  Enter  |      |      |
  *                             +-------------/         \-------------+
  */  
  [_RAISE] = LAYOUT_reviung41(
     KC_ESC,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
      KC_F1,  KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                            _______,   _______,  _______,   _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  _______,   RGB_TOG,            _______,  _______,  _______,  _______,  _______,  _______,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, _______,   _______,             TD_CSL,   TD_CSD,   TD_CSU,   TD_CSR,  _______,  _______,
    _______,   _______, _______,  _______,  _______,   _______,            KC_HOME,   KC_END,  KC_PGUP,  KC_PGDN,  _______,  _______,
                                            _______,   _______,  _______,  _______,  _______
  ),
};

const uint16_t PROGMEM combo_cut[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_CUT] = COMBO(combo_cut,CUT),
  [COMBO_COPY] = COMBO(combo_copy,COPY),
  [COMBO_PASTE] = COMBO(combo_paste,PASTE),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GA:
            return true;
        case KC_AS:
            return true;
        case KC_SD:
            return true;
        case KC_CF:
            return true;
        case KC_CJ:
            return true;
        case KC_SK:
            return true;
        case KC_AL:
            return true;
        case KC_GSCLN:
            return true;
        default:
            return false;
    }
}


#ifdef RGBLIGHT_ENABLE

  // Init of the RGB colors and effects
  void keyboard_post_init_user(void) {
      rgblight_set_effect_range(10, 1);
      rgblight_mode(RGBLIGHT_EFFECT_BREATHING + 2);
      rgblight_sethsv_range(HSV_YELLOW, 0, 10);
      rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
  }

  // Acitvate the default rgb layer when the _BASE layer is enabled
  layer_state_t default_layer_state_set_user(layer_state_t state) {
      rgblight_sethsv_range(HSV_YELLOW, 0, 10);
      rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
      return state;
  }
  
  // Acitvate the rgb specific for each layer when they are enabled enabled
  layer_state_t layer_state_set_user(layer_state_t state) {
      uint8_t layer = get_highest_layer(state);
      switch (layer) {
          case _BASE:
              rgblight_sethsv_range(HSV_YELLOW, 0, 10);
              rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
              break;
          case _LOWER:
              rgblight_sethsv_range(HSV_YELLOW, 0, 10);
              rgblight_sethsv_noeeprom(HSV_WHITE);
              break;
          case _RAISE:
              rgblight_sethsv_range(HSV_YELLOW, 0, 10);
              rgblight_sethsv_noeeprom(HSV_YELLOW);
              break;
          case _ADJUST:
              rgblight_sethsv_range(HSV_YELLOW, 0, 10);
              rgblight_sethsv_noeeprom(HSV_CYAN);
              break;
      }
      return state;
  }

 #endif
