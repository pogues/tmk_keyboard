/*
Copyright 2016 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "unimap_trans.h"

enum macro_id {
    FORWARD_WORD,
    BACKWARD_WORD,
    YANK,
    PASTE,
    UNDO,
    REDO,
    FORWARD_PARAGRAPH,
    BACKWARD_PARAGRAPH,
    FIND,
    OPEN_PARENS,
    CLOSE_PARENS,
    OPEN_BRACE,
    CLOSE_BRACE,
    PIPE,
    TILDE,
    UNDERSCORE,
    EXLCLAIM,
    AT_SIGN,
    DOLLAR,
    PERCENT,
    HAT,
    AMPERSAND,
    HASH,
    CTRL_ALT_F9,
    CTRL_ALT_F10,
    CTRL_ALT_T,
    CTRL_ALT_W,
    CTRL_ALT_DEL,
    CTRL_SHIFT_D,
    CTRL_SHIFT_E,
    CTRL_SHIFT_G,
    CTRL_SHIFT_P,
    CTRL_SHIFT_V,
};

/* id for user defined functions */
enum function_id {
    VIM_G,
};


// masks to detect modifiers
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))
#define SHIFT_HELD (get_mods() & MODS_SHIFT_MASK)


// Layers
#define AC_L1       ACTION_LAYER_MOMENTARY(1)
#define AC_L2       ACTION_LAYER_MOMENTARY(2)
#define AC_TAB3     ACTION_LAYER_TAP_KEY(3, KC_TAB)
#define AC_ESC4     ACTION_LAYER_TAP_KEY(4, KC_ESC)

// vim like multi key macros
#define AC__FWDW     ACTION_MACRO(FORWARD_WORD)       // (vi)w ==> ctrl+->
#define AC__BAKW     ACTION_MACRO(BACKWARD_WORD)      // (vi)b ==> ctrl+<-
#define AC__UNDO     ACTION_MACRO(UNDO)               // (vi)u ==> ctrl+z
#define AC__REDO     ACTION_MACRO(REDO)               // (vi)r ==> ctrl+y (vim redo is crtl+r)
#define AC__YANK     ACTION_MACRO(YANK)               // (vi)y ==> ctrl+c (vim yank)
#define AC__PSTE     ACTION_MACRO(PASTE)              // (vi)p ==> ctrl+p
#define AC__FWDP     ACTION_MACRO(FORWARD_PARAGRAPH)  // (vi)] ==> ctrl+down (officially vim is })
#define AC__BAKP     ACTION_MACRO(BACKWARD_PARAGRAPH) // (vi)[ ==> ctrl+up (officially vim is {)
#define AC__FIND     ACTION_MACRO(FIND)               // (vi)/ ==> ctrl+f  (find)
#define AC__VIMG     ACTION_FUNCTION(VIM_G)           // (vi)g ==> ctrl+home, (vi)G ==> ctrl+end

// bracket layer macros (to shift keys)
#define AC__LPRN ACTION_MACRO(OPEN_PARENS)               // (brackets)u => (
#define AC__RPRN ACTION_MACRO(CLOSE_PARENS)              // (brackets)i => )
#define AC__LBRC ACTION_MACRO(OPEN_BRACE)                // (brackets)m => {
#define AC__RBRC ACTION_MACRO(CLOSE_BRACE)               // (brackets), => }
#define AC__PIPE ACTION_MACRO(PIPE)
#define AC__TLDE ACTION_MACRO(TILDE)
#define AC__UNDR ACTION_MACRO(UNDERSCORE)
#define AC__EXCL ACTION_MACRO(EXLCLAIM)
#define AC__ATSN ACTION_MACRO(AT_SIGN)
#define AC__HASH ACTION_MACRO(HASH)
#define AC__DLLR ACTION_MACRO(DOLLAR)
#define AC__PCNT ACTION_MACRO(PERCENT)
#define AC___HAT ACTION_MACRO(HAT)
#define AC__AMPD ACTION_MACRO(AMPERSAND)

