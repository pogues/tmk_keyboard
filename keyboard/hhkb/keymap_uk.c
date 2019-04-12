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
         FN3,    1, FN22,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, NUBS,  DEL,\
         TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSPC,      \
         FN4,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, FN23,  FN5,            \
        LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT, LGUI,            \
                 FN1,  FN2,               SPC,                FN0, LALT
    ),

    /* Layer 1: brackets/symbols */
    KEYMAP( \
         ESC,   NO,   NO,   NO,   NO,   NO,   NO, FN25, FN26,   NO,   NO,   NO,   NO,  INS,  DEL,\
         TAB,   NO,   NO,   NO,   NO,   NO, FN16,  FN9, FN10, FN17, NUBS, TRNS, TRNS, TRNS,      \
        TRNS,   NO,   NO,   NO,   NO,   NO, NUHS, LBRC, RBRC, FN14, FN13,  GRV, TRNS,            \
        TRNS,   NO,   NO,   NO,   NO,   NO, FN21, FN11, FN12, FN18, FN20, TRNS, TRNS,            \
                TRNS,  FN0,              FN15,                 NO, RALT
    ),

    /* Layer 2: numpad */
    KEYMAP( \
         PWR,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS,  DEL,\
         TAB,   NO,   NO,   NO,   NO,   NO, PPLS,    7,    8,    9, FN19,   NO,   NO, TRNS,      \
        LCTL,   NO,   NO,   NO,   NO,   NO, PMNS,    4,    5,    6, PAST,   NO, TRNS,            \
         SPC, TRNS,   NO,   NO,   NO,   NO,  EQL,    1,    2,    3, SLSH,  SPC, TRNS,            \
                 FN0, TRNS,                 0,               COMM,  DOT
    ),

    /* Layer 3: movement */
    KEYMAP( \
         ESC,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9, MUTE, VOLD, VOLU,  INS,  DEL,\
        CAPS,   NO,  FN6,   UP,   NO,   NO,   NO,   NO, PSCR, SLCK, PAUS, FN10,  FN9, TRNS,      \
        TRNS,   NO, LEFT, DOWN, RGHT,  FN8, LEFT, DOWN,   UP, RGHT,   NO,   NO, TRNS,            \
        TRNS, FN30, FN29, FN28, FN27,  FN7, HOME, PGDN, PGUP,  END, MUTE, TRNS, TRNS,            \
                TRNS, TRNS,               SPC,               TRNS, RALT
    ),

    /* Layer 4: Alt layer */
    KEYMAP( \
        TRNS,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS, FN24,\
         TAB, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,      \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,            \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,            \
                  NO,   NO,               SPC,                 NO, TRNS
    ),
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
    CTRL_X,
    CTRL_Z,
};

/* id for user defined functions */
enum function_id {
    VIM_G,
    LAYER_ESC,
    BRACKETS_LAYER,
    NUMPAD_LAYER,
    ANSI_2,
    ANSI_SINGLE_DOUBLE_QUOTE,
};


#define CTRL_MACRO(KEY) (record->event.pressed ? MACRO(D(LCTRL), T(KEY), U(LCTRL), END) : MACRO_NONE)
#define SHIFT_MACRO(KEY) (record->event.pressed ? MACRO(D(LSFT), T(KEY), U(LSFT), END) : MACRO_NONE)

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
        case GREATER_THAN:
            return SHIFT_MACRO(DOT);
        case CTRL_INSERT:
            return CTRL_MACRO(INS);
        case SHIFT_INSERT:
            return SHIFT_MACRO(INS);
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
 * function to
 *    enter a layer on press with a modifier held
 *    or
 *    press the given key when tapped
 */
void action_function_mods_layer_tap(keyrecord_t *record, uint8_t mods, uint8_t layer, uint8_t key) {
    if (record->tap.count == 0 || record->tap.interrupted) {
        if (record->event.pressed) {
            layer_on(layer);
            add_weak_mods(mods);
        }
        else {
            del_weak_mods(mods);
            layer_off(layer);
        }
    }
    else {
        if (record->event.pressed) {
            key_press(key);
        }
        else {
            key_release(key);
        }
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
        dprintf("Enter Layer %d", layer);
    }
    else {
        // exit the entered layer
        layer_off(entered_layer);
        // always setting back to 0 as that is the default, though should not get used
        entered_layer = 0;
        dprintf("Exit Layer %d (from %d)", entered_layer, layer);
    }
}


