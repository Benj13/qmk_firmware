#include QMK_KEYBOARD_H

enum layers{
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum combo_events {
  COMBO_CUT,
  COMBO_COPY,
  COMBO_PASTE
};

#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_SPC)
#define ADJUST LT(_ADJUST, KC_ENT)

#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_SD LSFT_T(KC_D)
#define KC_CF LCTL_T(KC_F)
#define KC_CJ RCTL_T(KC_J)
#define KC_SK RSFT_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GQUOT RGUI_T(KC_QUOT)

#define FR_CCED RALT(KC_COMM)
#define SE_ARNG RALT(KC_W)
#define SE_ODIA RALT(KC_P)
#define SE_ADIA RALT(KC_Q)

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  * ,--------------------------------------------------------------------------.
  * | Esc  |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  Del  |
  * |------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-------|
  * | Tab   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  '  | Enter|
  * |-------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`------|
  * | Shift  |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  | Up  |  ?  |
  * |--------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----|
  * | Ctrl |  GUI  | Alt  | Backspc     | Space       |  :   | Left| Down|Right|
  * `--------------------------------------------------------------------------'
  */
  [_BASE] = LAYOUT_arrow(
    KC_ESC,  KC_Q,   KC_W,  KC_E,    KC_R,  KC_T, KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,     KC_DEL,
    KC_TAB,  KC_GA,  KC_AS, KC_SD,   KC_CF, KC_G, KC_H,   KC_CJ, KC_SK,   KC_AL,   KC_GQUOT, KC_ENT,
    KC_LSFT, KC_Z,   KC_X,  KC_C,    KC_V,  KC_B, KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_UP,    KC_SLSH,
    KC_LCTL, ADJUST, LOWER, KC_BSPC,              KC_SPC,        RAISE,   KC_LEFT, KC_DOWN,  KC_RIGHT
  ),
  /* Symbols
  * ,--------------------------------------------------------------------------.
  * |  `  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  -  |   =  |   +   |
  * |------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-------|
  * |   \  |  {  |  [  |  (  |  _  |  ;  |  :  |  |  |  )  |  ]  |  }   |      |
  * |-------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`------|
  * |   |   |  Ç  |  Å  |  Ä  |  Ö  |     |     |     |     |      |     |     |
  * |--------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----|
  * |      |       |      |             |             |      |     |     |     |
  * `--------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_arrow( 
    _______, KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS, _______, 
    _______, KC_BSLS, KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, KC_SCLN, KC_RPRN, KC_RBRC, KC_RCBR,  KC_GRV,  _______,
    _______, KC_PIPE, FR_CCED, SE_ARNG, SE_ADIA, SE_ODIA, KC_COLN, KC_PLUS, _______, KC_TILD,  _______, _______,
    _______, _______, _______, _______,          _______,                   _______, _______,  _______, _______
  ),
  /* Number and FN
  * ,--------------------------------------------------------------------------.
  * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |   0  |       |
  * |------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-------|
  * |  F1  |  F2 |  F3 |  F4 |  F5 |  F6 |  F8 |  F9 | F10 | F11 | F12  |      |
  * |-------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`------|
  * |       |     |     |     |     |     |     |     |     |      |     |     |
  * |--------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----|
  * |      |       |      |             |             |      |     |     |     |
  * `--------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_arrow( 
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
    _______, _______, KC_LALT, _______,          _______,                   _______, KC_HOME, KC_PGDN,  KC_END
  ),
  [_ADJUST] = LAYOUT_arrow( 
    QK_BOOT, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,   KC_F5,   KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10,  _______,
    _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, KC_F11,  KC_F12,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,                   _______, _______, _______, _______
  )
};

const uint16_t PROGMEM combo_cut[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_CUT] = COMBO(combo_cut,CUT),
  [COMBO_COPY] = COMBO(combo_copy,COPY),
  [COMBO_PASTE] = COMBO(combo_paste,PASTE),
};