// ctrl alt actions
#define AC_CAF9  ACTION_MACRO(CTRL_ALT_F9)
#define AC_CAF10 ACTION_MACRO(CTRL_ALT_F10)
#define AC_CADEL ACTION_MACRO(CTRL_ALT_DEL)
#define AC_CA_T  ACTION_MACRO(CTRL_ALT_T)
#define AC_CA_W  ACTION_MACRO(CTRL_ALT_W)
// strl shift actions
#define AC_CS_D  ACTION_MACRO(CTRL_SHIFT_D)
#define AC_CS_E  ACTION_MACRO(CTRL_SHIFT_E)
#define AC_CS_G  ACTION_MACRO(CTRL_SHIFT_G)
#define AC_CS_P  ACTION_MACRO(CTRL_SHIFT_P)
#define AC_CS_V  ACTION_MACRO(CTRL_SHIFT_V)

// action modifiers (tap vs hold)
#define AC__ENT_     ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT)    // RControl with tap Enter
#define AC__LCT_     ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC)    // LControl with tap ESC


#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [0] = UNIMAP_HHKB( // base layer
        ESC4,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSLS,  GRV,
        TAB3,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSPC,
       _LCT_,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,      _ENT_,
        LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT, RGUI,
               L2,  L1,               SPC,                     L1,  RALT),

    [1] = UNIMAP_HHKB(  // "vim" layer
         ESC,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS,  DEL,
        CAPS, PAUS,_FWDW,  ESC,_REDO,   NO,_YANK,_UNDO, PSCR, SLCK,_PSTE,_BAKP,_FWDP, TRNS,
        TRNS, VOLD, VOLU, MUTE, EJCT,_VIMG, LEFT, DOWN,   UP, RGHT,   NO,   NO,       TRNS,
        TRNS,   NO,  DEL, BTN1, BTN2,_BAKW, HOME, PGDN, PGUP,  END,_FIND, TRNS, TRNS,
             TRNS,TRNS,               TRNS,                    TRNS,TRNS),

    [2] = UNIMAP_HHKB( // "brackets" layer
          ESC, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
          TAB,   NO,   NO,   NO,   NO,   NO,_EXCL,_LPRN,_RPRN,_ATSN, BSLS, TRNS, TRNS, TRNS,      \
         LCTL,   NO,   NO,   NO,   NO,   NO,_HASH, LBRC, RBRC,_PIPE,_TLDE,  GRV,  ENT,            \
         TRNS,   NO,   NO,   NO,   NO,   NO,_AMPD,_LBRC,_RBRC,_DLLR,__HAT, TRNS, TRNS,            \
                TRNS,   NO,        _UNDR,                 NO, TRNS),

    [3] = UNIMAP_HHKB( // "numpad" layer
          PWR, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
          TAB,   NO,   NO,   NO,   NO,   NO, PPLS,    7,    8,    9,_PCNT,   NO,   NO, TRNS,      \
         LCTL,   NO,   NO,   NO,   NO,   NO, PMNS,    4,    5,    6, PAST,   NO,  ENT,            \
         TRNS,   NO,   NO,   NO,   NO,   NO,  EQL,    1,    2,    3, TRNS, TRNS, TRNS,            \
                  NO,   NO,            0,                 NO, TRNS),

    [4] = UNIMAP_HHKB( // "Ctrl-Alt" and "Ctrl-Shift" layer 
         TRNS,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8, CAF9,CAF10,  F11,  F12,  INS,CADEL,\
          TAB, TRNS, CA_W, CS_E, TRNS, CA_T, TRNS, TRNS, TRNS, TRNS, CS_P, TRNS, TRNS, TRNS,      \
         LCTL, TRNS, TRNS, CS_D, TRNS, CS_G, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  ENT,            \
         TRNS, TRNS, TRNS, TRNS, CS_V, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,            \
                  NO,   NO,         TRNS,                 NO, TRNS),
};

