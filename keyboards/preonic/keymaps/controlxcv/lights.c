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
/* 16-bit HSV to RGB computation (still outputs 8-bit) */
RGB rgblight_hsv_to_rgb(HSV hsv) {
    uint16_t sector = 0, offset = 0;
    uint16_t high = 0, mid = 0, low = 0;
    uint16_t hue = 0, sat = 0, val = 0;

    // uncomment to bypass
    // return hsv_to_rgb(hsv);

    if (hsv.s == 0) {
        return (RGB) { .r = hsv.v, .g = hsv.v, .b = hsv.v };
    }

    /* Stretch precision of input from 8-bit to 16-bit */
    hue = hsv.h << 8;
    sat = hsv.s << 8;
    val = hsv.v << 8;
 
    // sector = hue / (65536/6)
    uint32_t hue_x3 = hue * 3;
    sector = hue_x3 >> 15;

    // offset = 6 * (hue - (sector * (65536/6)))
    offset = 6 * (hue - (sector * 10922));

    // P = 65535 * sqrt(2)/2)
    const uint16_t P = 46340;

    // Q = 65535 * (1 - sqrt(2)/2)
    const uint16_t Q = 19195;
    
    if ((sector & 1) == 0) {
        high = mult(val, mult(sat, ~mult(offset, Q)) + ~sat) >> 8;
        mid  = mult(val, mult(sat,  mult(offset, P)) + ~sat) >> 8;
    }
    else {
        high = mult(val, mult(sat, ~mult(~offset, Q)) + ~sat) >> 8;
        mid  = mult(val, mult(sat,  mult(~offset, P)) + ~sat) >> 8;
    }
    low = mult(val, ~sat) >> 8;

    switch (sector) {
        case 0:  return (RGB) { .r = high, .g = mid,  .b = low  }; break;
        case 1:  return (RGB) { .r = mid,  .g = high, .b = low  }; break;
        case 2:  return (RGB) { .r = low,  .g = high, .b = mid  }; break;
        case 3:  return (RGB) { .r = low,  .g = mid,  .b = high }; break;
        case 4:  return (RGB) { .r = mid,  .g = low,  .b = high }; break;
        case 5:  return (RGB) { .r = high, .g = low,  .b = mid  }; break;
        default: return (RGB) { .r = 0,    .g = 0,    .b = 0    }; break;
    }
}
