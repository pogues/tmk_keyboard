/*
 * Paul's mapping adjusted so the keyboard appears as a UK keyboard.
 *
 * I have retained the " as shift-', and @ as shift-2
 * The top row rightmost becomes \|  and the one to the left of that is #~
 * The grave key is only available on the brackets/symbols layer as ;
 *
 * Set a "num pad" layer on the left meta key
 * Set a "symbols" layer on the left alt key
 * Set a "general" layer on the right meta key
 *
 *  Numpad layer
 *  y u i o p      + 7 8 9 %
 *  h j k l ;  ==  - 4 5 6 *
 *  n m , . /      = 1 2 3 /
 *  <space>          0
 *  Numbers become function keys, others are no-op
 *
 *  Bracket/symbol layer
 *  y u i o p        ! ( ) @ \
 *  h j k l ; '  ==  # [ ] | ~ `
 *  n m , . /        & { } $ ^
 *  [, ] are left as is, numbers become function keys, others are no-op
 *
 *  General (motion) layer
 *     e                up
 *   s d f  ==   left  down  right
 * z x c v       page down, page up, home, end
 *  w and b are word forward and word back
 *  [ and ] are paragraph back and paragraph forward
 */
#include "keymap_common.h"

// mask to determine if shift is held
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))
#define SHIFT_HELD (get_mods() & MODS_SHIFT_MASK)


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  #| \ |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| BSpc|
     * |-----------------------------------------------------------|
     * | Ctrl |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Ent:Ctrl|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |GUI|
     * `-----------------------------------------------------------'
     *       |FN1|FN2  |         SPC           |FN0  |Alt|
     *       `-------------------------------------------'
     */
    KEYMAP( \
        LGUI,    1, FN21,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, NUBS,  DEL,\
         TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSPC,      \
         FN3,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, FN22,  FN4,            \
        FN29,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, FN30, LGUI,            \
                 FN1,  FN2,               SPC,                FN0, LALT
    ),

    /* Layer 1: brackets/symbols */
    KEYMAP( \
         ESC,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS, TRNS,\
         TAB,   NO,   NO,   NO,   NO,   NO, FN15,  FN8,  FN9, FN16, NUBS, TRNS, TRNS, TRNS,      \
        TRNS,   NO,   NO,   NO,   NO,   NO, NUHS, LBRC, RBRC, FN13, FN12,  GRV, TRNS,            \
        TRNS,   NO,   NO, FN23, FN24,   NO, FN20, FN10, FN11, FN17, FN19, TRNS, TRNS,            \
                TRNS,  FN0,              FN14,                 NO, RALT
    ),

    /* Layer 2: numpad */
    KEYMAP( \
         PWR,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS, TRNS,\
         TAB,   NO,   NO,   NO,   NO,   NO, FN28,    7,    8,    9, FN18,   NO,   NO, TRNS,      \
        LCTL,   NO,   NO,   NO,   NO,   NO, MINS,    4,    5,    6, FN27,   NO, TRNS,            \
         SPC, TRNS,   NO, FN23, FN24,   NO,  EQL,    1,    2,    3, SLSH,  SPC, TRNS,            \
                 FN0, TRNS,                 0,               COMM,  DOT
    ),

    /* Layer 3: movement */
    KEYMAP( \
         ESC,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9, MUTE, VOLD, VOLU,  INS, TRNS,\
        CAPS,   NO,  FN5,   UP,   NO,   NO,   NO,   NO, PSCR, SLCK, PAUS, FN9,  FN8, TRNS,      \
        TRNS,   NO, LEFT, DOWN, RGHT,  FN7, LEFT, DOWN,   UP, RGHT,   NO,   NO, TRNS,            \
        TRNS,    Z,    X, FN25, FN26,  FN6, HOME, PGDN, PGUP,  END, MUTE, TRNS, TRNS,            \
                TRNS, TRNS,               SPC,               TRNS, RALT
    ),
};


// useful names for the various layers
enum layers {
    LAYER_BASE,
    LAYER_BRACKETS,
    LAYER_NUMPAD,
    LAYER_MOVEMENT,
};

/*
 * user defined action function
 */
enum macro_id {
    FORWARD_WORD,
    BACKWARD_WORD,
    OPEN_PARENS,
    CLOSE_PARENS,
    OPEN_BRACE,
    CLOSE_BRACE,
    TILDE,
    PIPE,
    UNDERSCORE,
    EXLCLAIM,
    AT_SIGN,
    DOLLAR,
    PERCENT,
    HAT,
    AMPERSAND,
    CTRL_DEL,
    LESS_THAN,
    GREATER_THAN,
    CTRL_INSERT,
    SHIFT_INSERT,
    CTRL_SHIFT_C,
    CTRL_SHIFT_V,
    CTRL_X,
    CTRL_Z,
    STAR,         // shift 8
    PLUS,         // shift eq
};

