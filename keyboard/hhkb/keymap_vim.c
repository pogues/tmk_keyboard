/*
 * Vim.  Activate a vim mode
 * http://geekhack.org/index.php?topic=51069.0
 *
 * The base layer is a standard HHKB layout, except
 *  Delete is backspace (i.e. like dip switch 3 is on)
 *  Holding Enter acts as right control (tap for enter)
 *  Holding left control is control but tap for escape
 *  The Fn key is LGui (windows/command)
 *  The LGui/RGui keys are used to enter the VIM layer when held
 *  The tab key when held enters the numpad layer, tap for tab
 *  The left alt key is used to enter the bracket layer
 *
 * VIM layer
 *  hjkl  are arrow keys
 *  y     yank (copy)
 *  p     paste
 *  u     undo
 *  r     redo
 *  x     delete forwards
 *  w     word forwards (ctrl ->)
 *  b     word backwards (crtl <-)
 *  G     to end of document
 *  g     to start of document
 *  [     to start of paragraph  (vim is really {)
 *  ]     to end of paragraph  (vim is really })
 *  /     find
 *
 * [non vim items that are not labelled on the hhkb]
 *  nm<>  are home, page down, page up, end respectively
 *  q     pause
 *  e     escape
 *  c     left mouse click
 *  v     right mouse click
 *
 * [items set according to the HHKB labelling]
 *  esc   power (hhkb label)
 *  1-0,-= F1 to F10, F11 F12
 *  \     Insert
 *  `     Del
 *  Tab   Caps lock
 *  i     print screen
 *  o     scroll lock
 *  a     volume down
 *  s     volume up
 *  d     mute
 *  f     eject
 *
 *  [unused]
 *  t
 *  '
 *  z
 *
 *
 *  Numpad layer (activate with esc held)
 *  + 7 8 9        y u i o
 *  - 4 5 6   ==   h j k l
 *  = 1 2 3        n m , .
 *  0            <space>
 *
 *  The top number row and modifiers are left as is, other keys are no-op
 *
 *
 *  Bracket layer (activate with tab held)
 *  y u i o p      _ ( ) | ~
 *  h j k l ;  ==  - [ ] \ `
 *    m ,            { }
 *
 *  [, ], ' are left as is, along with the number row and modifiers, other keys are no-op
 */
#include "keymap_common.h"

// mask to determine if shift is held
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))
#define SHIFT_HELD (get_mods() & MODS_SHIFT_MASK)


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \| ` |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| BSpc|
     * |-----------------------------------------------------------|
     * | Ctrl |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Ent:Ctrl|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |GUI|
     * `-----------------------------------------------------------'
     *       |FN2|FN1  |         SPC           |FN1  |Alt|
     *       `-------------------------------------------'
     */
    KEYMAP(FN29,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSLS,  GRV,\
           FN12,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSPC,      \
           FN28,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,  FN1,            \
           LSFT, FN30,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT, LGUI,            \
                FN13,  FN0,          SPC,                FN0, LALT),

    /* Layer 1: vi
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |     |   |(W)|Esc|   |   |   |C-Z|   |   |   |   |   |BSPC |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |PgU|Lef|Dow|Rig|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |Bsp|   |   |Spc|PgD|`  |~  |   |   |      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    KEYMAP( ESC,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS,  DEL,\
           CAPS, PAUS,  FN2,  ESC,  FN5,   NO,  FN6,  FN4, PSCR, SLCK,  FN7,  FN9,  FN8, TRNS,      \
           TRNS, VOLD, VOLU, MUTE, EJCT, FN11, LEFT, DOWN,   UP, RGHT,   NO,   NO, TRNS,            \
           TRNS,   NO,  DEL, BTN1, BTN2,  FN3, HOME, PGDN, PGUP,  END, FN10, TRNS, TRNS,            \
                LALT, TRNS,         TRNS,               TRNS, RALT),

    /* Layer 2: brackets  */
    KEYMAP( ESC, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
            TAB,   NO,   NO,   NO,   NO,   NO, FN21, FN14, FN15, FN22, BSLS, TRNS, TRNS, TRNS,      \
           TRNS,   NO,   NO,   NO,   NO,   NO, FN27, LBRC, RBRC, FN18, FN19,  GRV, TRNS,            \
           TRNS,   NO,   NO,   NO,   NO,   NO, FN26, FN16, FN17, FN23, FN25, TRNS, TRNS,            \
                TRNS,   NO,         FN20,                 NO, RALT),

    /* Layer 3: numpad  */
    KEYMAP( PWR, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
            TAB,   NO,   NO,   NO,   NO,   NO, PPLS,    7,    8,    9, FN24,   NO,   NO, TRNS,      \
           LCTL,   NO,   NO,   NO,   NO,   NO, PMNS,    4,    5,    6, PAST,   NO, TRNS,            \
           TRNS, TRNS,   NO,   NO,   NO,   NO,  EQL,    1,    2,    3, TRNS, TRNS, TRNS,            \
                  NO,   NO,            0,                 NO, RALT),

    /* Layer 4: Alt layer */
    KEYMAP(TRNS,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS, FN31,\
            TAB, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,      \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,            \
           TRNS,    Z, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,            \
                  NO,   NO,         TRNS,                 NO, TRNS),
};


