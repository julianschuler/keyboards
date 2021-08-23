#include QMK_KEYBOARD_H
#include "keymap_german.h"

// layer definitions
#define _VL         0
#define _QL         1
#define _WL         2
#define _SL         3
#define _NL         4
#define _FL         5

// layer switching keys
#define QWERTZ      DF(_QL)
#define VOU         DF(_VL)
#define WASD        TG(_WL)
#define NUM_L       MO(_NL)
#define SYM_L       MO(_SL)
#define FN_L        MO(_FL)


// modifier keys
/* #define L_SHIFT     KC_LSFT */
#define L_SHIFT     OSM(MOD_LSFT)
#define R_SHIFT     KC_RSFT
#define L_CTRL      KC_LCTL    
#define R_CTRL      KC_RCTL
#define L_GUI       KC_LGUI
#define L_ALT       KC_LALT

// kombination keys
#define MAX_WIN     LALT(KC_F10)
#define CTL_ALT     LCTL(KC_LALT)
#define CTL_SFT     LCTL(KC_LSFT)
#define ALT_GUI     LALT(KC_LGUI)
#define ALT_F4      LALT(KC_F4)
#define SFT_TAB     LSFT(KC_TAB)

#define SCOPE       LGUI(DE_S)
#define BROWSER     KC_WSCH
#define SLICER      LGUI(DE_P)
#define UPDATES     LGUI(DE_U)
#define ORGNZR      LGUI(DE_O)
#define MUSIC       LGUI(DE_M)
#define TERMNL      LGUI(DE_T)
#define EXPLOR      KC_MYCM
#define EDITOR      LGUI(DE_V)

#define KC_TEMP     KC_F22
#define BSP_ALT     LALT_T(KC_TEMP)
#define TAB_CTL     LCTL_T(KC_TAB)


// special keys
#define OMEGA       UC(0x03A9)
#define NNB_SPC     UC(0x202F)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* layer 0: vou
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| ESC  |  V   |  .   |  O   |  U   |  Ä   |                          |  Q   |  G   |  L   |  H   |  F   |  ß   |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| BSPC |  C   |  A   |  E   |  I   |  Ü   |                          |  B   |  T   |  R   |  N   |  S   |  J   |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
| SHFT |  Z   |  X   |  ,   |  Y   |  Ö   | PLAY |            | PAUS |  P   |  D   |  W   |  M   |  K   |  -   |
|______|______|______|______|______|______|______|__        __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        | GUI  |      |      |      |      |      |      |      | GUI  |
                        |______| TAB  | SHFT | NUMS |      | SYMS | SPC  | ENTR |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_VL] = LAYOUT(
KC_ESC,     DE_V,       DE_DOT,     DE_O,       DE_U,       DE_ADIA,                                        DE_Q,       DE_G,       DE_L,       DE_H,       DE_F,       DE_SS,   \
BSP_ALT,    DE_C,       DE_A,       DE_E,       DE_I,       DE_UDIA,                                        DE_B,       DE_T,       DE_R,       DE_N,       DE_S,       DE_J,    \
L_SHIFT,    DE_Z,       DE_X,       DE_COMM,    DE_Y,       DE_ODIA,    KC_MPLY,                KC_PAUS,    DE_P,       DE_D,       DE_W,       DE_M,       DE_K,       DE_MINS, \
                                        L_GUI,      TAB_CTL,    L_SHIFT,    NUM_L,          SYM_L,      KC_SPC,     KC_ENT,     L_GUI                                            ),



