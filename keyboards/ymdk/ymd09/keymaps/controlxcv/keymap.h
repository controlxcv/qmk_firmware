#pragma once

#include QMK_KEYBOARD_H

// Default layout (macOS)
#define KEYMAP_BASE LAYOUT( \
    LT(_MODE, KC_MUTE),   S(A(KC_VOLD)), S(A(KC_VOLU)), \
              KC_ESC,     KC_MCON,       KC_LPAD,       \
              KC_MS_BTN1, KC_MS_BTN2,    KC_MS_BTN3     \
)

// Function keys F11 to F19
#define KEYMAP_FUNC LAYOUT( \
    LT(_MODE, KC_F17), KC_F18, KC_F19, \
              KC_F14,  KC_F15, KC_F16, \
              KC_F11,  KC_F12, KC_F13  \
)

// Numeric keypad 1 to 9
#define KEYMAP_NPAD LAYOUT( \
    LT(_MODE, KC_KP_7), KC_KP_8, KC_KP_9, \
              KC_KP_4,  KC_KP_5, KC_KP_6, \
              KC_KP_1,  KC_KP_2, KC_KP_3  \
)

// Test mode
#define KEYMAP_TEST LAYOUT( \
    MO(_MODE),  XXXXXXX, XXXXXXX,             \
       XXXXXXX, KC_LPAD, KC_SHOW_ALL_WINDOWS, \
       XXXXXXX, KC_MCON, KC_SHOW_ALL_APPS     \
)

// Mode select
#define KEYMAP_MODE LAYOUT( \
    _______,   XXXXXXX,   MO(_DFU), \
    XXXXXXX,   XXXXXXX,   XXXXXXX,  \
    TO(_BASE), TO(_FUNC), TO(_NPAD) \
)

// System control
#define KEYMAP_DFU LAYOUT( \
    _______, EEP_RST,   _______, \
    XXXXXXX, TO(_TEST), XXXXXXX, \
    RESET,   XXXXXXX,   RESET    \
)