/*
 * user defined action function
 */
enum macro_id {
    FORWARD_WORD,
    BACKWARD_WORD,
    COPY,
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
    CTRL_DEL,
};

/* id for user defined functions */
enum function_id {
    VIM_G,
};


#define CTRL_MACRO(KEY) (record->event.pressed ? MACRO(D(LCTRL), T(KEY), U(LCTRL), END) : MACRO_NONE)
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
        case COPY:
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
        case CTRL_DEL:
            return CTRL_MACRO(DEL);
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


/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),                // VIM mode
    [1] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),    // RControl with tap Enter
    [2] = ACTION_MACRO(FORWARD_WORD),               // (vi)w ==> ctrl+->
    [3] = ACTION_MACRO(BACKWARD_WORD),              // (vi)b ==> ctrl+<-
    [4] = ACTION_MACRO(UNDO),                       // (vi)u ==> ctrl+z
    [5] = ACTION_MACRO(REDO),                       // (vi)r ==> ctrl+y (vim redo is crtl+r)
    [6] = ACTION_MACRO(COPY),                       // (vi)y ==> ctrl+c (vim yank)
    [7] = ACTION_MACRO(PASTE),                      // (vi)p ==> ctrl+p
    [8] = ACTION_MACRO(FORWARD_PARAGRAPH),          // (vi)] ==> ctrl+down (officially vim is })
    [9] = ACTION_MACRO(BACKWARD_PARAGRAPH),         // (vi)[ ==> ctrl+up (officially vim is {)
    [10] = ACTION_MACRO(FIND),                      // (vi)/ ==> ctrl+f  (find)
    [11] = ACTION_FUNCTION(VIM_G),                  // (vi)g ==> ctrl+home, (vi)G ==> ctrl+end
    [12] = ACTION_LAYER_TAP_KEY(3, KC_TAB),         // numpad with held tab
    [13] = ACTION_LAYER_MOMENTARY(2),               // brackets layer
    [14] = ACTION_MACRO(OPEN_PARENS),               // (brackets)u => (
    [15] = ACTION_MACRO(CLOSE_PARENS),              // (brackets)i => )
    [16] = ACTION_MACRO(OPEN_BRACE),                // (brackets)m => {
    [17] = ACTION_MACRO(CLOSE_BRACE),               // (brackets), => }
    [18] = ACTION_MACRO(PIPE),
    [19] = ACTION_MACRO(TILDE),
    [20] = ACTION_MACRO(UNDERSCORE),
    [21] = ACTION_MACRO(EXLCLAIM),
    [22] = ACTION_MACRO(AT_SIGN),
    [23] = ACTION_MACRO(DOLLAR),
    [24] = ACTION_MACRO(PERCENT),
    [25] = ACTION_MACRO(HAT),
    [26] = ACTION_MACRO(AMPERSAND),
    [27] = ACTION_MACRO(HASH),
    [28] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),    // LControl with tap ESC
    [29] = ACTION_LAYER_MODS(4, MOD_LALT),   // enter layer 4 on holding esc, with ctrl held
    [30] = ACTION_LAYER_TAP_KEY(3, KC_Z),
    [31] = ACTION_MACRO(CTRL_DEL),
};
