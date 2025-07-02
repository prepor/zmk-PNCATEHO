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

// Switch positions (matching ZMK)
#define SN 0  // TOP
#define SA 1  // TOP  
#define SE 2  // TOP
#define SO 3  // TOP
#define SP 4  // BOTTOM
#define SC 5  // BOTTOM
#define ST 6  // BOTTOM
#define SH 7  // BOTTOM
#define SOT 8 // O-THUMB
#define SIT 9 // I-THUMB

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

// Combo definitions
enum combos {
    // Basic thumb combos
    COMBO_SPACE,
    COMBO_BSPC,
    
    // Single key combos
    COMBO_B, COMBO_F, COMBO_T, COMBO_J, COMBO_H, COMBO_C, COMBO_N, COMBO_Y,
    
    // Two key combos  
    COMBO_D, COMBO_K, COMBO_R, COMBO_V, COMBO_L, COMBO_G, COMBO_E, COMBO_Z,
    COMBO_S, COMBO_M, COMBO_U, COMBO_P, COMBO_COMMA, COMBO_X, COMBO_Q,
    COMBO_LBKT, COMBO_SEMI, COMBO_I, COMBO_DOT, COMBO_W, COMBO_O,
    COMBO_SQT, COMBO_A, COMBO_RBKT,
    
    // Three key combos
    COMBO_GRAVE, COMBO_NUBS,
    
    // Four key combos
    COMBO_DEL, COMBO_ESC, COMBO_TAB, COMBO_ENTER,
    
    // Layer switching
    COMBO_SLCT,
    
    // Inner thumb combos (with SIT)
    COMBO_B_I, COMBO_F_I, COMBO_T_I, COMBO_J_I, COMBO_H_I, COMBO_C_I, COMBO_N_I, COMBO_Y_I,
    COMBO_D_I, COMBO_K_I, COMBO_R_I, COMBO_V_I, COMBO_L_I, COMBO_G_I, COMBO_E_I, COMBO_Z_I,
    COMBO_S_I, COMBO_M_I, COMBO_U_I, COMBO_P_I, COMBO_COMMA_I, COMBO_X_I, COMBO_Q_I,
    COMBO_LBKT_I, COMBO_SEMI_I, COMBO_I_I, COMBO_DOT_I, COMBO_W_I, COMBO_O_I,
    COMBO_SQT_I, COMBO_A_I, COMBO_RBKT_I, COMBO_GRAVE_I, COMBO_NUBS_I,
    
    // Outer thumb combos (with SOT)
    COMBO_B_O, COMBO_F_O, COMBO_T_O, COMBO_J_O, COMBO_H_O, COMBO_C_O, COMBO_N_O, COMBO_Y_O,
    COMBO_D_O, COMBO_K_O, COMBO_R_O, COMBO_V_O, COMBO_L_O, COMBO_G_O, COMBO_E_O, COMBO_Z_O,
    COMBO_S_O, COMBO_M_O, COMBO_U_O, COMBO_P_O, COMBO_COMMA_O, COMBO_X_O, COMBO_Q_O,
    COMBO_LBKT_O, COMBO_SEMI_O, COMBO_I_O, COMBO_DOT_O, COMBO_W_O, COMBO_O_O,
    COMBO_SQT_O, COMBO_A_O, COMBO_RBKT_O, COMBO_GRAVE_O, COMBO_NUBS_O,
    
    // Both thumb combos (with SIT and SOT)
    COMBO_B_B, COMBO_F_B, COMBO_T_B, COMBO_J_B, COMBO_H_B, COMBO_C_B, COMBO_N_B, COMBO_Y_B,
    COMBO_D_B, COMBO_K_B, COMBO_R_B, COMBO_V_B, COMBO_L_B, COMBO_G_B, COMBO_E_B, COMBO_Z_B,
    COMBO_S_B, COMBO_M_B, COMBO_U_B, COMBO_P_B,
};

