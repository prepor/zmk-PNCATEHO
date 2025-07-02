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

// Complete ZMK combo system implementation
enum combos {
    // Single key combos (base)
    CB_B, CB_F, CB_T, CB_J, CB_H, CB_C, CB_N, CB_Y,
    
    // Two key combos (base)  
    CB_D, CB_K, CB_R, CB_V, CB_L, CB_G, CB_E, CB_Z,
    CB_S, CB_M, CB_U, CB_P, CB_COMMA, CB_X, CB_Q, CB_LBKT,
    CB_SEMI, CB_I, CB_DOT, CB_W, CB_O, CB_SQT, CB_A, CB_RBKT,
    
    // Three key combos (base)
    CB_GRAVE, CB_NUBS,
    
    // System combos (base)
    CB_DEL, CB_ESC, CB_TAB, CB_ENTER, CB_SLCT,
    
    // Inner thumb variants (+ SIT)
    CBI_B, CBI_F, CBI_T, CBI_J, CBI_H, CBI_C, CBI_N, CBI_Y,
    CBI_D, CBI_K, CBI_R, CBI_V, CBI_L, CBI_G, CBI_E, CBI_Z,
    CBI_S, CBI_M, CBI_U, CBI_P, CBI_COMMA, CBI_X, CBI_Q, CBI_LBKT,
    CBI_SEMI, CBI_I, CBI_DOT, CBI_W, CBI_O, CBI_SQT, CBI_A, CBI_RBKT,
    CBI_GRAVE, CBI_NUBS, CBI_TAB, CBI_ENTER,
    
    // Outer thumb variants (+ SOT)
    CBO_B, CBO_F, CBO_T, CBO_J, CBO_H, CBO_C, CBO_N, CBO_Y,
    CBO_D, CBO_K, CBO_R, CBO_V, CBO_L, CBO_G, CBO_E, CBO_Z,
    CBO_S, CBO_M, CBO_U, CBO_P, CBO_COMMA, CBO_X, CBO_Q, CBO_LBKT,
    CBO_SEMI, CBO_I, CBO_DOT, CBO_W, CBO_O, CBO_SQT, CBO_A, CBO_RBKT,
    CBO_GRAVE, CBO_NUBS, CBO_DEL, CBO_ESC, CBO_TAB,
    
    // Both thumb variants (+ SIT SOT)
    CBB_B, CBB_F, CBB_T, CBB_J, CBB_D, CBB_K, CBB_R, CBB_V,
    CBB_L, CBB_G, CBB_E, CBB_Z, CBB_S, CBB_M, CBB_U, CBB_P,
};

