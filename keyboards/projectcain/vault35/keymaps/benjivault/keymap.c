
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

#include QMK_KEYBOARD_H

enum layers{
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum combo_events {
  COMBO_TAB,
  COMBO_ESC,
  COMBO_CUT,
  COMBO_COPY,
  COMBO_PASTE
};

#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_SD LSFT_T(KC_D)
#define KC_CF LCTL_T(KC_F)
#define KC_CJ RCTL_T(KC_J)
#define KC_SK RSFT_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GQUOT RGUI_T(KC_QUOT)

#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_SPC)
#define ADJUST LT(_ADJUST, KC_ENT)

#define FR_CCED RALT(KC_COMM)
#define SE_ARNG RALT(KC_W)
#define SE_ODIA RALT(KC_P)
#define SE_ADIA RALT(KC_Q)

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  * ,-----------------------------------------------------------------.
  * |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Del |
  * |-----------------------------------------------------------------|
  * |  A    |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |    '    |
  * |-----------------------------------------------------------------|
  * |    Z    |  X  |  C  |  V  |  B  |  N  |  M  |  <  |  >  |   ?   |
  * |-----------------------------------------------------------------|
  *        |Adjust|       Lower      |      Raise       |Adjust|
  *        `---------------------------------------------------'
  */
  [_BASE] = LAYOUT_split_2space(

    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T, KC_Y, KC_U,  KC_I,    KC_O,   KC_P,     KC_DEL,
    KC_GA, KC_AS, KC_SD, KC_CF, KC_G, KC_H, KC_CJ, KC_SK,   KC_AL,  KC_GQUOT,
    KC_Z,  KC_X,  KC_C,  KC_V,  KC_B, KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH,         
          ADJUST,     LOWER,            RAISE,         ADJUST
  ),

  /* Lower Layer - Symbols
  * ,-----------------------------------------------------------------.
  * |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  =  |  -  | Del |
  * |-----------------------------------------------------------------|
  * |  \    |  {  |  [  |  (  |  _  |  ;  |  )  |  ]  |  }  |    `    |
  * |-----------------------------------------------------------------|
  * |    |   |  Ç  |  Å  |  Ä  |  Ö  |  :  |  +  |     |    |    ~    |
  * |-----------------------------------------------------------------|
  *        |Adjust|       Lower      |      Raise       |Adjust|
  *        `---------------------------------------------------'
  */
  [_LOWER] = LAYOUT_split_2space(

    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS, KC_DEL,
    KC_BSLS, KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, KC_SCLN, KC_RPRN, KC_RBRC, KC_RCBR,  KC_GRV,
    KC_PIPE, FR_CCED, SE_ARNG, SE_ADIA, SE_ODIA, KC_COLN, KC_PLUS, KC_DOT,   KC_TILD, _______,
             KC_TRNS,          KC_TRNS,                   KC_TRNS,          KC_TRNS
  ),
  /* Raise Layer - Num row and F row
  * ,-----------------------------------------------------------------.
  * |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Del |
  * |-----------------------------------------------------------------|
  * |   F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  |   F10   |
  * |-----------------------------------------------------------------|
  * |        |    |     |     |     |     |     |     | F11 |  F12    |
  * |-----------------------------------------------------------------|
  *        |Adjust|       Lower      |      Raise       |Adjust|
  *        `---------------------------------------------------'
  */
  [_RAISE] = LAYOUT_split_2space(

    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_DEL,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,          
    _______, _______, _______, _______, _______, _______, KC_COLN, _______, KC_F11, KC_F12,
             KC_TRNS,          KC_TRNS,                   KC_TRNS,          KC_TRNS
  ),
  [_ADJUST] = LAYOUT_split_2space(

    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,  RGB_TOG, _______, _______, _______, _______, _______, QK_BOOT,
    RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______,  _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______,
             KC_TRNS,          KC_TRNS,                   KC_TRNS,          KC_TRNS
  )
};

#ifdef COMBO_ENABLE

const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_GA, KC_AS, COMBO_END};
const uint16_t PROGMEM combo_cut[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_CUT] = COMBO(combo_cut,CUT),
  [COMBO_COPY] = COMBO(combo_copy,COPY),
  [COMBO_PASTE] = COMBO(combo_paste,PASTE)
};

#endif

#ifdef RGBLIGHT_ENABLE

  // Init of the RGB colors and effects
  void keyboard_post_init_user(void) {
      rgblight_sethsv_range(HSV_YELLOW, 0, 14);
  }

 #endif