/**
 * main tmk action function called via the ACTION_FUNCTION in fn_actions
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case VIM_G:
            action_funtion_vim_g(record);
            break;
        case ANSI_2:
            action_function_alternate_shift_two(record);   // 2 @  under the UK layout
            break;
        case ANSI_SINGLE_DOUBLE_QUOTE:
            action_function_alternate_shift_quote(record);   // ' "  under the UK layout
            break;
        case LAYER_ESC:
            action_function_mods_layer_tap(record, MOD_BIT(KC_LALT), 4, KC_ESC);
            break;
        case BRACKETS_LAYER:
            action_function_multi_layer(record, 1);
            break;
        case NUMPAD_LAYER:
            action_function_multi_layer(record, 2);
            break;
    }
}


/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    // Layers
    [0] = ACTION_LAYER_MOMENTARY(3),                // motion mode
    [1] = ACTION_FUNCTION(BRACKETS_LAYER),          // enter the brackets layer
    [2] = ACTION_FUNCTION(NUMPAD_LAYER),            // numpad layer
    //[3] = ACTION_LAYER_MODS(4, MOD_LALT),           // enter layer 4 on holding esc, with alt held
    [3] = ACTION_FUNCTION(LAYER_ESC),               // enter layer 4 on holding esc, with alt held

    // control keys on the ends of the home row
    [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),    // LControl with tap ESC
    [5] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),    // RControl with tap Enter

    // motions
    [6] = ACTION_MACRO(FORWARD_WORD),               // ctrl+->
    [7] = ACTION_MACRO(BACKWARD_WORD),              // ctrl+<-
    [8] = ACTION_FUNCTION(VIM_G),                   // g ==> ctrl+home, G ==> ctrl+end

    // brackets and symbols
    [9] = ACTION_MACRO(OPEN_PARENS),               // (brackets)u => (
    [10] = ACTION_MACRO(CLOSE_PARENS),              // (brackets)i => )
    [11] = ACTION_MACRO(OPEN_BRACE),                // (brackets)m => {
    [12] = ACTION_MACRO(CLOSE_BRACE),               // (brackets), => }
    [13] = ACTION_MACRO(TILDE),
    [14] = ACTION_MACRO(PIPE),
    [15] = ACTION_MACRO(UNDERSCORE),
    [16] = ACTION_MACRO(EXLCLAIM),
    [17] = ACTION_MACRO(AT_SIGN),
    [18] = ACTION_MACRO(DOLLAR),
    [19] = ACTION_MACRO(PERCENT),
    [20] = ACTION_MACRO(HAT),
    [21] = ACTION_MACRO(AMPERSAND),

    // uk key mappings to ansi versions
    [22] = ACTION_FUNCTION(ANSI_2),
    [23] = ACTION_FUNCTION(ANSI_SINGLE_DOUBLE_QUOTE),

    // control and delete used in the alt layer...
    [24] = ACTION_MACRO(CTRL_DEL),

    // the < and > for the numpad layer
    [25] = ACTION_MACRO(LESS_THAN),
    [26] = ACTION_MACRO(GREATER_THAN),

    // shift insert (paste) and control insert (copy) for windows
    [27] = ACTION_MACRO(SHIFT_INSERT),
    [28] = ACTION_MACRO(CTRL_INSERT),
    [29] = ACTION_MACRO(CTRL_X),
    [30] = ACTION_MACRO(CTRL_Z),
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

/******************************************************************************
 * to use oneshot modifiers the functions need to be changed...
 * expose get_oneshot_modifier in tmk_core/action_util.[c|h]
 * then in the functions check if this is set and act shifted if so
 * would also need to call clear_oneshot_mods once done
 * plus check if this needs to honour the oneshot timeout specifically
 *****************************************************************************/
