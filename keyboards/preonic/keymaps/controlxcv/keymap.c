#include QMK_KEYBOARD_H

void keyboard_pre_init_user(void) {
    rgblight_set_effect_range(5, 4);
}
void keyboard_post_init_user(void) {
    rgblight_setrgb(RGB_OFF);
}

#if defined CXCV_MAC_KEYS

    #define KC_MCON KC_SHOW_ALL_WINDOWS
    #define KC_LPAD KC_SHOW_ALL_APPS

    enum my_keycodes {
        KC_SHOW_ALL_WINDOWS = SAFE_RANGE,
        KC_SHOW_ALL_APPS
    };
    enum my_consumer_usages {
        AC_SHOW_ALL_WINDOWS = 0x29F,
        AC_SHOW_ALL_APPS    = 0x2A0
    };

    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case KC_SHOW_ALL_WINDOWS:
                if (record->event.pressed) {
                    host_consumer_send(AC_SHOW_ALL_WINDOWS);
                } else {
                    host_consumer_send(0);
                }
                return false; /* Skip all further processing of this key */

            case KC_SHOW_ALL_APPS:
                if (record->event.pressed) {
                    host_consumer_send(AC_SHOW_ALL_APPS);
                } else {
                    host_consumer_send(0);
                }
                return false; /* Skip all further processing of this key */

            default:
                return true; /* Process all other keycodes normally */
        }
    }

#endif /* CXCV_MAC_KEYS */
