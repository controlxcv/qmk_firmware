
/*
#define CXCV_RGBY_HUE
#define CXCV_MAC_KEYS
*/

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

    