// Combo key positions
const uint16_t PROGMEM combo_space[] = {SIT, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {SOT, COMBO_END};

// Single key combos
const uint16_t PROGMEM combo_b[] = {SN, COMBO_END};
const uint16_t PROGMEM combo_f[] = {SA, COMBO_END};
const uint16_t PROGMEM combo_t[] = {SE, COMBO_END};
const uint16_t PROGMEM combo_j[] = {SO, COMBO_END};
const uint16_t PROGMEM combo_h[] = {SP, COMBO_END};
const uint16_t PROGMEM combo_c[] = {SC, COMBO_END};
const uint16_t PROGMEM combo_n[] = {ST, COMBO_END};
const uint16_t PROGMEM combo_y[] = {SH, COMBO_END};

// Two key combos
const uint16_t PROGMEM combo_d[] = {SN, SO, COMBO_END};
const uint16_t PROGMEM combo_k[] = {SP, SH, COMBO_END};
const uint16_t PROGMEM combo_r[] = {SP, SC, COMBO_END};
const uint16_t PROGMEM combo_v[] = {ST, SH, COMBO_END};
const uint16_t PROGMEM combo_l[] = {SN, SA, COMBO_END};
const uint16_t PROGMEM combo_g[] = {SE, SO, COMBO_END};
const uint16_t PROGMEM combo_e[] = {SC, ST, COMBO_END};
const uint16_t PROGMEM combo_z[] = {SA, SE, COMBO_END};
const uint16_t PROGMEM combo_s[] = {SP, ST, COMBO_END};
const uint16_t PROGMEM combo_m[] = {SC, SH, COMBO_END};
const uint16_t PROGMEM combo_u[] = {SN, SE, COMBO_END};
const uint16_t PROGMEM combo_p[] = {SA, SO, COMBO_END};
const uint16_t PROGMEM combo_comma[] = {SN, SH, COMBO_END};
const uint16_t PROGMEM combo_x[] = {SP, SO, COMBO_END};
const uint16_t PROGMEM combo_q[] = {SN, ST, COMBO_END};
const uint16_t PROGMEM combo_lbkt[] = {SC, SO, COMBO_END};
const uint16_t PROGMEM combo_semi[] = {SP, SE, COMBO_END};
const uint16_t PROGMEM combo_i[] = {SA, SH, COMBO_END};
const uint16_t PROGMEM combo_dot[] = {SN, SC, COMBO_END};
const uint16_t PROGMEM combo_w[] = {SO, ST, COMBO_END};
const uint16_t PROGMEM combo_o[] = {SA, ST, COMBO_END};
const uint16_t PROGMEM combo_sqt[] = {SE, SC, COMBO_END};
const uint16_t PROGMEM combo_a[] = {SE, SH, COMBO_END};
const uint16_t PROGMEM combo_rbkt[] = {SA, SP, COMBO_END};

// Three key combos
const uint16_t PROGMEM combo_grave[] = {SA, SE, SO, COMBO_END};
const uint16_t PROGMEM combo_nubs[] = {SC, ST, SH, COMBO_END};

// Four key combos  
const uint16_t PROGMEM combo_del[] = {SA, SC, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {SE, ST, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {SN, SP, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {SO, SH, COMBO_END};

// Layer switching
const uint16_t PROGMEM combo_slct[] = {SN, SA, SE, SO, COMBO_END};

// Inner thumb variants (add SIT to each combo)
const uint16_t PROGMEM combo_b_i[] = {SN, SIT, COMBO_END};
const uint16_t PROGMEM combo_f_i[] = {SA, SIT, COMBO_END};
const uint16_t PROGMEM combo_t_i[] = {SE, SIT, COMBO_END};
const uint16_t PROGMEM combo_j_i[] = {SO, SIT, COMBO_END};
const uint16_t PROGMEM combo_h_i[] = {SP, SIT, COMBO_END};
const uint16_t PROGMEM combo_c_i[] = {SC, SIT, COMBO_END};
const uint16_t PROGMEM combo_n_i[] = {ST, SIT, COMBO_END};
const uint16_t PROGMEM combo_y_i[] = {SH, SIT, COMBO_END};

// Outer thumb variants (add SOT to each combo)
const uint16_t PROGMEM combo_b_o[] = {SN, SOT, COMBO_END};
const uint16_t PROGMEM combo_f_o[] = {SA, SOT, COMBO_END};
const uint16_t PROGMEM combo_t_o[] = {SE, SOT, COMBO_END};
const uint16_t PROGMEM combo_j_o[] = {SO, SOT, COMBO_END};
const uint16_t PROGMEM combo_h_o[] = {SP, SOT, COMBO_END};
const uint16_t PROGMEM combo_c_o[] = {SC, SOT, COMBO_END};
const uint16_t PROGMEM combo_n_o[] = {ST, SOT, COMBO_END};
const uint16_t PROGMEM combo_y_o[] = {SH, SOT, COMBO_END};

// Both thumb variants (add SIT and SOT to each combo)
const uint16_t PROGMEM combo_b_b[] = {SN, SIT, SOT, COMBO_END};
const uint16_t PROGMEM combo_f_b[] = {SA, SIT, SOT, COMBO_END};
const uint16_t PROGMEM combo_t_b[] = {SE, SIT, SOT, COMBO_END};
const uint16_t PROGMEM combo_j_b[] = {SO, SIT, SOT, COMBO_END};

// Combo actions
combo_t key_combos[] = {
    // Basic thumb combos
    [COMBO_SPACE] = COMBO(combo_space, KC_SPC),
    [COMBO_BSPC] = COMBO(combo_bspc, KC_BSPC),
    
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
    [COMBO_E] = COMBO(combo_e, KC_E),
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
    
    // Four key combos
    [COMBO_DEL] = COMBO(combo_del, KC_DEL),
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
    [COMBO_ENTER] = COMBO(combo_enter, KC_ENT),
    
    // Layer switching
    [COMBO_SLCT] = COMBO(combo_slct, TO(SELECTION_LAYER)),
    
    // Inner thumb variants (shifted versions)
    [COMBO_B_I] = COMBO(combo_b_i, S(KC_B)),
    [COMBO_F_I] = COMBO(combo_f_i, S(KC_F)),
    [COMBO_T_I] = COMBO(combo_t_i, S(KC_T)),
    [COMBO_J_I] = COMBO(combo_j_i, S(KC_J)),
    [COMBO_H_I] = COMBO(combo_h_i, S(KC_H)),
    [COMBO_C_I] = COMBO(combo_c_i, S(KC_C)),
    [COMBO_N_I] = COMBO(combo_n_i, S(KC_N)),
    [COMBO_Y_I] = COMBO(combo_y_i, S(KC_Y)),
    
    // Outer thumb variants (navigation/modifiers)
    [COMBO_B_O] = COMBO(combo_b_o, KC_LEFT),
    [COMBO_F_O] = COMBO(combo_f_o, KC_UP),
    [COMBO_T_O] = COMBO(combo_t_o, KC_DOWN),
    [COMBO_J_O] = COMBO(combo_j_o, KC_RGHT),
    [COMBO_H_O] = COMBO(combo_h_o, OSM(MOD_LGUI)),
    [COMBO_C_O] = COMBO(combo_c_o, OSM(MOD_LALT)),
    [COMBO_N_O] = COMBO(combo_n_o, OSM(MOD_LCTL)),
    [COMBO_Y_O] = COMBO(combo_y_o, OSM(MOD_LSFT)),
    
    // Both thumb variants (special functions)
    [COMBO_B_B] = COMBO(combo_b_b, S(KC_LEFT)),
    [COMBO_F_B] = COMBO(combo_f_b, S(KC_UP)),
    [COMBO_T_B] = COMBO(combo_t_b, S(KC_DOWN)),
    [COMBO_J_B] = COMBO(combo_j_b, S(KC_RGHT)),
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
