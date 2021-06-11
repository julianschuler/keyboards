#include "manuform.h"


void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } 
    else {
        tap_code(KC_VOLD);
    }
}


void encoder_update_kb(uint8_t index, bool clockwise) {
    encoder_update_user(0, clockwise);
}