/* id for user defined functions */
enum function_id {
    FN_VIM_G,
    FN_LAYER_ESC,
    FN_BRACKETS_LAYER,
    FN_NUMPAD_LAYER,
    FN_ANSI_2,
    FN_ANSI_SINGLE_DOUBLE_QUOTE,
};


#define CTRL_MACRO(KEY) (record->event.pressed ? MACRO(D(LCTRL), T(KEY), U(LCTRL), END) : MACRO_NONE)
#define SHIFT_MACRO(KEY) (record->event.pressed ? MACRO(D(LSFT), T(KEY), U(LSFT), END) : MACRO_NONE)
#define CTRL_SHIFT_MACRO(KEY) (record->event.pressed ? MACRO(D(LCTRL), D(LSFT), T(KEY), U(LSFT), U(LCTRL), END) : MACRO_NONE)

/*
 * the macro definitions
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case FORWARD_WORD:
            return CTRL_MACRO(RIGHT);
        case BACKWARD_WORD:
            return CTRL_MACRO(LEFT);
        case OPEN_BRACE:
            return SHIFT_MACRO(LBRC);
        case CLOSE_BRACE:
            return SHIFT_MACRO(RBRC);
        case TILDE:
            return SHIFT_MACRO(NUHS);
        case PIPE:
            return SHIFT_MACRO(NUBS);
        case UNDERSCORE:
            return SHIFT_MACRO(MINS);
        case CLOSE_PARENS:
            return SHIFT_MACRO(0);
        case EXLCLAIM:
            return SHIFT_MACRO(1);
        case AT_SIGN:
            return SHIFT_MACRO(QUOTE);
        case DOLLAR:
            return SHIFT_MACRO(4);
        case PERCENT:
            return SHIFT_MACRO(5);
        case HAT:
            return SHIFT_MACRO(6);
        case AMPERSAND:
            return SHIFT_MACRO(7);
        case OPEN_PARENS:
            return SHIFT_MACRO(9);
        case CTRL_DEL:
            return CTRL_MACRO(DEL);
        case LESS_THAN:
            return SHIFT_MACRO(COMM);
        case STAR:
            return SHIFT_MACRO(8);
        case PLUS:
            return SHIFT_MACRO(EQL);
        case GREATER_THAN:
            return SHIFT_MACRO(DOT);
        case CTRL_INSERT:
            return CTRL_MACRO(INS);
        case SHIFT_INSERT:
            return SHIFT_MACRO(INS);
        case CTRL_SHIFT_C:
            return CTRL_SHIFT_MACRO(C);
        case CTRL_SHIFT_V:
            return CTRL_SHIFT_MACRO(V);
        case CTRL_X:
            return CTRL_MACRO(X);
        case CTRL_Z:
            return CTRL_MACRO(Z);
    }
    return MACRO_NONE;
}


/** press the specified key */
void key_press(uint8_t key) {
    add_key(key);
    send_keyboard_report();
}


/* Apply the given key with ctrl held down */
void key_press_with_ctrl(uint8_t key) {
    add_weak_mods(MOD_BIT(KC_LCTRL));
    key_press(key);
    del_weak_mods(MOD_BIT(KC_LCTRL));
    send_keyboard_report();
}


/** release the specified key */
void key_release(uint8_t key) {
    del_key(key);
    send_keyboard_report();
}


/**
 * function to emulate the vim behaviour of "g"
 *     emits ctrl+home for "g"
 *     emits ctrl+end  for "G"
 */
void action_funtion_vim_g(keyrecord_t *record) {
    uint8_t shift_held = SHIFT_HELD;
    if (record->event.pressed) {
        if (shift_held) {
            del_mods(shift_held);  // remove whichever shift it was
            key_press_with_ctrl(KC_END);
            add_mods(shift_held);  // restore the shift
        }
        else {
            key_press_with_ctrl(KC_HOME);
        }
    }
    else {
        key_release(shift_held ? KC_END : KC_HOME);
    }
}


/**
 * function that emits ' in unshifted but " in shifted.  records the staus
 * of the shift on press to ensure the correct key is released.
 */
void action_function_alternate_shift_two(keyrecord_t *record) {
    static uint8_t shifted = false;
    if (record->event.pressed) {
        shifted = SHIFT_HELD;
        key_press(shifted ? KC_QUOTE : KC_2);
    }
    else {
        key_release(shifted ? KC_QUOTE : KC_2);
    }
}


/**
 * function that emits 2 unshifted and @ shifted.  records the staus
 * of the shift on press to ensure the correct key is released.
 */
void action_function_alternate_shift_quote(keyrecord_t *record) {
    static uint8_t shifted = false;
    if (record->event.pressed) {
        shifted = SHIFT_HELD;
        key_press(shifted ? KC_2 : KC_QUOTE);
    }
    else {
        key_release(shifted ? KC_2 : KC_QUOTE);
    }
}

