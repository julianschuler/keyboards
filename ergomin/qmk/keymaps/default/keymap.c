#include QMK_KEYBOARD_H
#include "keymap_german.h"

// layer definitions
#define _QL         0
#define _WL         1
#define _SL         2
#define _NL         3
#define _FL         4

// layer switching keys
#define QWERTZ      DF(_QL)
#define WASD        TG(_WL)
#define NUM_L       MO(_NL)
#define SYM_L       MO(_SL)
#define FN_L        MO(_FL)


// modifier keys
#define L_SHIFT     KC_LSFT
#define R_SHIFT     KC_RSFT
#define L_CTRL      KC_LCTL    
#define R_CTRL      KC_RCTL
#define L_GUI       KC_LGUI
#define L_ALT       KC_LALT

// kombination keys
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


// special keys
#define OMEGA       UC(0x03A9)
#define NNB_SPC     UC(0x202F)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* layer 0: qwertz
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| ESC  |  Q   |  W   |  E   |  R   |  T   |                          |  Z   |  U   |  I   |  O   |  P   |  Ü   |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| BSPC |  A   |  S   |  D   |  F   |  G   |                          |  H   |  J   |  K   |  L   |  Ö   |  Ä   |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
| ALT  |  Y   |  X   |  C   |  V   |  B   | PLAY |            | PAUS |  N   |  M   |  ,   |  .   |  -   |  ß   |
|______|______|______|______|______|______|______|__        __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        | GUI  |      |      |      |      |      |      |      | GUI  |
                        |______| TAB  | SHFT | NUMS |      | SYMS | SPC  | ENTR |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_QL] = LAYOUT(
KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                                           DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA, \
KC_BSPC,    DE_A,       DE_S,       DE_D,       DE_F,       DE_G,                                           DE_H,       DE_J,       DE_K,       DE_L,       DE_ODIA,    DE_ADIA, \
KC_LALT,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       KC_MPLY,                KC_PAUS,    DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,   \
                                        L_GUI,      TAB_CTL,    L_SHIFT,    NUM_L,          SYM_L,      KC_SPC,     ENT_GUI,    L_GUI                                            ),



