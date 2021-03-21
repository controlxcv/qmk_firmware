#include QMK_KEYBOARD_H

/* RGB Layout
    esc ------------\
    |  6  5   4  3  |
    |       0       |
    |  7  8   1  2  |
    \----- spc -- ent
*/

/* multiply range values */
inline uint16_t mult(uint16_t a, uint16_t b) {
    uint32_t result = a * b;
    return result >> 16;
}
/* complement of range */
inline uint16_t comp(uint16_t a) {
    return UINT16_MAX - a;
}
/* 16-bit HSV to RGB computation (still outputs 8-bit) */
RGB rgblight_hsv_to_rgb(HSV hsv) {
    RGB rgb = {.r = 0, .g = 0, .b = 0};
    uint16_t sector = 0;
    uint16_t offset = 0;
    uint16_t high = 0;
    uint16_t mid = 0;
    uint16_t low = 0;
    uint16_t hue = 0;
    uint16_t sat = 0;
    uint16_t val = 0;

    // bypass this function
    // return hsv_to_rgb(hsv);

    if (hsv.s == 0) {
        rgb.r = rgb.g = rgb.b = hsv.v >> 8;
        return rgb;
    }

    /* Stretch precision of input from 8-bit to 16-bit */
    hue = hsv.h << 8;
    sat = hsv.s << 8;
    val = hsv.v << 8;

    /* Important Reminder: Fixed point computations always drop fractional components */
    #if defined CXCV_RGBY_HUE
        if (hue < 32768) {
            /*
                Warm Arc (RYG)
                Used for hue values in [0, 32768)
                sector_width = 16384

                sector should have range [0, 1]
                    sector = hue / sector_width
                    sector = hue / 16384

                offset possible range is [0, sector_width), or [0, 16384)
                offset is multiplied by 4 to normalize the range to [0, 65536)
                    offset = (hue - (sector * sector_width)) * 4
                    offset = (hue - (sector * 16384)) * 4
            */
            sector = hue >> 14;
            offset = (hue - (sector << 14)) << 2;
        }
        else {
            /*
                Cool Arc (GBR)
                Used for hue values in [32768, 65536)
                sector_width = 8192

                sector should have range [2, 5], so subtract 2 after computing offset
                    sector = hue / sector_width
                    sector = hue / 8192

                offset possible range is [0, sector_width), or [0, 8192)
                offset is multiplied by 8 to normalize the range to [0, 65536)
                    offset = (hue - (sector * sector_width)) * 8
                    offset = (hue - (sector * 8192)) * 8
            */
            uint16_t sector_raw = hue >> 13;
            sector = sector_raw - 2;
            offset = (hue - (sector_raw << 13)) << 3;
        }
    #else
        /*
            whole circumference: 65536
            sector_width = 65536 / 6;

            sector occupies only the least significant 3 bits (0 to 7)
                sector = hue / sector_width;
                sector = hue / (65536 / 6);
                sector = hue / 4 * 3 / 8192;
                sector = ((hue >> 2) * 3) >> 13;

            offset possible range is [0, sector_width), or [0, (65536 / 6))
            offset is multiplied by 6 to normalize the range to [0, 65536)
                offset = (hue - (sector * sector_width)) * 6;
                offset = (hue - (sector * (65536 / 6))) * 6;
                offset = (hue - ((sector * 8192) / 3 * 4)) * 6;
                offset = (hue - (((sector << 13) / 3) << 2)) * 6;

            Note: divisions cost a lot on Cortex M4, so we precompute
                  the factor 10922 instead of using (65536/6) or (8192/3*4)
        */
        uint32_t hue_x3 = hue * 3;
        sector = hue_x3 >> 15;
        offset = (hue - (sector * 10922)) * 6;
    #endif

    // high = val >> 8;
    // low = mult(val, comp(sat)) >> 8;
    // /* mid depends on whether the sector is even or odd */
    // mid = ((sector & 1) == 0) ? mult(val, comp(mult(sat, comp(offset)))) >> 8 :
    //                             mult(val, comp(mult(sat, offset))) >> 8 ;

    const uint16_t P = 46340; // 65535 * sqrt(2)/2
    const uint16_t Q = 19195; // 65535 * (1 - sqrt(2)/2)
    uint16_t R = comp(sat);
    uint16_t S = mult(val, sat);
    if ((sector & 1) == 0) {
        high = mult(S, comp(mult(offset, Q)) + R) >> 8;
        mid  = mult(S,      mult(offset, P)  + R) >> 8;
    }
    else {
        high = mult(S, P + mult(offset, Q) + R) >> 8;
        mid  = mult(S, P - mult(offset, P) + R) >> 8;
    }
    low = mult(val, R) >> 8;

    switch (sector) {
        case 0:  rgb = (RGB) { .r = high, .g = mid,  .b = low  }; break;
        case 1:  rgb = (RGB) { .r = mid,  .g = high, .b = low  }; break;
        case 2:  rgb = (RGB) { .r = low,  .g = high, .b = mid  }; break;
        case 3:  rgb = (RGB) { .r = low,  .g = mid,  .b = high }; break;
        case 4:  rgb = (RGB) { .r = mid,  .g = low,  .b = high }; break;
        case 5:  rgb = (RGB) { .r = high, .g = low,  .b = mid  }; break;
        default: rgb = (RGB) { .r = 0,    .g = 0,    .b = 0    }; break;
    }
    return rgb;
}

/*
bool led_update_user(led_t led_state) {
    #if defined AUDIO_ENABLE
        static uint8_t caps_state = 0;
        if (caps_state != led_state.caps_lock) {
            led_state.caps_lock ? PLAY_SONG(caps_on) : PLAY_SONG(caps_off);
            caps_state = led_state.caps_lock;
        }
        static uint8_t num_state = 0;
        if (num_state != led_state.num_lock) {
            led_state.num_lock ? PLAY_SONG(num_on) : PLAY_SONG(num_off);
            num_state = led_state.num_lock;
        }
        static uint8_t scroll_state = 0;
        if (scroll_state != led_state.scroll_lock) {
            led_state.scroll_lock ? PLAY_SONG(scroll_on) : PLAY_SONG(scroll_off);
            scroll_state = led_state.scroll_lock;
        }
    #endif
    return true;
}
*/
