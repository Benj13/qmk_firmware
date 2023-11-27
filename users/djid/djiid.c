#include "djid.h"

// Combos
#ifdef COMBO_ENABLE
    const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
    const uint16_t PROGMEM combo_tab[] = {KC_GA, KC_AS, COMBO_END};
    const uint16_t PROGMEM combo_del[] = {KC_O, KC_P, COMBO_END};
    const uint16_t PROGMEM combo_ent[] = {KC_AL, KC_GQUOT, COMBO_END};
    const uint16_t PROGMEM combo_cut[] = {KC_Z, KC_X, COMBO_END};
    const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
    const uint16_t PROGMEM combo_paste[] = {KC_C, KC_V, COMBO_END};


    combo_t key_combos[COMBO_COUNT] = {
        [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
        [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
        [COMBO_DEL] = COMBO(combo_del,KC_DEL),
        [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
        [COMBO_CUT] = COMBO(combo_cut,CUT),
        [COMBO_COPY] = COMBO(combo_copy,COPY),
        [COMBO_PASTE] = COMBO(combo_paste,PASTE),
    };
	uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);
#endif

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_GRV):
            return TAPPING_TERM - 20;
        case LSFT_T(KC_A):
            return TAPPING_TERM - 20;
        case RSFT_T(KC_SCLN):
            return TAPPING_TERM - 20;
        default:
            // Increase for tap hold macros
            return ((keycode & 0xFF00) == LT0_MASK) ? TAPPING_TERM + 80 : TAPPING_TERM;
    }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Disable for home row mods
    return ((keycode & 0xF000) == LMOD_T_MASK) ? false : true;
}
#endif