// Base combo key positions
const uint16_t PROGMEM cb_b[] = {SN, COMBO_END};
const uint16_t PROGMEM cb_f[] = {SA, COMBO_END};
const uint16_t PROGMEM cb_t[] = {S_E, COMBO_END};
const uint16_t PROGMEM cb_j[] = {SO, COMBO_END};
const uint16_t PROGMEM cb_h[] = {S_P, COMBO_END};
const uint16_t PROGMEM cb_c[] = {SC, COMBO_END};
const uint16_t PROGMEM cb_n[] = {ST, COMBO_END};
const uint16_t PROGMEM cb_y[] = {SH, COMBO_END};
const uint16_t PROGMEM cb_d[] = {SN, SO, COMBO_END};
const uint16_t PROGMEM cb_k[] = {S_P, SH, COMBO_END};
const uint16_t PROGMEM cb_r[] = {S_P, SC, COMBO_END};
const uint16_t PROGMEM cb_v[] = {ST, SH, COMBO_END};
const uint16_t PROGMEM cb_l[] = {SN, SA, COMBO_END};
const uint16_t PROGMEM cb_g[] = {S_E, SO, COMBO_END};
const uint16_t PROGMEM cb_e[] = {SC, ST, COMBO_END};
const uint16_t PROGMEM cb_z[] = {SA, S_E, COMBO_END};
const uint16_t PROGMEM cb_s[] = {S_P, ST, COMBO_END};
const uint16_t PROGMEM cb_m[] = {SC, SH, COMBO_END};
const uint16_t PROGMEM cb_u[] = {SN, S_E, COMBO_END};
const uint16_t PROGMEM cb_p[] = {SA, SO, COMBO_END};
const uint16_t PROGMEM cb_comma[] = {SN, SH, COMBO_END};
const uint16_t PROGMEM cb_x[] = {S_P, SO, COMBO_END};
const uint16_t PROGMEM cb_q[] = {SN, ST, COMBO_END};
const uint16_t PROGMEM cb_lbkt[] = {SC, SO, COMBO_END};
const uint16_t PROGMEM cb_semi[] = {S_P, S_E, COMBO_END};
const uint16_t PROGMEM cb_i[] = {SA, SH, COMBO_END};
const uint16_t PROGMEM cb_dot[] = {SN, SC, COMBO_END};
const uint16_t PROGMEM cb_w[] = {SO, ST, COMBO_END};
const uint16_t PROGMEM cb_o[] = {SA, ST, COMBO_END};
const uint16_t PROGMEM cb_sqt[] = {S_E, SC, COMBO_END};
const uint16_t PROGMEM cb_a[] = {S_E, SH, COMBO_END};
const uint16_t PROGMEM cb_rbkt[] = {SA, S_P, COMBO_END};
const uint16_t PROGMEM cb_grave[] = {SA, S_E, SO, COMBO_END};
const uint16_t PROGMEM cb_nubs[] = {SC, ST, SH, COMBO_END};
const uint16_t PROGMEM cb_del[] = {SA, SC, COMBO_END};
const uint16_t PROGMEM cb_esc[] = {S_E, ST, COMBO_END};
const uint16_t PROGMEM cb_tab[] = {SN, S_P, COMBO_END};
const uint16_t PROGMEM cb_enter[] = {SO, SH, COMBO_END};
const uint16_t PROGMEM cb_slct[] = {SN, SA, S_E, SO, COMBO_END};

