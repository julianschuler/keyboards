#include QMK_KEYBOARD_H
#include "keymap_german.h"

// layer definitions
#define _QL         0
#define _GL         1
#define _LL         2
#define _SL         3
#define _NL         4
#define _FL         5

// layer switching keys
#define GAME_L      TG(_GL)
#define LNUM_L      MO(_LL)
#define NUM_L       MO(_NL)
#define SYM_L       MO(_SL)
#define FN_L        MO(_FL)


// modifier keys
#define L_SHIFT     KC_LSFT

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* layer 0: qwertz
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │ESC│ Q │ W │ E │ R │ T │               │ Z │ U │ I │ O │ P │ Ü │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │BSP│ A │ S │ D │ F │ G │               │ H │ J │ K │ L │ Ö │ Ä │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │ALT│ Y │ X │ C │ V │ B │               │ N │ M │ , │ . │ - │ ß │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┐           ┌─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │CTL│   │   │           │   │   │GUI│
 *               │TAB│SFT│NUM│           │SYM│SPC│ENT│
 *               └───┴───┴───┘           └───┴───┴───┘
 */
[_QL] = LAYOUT(
KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                           DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
KC_BSPC,    DE_A,       DE_S,       DE_D,       DE_F,       DE_G,                           DE_H,       DE_J,       DE_K,       DE_L,       DE_ODIA,    DE_ADIA,
KC_LALT,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,                           DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,
                                        TAB_CTL,    L_SHIFT,    NUM_L,                  SYM_L,      KC_SPC,     ENT_GUI
),


/* layer 1: gaming layer
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │ESC│TAB│ Q │ W │ E │ R │               │ T │ Z │ U │ I │ O │ P │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │CTL│SFT│ A │ S │ D │ F │               │ G │ H │ J │ K │ L │ Ö │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │ALT│CTL│ Y │ X │ C │ V │               │ B │ N │ M │ , │ . │ - │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┐           ┌─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │   │   │   │           │   │   │   │
 *               │ 1 │SPC│NUM│           │   │XXX│ENT│
 *               └───┴───┴───┘           └───┴───┴───┘
 */
[_GL] = LAYOUT(
KC_ESC,     KC_TAB,     DE_Q,       DE_W,       DE_E,       DE_R,                           DE_T,       DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,
KC_LCTL,    KC_LSFT,    DE_A,       DE_S,       DE_D,       DE_F,                           DE_G,       DE_H,       DE_J,       DE_K,       DE_L,       DE_ODIA,
KC_LALT,    KC_LCTL,    DE_Y,       DE_X,       DE_C,       DE_V,                           DE_B,       DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,
                                        DE_1,       KC_SPC,     LNUM_L,                 _______,    XXXXXXX,    KC_ENT
),


/* layer 2: left hand num layer (press number layer key in gaming layer to access)
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │   │   │ 4 │ 5 │ 6 │   │               │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │   │ 0 │ 1 │ 2 │ 3 │   │               │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │   │   │ 7 │ 8 │ 9 │   │               │   │   │   │   │   │   │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┐           ┌─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │   │   │   │           │   │   │   │
 *               │   │   │NUM│           │FN │   │   │
 *               └───┴───┴───┘           └───┴───┴───┘
 */
[_LL] = LAYOUT(
_______,    _______,    DE_4,       DE_5,       DE_6,       _______,                        _______,    _______,    _______,    _______,    _______,    _______,
_______,    DE_0,       DE_1,       DE_2,       DE_3,       _______,                        _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    DE_7,       DE_8,       DE_9,       _______,                        _______,    _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    LNUM_L,                 FN_L,        _______,    _______
),


