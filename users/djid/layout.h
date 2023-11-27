// Layers
#define BSE 0
#define LWR 1
#define RSE 2
#define ADJ 3

/// These are called in the wrapper-<kbname>.json file under "layout"
/// Look in the original keyboard folder for list of available layouts
#define LAYOUT_lesovoz_w(...) LAYOUT(__VA_ARGS__)

// Home row mod-tap macros
/// Home row mods are added to layers in wrapper-<kbname>.json 
/// under layer name add "HRM<Alias>(layer_name)" e.g. 
/// Rainkeeb has: #define HRMRK(k) LAYOUT_rainkeeb(k)
/// So we add: "HRMRK(RAINKEEB_BASE)" in wrapper-rainkeeb.json
#define HRML(k1,k2,k3,k4) LGUI_T(k1),LALT_T(k2),LSFT_T(k3),LCTL_T(k4)
#define HRMR(k1,k2,k3,k4) RCTL_T(k1),RSFT_T(k2),RALT_T(k3),RGUI_T(k4)

// Define special characters
#define FR_CCED RALT(KC_COMM)
#define SE_ARNG RALT(KC_W)
#define SE_ODIA RALT(KC_P)
#define SE_ADIA RALT(KC_Q)

// Base Layer QWERTY Layout
#define __BASE_L1__	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T
#define __BASE_L2__	KC_A,	KC_S,	KC_D,	KC_F,	KC_G
#define __BASE_L3__	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B

#define __BASE_R1__	KC_Y,	KC_U,	KC_I,		KC_O,	KC_P
#define __BASE_R2__	KC_H,	KC_J,	KC_K,		KC_L,	KC_SCLN
#define __BASE_R3__	KC_N,	KC_M, 	KC_COMM,	KC_DOT,	KC_SLSH

// Base Layer Bottom Row
// 1 = Lower, 2 = Raise, 3 = Adjust
#define __BASE_3KEY_L_BOT__ LT(3, KC_ENT), LT(1, KC_BSPC), LSFT_T(KC_BSPC)
#define __BASE_3KEY_R_BOT__	RSFT_T(KC_SPC), LT(2, KC_SPC), LT(3, KC_ENT)

 /* Lower Layer - Symbols
  * ,---------------------------------------------------------------------.
  * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   =  |   -  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |   \  |   {  |   [  |   (  |   _  |   ;  |   )  |   ]  |   }  |   `  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |   |  |   Ç  |   Å  |   Ä  |   Ö  |   :  |   +  |      |      |   ~  |
  * |------+------+------+------+------+------+------+------+------+------|
  */
#define __LOWER_L1__ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __LOWER_L2__ KC_BSLS, KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS 
#define	__LOWER_L3__ KC_PIPE, FR_CCED, SE_ARNG, SE_ODIA, SE_ADIA

#define __LOWER_R1__ KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS
#define __LOWER_R2__ KC_SCLN, KC_RPRN, KC_RBRC, KC_RCBR,  KC_GRV
#define __LOWER_R3__ KC_COLN, KC_PLUS, KC_TRNS, KC_TRNS,  KC_TILD

  /* Raise Layer - Numbers and FN
  * ,----------------------------------+----------------------------------.
  * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |
  * |------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      | F11  | F12  |
  * |------+------+------+------+------+------+------+------+------+------|
  */
#define __RAISE_L1__	KC_1,    KC_2,    KC_3,    KC_4,    KC_5      
#define __RAISE_L2__	KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __RAISE_L3__	KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS

#define __RAISE_R1__	KC_6,    KC_7,    KC_8,    KC_9,   KC_0
#define __RAISE_R2__	KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10
#define __RAISE_R3__	KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_F11,   KC_F12

  /* Adjust Layer - Boot, RGB and Navigation
  * ,----------------------------------+----------------------------------.
  * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |
  * |------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      | F11  | F12  |
  * |------+------+------+------+------+------+------+------+------+------|
  */
#define __ADJUST_L1__	QK_BOOT, RGB_SAI, RGB_HUI, RGB_MOD,  RGB_TOG     
#define __ADJUST_L2__	KC_TRNS, RGB_VAD, RGB_SAD, RGB_RMOD, KC_TRNS
#define __ADJUST_L3__	 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS

#define __ADJUST_R1__	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define __ADJUST_R2__	KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS
#define __ADJUST_R3__	KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_TRNS

// Set our standard layout building block for the wrappers below to utilise
#define _BASE \
	__BASE_L1__, __BASE_R1__, \
	__BASE_L2__, __BASE_R2__, \
	__BASE_L3__, __BASE_R3__,
#define _BASE_3KEY_BOTROW \
	__BASE_3KEY_L_BOT__, __BASE_3KEY_R_BOT__

#define _LOWER \
	__LOWER_L1__, __LOWER_R1__, \
	__LOWER_L2__, __LOWER_R2__, \
	__LOWER_L3__, __LOWER_R3__
#define _LOWER_3KEY_BOTROW \
	__LOWER_3KEY_L_BOT__, __LOWER_3KEY_R_BOT__

#define _RAISE \
	__RAISE_L1__, __RAISE_R1__, \
	__RAISE_L2__, __RAISE_R2__, \
	__RAISE_L3__, __RAISE_R3__
#define _RAISE_3KEY_BOTROW\
	__RAISE_3KEY_L_BOT__, __RAISE_3KEY_R_BOT__

#define _ADJUST \
	__ADJUST_L1__, __ADJUST_R1__, \
	__ADJUST_L2__, __ADJUST_R2__, \
	__ADJUST_L3__, __ADJUST_R3__
#define _ADJUST_3KEY_BOTROW \
	__ADJUST_3KEY_L_BOT__, __ADJUST_3KEY_R_BOT__			

// Lesovoz
#define HRMRK(k) LAYOUT_lesovoz(k)
#define LAYOUT_lesovoz( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
  K30, K31,      K33,           K36,      K38, K39  \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, }, \
{ K30, K31, XXX, K33, XXX, XXX, K36, XXX, K38, K39, }  \
}

#define LESOVOZ_BASE \
	__BASE_L1__, __BASE_R1__, \
	__BASE_L2__, __BASE_R2__, \
	__BASE_L3__, __BASE_R3__, \
	__BASE_3KEY_L_BOT__, __BASE_3KEY_R_BOT__

#define LESOVOZ_LOWER \
	__LOWER_L1__, __LOWER_R1__, \
	__LOWER_L2__, __LOWER_R2__, \
	__LOWER_L3__, __LOWER_R3__, \
	__LOWER_3KEY_L_BOT__, __LOWER_3KEY_R_BOT__

#define LESOVOZ_RAISE \
	__RAISE_L1__, __RAISE_R1__, \
	__RAISE_L2__, __RAISE_R2__, \
	__RAISE_L3__, __RAISE_R3__, \
	__RAISE_3KEY_L_BOT__, __RAISE_3KEY_R_BOT__

#define LESOVOZ_ADJUST \
	__ADJUST_L1__, __ADJUST_R1__, \
	__ADJUST_L2__, _______, __ADJUST_R2__, \
	__ADJUST_L3__, _______, __ADJUST_R3__, \
	KC_TRNS, __ADJUST_3KEY_L_BOT__, KC_TRNS, __ADJUST_3KEY_R_BOT__, KC_TRNS
