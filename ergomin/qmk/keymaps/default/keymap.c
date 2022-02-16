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
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │ESC│ Q │ W │ E │ R │ T │               │ Z │ U │ I │ O │ P │ Ü │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │BSP│ A │ S │ D │ F │ G │               │ H │ J │ K │ L │ Ö │ Ä │
 * ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
 * │ALT│ Y │ X │ C │ V │ B │PLA│       │PAU│ N │ M │ , │ . │ - │ ß │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┬─┴─┐   ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │GUI│CTL│   │   │   │   │   │GUI│GUI│
 *               └───┤TAB│SFT│NUM│   │SYM│SPC│ENT├───┘
 *                   └───┴───┴───┘   └───┴───┴───┘
 */
[_QL] = LAYOUT(
KC_ESC,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,                                           DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
KC_BSPC,    DE_A,       DE_S,       DE_D,       DE_F,       DE_G,                                           DE_H,       DE_J,       DE_K,       DE_L,       DE_ODIA,    DE_ADIA,
KC_LALT,    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       KC_MPLY,                KC_PAUS,    DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    DE_SS,
                                        KC_LGUI,    TAB_CTL,    L_SHIFT,    NUM_L,          SYM_L,      KC_SPC,     ENT_GUI,    KC_LGUI
),


/* layer 1: wasd (for gaming)
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │ESC│TAB│ Q │ W │ E │ R │               │ T │ Z │ U │ I │ O │ P │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │BSP│SFT│ A │ S │ D │ F │               │ G │ H │ J │ K │ L │ Ö │
 * ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
 * │ALT│CTL│ Y │ X │ C │ V │   │       │   │ B │ N │ M │ , │ . │ - │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┬─┴─┐   ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │ 1 │   │   │   │   │   │   │   │GUI│
 *               └───┤ 2 │SPC│   │   │   │XXX│ENT├───┘
 *                   └───┴───┴───┘   └───┴───┴───┘
 */
[_WL] = LAYOUT(
KC_ESC,     KC_TAB,     DE_Q,       DE_W,       DE_E,       DE_R,                                           DE_T,       DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,
KC_LCTL,    KC_LSFT,    DE_A,       DE_S,       DE_D,       DE_F,                                           DE_G,       DE_H,       DE_J,       DE_K,       DE_L,       DE_ODIA,
KC_LALT,    KC_LCTL,    DE_Y,       DE_X,       DE_C,       DE_V,       _______,                _______,    DE_B,       DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,
                                        DE_1,       DE_2,       KC_SPC,     _______,        _______,    XXXXXXX,    KC_ENT,     KC_LGUI
),


/* layer 2: symbol layer (press symbol layer key to access)
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │ ° │ * │ + │ { │ } │ ^ │               │ \ │ < │ > │ = │ - │ § │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │   │ . │ / │ [ │ ] │ ! │               │ ~ │ ( │ ) │ ; │ : │ % │
 * ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
 * │ € │ µ │ Ω │ @ │ & │ ? │   │       │   │ | │ # │ $ │ " │ ' │ ` │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┬─┴─┐   ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │   │   │   │   │   │   │   │   │   │
 *               └───┤STB│SPC│FN │   │SYM│   │   ├───┘
 *                   └───┴───┴───┘   └───┴───┴───┘
 */
[_SL] = LAYOUT(
DE_DEG,     DE_ASTR,    DE_PLUS,    DE_LCBR,    DE_RCBR,    DE_CIRC,                                        DE_BSLS,    DE_LABK,    DE_RABK,    DE_EQL,     DE_MINS,    DE_SECT,
_______,    DE_DOT,     DE_SLSH,    DE_LBRC,    DE_RBRC,    DE_EXLM,                                        DE_TILD,    DE_LPRN,    DE_RPRN,    DE_SCLN,    DE_COLN,    DE_PERC,
DE_EURO,    DE_MICR,    OMEGA,      DE_AT,      DE_AMPR,    DE_QUES,    _______,                _______,    DE_PIPE,    DE_HASH,    DE_DLR,     DE_DQUO,    DE_QUOT,    DE_GRV,
                                        _______,    SFT_TAB,    KC_SPC,     FN_L,           SYM_L,      _______,    _______,    _______
),


/* layer 3: number and movement layer (press number layer key to access)
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │C_A│C_S│BSP│ ᐃ │DEL│AF4│               │ * │ 7 │ 8 │ 9 │ : │ _ │
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │   │SFT│ ᐊ │ ᐁ │ ᐅ │PUP│               │ + │ 4 │ 5 │ 6 │ . │BSP│
 * ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
 * │GUI│CTL│C_G│HOM│END│PDN│   │       │   │ / │ 1 │ 2 │ 3 │ , │ - │
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┬─┴─┐   ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │   │   │   │   │   │   │   │   │NBS│
 *               └───┤   │XXX│NUM│   │FN │SPC│ 0 ├───┘
 *                   └───┴───┴───┘   └───┴───┴───┘
 */
[_NL] = LAYOUT(
CTL_ALT,    CTL_SFT,    KC_BSPC,    KC_UP,      KC_DEL,     ALT_F4,                                         DE_ASTR,    DE_7,       DE_8,       DE_9,       DE_COLN,    DE_UNDS,
_______,    KC_LSFT,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGUP,                                        DE_PLUS,    DE_4,       DE_5,       DE_6,       DE_DOT,     KC_BSPC,
KC_LGUI,    KC_LCTL,    CTL_GUI,    KC_HOME,    KC_END,     KC_PGDN,    _______,                _______,    DE_SLSH,    DE_1,       DE_2,       DE_3,       DE_COMM,    DE_MINS,
                                        _______,    _______,    XXXXXXX,    NUM_L,           FN_L,      KC_SPC,     DE_0,       NNB_SPC
),


/* layer 4: function keys (press symbol and number layer key together to access)
 * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
 * │F1 │F2 │F3 │F4 │F5 │F6 │               │F7 │F8 │F9 │F10│F11│F12│
 * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
 * │WAS│PAU│PRE│PLA│NEX│BUP│               │GF1│GF2│GF3│GF4│GF5│GF6│
 * ├───┼───┼───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┼───┼───┤
 * │RST│PSC│MUT│VDN│VUP│BDN│   │       │   │GF7│GF8│GF9│G10│G11│G12│
 * └───┴───┴───┴─┬─┴─┬─┴─┬─┴─┬─┴─┐   ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴───┴───┘
 *               │XXX│   │   │   │   │   │   │   │XXX│
 *               └───┤XXX│XXX│FN │   │FN │XXX│XXX├───┘
 *                   └───┴───┴───┘   └───┴───┴───┘
 */
[_FL] = LAYOUT(
KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                                          KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
WASD,       KC_PAUS,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_BRIU,                                        GUI_F1,     GUI_F2,     GUI_F3,     GUI_F4,     GUI_F5,     GUI_F6,
RESET,      KC_PAUS,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_BRID,    _______,                _______,    GUI_F7,     GUI_F8,     GUI_F9,     GUI_F10,    GUI_F11,    GUI_F12,
                                        XXXXXXX,    XXXXXXX,    XXXXXXX,    FN_L,           FN_L,       XXXXXXX,    XXXXXXX,    XXXXXXX
),
};