/**
 * enter a layer and record that we have.  when exiting the recorded layer is exited.
 * we use this to have a pair of keys, (lalt and lmeta) where:
 *      in the base layer lalt enters layer 1 and lmeta enters layer 2
 *      both these keys are TRNS in the respective layers, but the other enters layer 3
 *      in this case if we press A then B then release B then A all is OK.
 *      the code below handles the case where we press A then B then release A then B
 *      exiting the correct layer underneath.
 */
void action_function_multi_layer(keyrecord_t *record, uint8_t layer) {
    static uint8_t entered_layer = 0;

    if (record->event.pressed) {
        entered_layer = layer;
        layer_on(layer);
    }
    else {
        // exit the entered layer
        layer_off(entered_layer);
        // always setting back to 0 as that is the default, though should not get used
        entered_layer = 0;
    }
}


/**
 * main tmk action function called via the ACTION_FUNCTION in fn_actions
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case FN_VIM_G:
            action_funtion_vim_g(record);
            break;
        case FN_ANSI_2:
            action_function_alternate_shift_two(record);   // 2 @  under the UK layout
            break;
        case FN_ANSI_SINGLE_DOUBLE_QUOTE:
            action_function_alternate_shift_quote(record);   // ' "  under the UK layout
            break;
        case FN_BRACKETS_LAYER:
            action_function_multi_layer(record, LAYER_BRACKETS);
            break;
        case FN_NUMPAD_LAYER:
            action_function_multi_layer(record, LAYER_NUMPAD);
            break;
    }
}


/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    // Layers
    [0] = ACTION_LAYER_MOMENTARY(LAYER_MOVEMENT),
    [1] = ACTION_FUNCTION(FN_BRACKETS_LAYER),
    [2] = ACTION_FUNCTION(FN_NUMPAD_LAYER),

    // control keys on the ends of the home row
    [3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),    // LControl with tap ESC
    [4] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),    // RControl with tap Enter

    // motions
    [5] = ACTION_MACRO(FORWARD_WORD),
    [6] = ACTION_MACRO(BACKWARD_WORD),
    [7] = ACTION_FUNCTION(FN_VIM_G),

    // brackets and symbols
    [8] = ACTION_MACRO(OPEN_PARENS),
    [9] = ACTION_MACRO(CLOSE_PARENS),
    [10] = ACTION_MACRO(OPEN_BRACE),
    [11] = ACTION_MACRO(CLOSE_BRACE),
    [12] = ACTION_MACRO(TILDE),
    [13] = ACTION_MACRO(PIPE),
    [14] = ACTION_MACRO(UNDERSCORE),
    [15] = ACTION_MACRO(EXLCLAIM),
    [16] = ACTION_MACRO(AT_SIGN),
    [17] = ACTION_MACRO(DOLLAR),
    [18] = ACTION_MACRO(PERCENT),
    [19] = ACTION_MACRO(HAT),
    [20] = ACTION_MACRO(AMPERSAND),

    // uk key mappings to ansi versions
    [21] = ACTION_FUNCTION(FN_ANSI_2),
    [22] = ACTION_FUNCTION(FN_ANSI_SINGLE_DOUBLE_QUOTE),

    // the < and > for the numpad layer
    [23] = ACTION_MACRO(LESS_THAN),
    [24] = ACTION_MACRO(GREATER_THAN),

    // ctrl shift c and ctrl shift v (i.e. for terminals)
    [25] = ACTION_MACRO(CTRL_SHIFT_C),
    [26] = ACTION_MACRO(CTRL_SHIFT_V),

    // seems Arch has issues with numpad - (possibly others) so switch out
    [27] = ACTION_MACRO(STAR),
    [28] = ACTION_MACRO(PLUS),

    // shift keys as \ (vim leader) when tapped
    [29] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_NUBS),
    [30] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_NUBS),
};

/******************************************************************************
 * as per cub-anic
 * if you need more than 32 fn_actions then create once fn_actions function per layer i.e.
 *     const action_t PROGMEM fn_actions_motion = { ... }
 *     const action_t PROGMEM fn_actions_brackets = { ... }
 *     const action_t PROGMEM fn_actions_numpad = { ... }
 *     ...
 *
 *  then create a custom mapping as follows
 *     #define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions)[0])
 *     #define FN_ACTIONS_MOTION_SIZE (sizeof(fn_actions_motion) / sizeof(fn_actions_motion)[0])
 *     ...
 *     action_t keymap_fn_to_action(uint8_t keycode)
 *     {
 *         uint8_t layer = biton32(layer_state);
 *
 *         action_t action;
 *         action.code = ACTION_NO;
 *
 *         // here 1 is the motion layer
 *         if (layer == 1 && FN_INDEX(keycode) < FN_ACTIONS_MOTION_SIZE) {
 *             action.code = pgm_read_word(&fn_actions_motion[FN_INDEX(keycode)]);
 *         }
 *
 *         // by default, use fn_actions from default layer 0
 *         // this is needed to get mapping for same key, that was used switch to some layer,
 *         // to have possibility to switch layers back
 *         if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
 *             action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
 *         }
 *
 *         return action;
 *     }
 *
 *****************************************************************************/
