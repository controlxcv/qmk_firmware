#pragma once

/* Default layout (macOS) */
#define KEYMAP_BASE LAYOUT( \
    LT(_MODE, KC_ESC),    S(A(KC_VOLD)), S(A(KC_VOLU)), \
              G(KC_SPC),  _KC_MCON,      _KC_LPAD, \
              KC_MS_BTN1, KC_MS_BTN2,    KC_MS_BTN3 )

/* Editing layout (macOS) */
#define KEYMAP_EDIT LAYOUT( \
    LT(_MODE, KC_ESC), G(KC_Z), G(S(KC_Z)), \
              G(KC_X), KC_SPC,  KC_BSPC, \
              G(KC_C), G(KC_V), KC_ENT  )

/* Numeric keypad 1 to 9 */
#define KEYMAP_NPAD LAYOUT( \
    LT(_MODE, KC_KP_7), KC_KP_8, KC_KP_9, \
              KC_KP_4,  KC_KP_5, KC_KP_6, \
              KC_KP_1,  KC_KP_2, KC_KP_3  )

/* Function keys F11 to F19 */
#define KEYMAP_FUNC LAYOUT( \
    LT(_MODE, KC_F17), KC_F18, KC_F19, \
              KC_F14,  KC_F15, KC_F16, \
              KC_F11,  KC_F12, KC_F13  )

/* Test layer */
#define KEYMAP_TEST LAYOUT( \
    MO(_MODE),  _KC_SHOW_ALL_WINDOWS, _KC_SHOW_ALL_APPS, \
       XXXXXXX, XXXXXXX, XXXXXXX, \
       XXXXXXX, XXXXXXX, XXXXXXX )

/* Mode select */
#define KEYMAP_MODE LAYOUT( \
    _______,   TO(_BASE),   MO(_DEV), \
    XXXXXXX,   XXXXXXX,   XXXXXXX, \
    TO(_EDIT), TO(_NPAD), TO(_FUNC) )

/* Developer tools */
#define KEYMAP_DEV LAYOUT( \
    _______, EEP_RST,   _______, \
    XXXXXXX, TO(_TEST), XXXXXXX, \
    RESET,   XXXXXXX,   RESET )
