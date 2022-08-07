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

#define LOWER  LT(_LOWER, KC_BSPC)
#define RAISE  LT(_RAISE, KC_SPC)
#define ADJUST LT(_ADJUST, KC_ENT)

#define FR_CCED  RALT(KC_COMM)
#define SE_ARNG  RALT(KC_W)
#define SE_ODIA  RALT(KC_P)
#define SE_ADIA  RALT(KC_Q)

#define SEL_L LCTL(LSFT(KC_LEFT))
#define SEL_D LCTL(LSFT(KC_DOWN))
#define SEL_U LCTL(LSFT(KC_UP))
#define SEL_R LCTL(LSFT(KC_RIGHT))
#define SEL_LL LCTL(LSFT(KC_HOME))
#define SEL_LR LCTL(LSFT(KC_END))

#define TD_CSL TD(_TD_CTL_SFT_LEFT)
#define TD_CSD TD(_TD_CTL_SFT_DOWN)
#define TD_CSU TD(_TD_CTL_SFT_UP)
#define TD_CSR TD(_TD_CTL_SFT_RIGHT)

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
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |         |   Y  |   U  |   I  |   O  |   P  |  Del |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * | Shift|   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   ;  |   '  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * | Ctrl |   Z  |   X  |   C  |   V  |   B  |         |   N  |   M  |   ,  |   .  |   /  |   \  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |  GUI | Lower|  Enter  | Raise|  Alt |
  *                             +-------------/         \-------------+
  */
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_DEL,
    KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_BSLS,
                                            KC_RGUI,   LOWER,   ADJUST,    RAISE,    KC_LALT
  ),

  /* Lower Layer - Symbols
  * ,-----------------------------------------+         +-----------------------------------------.
  * |  Esc |   !  |   @  |   #  |   $  |   %  |         |   ^  |   &  |   *  |   (  |   )  |  Del |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |   -  |   =  |   [  |   ]  |   |  |         | Left | Down |  Up  | Right|   `  |   '  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |   Ç  |   Å  |   Ä  |   Ö  |         | Home |  End | PgUp | PgDn |   ~  |   \  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |      |      |  Enter  |      |      |
  *                             +-------------/         \-------------+
  */
  [_LOWER] = LAYOUT_reviung41(
    KC_ESC,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    _______,  _______,  KC_MINS,   KC_EQL,  KC_LBRC,   KC_RBRC,            TD_CSL,   TD_CSD,   TD_CSU,   TD_CSR,   KC_GRV,   _______,
    _______,  _______,  FR_CCED,  SE_ARNG,  SE_ADIA,   SE_ODIA,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_TILD,  _______,
                                            _______,   _______,  _______,   _______,  _______
  ),

  /* Raise Layer - Number and FN
  * ,-----------------------------------------+         +-----------------------------------------.
  * |  Esc |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  |  Del |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |         |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |      |      |      |      |         |      |      |      |      |      |   \  |
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
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, _______,   _______,            SEL_L,    SEL_D,    SEL_U,    SEL_R,    _______,  _______,
    _______,   _______, _______,  _______,  _______,   _______,            SEL_LL,   SEL_LR,   _______,  _______,  _______,  _______,
                                            _______,   _______,  _______,  _______,  _______
  ),
};

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