/* layer 1: qwertz
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| ESC  |  Q   |  W   |  E   |  R   |  T   |                          |  Z   |  U   |  I   |  O   |  P   |  Ü   |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| BSPC |  A   |  S   |  D   |  F   |  G   |                          |  H   |  J   |  K   |  L   |  Ö   |  Ä   |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
| SHFT |  Y   |  X   |  C   |  V   |  B   | PLAY |            | PAUS |  N   |  M   |  ,   |  .   |  -   |  ß   |
|______|______|______|______|______|______|______|__        __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        | GUI  |      |      |      |      |      |      |      | GUI  |
                        |______| TAB  | SHFT | NUMS |      | SYMS | SPC  | ENTR |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_QL] = LAYOUT(
KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                                           DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA, \
BSP_ALT,    DE_A,       DE_S,       DE_D,       DE_F,       DE_G,                                           DE_H,       DE_J,       DE_K,       DE_L,       DE_ODIA,    DE_ADIA, \
L_SHIFT,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       KC_MPLY,                KC_PAUS,    DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,   \
                                        L_GUI,      TAB_CTL,    L_SHIFT,    NUM_L,          SYM_L,      KC_SPC,     KC_ENT,     L_GUI                                            ),



/* layer 2: wasd (for gaming)
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



/* layer 3: symbol layer (press symbol layer key to access)
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



/* layer 4: number and movement layer (press number layer key to access)
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| AGUI | CALT | BSPC |  UP  | DEL  | A_F4 |                          |  *   |  7   |  8   |  9   |  :   |  /   |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| CTL  | GUI  |  <-  | DOWN |  ->  | PGUP |                          |  +   |  4   |  5   |  6   |  .   | BSPC |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
| SHFT | CSFT | PSCR | HOME | END  | PGDN |      |            |      |  -   |  1   |  2   |  3   |  ,   |  _   |
|______|______|______|______|______|______|______|__        __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        |      |      |      |      |      |      |      |      | NNBS |
                        |______|      | NONE | NUMS |      |  FN  | SPC  |  0   |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_NL] = LAYOUT(
ALT_GUI,    CTL_ALT,    KC_BSPC,    KC_UP,      KC_DEL,     ALT_F4,                                         DE_ASTR,    DE_7,       DE_8,       DE_9,       DE_COLN,    DE_SLSH, \
KC_LCTL,    KC_LGUI,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGUP,                                        DE_PLUS,    DE_4,       DE_5,       DE_6,       DE_DOT,     KC_BSPC, \
KC_LSFT,    CTL_SFT,    KC_PSCR,    KC_HOME,    KC_END,     KC_PGDN,    _______,                _______,    DE_MINS,    DE_1,       DE_2,       DE_3,       DE_COMM,    DE_UNDS, \
                                        _______,    _______,    XXXXXXX,    NUM_L,           FN_L,      KC_SPC,     DE_0,       NNB_SPC                                         ),



/* layer 5: function keys (press symbol and number layer key together to access)
 _________________________________________                            _________________________________________
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
| NONE | SLCK | PREV | PLAY | NEXT | WASD |                          | SCOP | BROW | MAIL | UPDT | ORG  | MSC  |
|______|______|______|______|______|______|                          |______|______|______|______|______|______|
|      |      |      |      |      |      |                          |      |      |      |      |      |      |
|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                          |  F7  |  F8  |  F9  | F10  | F11  | F12  |
|______|______|______|______|______|______|______              ______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |            |      |      |      |      |      |      |      |
| RST  | PAUS | MUTE | VOLD | VOLU | VOU  |      |            |      | QWER | TERM | EXPL | EDIT | CALC | SLIC |
|______|______|______|______|______|______|______|__        __|______|______|______|______|______|______|______|
                        |      |      |      |      |      |      |      |      |      |
                        | NONE |      |      |      |      |      |      |      | NONE |
                        |______| NONE | NONE |  FN  |      |  FN  | NONE | NONE |______|
                               |      |      |      |      |      |      |      |
                               |______|______|______|      |______|______|______| */
[_FL] = LAYOUT(
XXXXXXX,    KC_SLCK,    KC_MPRV,    KC_MPLY,    KC_MNXT,    WASD,                                           SCOPE,      BROWSER,    KC_MAIL,    UPDATES,    ORGNZR,     MUSIC,   \
KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                                          KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,  \
RESET,      KC_PAUS,    KC_MUTE,    KC_VOLD,    KC_VOLU,    VOU,        _______,                _______,    QWERTZ,     TERMNL,     EXPLOR,     EDITOR,     KC_CALC,    SLICER,  \
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


// allow for sending CTL+BSP within ALT_T
bool register_code_user(uint8_t code) {
    if (KC_TEMP == code) {
        if (get_mods() & MOD_LSFT) { 
            del_mods(MOD_LSFT);
            add_weak_mods(MOD_LCTL);
            add_key(KC_BSPC);
            send_keyboard_report();
            add_mods(MOD_LSFT);
            return false;
        }
        else {
            add_key(KC_BSPC);
            send_keyboard_report();
            return false;
        }
    }
    return true;
}


bool unregister_code_user(uint8_t code) {
    if (KC_TEMP == code) {
        del_key(KC_BSPC);
        del_weak_mods(MOD_LCTL);
        send_keyboard_report();
        return false;
    }
    return true;
}