// Inner thumb variants (+ SIT)
const uint16_t PROGMEM cbi_b[] = {SN, SIT, COMBO_END};
const uint16_t PROGMEM cbi_f[] = {SA, SIT, COMBO_END};
const uint16_t PROGMEM cbi_t[] = {S_E, SIT, COMBO_END};
const uint16_t PROGMEM cbi_j[] = {SO, SIT, COMBO_END};
const uint16_t PROGMEM cbi_h[] = {S_P, SIT, COMBO_END};
const uint16_t PROGMEM cbi_c[] = {SC, SIT, COMBO_END};
const uint16_t PROGMEM cbi_n[] = {ST, SIT, COMBO_END};
const uint16_t PROGMEM cbi_y[] = {SH, SIT, COMBO_END};
const uint16_t PROGMEM cbi_d[] = {SN, SO, SIT, COMBO_END};
const uint16_t PROGMEM cbi_k[] = {S_P, SH, SIT, COMBO_END};
const uint16_t PROGMEM cbi_r[] = {S_P, SC, SIT, COMBO_END};
const uint16_t PROGMEM cbi_v[] = {ST, SH, SIT, COMBO_END};
const uint16_t PROGMEM cbi_l[] = {SN, SA, SIT, COMBO_END};
const uint16_t PROGMEM cbi_g[] = {S_E, SO, SIT, COMBO_END};
const uint16_t PROGMEM cbi_e[] = {SC, ST, SIT, COMBO_END};
const uint16_t PROGMEM cbi_z[] = {SA, S_E, SIT, COMBO_END};
const uint16_t PROGMEM cbi_s[] = {S_P, ST, SIT, COMBO_END};
const uint16_t PROGMEM cbi_m[] = {SC, SH, SIT, COMBO_END};
const uint16_t PROGMEM cbi_u[] = {SN, S_E, SIT, COMBO_END};
const uint16_t PROGMEM cbi_p[] = {SA, SO, SIT, COMBO_END};
const uint16_t PROGMEM cbi_comma[] = {SN, SH, SIT, COMBO_END};
const uint16_t PROGMEM cbi_x[] = {S_P, SO, SIT, COMBO_END};
const uint16_t PROGMEM cbi_q[] = {SN, ST, SIT, COMBO_END};
const uint16_t PROGMEM cbi_lbkt[] = {SC, SO, SIT, COMBO_END};
const uint16_t PROGMEM cbi_semi[] = {S_P, S_E, SIT, COMBO_END};
const uint16_t PROGMEM cbi_i[] = {SA, SH, SIT, COMBO_END};
const uint16_t PROGMEM cbi_dot[] = {SN, SC, SIT, COMBO_END};
const uint16_t PROGMEM cbi_w[] = {SO, ST, SIT, COMBO_END};
const uint16_t PROGMEM cbi_o[] = {SA, ST, SIT, COMBO_END};
const uint16_t PROGMEM cbi_sqt[] = {S_E, SC, SIT, COMBO_END};
const uint16_t PROGMEM cbi_a[] = {S_E, SH, SIT, COMBO_END};
const uint16_t PROGMEM cbi_rbkt[] = {SA, S_P, SIT, COMBO_END};
const uint16_t PROGMEM cbi_grave[] = {SA, S_E, SO, SIT, COMBO_END};
const uint16_t PROGMEM cbi_nubs[] = {SC, ST, SH, SIT, COMBO_END};
const uint16_t PROGMEM cbi_tab[] = {SN, S_P, SIT, COMBO_END};
const uint16_t PROGMEM cbi_enter[] = {SO, SH, SIT, COMBO_END};

// Outer thumb variants (navigation/numbers)
const uint16_t PROGMEM cbo_b[] = {SN, SOT, COMBO_END};
const uint16_t PROGMEM cbo_f[] = {SA, SOT, COMBO_END};
const uint16_t PROGMEM cbo_t[] = {S_E, SOT, COMBO_END};
const uint16_t PROGMEM cbo_j[] = {SO, SOT, COMBO_END};
const uint16_t PROGMEM cbo_h[] = {S_P, SOT, COMBO_END};
const uint16_t PROGMEM cbo_c[] = {SC, SOT, COMBO_END};
const uint16_t PROGMEM cbo_n[] = {ST, SOT, COMBO_END};
const uint16_t PROGMEM cbo_y[] = {SH, SOT, COMBO_END};
const uint16_t PROGMEM cbo_d[] = {SN, SO, SOT, COMBO_END};
const uint16_t PROGMEM cbo_k[] = {S_P, SH, SOT, COMBO_END};
const uint16_t PROGMEM cbo_r[] = {S_P, SC, SOT, COMBO_END};
const uint16_t PROGMEM cbo_v[] = {ST, SH, SOT, COMBO_END};
const uint16_t PROGMEM cbo_l[] = {SN, SA, SOT, COMBO_END};
const uint16_t PROGMEM cbo_g[] = {S_E, SO, SOT, COMBO_END};
const uint16_t PROGMEM cbo_e[] = {SC, ST, SOT, COMBO_END};
const uint16_t PROGMEM cbo_z[] = {SA, S_E, SOT, COMBO_END};
const uint16_t PROGMEM cbo_s[] = {S_P, ST, SOT, COMBO_END};
const uint16_t PROGMEM cbo_m[] = {SC, SH, SOT, COMBO_END};
const uint16_t PROGMEM cbo_u[] = {SN, S_E, SOT, COMBO_END};
const uint16_t PROGMEM cbo_p[] = {SA, SO, SOT, COMBO_END};
const uint16_t PROGMEM cbo_comma[] = {SN, SH, SOT, COMBO_END};
const uint16_t PROGMEM cbo_x[] = {S_P, SO, SOT, COMBO_END};
const uint16_t PROGMEM cbo_q[] = {SN, ST, SOT, COMBO_END};
const uint16_t PROGMEM cbo_lbkt[] = {SC, SO, SOT, COMBO_END};
const uint16_t PROGMEM cbo_semi[] = {S_P, S_E, SOT, COMBO_END};
const uint16_t PROGMEM cbo_i[] = {SA, SH, SOT, COMBO_END};
const uint16_t PROGMEM cbo_dot[] = {SN, SC, SOT, COMBO_END};
const uint16_t PROGMEM cbo_w[] = {SO, ST, SOT, COMBO_END};
const uint16_t PROGMEM cbo_o[] = {SA, ST, SOT, COMBO_END};
const uint16_t PROGMEM cbo_sqt[] = {S_E, SC, SOT, COMBO_END};
const uint16_t PROGMEM cbo_a[] = {S_E, SH, SOT, COMBO_END};
const uint16_t PROGMEM cbo_rbkt[] = {SA, S_P, SOT, COMBO_END};
const uint16_t PROGMEM cbo_grave[] = {SA, S_E, SO, SOT, COMBO_END};
const uint16_t PROGMEM cbo_nubs[] = {SC, ST, SH, SOT, COMBO_END};
const uint16_t PROGMEM cbo_del[] = {SA, SC, SOT, COMBO_END};
const uint16_t PROGMEM cbo_esc[] = {S_E, ST, SOT, COMBO_END};
const uint16_t PROGMEM cbo_tab[] = {SN, S_P, SOT, COMBO_END};

