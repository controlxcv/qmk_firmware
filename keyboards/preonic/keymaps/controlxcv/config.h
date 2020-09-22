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
#define AUDIO_CLICKY_FREQ_DEFAULT 440.0f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.5f