/* layer 1: wasd (for gaming)
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| ESC  | TAB  |  Q   |  W   |  E   |  R   |                          |  T   |  Z   |  U   |  I   |  O   |  P   |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| CTRL | SHFT |  A   |  S   |  D   |  F   |                          |  G   |  H   |  J   |  K   |  L   |  Ö   |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
| ALT  | CTRL |  Y   |  X   |  C   |  V   |      |            |      |  B   |  N   |  M   |  ,   |  .   |  -   |
|______|______|______|______|______|______|______|__        __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        |  1   |      |      |      |      |      |      |      | GUI  |
                        |______|  2   | SPC  |      |      |      | NONE | ENTR |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_WL] = LAYOUT(
KC_ESC,     KC_TAB,     DE_Q,       DE_W,       DE_E,       DE_R,                                           DE_T,       DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,    \
KC_LCTL,    KC_LSFT,    DE_A,       DE_S,       DE_D,       DE_F,                                           DE_G,       DE_H,       DE_J,       DE_K,       DE_L,       DE_ODIA, \
KC_LALT,    KC_LCTL,    DE_Y,       DE_X,       DE_C,       DE_V,       _______,                _______,    DE_B,       DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS, \
                                        DE_1,       DE_2,       KC_SPC,     _______,        _______,    XXXXXXX,    KC_ENT,     L_GUI                                            ),



/* layer 2: symbol layer (press symbol layer key to access)
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
|  °   |  *   |  +   |  {   |  }   |  ^   |                          |  \   |  <   |  >   |  =   |  -   |  §   |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
|      |  .   |  /   |  [   |  ]   |  !   |                          |  ~   |  (   |  )   |  ;   |  :   |  %   |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
|  €   |  µ   |  Ω   |  @   |  &   |  ?   |      |            |      |  |   |  #   |  $   |  "   |  '   |  `   |
|______|______|______|______|______|______|______|___       __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        |      |      |      |      |      |      |      |      |      |
                        |______| STAB | SPC  |  FN  |      | SYMS |      |      |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_SL] = LAYOUT(
DE_DEG,     DE_ASTR,    DE_PLUS,    DE_LCBR,    DE_RCBR,    DE_CIRC,                                        DE_BSLS,    DE_LESS,    DE_MORE,    DE_EQL,     DE_MINS,    DE_PARA, \
_______,    DE_DOT,     DE_SLSH,    DE_LBRC,    DE_RBRC,    DE_EXLM,                                        DE_TILD,    DE_LPRN,    DE_RPRN,    DE_SCLN,    DE_COLN,    DE_PERC, \
DE_EURO,    DE_MICR,    OMEGA,      DE_AT,      DE_AMPR,    DE_QST,     _______,                _______,    DE_PIPE,    DE_HASH,    DE_DLR,     DE_DQOT,    DE_QUOT,    DE_GRV,  \
                                        _______,    SFT_TAB,    KC_SPC,     FN_L,           SYM_L,      _______,    _______,    _______                                         ),




/* layer 3: number and movement layer (press number layer key to access)
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| CALT | CSFT | BSPC |  UP  | DEL  | A_F4 |                          |  *   |  7   |  8   |  9   |  :   |  _   |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
|      | SHFT |  <-  | DOWN |  ->  | PGUP |                          |  +   |  4   |  5   |  6   |  .   | BSPC |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
| GUI  | CTL  | CGUI | HOME | END  | PGDN |      |            |      |  /   |  1   |  2   |  3   |  ,   |  -   |
|______|______|______|______|______|______|______|__        __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        |      |      |      |      |      |      |      |      | NNBS |
                        |______|      | NONE | NUMS |      |  FN  | SPC  |  0   |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_NL] = LAYOUT(
CTL_ALT,    CTL_SFT,    KC_BSPC,    KC_UP,      KC_DEL,     ALT_F4,                                         DE_ASTR,    DE_7,       DE_8,       DE_9,       DE_COLN,    DE_UNDS, \
_______,    KC_LSFT,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGUP,                                        DE_PLUS,    DE_4,       DE_5,       DE_6,       DE_DOT,     KC_BSPC, \
KC_LGUI,    KC_LCTL,    CTL_GUI,    KC_HOME,    KC_END,     KC_PGDN,    _______,                _______,    DE_SLSH,    DE_1,       DE_2,       DE_3,       DE_COMM,    DE_MINS, \
                                        _______,    _______,    XXXXXXX,    NUM_L,           FN_L,      KC_SPC,     DE_0,       NNB_SPC                                         ),


/* layer 4: function keys (press symbol and number layer key together to access)
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                          |  F7  |  F8  |  F9  | F10  | F11  | F12  |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| WASD | PAUS | PREV | PLAY | NEXT | BRIU |                          | G_F1 | G_F2 | G_F3 | G_F4 | G_F5 | G_F6 |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
| RST  | PSCR | MUTE | VOLD | VOLU | BRID |      |            |      | G_F7 | G_F8 | G_F9 | GF10 | GF11 | GF12 |
|______|______|______|______|______|______|______|__        __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        | NONE |      |      |      |      |      |      |      | NONE |
                        |______| NONE | NONE |  FN  |      |  FN  | NONE | NONE |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_FL] = LAYOUT(
KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                                          KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,  \
WASD,       KC_PAUS,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_BRIU,                                        GUI_F1,     GUI_F2,     GUI_F3,     GUI_F4,     GUI_F5,     GUI_F6,  \
RESET,      KC_PAUS,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_BRID,    _______,                _______,    GUI_F7,     GUI_F8,     GUI_F9,     GUI_F10,    GUI_F11,    GUI_F12, \
                                        XXXXXXX,    XXXXXXX,    XXXXXXX,    FN_L,           FN_L,       XXXXXXX,    XXXXXXX,    XXXXXXX                                          )
};



// fix for MO()
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:;
            uint8_t layer = keycode & 0xFF;
            if (record->event.pressed) {
                layer_on(layer);
            }
            else {
                layer_off(layer);
            }
        break;
    }
    return true;
}

