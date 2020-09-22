#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define NO_MUSIC_MODE

#define AUDIO_CLICKY
#define AUDIO_CLICKY_DELAY_DURATION 4
#define AUDIO_CLICKY_FREQ_MIN 220.0f
#define AUDIO_CLICKY_FREQ_DEFAULT 440.0f
#define AUDIO_CLICKY_FREQ_MAX 880.0f

// do-re-mi
//#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.2599f

// do-re-mi-fa-so
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.4983f
