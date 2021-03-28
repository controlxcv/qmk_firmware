#include QMK_KEYBOARD_H

/* Multiply range values */
inline uint16_t mult(uint16_t a, uint16_t b) {
    #if UINTMAX_MAX >= UINT32_MAX
        uint32_t result = a * b;
        return result >> 16;
    #else
        return (a >> 8) * (b >> 8);
    #endif
}
/* 16-bit HSV to RGB computation (still outputs 8-bit) */
RGB rgblight_hsv_to_rgb(HSV hsv) {

    /* return hsv_to_rgb(hsv); */

    /* Special cases for zero value and zero saturation respectively */
    if (hsv.v == 0) { return (RGB) { .r = 0,     .g = 0,     .b = 0     }; }
    if (hsv.s == 0) { return (RGB) { .r = hsv.v, .g = hsv.v, .b = hsv.v }; }

    /* Stretch precision of input from 8-bit to 16-bit */
    uint16_t hue = hsv.h << 8;
    uint16_t sat = hsv.s << 8;
    uint16_t val = hsv.v << 8;
 
    /* sector  = hue / (65536/6)
       offset  = 6 * (hue - (sector * (65536/6)))
       65536/6 = 10922                            */
    #if UINTMAX_MAX >= UINT32_MAX
        uint16_t sector = (uint32_t)hue * 3 >> 15;
    #else
        uint16_t sector = ((hue >> 2) * 3 >> 13);
    #endif
    uint16_t offset = 6 * (hue - (sector * 10922));

    /* Odd sectors count the offset from the other end */
    if ((sector & 1) == 1) { offset = ~offset; }

    /* 65535 * cos(45)       = 46340
       65535 * (1 - cos(45)) = 19195; */
    uint16_t high = mult(val, ~sat + mult(sat, ~mult(offset, 19195))) >> 8;
    uint16_t mid  = mult(val, ~sat + mult(sat,  mult(offset, 46340))) >> 8;
    uint16_t low  = mult(val, ~sat                                  ) >> 8;

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
