#if defined INCLUDE_SCRATCH_FILE
/*
    This file is not included in the build.
    It's just to store snips and unused code.    
*/


/*
    This macro produces the same output as LAYOUT_ortho_5x12;
    it's just that it's written in code as if the keyboard were
    viewed rotated 90 degrees clockwise. This is done for
    hopefully easier editing.

    Note that this is rotation and not transposition.
*/

#define LAYOUT_ortho_5x12_vertical( \
    k40, k30, k20, k10, k00, \
    k41, k31, k21, k11, k01, \
    k42, k32, k22, k12, k02, \
    k43, k33, k23, k13, k03, \
    k44, k34, k24, k14, k04, \
    k45, k35, k25, k15, k05, \
    k46, k36, k26, k16, k06, \
    k47, k37, k27, k17, k07, \
    k48, k38, k28, k18, k08, \
    k49, k39, k29, k19, k09, \
    k4a, k3a, k2a, k1a, k0a, \
    k4b, k3b, k2b, k1b, k0b \
) { \
    { k00, k01, k02, k03, k04, k05 }, \
    { k10, k11, k12, k13, k14, k15 }, \
    { k20, k21, k22, k23, k24, k25 }, \
    { k30, k31, k32, k33, k34, k35 }, \
    { k06, k07, k08, k09, k0a, k0b }, \
    { k16, k17, k18, k19, k1a, k1b }, \
    { k26, k27, k28, k29, k2a, k2b }, \
    { k36, k37, k38, k39, k3a, k3b }, \
    { k40, k41, k42, k49, k4a, k4b }, \
    { k46, k47, k48, k43, k44, k45 } \
}
#define LAYOUT_preonic_grid_vertical LAYOUT_ortho_5x12_vertical





/*
    End of file.
*/
#endif
