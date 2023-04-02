# Disable unused features
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ENCODER_ENABLE = no
GRAVE_ESC_ENABLE = no 
KEY_LOCK_ENABLE = no
LEADER_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
SLEEP_LED_ENABLE = no
SPACE_CADET_ENABLE = no
STENO_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no
TERMINAL_ENABLE = no
UNICODE_ENABLE = no
VELOCIKEY_ENABLE = no
VIA_ENABLE = no
WPM_ENABLE = no

# Common features enabled
BOOTMAGIC_ENABLE = yes
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes # Makes hex file smaller but breaks legacy macros
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = yes

# Main source file
SRC += djid.c

# Reviung41 keyboard features
ifeq ($(strip $(KEYBOARD)), lesovoz)
	SRC += lesovoz.c
	MCU = atmega328p
	BOOTLOADER = USBasp
endif
