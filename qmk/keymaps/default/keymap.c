// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layer definitions (matching ZMK order)
enum layers {
    COMBO_LAYER = 0,
    SELECTION_LAYER,
    NAVIGATION_LAYER,
    BLUETOOTH_LAYER,
    KBCTRL_LAYER,
    RGB_LAYER,
    LOL_MAIN_LAYER,
    LOL_NUMBERS_LAYER,
    LOL_ADDITIONAL_LAYER,
    LOL_FN_LAYER
};

// Switch positions (matching ZMK) - renamed to avoid AVR conflicts
#define SN 0   // TOP
#define SA 1   // TOP  
#define S_E 2  // TOP (renamed from SE to avoid conflict)
#define SO 3   // TOP
#define S_P 4  // BOTTOM (renamed from SP to avoid conflict)
#define SC 5   // BOTTOM
#define ST 6   // BOTTOM
#define SH 7   // BOTTOM
#define SOT 8  // O-THUMB
#define SIT 9  // I-THUMB

// Tap dance declarations
enum {
    TD_ADD_CTRL_FN,
};

// Tap dance definitions
void dance_add_ctrl_fn(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            layer_on(LOL_ADDITIONAL_LAYER);
            break;
        case 2:
            register_code(KC_LCTL);
            break;
        case 3:
            layer_on(LOL_FN_LAYER);
            break;
    }
}

void dance_add_ctrl_fn_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            layer_off(LOL_ADDITIONAL_LAYER);
            break;
        case 2:
            unregister_code(KC_LCTL);
            break;
        case 3:
            layer_off(LOL_FN_LAYER);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ADD_CTRL_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_add_ctrl_fn, dance_add_ctrl_fn_reset),
};

// Expanded combo definitions
enum combos {
    // Basic system combos
    COMBO_ESC,
    COMBO_TAB,
    COMBO_ENTER,
    COMBO_DEL,
    COMBO_SLCT,
    
    // Single key combos (individual switches)
    COMBO_B,
    COMBO_F,
    COMBO_T,
    COMBO_J,
    COMBO_H,
    COMBO_C,
    COMBO_N,
    COMBO_Y,
    
    // Two key combos
    COMBO_D,
    COMBO_K,
    COMBO_R,
    COMBO_V,
    COMBO_L,
    COMBO_G,
    COMBO_EE,
    COMBO_Z,
    COMBO_S,
    COMBO_M,
    COMBO_U,
    COMBO_P,
    COMBO_COMMA,
    COMBO_X,
    COMBO_Q,
    COMBO_LBKT,
    COMBO_SEMI,
    COMBO_I,
    COMBO_DOT,
    COMBO_W,
    COMBO_O,
    COMBO_SQT,
    COMBO_A,
    COMBO_RBKT,
    
    // Three key combos
    COMBO_GRAVE,
    COMBO_NUBS,
    
    // Thumb + key combos (shifted versions)
    COMBO_B_SH,
    COMBO_F_SH,
    COMBO_T_SH,
    COMBO_J_SH,
    COMBO_H_SH,
    COMBO_C_SH,
    COMBO_N_SH,
    COMBO_Y_SH,
    
    // Thumb + key combos (navigation)
    COMBO_B_NAV,
    COMBO_F_NAV,
    COMBO_T_NAV,
    COMBO_J_NAV,
    COMBO_H_NAV,
    COMBO_C_NAV,
    COMBO_N_NAV,
    COMBO_Y_NAV,
};

