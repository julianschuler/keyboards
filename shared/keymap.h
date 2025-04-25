#pragma once

uint8_t mod_state;
bool space_present = false;
bool chords_enabled = false;

#include "sendstring_german.h"
#include "shared/combos.h"

#define SYMBOL_COMBOS 36

// layer definitions
#define _VL         0
#define _QL         1
#define _GL         2
#define _LL         3
#define _SL         4
#define _NL         5
#define _FL         6

// layer switching keys
#define VOU         DF(_VL)
#define QWERTZ      DF(_QL)
#define GAME_L      TG(_GL)
#define LNUM_L      MO(_LL)
#define NUM_L       MO(_NL)
#define SYM_L       MO(_SL)
#define FN_L        MO(_FL)

// modifier keys
#define L_SHIFT     OSM(MOD_LSFT)
#define L_CTRL      KC_LCTL
#define R_CTRL      KC_RCTL
#define L_GUI       KC_LGUI
#define L_ALT       KC_LALT

// combination keys
#define SFT_TAB     LSFT(KC_TAB)
#define CTL_ALT     LCTL(KC_LALT)
#define CTL_SFT     LCTL(KC_LSFT)
#define CTL_GUI     LCTL(KC_LGUI)
#define ALT_F4      LALT(KC_F4)

#define GUI_F1      LGUI(KC_F1)
#define GUI_F2      LGUI(KC_F2)
#define GUI_F3      LGUI(KC_F3)
#define GUI_F4      LGUI(KC_F4)
#define GUI_F5      LGUI(KC_F5)
#define GUI_F6      LGUI(KC_F6)
#define GUI_F7      LGUI(KC_F7)
#define GUI_F8      LGUI(KC_F8)
#define GUI_F9      LGUI(KC_F9)
#define GUI_F10     LGUI(KC_F10)
#define GUI_F11     LGUI(KC_F11)
#define GUI_F12     LGUI(KC_F12)

#define TAB_CTL     LCTL_T(KC_TAB)
#define ENT_GUI     LGUI_T(KC_ENT)
#define SS_ALT      LALT_T(DE_SS)

// custom keycode handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // convert shift-backspace to control-backspace
        case KC_BSPC:
            mod_state = get_mods();
            static bool ctrl_bspc_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT || chords_enabled) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(LCTL(KC_BSPC));
                    ctrl_bspc_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            }
            else {
                if (ctrl_bspc_registered) {
                    unregister_code16(LCTL(KC_BSPC));
                    ctrl_bspc_registered = false;
                    return false;
                }
            }
            return true;
        // enable chords while space is pressed
        case KC_SPC:
            if (record->event.pressed) {
                tap_code(KC_SPC);
                space_present = true;
                chords_enabled = true;
            }
            else {
                chords_enabled = false;
            }
            return false;
    }
    return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return ((combo_index < SYMBOL_COMBOS) != chords_enabled);
}

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    if (combo_index < SYMBOL_COMBOS) {
        return 15;
    } else {
        return 100;
    }
}

// configure keys that continue caps word and are shifted by it
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case DE_A ... DE_Z:
        case DE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case DE_1 ... DE_0:
        case KC_BSPC:
        case KC_DEL:
        case DE_UNDS:
            return true;
        default:
            return false;
    }
}