/* layer 3: symbol layer (press symbol layer key to access)
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │ ° │ + │ < │ ' │ { │ ^ │               │ \ │ } │ & │ > │ - │ § │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │ . │ : │ ; │ " │ ( │ ! │               │ ~ │ ) │ = │ / │ * │ ` │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │ µ │ 0 │ @ │ $ │ [ │ ? │               │ | │ ] │ # │ % │ 1 │ € │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┐           ┌─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │   │   │   │           │   │   │   │
 *               │STB│SPC│FN │           │SYM│   │   │
 *               └───┴───┴───┘           └───┴───┴───┘
 */
[_SL] = LAYOUT(
DE_DEG,     DE_PLUS,    DE_LABK,    DE_QUOT,    DE_LCBR,    DE_CIRC,                        DE_BSLS,    DE_RCBR,    DE_AMPR,    DE_RABK,    DE_MINS,    DE_SECT,
DE_DOT,     DE_COLN,    DE_SCLN,    DE_DQUO,    DE_LPRN,    DE_EXLM,                        DE_TILD,    DE_RPRN,    DE_EQL,     DE_SLSH,    DE_ASTR,    DE_GRV,
DE_MICR,    DE_0,       DE_AT,      DE_DLR,     DE_LBRC,    DE_QUES,                        DE_PIPE,    DE_RBRC,    DE_HASH,    DE_PERC,    DE_1,       DE_EURO,
                                        SFT_TAB,    KC_SPC,     FN_L,                   SYM_L,      _______,    _______
),


/* layer 4: number and movement layer (press number layer key to access)
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │C_G│C_A│BSP│ ᐃ │DEL│AF4│               │ * │ 7 │ 8 │ 9 │ : │ _ │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │C_S│SFT│ ᐊ │ ᐁ │ ᐅ │PUP│               │ + │ 4 │ 5 │ 6 │ . │BSP│
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │GUI│CTL│INS│HOM│END│PDN│               │ / │ 1 │ 2 │ 3 │ , │ - │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┐           ┌─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │   │   │   │           │   │   │   │
 *               │   │   │NUM│           │FN │SPC│ 0 │
 *               └───┴───┴───┘           └───┴───┴───┘
 */
[_NL] = LAYOUT(
CTL_GUI,    CTL_ALT,    KC_BSPC,    KC_UP,      KC_DEL,     ALT_F4,                         DE_ASTR,    DE_7,       DE_8,       DE_9,       DE_COLN,    DE_UNDS,
CTL_SFT,    KC_LSFT,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGUP,                        DE_PLUS,    DE_4,       DE_5,       DE_6,       DE_DOT,     KC_BSPC,
KC_LGUI,    KC_LCTL,    KC_INS,     KC_HOME,    KC_END,     KC_PGDN,                        DE_SLSH,    DE_1,       DE_2,       DE_3,       DE_COMM,    DE_MINS,
                                        _______,    _______,    NUM_L,                  FN_L,      KC_SPC,     DE_0
),


/* layer 5: function keys (press symbol and number layer key together to access)
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │F1 │F2 │F3 │F4 │F5 │F6 │               │F7 │F8 │F9 │F10│F11│F12│
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │GAM│PAU│PRE│PLA│NEX│BUP│               │GF1│GF2│GF3│GF4│GF5│GF6│
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │QBT│PSC│MUT│VDN│VUP│BDN│               │GF7│GF8│GF9│G10│G11│G12│
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┐           ┌─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │   │   │   │           │   │   │   │
 *               │XXX│XXX│FN │           │FN │XXX│XXX│
 *               └───┴───┴───┘           └───┴───┴───┘
 */
[_FL] = LAYOUT(
KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                          KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
GAME_L,     KC_PAUS,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_BRIU,                        GUI_F1,     GUI_F2,     GUI_F3,     GUI_F4,     GUI_F5,     GUI_F6,
QK_BOOT,    KC_PSCR,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_BRID,                        GUI_F7,     GUI_F8,     GUI_F9,     GUI_F10,    GUI_F11,    GUI_F12,
                                        XXXXXXX,    XXXXXXX,    FN_L,                   FN_L,       XXXXXXX,    XXXXXXX
),
};
