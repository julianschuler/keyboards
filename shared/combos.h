#pragma once

#define K_ENUM(name, key, ...) name,
#define K_DATA(name, key, ...)                                           \
  const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
#define K_COMB(name, key, ...) [name] = COMBO(cmb_##name, key),

#define A_ENUM(name, string, ...) name,
#define A_DATA(name, string, ...)                                        \
  const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
#define A_COMB(name, string, ...) [name] = COMBO_ACTION(cmb_##name),
#define A_ACTI(name, string, ...)                                        \
  case name:                                                             \
    SEND_STRING(string);                                                 \
    break;

#define BLANK(...)

// Generate data needed for combos/actions
// Create Enum
#undef COMB
#undef SUBS
#define COMB K_ENUM
#define SUBS A_ENUM
enum combos {
#include "combos.def"
};

// Bake combos into mem
#undef COMB
#undef SUBS
#define COMB K_DATA
#define SUBS A_DATA
#include "combos.def"
#undef COMB
#undef SUBS

// Fill combo array
#define COMB K_COMB
#define SUBS A_COMB
combo_t key_combos[] = {
#include "combos.def"
};
#undef COMB
#undef SUBS

// Fill QMK hook
#define COMB BLANK
#define SUBS A_ACTI
void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) {
        return;
    }

    if (space_present) {
        tap_code(KC_BSPC);
        space_present = false;
    }

    switch (combo_index) {
#include "combos.def"
    }
}
#undef COMB
#undef SUBS