// Combo key positions
const uint16_t PROGMEM combo_esc[] = {S_E, ST, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {SN, S_P, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {SO, SH, COMBO_END};
const uint16_t PROGMEM combo_del[] = {SA, SC, COMBO_END};
const uint16_t PROGMEM combo_slct[] = {SN, SA, S_E, SO, COMBO_END};

// Single key combos
const uint16_t PROGMEM combo_b[] = {SN, COMBO_END};
const uint16_t PROGMEM combo_f[] = {SA, COMBO_END};
const uint16_t PROGMEM combo_t[] = {S_E, COMBO_END};
const uint16_t PROGMEM combo_j[] = {SO, COMBO_END};
const uint16_t PROGMEM combo_h[] = {S_P, COMBO_END};
const uint16_t PROGMEM combo_c[] = {SC, COMBO_END};
const uint16_t PROGMEM combo_n[] = {ST, COMBO_END};
const uint16_t PROGMEM combo_y[] = {SH, COMBO_END};

// Two key combos
const uint16_t PROGMEM combo_d[] = {SN, SO, COMBO_END};
const uint16_t PROGMEM combo_k[] = {S_P, SH, COMBO_END};
const uint16_t PROGMEM combo_r[] = {S_P, SC, COMBO_END};
const uint16_t PROGMEM combo_v[] = {ST, SH, COMBO_END};
const uint16_t PROGMEM combo_l[] = {SN, SA, COMBO_END};
const uint16_t PROGMEM combo_g[] = {S_E, SO, COMBO_END};
const uint16_t PROGMEM combo_ee[] = {SC, ST, COMBO_END};
const uint16_t PROGMEM combo_z[] = {SA, S_E, COMBO_END};
const uint16_t PROGMEM combo_s[] = {S_P, ST, COMBO_END};
const uint16_t PROGMEM combo_m[] = {SC, SH, COMBO_END};
const uint16_t PROGMEM combo_u[] = {SN, S_E, COMBO_END};
const uint16_t PROGMEM combo_p[] = {SA, SO, COMBO_END};
const uint16_t PROGMEM combo_comma[] = {SN, SH, COMBO_END};
const uint16_t PROGMEM combo_x[] = {S_P, SO, COMBO_END};
const uint16_t PROGMEM combo_q[] = {SN, ST, COMBO_END};
const uint16_t PROGMEM combo_lbkt[] = {SC, SO, COMBO_END};
const uint16_t PROGMEM combo_semi[] = {S_P, S_E, COMBO_END};
const uint16_t PROGMEM combo_i[] = {SA, SH, COMBO_END};
const uint16_t PROGMEM combo_dot[] = {SN, SC, COMBO_END};
const uint16_t PROGMEM combo_w[] = {SO, ST, COMBO_END};
const uint16_t PROGMEM combo_o[] = {SA, ST, COMBO_END};
const uint16_t PROGMEM combo_sqt[] = {S_E, SC, COMBO_END};
const uint16_t PROGMEM combo_a[] = {S_E, SH, COMBO_END};
const uint16_t PROGMEM combo_rbkt[] = {SA, S_P, COMBO_END};

// Three key combos
const uint16_t PROGMEM combo_grave[] = {SA, S_E, SO, COMBO_END};
const uint16_t PROGMEM combo_nubs[] = {SC, ST, SH, COMBO_END};

// Thumb + key combos (shifted versions with SIT)
const uint16_t PROGMEM combo_b_sh[] = {SN, SIT, COMBO_END};
const uint16_t PROGMEM combo_f_sh[] = {SA, SIT, COMBO_END};
const uint16_t PROGMEM combo_t_sh[] = {S_E, SIT, COMBO_END};
const uint16_t PROGMEM combo_j_sh[] = {SO, SIT, COMBO_END};
const uint16_t PROGMEM combo_h_sh[] = {S_P, SIT, COMBO_END};
const uint16_t PROGMEM combo_c_sh[] = {SC, SIT, COMBO_END};
const uint16_t PROGMEM combo_n_sh[] = {ST, SIT, COMBO_END};
const uint16_t PROGMEM combo_y_sh[] = {SH, SIT, COMBO_END};

// Thumb + key combos (navigation with SOT)
const uint16_t PROGMEM combo_b_nav[] = {SN, SOT, COMBO_END};
const uint16_t PROGMEM combo_f_nav[] = {SA, SOT, COMBO_END};
const uint16_t PROGMEM combo_t_nav[] = {S_E, SOT, COMBO_END};
const uint16_t PROGMEM combo_j_nav[] = {SO, SOT, COMBO_END};
const uint16_t PROGMEM combo_h_nav[] = {S_P, SOT, COMBO_END};
const uint16_t PROGMEM combo_c_nav[] = {SC, SOT, COMBO_END};
const uint16_t PROGMEM combo_n_nav[] = {ST, SOT, COMBO_END};
const uint16_t PROGMEM combo_y_nav[] = {SH, SOT, COMBO_END};

// Combo actions
combo_t key_combos[] = {
    // Basic system combos
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
    [COMBO_ENTER] = COMBO(combo_enter, KC_ENT),
    [COMBO_DEL] = COMBO(combo_del, KC_DEL),
    [COMBO_SLCT] = COMBO(combo_slct, TO(SELECTION_LAYER)),
    
    // Single key combos
    [COMBO_B] = COMBO(combo_b, KC_B),
    [COMBO_F] = COMBO(combo_f, KC_F),
    [COMBO_T] = COMBO(combo_t, KC_T),
    [COMBO_J] = COMBO(combo_j, KC_J),
    [COMBO_H] = COMBO(combo_h, KC_H),
    [COMBO_C] = COMBO(combo_c, KC_C),
    [COMBO_N] = COMBO(combo_n, KC_N),
    [COMBO_Y] = COMBO(combo_y, KC_Y),
    
    // Two key combos
    [COMBO_D] = COMBO(combo_d, KC_D),
    [COMBO_K] = COMBO(combo_k, KC_K),
    [COMBO_R] = COMBO(combo_r, KC_R),
    [COMBO_V] = COMBO(combo_v, KC_V),
    [COMBO_L] = COMBO(combo_l, KC_L),
    [COMBO_G] = COMBO(combo_g, KC_G),
    [COMBO_EE] = COMBO(combo_ee, KC_E),
    [COMBO_Z] = COMBO(combo_z, KC_Z),
    [COMBO_S] = COMBO(combo_s, KC_S),
    [COMBO_M] = COMBO(combo_m, KC_M),
    [COMBO_U] = COMBO(combo_u, KC_U),
    [COMBO_P] = COMBO(combo_p, KC_P),
    [COMBO_COMMA] = COMBO(combo_comma, KC_COMM),
    [COMBO_X] = COMBO(combo_x, KC_X),
    [COMBO_Q] = COMBO(combo_q, KC_Q),
    [COMBO_LBKT] = COMBO(combo_lbkt, KC_LBRC),
    [COMBO_SEMI] = COMBO(combo_semi, KC_SCLN),
    [COMBO_I] = COMBO(combo_i, KC_I),
    [COMBO_DOT] = COMBO(combo_dot, KC_DOT),
    [COMBO_W] = COMBO(combo_w, KC_W),
    [COMBO_O] = COMBO(combo_o, KC_O),
    [COMBO_SQT] = COMBO(combo_sqt, KC_QUOT),
    [COMBO_A] = COMBO(combo_a, KC_A),
    [COMBO_RBKT] = COMBO(combo_rbkt, KC_RBRC),
    
    // Three key combos
    [COMBO_GRAVE] = COMBO(combo_grave, KC_GRV),
    [COMBO_NUBS] = COMBO(combo_nubs, KC_NUBS),
    
    // Thumb + key combos (shifted versions)
    [COMBO_B_SH] = COMBO(combo_b_sh, S(KC_B)),
    [COMBO_F_SH] = COMBO(combo_f_sh, S(KC_F)),
    [COMBO_T_SH] = COMBO(combo_t_sh, S(KC_T)),
    [COMBO_J_SH] = COMBO(combo_j_sh, S(KC_J)),
    [COMBO_H_SH] = COMBO(combo_h_sh, S(KC_H)),
    [COMBO_C_SH] = COMBO(combo_c_sh, S(KC_C)),
    [COMBO_N_SH] = COMBO(combo_n_sh, S(KC_N)),
    [COMBO_Y_SH] = COMBO(combo_y_sh, S(KC_Y)),
    
    // Thumb + key combos (navigation/modifiers)
    [COMBO_B_NAV] = COMBO(combo_b_nav, KC_LEFT),
    [COMBO_F_NAV] = COMBO(combo_f_nav, KC_UP),
    [COMBO_T_NAV] = COMBO(combo_t_nav, KC_DOWN),
    [COMBO_J_NAV] = COMBO(combo_j_nav, KC_RGHT),
    [COMBO_H_NAV] = COMBO(combo_h_nav, OSM(MOD_LGUI)),
    [COMBO_C_NAV] = COMBO(combo_c_nav, OSM(MOD_LALT)),
    [COMBO_N_NAV] = COMBO(combo_n_nav, OSM(MOD_LCTL)),
    [COMBO_Y_NAV] = COMBO(combo_y_nav, OSM(MOD_LSFT)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layer 0: COMBO_LAYER
     * ┌───┬───┬───┬───┐
     * │   │   │   │   │
     * ├───┼───┼───┼───┤
     * │   │   │   │   │
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │SPC│BSP│
     *     └───┴───┘
     */
    [COMBO_LAYER] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_SPC,  KC_BSPC
    ),

    /*
     * Layer 1: SELECTION_LAYER
     * ┌───┬───┬───┬───┐
     * │NAV│LOL│   │BLT│
     * ├───┼───┼───┼───┤
     * │RGB│   │   │KBC│
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │COM│   │
     *     └───┴───┘
     */
    [SELECTION_LAYER] = LAYOUT(
        TO(NAVIGATION_LAYER), TO(LOL_MAIN_LAYER), KC_NO,    TO(BLUETOOTH_LAYER),
        TO(RGB_LAYER),        KC_NO,              KC_NO,    TO(KBCTRL_LAYER),
                              TO(COMBO_LAYER),    KC_NO
    ),

    /*
     * Layer 2: NAVIGATION_LAYER
     * ┌───┬───┬───┬───┐
     * │PGU│END│UP │HOM│
     * ├───┼───┼───┼───┤
     * │PGD│LFT│DWN│RGT│
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │COM│   │
     *     └───┴───┘
     */
    [NAVIGATION_LAYER] = LAYOUT(
        KC_PGUP, KC_END,  KC_UP,   KC_HOME,
        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,
                 TO(COMBO_LAYER), KC_NO
    ),

    /*
     * Layer 3: BLUETOOTH_LAYER (placeholder - BT not available in QMK)
     */
    [BLUETOOTH_LAYER] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 TO(COMBO_LAYER), KC_NO
    ),

    /*
     * Layer 4: KBCTRL_LAYER
     * ┌───┬───┬───┬───┐
     * │BOT│   │   │   │
     * ├───┼───┼───┼───┤
     * │RST│   │   │   │
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │COM│   │
     *     └───┴───┘
     */
    [KBCTRL_LAYER] = LAYOUT(
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,
        QK_RBT,  KC_NO,   KC_NO,   KC_NO,
                 TO(COMBO_LAYER), KC_NO
    ),

    /*
     * Layer 5: RGB_LAYER (placeholder - basic RGB not implemented)
     */
    [RGB_LAYER] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 TO(COMBO_LAYER), KC_NO
    ),

    /*
     * Layer 6: LOL_MAIN_LAYER
     * ┌───┬───┬───┬───┐
     * │ Q │ W │ E │ R │
     * ├───┼───┼───┼───┤
     * │ A │ S │ D │ F │
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │NUM│TDN│
     *     └───┴───┘
     */
    [LOL_MAIN_LAYER] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,
        KC_A,    KC_S,    KC_D,    KC_F,
                 MO(LOL_NUMBERS_LAYER), TD(TD_ADD_CTRL_FN)
    ),

    /*
     * Layer 7: LOL_NUMBERS_LAYER
     * ┌───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │
     * ├───┼───┼───┼───┤
     * │ 5 │ 6 │ 7 │ 8 │
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │   │ V │
     *     └───┴───┘
     */
    [LOL_NUMBERS_LAYER] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,
        KC_5,    KC_6,    KC_7,    KC_8,
                 KC_TRNS, KC_V
    ),

    /*
     * Layer 8: LOL_ADDITIONAL_LAYER
     * ┌───┬───┬───┬───┐
     * │ESC│   │   │COM│
     * ├───┼───┼───┼───┤
     * │TAB│   │   │   │
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │   │   │
     *     └───┴───┘
     */
    [LOL_ADDITIONAL_LAYER] = LAYOUT(
        KC_ESC,  KC_NO,   KC_NO,   TO(COMBO_LAYER),
        KC_TAB,  KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO
    ),

    /*
     * Layer 9: LOL_FN_LAYER
     * ┌───┬───┬───┬───┐
     * │F1 │F2 │F3 │F4 │
     * ├───┼───┼───┼───┤
     * │F5 │F6 │F7 │F8 │
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │   │   │
     *     └───┴───┘
     */
    [LOL_FN_LAYER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,
                 KC_NO,   KC_NO
    )
};
