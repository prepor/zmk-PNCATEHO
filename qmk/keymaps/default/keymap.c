// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    COMBO_LAYER,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ Q │ W │ E │ R │
     * ├───┼───┼───┼───┤
     * │ A │ S │ D │ F │
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │NUM│CTL│
     *     └───┴───┘
     */
    [LOL_MAIN_LAYER] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,
        KC_A,    KC_S,    KC_D,    KC_F,
                 MO(LOL_NUMBERS_LAYER), LT(LOL_FN_LAYER, KC_LCTL)
    ),

    /*
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
                 _______, KC_V
    ),

    /*
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
        KC_ESC,  _______, _______, TO(COMBO_LAYER),
        KC_TAB,  _______, _______, _______,
                 _______, _______
    ),

    /*
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
                 _______, _______
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │SEL│LOL│   │BLT│
     * ├───┼───┼───┼───┤
     * │RGB│   │   │KBC│
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │COM│   │
     *     └───┴───┘
     */
    [SELECTION_LAYER] = LAYOUT(
        TO(NAVIGATION_LAYER), TO(LOL_MAIN_LAYER), _______, TO(BLUETOOTH_LAYER),
        TO(RGB_LAYER),        _______,            _______, TO(KBCTRL_LAYER),
                              TO(COMBO_LAYER),     _______
    ),

    /*
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
        KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,
                 TO(COMBO_LAYER), _______
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │BT1│BT2│BT3│BT4│
     * ├───┼───┼───┼───┤
     * │BTC│   │BTP│BTN│
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │COM│   │
     *     └───┴───┘
     */
    [BLUETOOTH_LAYER] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,  // BT_SEL 0-3 (not available in QMK)
        KC_NO,   _______, KC_NO,   KC_NO,  // BT_CLR, BT_PRV, BT_NXT
                 TO(COMBO_LAYER), _______
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │BOO│   │   │STU│
     * ├───┼───┼───┼───┤
     * │RST│   │   │   │
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │COM│   │
     *     └───┴───┘
     */
    [KBCTRL_LAYER] = LAYOUT(
        QK_BOOT, _______, _______, KC_NO,  // studio_unlock not available
        QK_RBT,  _______, _______, _______,
                 TO(COMBO_LAYER), _______
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │PWR│BRI│SPI│EFF│
     * ├───┼───┼───┼───┤
     * │   │BRD│SPD│EFR│
     * └───┴───┴───┴───┘
     *     ┌───┬───┐
     *     │COM│   │
     *     └───┴───┘
     */
    [RGB_LAYER] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,  // RGB controls (not available in basic QMK)
        _______, KC_NO,   KC_NO,   KC_NO,
                 TO(COMBO_LAYER), _______
    ),

    /*
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
        _______, _______, _______, _______,
        _______, _______, _______, _______,
                 KC_SPC,  KC_BSPC
    )
};