// Both thumb variants (shifted navigation/function keys)
const uint16_t PROGMEM cbb_b[] = {SN, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_f[] = {SA, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_t[] = {S_E, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_j[] = {SO, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_d[] = {SN, SO, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_k[] = {S_P, SH, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_r[] = {S_P, SC, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_v[] = {ST, SH, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_l[] = {SN, SA, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_g[] = {S_E, SO, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_e[] = {SC, ST, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_z[] = {SA, S_E, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_s[] = {S_P, ST, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_m[] = {SC, SH, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_u[] = {SN, S_E, SIT, SOT, COMBO_END};
const uint16_t PROGMEM cbb_p[] = {SA, SO, SIT, SOT, COMBO_END};

// Combo actions (complete ZMK implementation)
combo_t key_combos[] = {
    // Base combos
    [CB_B] = COMBO(cb_b, KC_B),
    [CB_F] = COMBO(cb_f, KC_F),
    [CB_T] = COMBO(cb_t, KC_T),
    [CB_J] = COMBO(cb_j, KC_J),
    [CB_H] = COMBO(cb_h, KC_H),
    [CB_C] = COMBO(cb_c, KC_C),
    [CB_N] = COMBO(cb_n, KC_N),
    [CB_Y] = COMBO(cb_y, KC_Y),
    [CB_D] = COMBO(cb_d, KC_D),
    [CB_K] = COMBO(cb_k, KC_K),
    [CB_R] = COMBO(cb_r, KC_R),
    [CB_V] = COMBO(cb_v, KC_V),
    [CB_L] = COMBO(cb_l, KC_L),
    [CB_G] = COMBO(cb_g, KC_G),
    [CB_E] = COMBO(cb_e, KC_E),
    [CB_Z] = COMBO(cb_z, KC_Z),
    [CB_S] = COMBO(cb_s, KC_S),
    [CB_M] = COMBO(cb_m, KC_M),
    [CB_U] = COMBO(cb_u, KC_U),
    [CB_P] = COMBO(cb_p, KC_P),
    [CB_COMMA] = COMBO(cb_comma, KC_COMM),
    [CB_X] = COMBO(cb_x, KC_X),
    [CB_Q] = COMBO(cb_q, KC_Q),
    [CB_LBKT] = COMBO(cb_lbkt, KC_LBRC),
    [CB_SEMI] = COMBO(cb_semi, KC_SCLN),
    [CB_I] = COMBO(cb_i, KC_I),
    [CB_DOT] = COMBO(cb_dot, KC_DOT),
    [CB_W] = COMBO(cb_w, KC_W),
    [CB_O] = COMBO(cb_o, KC_O),
    [CB_SQT] = COMBO(cb_sqt, KC_QUOT),
    [CB_A] = COMBO(cb_a, KC_A),
    [CB_RBKT] = COMBO(cb_rbkt, KC_RBRC),
    [CB_GRAVE] = COMBO(cb_grave, KC_GRV),
    [CB_NUBS] = COMBO(cb_nubs, KC_BSLS),
    [CB_DEL] = COMBO(cb_del, KC_DEL),
    [CB_ESC] = COMBO(cb_esc, KC_ESC),
    [CB_TAB] = COMBO(cb_tab, KC_TAB),
    [CB_ENTER] = COMBO(cb_enter, KC_ENT),
    [CB_SLCT] = COMBO(cb_slct, TO(SELECTION_LAYER)),
    
    // Inner thumb variants (shifted)
    [CBI_B] = COMBO(cbi_b, KC_B),
    [CBI_F] = COMBO(cbi_f, KC_F),
    [CBI_T] = COMBO(cbi_t, KC_T),
    [CBI_J] = COMBO(cbi_j, KC_J),
    [CBI_H] = COMBO(cbi_h, KC_H),
    [CBI_C] = COMBO(cbi_c, KC_C),
    [CBI_N] = COMBO(cbi_n, KC_N),
    [CBI_Y] = COMBO(cbi_y, KC_Y),
    [CBI_D] = COMBO(cbi_d, KC_D),
    [CBI_K] = COMBO(cbi_k, KC_K),
    [CBI_R] = COMBO(cbi_r, KC_R),
    [CBI_V] = COMBO(cbi_v, KC_V),
    [CBI_L] = COMBO(cbi_l, KC_L),
    [CBI_G] = COMBO(cbi_g, KC_G),
    [CBI_E] = COMBO(cbi_e, KC_E),
    [CBI_Z] = COMBO(cbi_z, KC_Z),
    [CBI_S] = COMBO(cbi_s, KC_S),
    [CBI_M] = COMBO(cbi_m, KC_M),
    [CBI_U] = COMBO(cbi_u, KC_U),
    [CBI_P] = COMBO(cbi_p, KC_P),
    [CBI_COMMA] = COMBO(cbi_comma, KC_COMM),
    [CBI_X] = COMBO(cbi_x, KC_X),
    [CBI_Q] = COMBO(cbi_q, KC_Q),
    [CBI_LBKT] = COMBO(cbi_lbkt, KC_LBRC),
    [CBI_SEMI] = COMBO(cbi_semi, KC_SCLN),
    [CBI_I] = COMBO(cbi_i, KC_I),
    [CBI_DOT] = COMBO(cbi_dot, KC_DOT),
    [CBI_W] = COMBO(cbi_w, KC_W),
    [CBI_O] = COMBO(cbi_o, KC_O),
    [CBI_SQT] = COMBO(cbi_sqt, KC_QUOT),
    [CBI_A] = COMBO(cbi_a, KC_A),
    [CBI_RBKT] = COMBO(cbi_rbkt, KC_RBRC),
    [CBI_GRAVE] = COMBO(cbi_grave, KC_GRV),
    [CBI_NUBS] = COMBO(cbi_nubs, KC_BSLS),
    [CBI_TAB] = COMBO(cbi_tab, LALT(KC_TAB)),
    [CBI_ENTER] = COMBO(cbi_enter, KC_ENT),
    
    // Outer thumb variants (navigation/numbers)
    [CBO_B] = COMBO(cbo_b, KC_LEFT),
    [CBO_F] = COMBO(cbo_f, KC_UP),
    [CBO_T] = COMBO(cbo_t, KC_DOWN),
    [CBO_J] = COMBO(cbo_j, KC_RGHT),
    [CBO_H] = COMBO(cbo_h, KC_LGUI),
    [CBO_C] = COMBO(cbo_c, KC_LALT),
    [CBO_N] = COMBO(cbo_n, KC_LCTL),
    [CBO_Y] = COMBO(cbo_y, KC_LSFT),
    [CBO_D] = COMBO(cbo_d, KC_1),
    [CBO_K] = COMBO(cbo_k, KC_2),
    [CBO_R] = COMBO(cbo_r, KC_3),
    [CBO_V] = COMBO(cbo_v, KC_4),
    [CBO_L] = COMBO(cbo_l, KC_5),
    [CBO_G] = COMBO(cbo_g, KC_6),
    [CBO_E] = COMBO(cbo_e, KC_7),
    [CBO_Z] = COMBO(cbo_z, KC_8),
    [CBO_S] = COMBO(cbo_s, KC_9),
    [CBO_M] = COMBO(cbo_m, KC_0),
    [CBO_U] = COMBO(cbo_u, KC_EXLM),
    [CBO_P] = COMBO(cbo_p, KC_AT),
    [CBO_COMMA] = COMBO(cbo_comma, KC_HASH),
    [CBO_X] = COMBO(cbo_x, KC_DLR),
    [CBO_Q] = COMBO(cbo_q, KC_PERC),
    [CBO_LBKT] = COMBO(cbo_lbkt, KC_CIRC),
    [CBO_SEMI] = COMBO(cbo_semi, KC_AMPR),
    [CBO_I] = COMBO(cbo_i, KC_ASTR),
    [CBO_DOT] = COMBO(cbo_dot, KC_LPRN),
    [CBO_W] = COMBO(cbo_w, KC_RPRN),
    [CBO_O] = COMBO(cbo_o, KC_SLSH),
    [CBO_SQT] = COMBO(cbo_sqt, KC_QUES),
    [CBO_A] = COMBO(cbo_a, KC_MINS),
    [CBO_RBKT] = COMBO(cbo_rbkt, KC_UNDS),
    [CBO_GRAVE] = COMBO(cbo_grave, KC_EQL),
    [CBO_NUBS] = COMBO(cbo_nubs, KC_PLUS),
    [CBO_DEL] = COMBO(cbo_del, LCTL(KC_DEL)),
    [CBO_ESC] = COMBO(cbo_esc, KC_1),
    [CBO_TAB] = COMBO(cbo_tab, LCTL(KC_TAB)),
    
    // Both thumb variants (shifted navigation/function keys)
    [CBB_B] = COMBO(cbb_b, LSFT(KC_LEFT)),
    [CBB_F] = COMBO(cbb_f, LSFT(KC_UP)),
    [CBB_T] = COMBO(cbb_t, LSFT(KC_DOWN)),
    [CBB_J] = COMBO(cbb_j, LSFT(KC_RGHT)),
    [CBB_D] = COMBO(cbb_d, KC_F1),
    [CBB_K] = COMBO(cbb_k, KC_F2),
    [CBB_R] = COMBO(cbb_r, KC_F3),
    [CBB_V] = COMBO(cbb_v, KC_F4),
    [CBB_L] = COMBO(cbb_l, KC_F5),
    [CBB_G] = COMBO(cbb_g, KC_F6),
    [CBB_E] = COMBO(cbb_e, KC_F7),
    [CBB_Z] = COMBO(cbb_z, KC_F8),
    [CBB_S] = COMBO(cbb_s, KC_F9),
    [CBB_M] = COMBO(cbb_m, KC_F10),
    [CBB_U] = COMBO(cbb_u, KC_F11),
    [CBB_P] = COMBO(cbb_p, KC_F12),
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