#define CTRL_MACRO(KEY) (record->event.pressed ? MACRO(D(LCTRL), T(KEY), U(LCTRL), END) : MACRO_NONE)
#define CTRL_ALT_MACRO(KEY) (record->event.pressed ? MACRO(D(LCTRL), D(LALT), T(KEY), U(LALT), U(LCTRL), END) : MACRO_NONE)
#define CTRL_SHIFT_MACRO(KEY) (record->event.pressed ? MACRO(D(LCTRL), D(LSFT), T(KEY), U(LSFT), U(LCTRL), END) : MACRO_NONE)
#define SHIFT_MACRO(KEY) (record->event.pressed ? MACRO(D(LSFT), T(KEY), U(LSFT), END) : MACRO_NONE)

/*
 * the macro definitions
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case FORWARD_WORD:
            return CTRL_MACRO(RIGHT);
        case BACKWARD_WORD:
            return CTRL_MACRO(LEFT);
        case YANK:
            return CTRL_MACRO(C);
        case PASTE:
            return CTRL_MACRO(V);
        case UNDO:
            return CTRL_MACRO(Z);
        case REDO:
            return CTRL_MACRO(Y);
        case FORWARD_PARAGRAPH:
            return CTRL_MACRO(DOWN);
        case BACKWARD_PARAGRAPH:
            return CTRL_MACRO(UP);
        case FIND:
            return CTRL_MACRO(F);
        case OPEN_BRACE:
            return SHIFT_MACRO(LBRC);
        case CLOSE_BRACE:
            return SHIFT_MACRO(RBRC);
        case PIPE:
            return SHIFT_MACRO(BSLS);
        case TILDE:
            return SHIFT_MACRO(GRV);
        case UNDERSCORE:
            return SHIFT_MACRO(MINS);
        case CLOSE_PARENS:
            return SHIFT_MACRO(0);
        case EXLCLAIM:
            return SHIFT_MACRO(1);
        case AT_SIGN:
            return SHIFT_MACRO(2);
        case HASH:
            return SHIFT_MACRO(3); // note the NUHS for non us hash prints backslash (\)
        case DOLLAR:
            return SHIFT_MACRO(4);
        case PERCENT:
            return SHIFT_MACRO(5);
        case HAT:
            return SHIFT_MACRO(6);
        case AMPERSAND:
            return SHIFT_MACRO(7);
        // 8 is omitted as it can be got via the num pad asterisk PAST
        case OPEN_PARENS:
            return SHIFT_MACRO(9);
        case CTRL_ALT_F9:
            return CTRL_ALT_MACRO(F9);
        case CTRL_ALT_F10:
            return CTRL_ALT_MACRO(F10);
        case CTRL_ALT_T:
            return CTRL_ALT_MACRO(T);
        case CTRL_ALT_W:
            return CTRL_ALT_MACRO(W);
        case CTRL_ALT_DEL:
            return CTRL_ALT_MACRO(DEL);
        case CTRL_SHIFT_D:
            return CTRL_SHIFT_MACRO(D);
        case CTRL_SHIFT_E:
            return CTRL_SHIFT_MACRO(E);
        case CTRL_SHIFT_G:
            return CTRL_SHIFT_MACRO(G);
        case CTRL_SHIFT_P:
            return CTRL_SHIFT_MACRO(P);
        case CTRL_SHIFT_V:
            return CTRL_SHIFT_MACRO(V);
    }
    return MACRO_NONE;
}


// Apply the given key with ctrl held down
void key_press_with_ctrl(uint8_t key)
{
    add_weak_mods(MOD_BIT(KC_LCTRL));
    add_key(key);
    send_keyboard_report();
    del_weak_mods(MOD_BIT(KC_LCTRL));
    send_keyboard_report();
}


// release the given key
void key_release(uint8_t key)
{
    del_key(key);
    send_keyboard_report();
}


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static uint8_t shift_held;

    switch (id) 
    {
        case VIM_G:
            shift_held = SHIFT_HELD;
            if (record->event.pressed)
            {
                if (shift_held) 
                {
                    del_mods(shift_held);  // remove whichever shift it was
                    key_press_with_ctrl(KC_END);
                    add_mods(shift_held);  // restore the shift
                }
                else 
                {
                    key_press_with_ctrl(KC_HOME);
                }
            }
            else {
                key_release(shift_held ? KC_END : KC_HOME);
            }
            break;
    }
}
