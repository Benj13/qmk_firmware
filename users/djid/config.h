#pragma once

// Key and layout wrapper macros
#include "layout.h"

// Common QMK settings
// Reduce size for things not being used
// https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT // 8-layer limit, saves ~462 bytes

// Tapping Terms
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 185
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define USB_SUSPEND_WAKEUP_DELAY 200

#ifdef RGBLIGHT_ENABLE
#  undef RGBLED_NUM
#  if defined(KEYBOARD_reviung_reviung41)
#   define RGB_DI_PIN D3
#   define RGBLED_NUM 11
#endif

#ifdef RGB_MATRIX_ENABLE
#  if defined(KEYBOARD_tominabox1_le_chiffre_rev2)
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#  else
//   #  define RGB_DISABLE_TIMEOUT 180000
//   https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#suspended-state-id-suspended-state
//   #  define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#    define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120    // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 5
#    define RGB_MATRIX_SPD_STEP 10
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_BREATHING
#  endif
#endif // RGB_MATRIX_ENABLE

#ifdef COMBO_ENABLE
#	define COMBO_TERM 25
#	define COMBO_ONLY_FROM_LAYER 0
#endif