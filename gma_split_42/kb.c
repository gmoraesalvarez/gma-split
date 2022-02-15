#include "kb.h"

void keyboard_pre_init_kb(void){
    // Workaround for reversible pcb/mcu
    palSetLineMode(C13, PAL_MODE_OUTPUT_OPENDRAIN);
    palSetLineMode(B9, PAL_MODE_OUTPUT_OPENDRAIN);
    palSetLineMode(B8, PAL_MODE_OUTPUT_OPENDRAIN);

    keyboard_pre_init_user();
}