/*
 Copyright 2021 0xCB - Conor Burns

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
#include QMK_KEYBOARD_H
// clang-format off
enum my_keycodes {
    WPM = SAFE_RANGE,
};
enum layer_names {
  _HOME,
  _GAME,
  _FN3,
  _FN4
};
// combo list
enum combos {
  SD_LBR,
  DF_RBR,
  XC_GRV,
  CV_TLD,
  UI_DSH,
  IO_EQL,
  JK_COL,
  KL_QOT,
  CD_BSL,
  DS_FSL
};
// combo keys
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_RSPC, COMBO_END};
// combo result
combo_t key_combos[COMBO_COUNT] = {
  [SD_LBR] = COMBO(sd_combo, KC_LBRC),
  [DF_RBR] = COMBO(df_combo, KC_RBRC),
  [XC_GRV] = COMBO(xc_combo, KC_GRV),
  [CV_TLD] = COMBO(cv_combo, KC_TILD),
  [UI_DSH] = COMBO(ui_combo, KC_MINS),
  [IO_EQL] = COMBO(io_combo, KC_EQL),
  [JK_COL] = COMBO(jk_combo, KC_SCLN),
  [KL_QOT] = COMBO(kl_combo, KC_QUOTE),
  [CD_BSL] = COMBO(cd_combo, KC_BSLS),
  [DS_FSL] = COMBO(ds_combo, KC_SLSH)
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_HOME] = LAYOUT_all(
                                                                                                       KC_MPLY,
    KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT,
    KC_LSPO,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSPC,
    KC_LCTL, KC_LALT, KC_LGUI, LT(_FN4, KC_BSPC),TG(_GAME),     LT(_FN3, KC_SPC),    KC_RGUI, KC_LALT, KC_RCTL
),
[_GAME] = LAYOUT_all(
                                                                                                       KC_MPLY,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,
    KC_TAB,  KC_LALT, KC_LGUI, KC_SPC,           TG(_GAME),        LT(_FN3,KC_SPC),  KC_RGUI, KC_LALT, KC_RCTL
),
[_FN3] = LAYOUT_all(
                                                                                                       RESET,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,                   _______, _______, _______, _______
),
[_FN4] = LAYOUT_all(
                                                                                                       _______,
    WPM,     KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MSTP, KC_PGUP, KC_UP,   KC_PGDN, _______, _______,
    _______, _______, KC_BRID, KC_BRIU, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,          KC_END,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,                   _______, _______, _______, _______
),
};
// clang-format on
/* WPM toggle key bongocat hehe */
bool wpm = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WPM:
        if (record->event.pressed) {
            wpm = !wpm;
        }
        return false;
    default:
        return true;
  }
}
/*layer switcher */
//layer_state_t layer_state_set_user(layer_state_t state) {
//    state = update_tri_layer_state(state, _FN2, _FN3, _FN4);
//    return state;
//}
/* rotary encoder (MX12) - add different functions for layers here */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}
#endif

/* oled stuff :) */
#ifdef OLED_ENABLE
#define IDLE_FRAMES 5
#define IDLE_SPEED 20 // below this wpm value your animation will idle
#define TAP_FRAMES 2
#define TAP_SPEED 40 // above this wpm value typing animation to trigger
#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#define ANIM_SIZE 636 // number of bytes in array

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
uint8_t current_tap_frame = 0;

uint16_t startup_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    startup_timer = timer_read();
    return rotation;
}
static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  8,  0,192,194,192,192, 60, 60, 44, 60,188, 60, 60, 60, 60, 44, 61, 60,192,192,192,208,  1,  0,252,252,180,252, 60, 60, 44, 60,252,253,252,252, 60, 60, 44, 60,244,220,252,252,  0,  0, 16,  0,  0,  0,192,192, 65,192, 60, 60, 52, 60,192,193,192,192, 16,  0,  0,144,  4,  0,252,125,244, 60, 60, 60, 60, 61,252,252,244,252, 60, 60, 60, 61,248,108,252,  0,  0, 61, 60,188, 60, 52,252,252,220,252, 61, 60, 60, 52,  0,  0,192,210, 64,192, 60, 60, 44, 61, 60, 60, 60, 61, 52, 60, 60, 60,192,192, 64,196,  0,  4,  0,
        0, 16,  0, 61, 63, 55, 63,192, 64,192,196,192,192,192,200,192,196,192,192,  3,  3,  2, 11,  0,  0, 35,  3,  3,  3,  0, 64,  2,  0,255,255,253,247,  0,  0,  0, 32,  1,  0,  1, 65,  8,  0,189,244,252,236,  3,130,  3,  1,  0, 68,  0,  0,  3, 34,131,  3,252,252,236,252,  0, 32, 17,  1,  1,  0,  0, 32,  0,  2,255,255,127,247,  0,  1,  0,  8,  1,  1,  1,  0,  0,  0, 16,  0, 64,  0,255,191,255,251,  0,129,  0,  2, 32,  0,255,255,239,255,  0,  0,  2,  0,  0,  0,  8, 64,  0,  1,  0,  0,  3, 35,  3,  3,  0,  8,  0,
        1, 16,  0,192, 64,194,192,  3, 67,  3,  3,  9,  3,  3,  3,  3,  2, 83,  3,252,252,188,244,  0,  2, 32,  0,  0,  2,  0,144,  0,  0,255,255,237,255,  0, 16,  0,  0,  0, 64,  2,  0,128,  0,255,123,255,255, 60, 52, 60, 60, 60, 60, 60, 60, 44, 60, 56, 60,239,255,126,255,  0,  2, 32,  0,  0, 34,  0,  0, 16,  0,255,255,255,223,  0,  0,  4,  0,  0,  0, 33,  0,  0, 17,  0,  0,  0,  0,255,255,239,255,  0,128,  0,  0, 72,  0,255,253,247,255,  0,  0,  1,  0,144,  0,  4,  0, 32,  0,  0,  2,192,192,192,200,  0, 16,  0,
        64,  4,  0,  3,  7,  3,  3, 60, 60, 52,188, 60, 61, 60, 60, 60, 60, 44, 60, 67,  3,  3,  3,  0,  0, 64,  0,  0,  4,  0,  0, 16,  0, 47, 63, 62, 63,  0,  0,132,  0,  0,  0,  0,128,  8,  0,255,255,111,127,  0,  0,  0,  2,128,  0,  0,  0, 64,  4,  0,128,127,127,107,127,  0, 32,  0,  0,  0, 66,  0,  0,  0,136, 55, 63, 61, 63,  0,  0,  0,  2,  0, 64,  0,136,  0,  0, 60, 44,189, 60, 63, 63, 63, 59, 60, 60,172, 60,  0, 64,  3,  2,  3,131, 60, 44, 60, 60, 60, 60,188, 60, 56, 44, 60, 60,  3,  3,131,  2,  0, 32,  2,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}
/* Shows the name of the current layer and locks for the host (CAPS etc.) */
static void render_layer(void) {
    led_t led_state = host_keyboard_led_state();
    // clang-format off
    static const char PROGMEM logo[][3][7] = {
        {{0x97, 0x98, 0x99, 0x9A, 0}, {0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0}, {0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0}}, /* l      num      CB */
        {{0xB7, 0xB8, 0xB9, 0xBA, 0}, {0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0}, {0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0}}, /* 1      num      CB */
        {{0xD7, 0xD8, 0xD9, 0xDA, 0}, {0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0}, {0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0}}, /* 1      cap      CB */
        {{0xF7, 0xF8, 0xF9, 0xFA, 0}, {0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0}, {0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0}}, /* l      cap      CB */
        {{0xB7, 0xC0, 0xC1, 0xBA, 0}, {0xB7, 0xC2, 0xC3, 0xBA, 0},             {0xB7, 0xC4, 0xC5, 0xBA, 0}},       /* 2       3       4  */
        {{0xD7, 0xE0, 0xE1, 0xDA, 0}, {0xD7, 0xE2, 0xE3, 0xDA, 0},             {0xD7, 0xE4, 0xE5, 0xDA, 0}},       /* 2       3       4  */
    };
    // clang-format on
    oled_set_cursor(0, 0);
    oled_write_P(logo[0][0], false);
    oled_set_cursor(0, 3);
    oled_write_P(logo[3][0], false);
    switch (get_highest_layer(layer_state)) {
        case _HOME:
            oled_set_cursor(0, 1);
            oled_write_P(logo[1][0], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[2][0], false);
            break;
        case _GAME:
            oled_set_cursor(0, 1);
            oled_write_P(logo[4][0], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[5][0], false);
            break;
        case _FN3:
            oled_set_cursor(0, 1);
            oled_write_P(logo[4][1], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[5][1], false);
            break;
        case _FN4:
            oled_set_cursor(0, 1);
            oled_write_P(logo[4][2], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[5][2], false);
            break;
        default:
            oled_set_cursor(0, 1);
            oled_write_P(PSTR("    "), false);
            oled_set_cursor(0, 2);
            oled_write_P(PSTR("    "), false);
    }
    oled_set_cursor(8, 0);
    oled_write_P(led_state.num_lock ? logo[0][1] : PSTR("      "), false);
    oled_set_cursor(8, 1);
    oled_write_P(led_state.num_lock ? logo[1][1] : PSTR("      "), false);
    oled_set_cursor(8, 2);
    oled_write_P(led_state.caps_lock ? logo[2][1] : PSTR("      "), false);
    oled_set_cursor(8, 3);
    oled_write_P(led_state.caps_lock ? logo[3][1] : PSTR("      "), false);

    oled_set_cursor(16, 0);
    oled_write_P(logo[0][2], false);
    oled_set_cursor(16, 1);
    oled_write_P(logo[1][2], false);
    oled_set_cursor(16, 2);
    oled_write_P(logo[2][2], false);
    oled_set_cursor(16, 3);
    oled_write_P(logo[3][2], false);

    /* Fill empty space to clear animation */
    oled_set_cursor(4, 0);
    oled_write_P(PSTR("    "), false);
    oled_set_cursor(4, 1);
    oled_write_P(PSTR("    "), false);
    oled_set_cursor(4, 2);
    oled_write_P(PSTR("    "), false);
    oled_set_cursor(4, 3);
    oled_write_P(PSTR("    "), false);

    oled_set_cursor(14, 0);
    oled_write_P(PSTR("  "), false);
    oled_set_cursor(14, 1);
    oled_write_P(PSTR("  "), false);
    oled_set_cursor(14, 2);
    oled_write_P(PSTR("  "), false);
    oled_set_cursor(14, 3);
    oled_write_P(PSTR("  "), false);
}

static void render_cat(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc1, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x80, 0x80, 0x40, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x83, 0x83, 0x40, 0x40, 0x40, 0x40, 0x20, 0x21, 0x21, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x30, 0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x86, 0x98, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x41, 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc1, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x86, 0x86, 0x40, 0x40, 0x40, 0x40, 0x21, 0x22, 0x22, 0x20, 0x11, 0x11, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x30, 0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x86, 0x98, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x41, 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x82, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x60, 0x60, 0x00, 0x01, 0x01, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x86, 0x86, 0x40, 0x40, 0x40, 0x40, 0x21, 0x22, 0x22, 0x20, 0x11, 0x11, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x30, 0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x86, 0x98, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x41, 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x34, 0xc4, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x80, 0x80, 0x40, 0x00, 0x00, 0x30, 0x30, 0x00, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x83, 0x83, 0x40, 0x40, 0x40, 0x40, 0x20, 0x21, 0x21, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x30, 0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x86, 0x98, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x41, 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0d, 0x31, 0xc1, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x80, 0x80, 0x40, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x83, 0x83, 0x40, 0x40, 0x40, 0x40, 0x20, 0x21, 0x21, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x30, 0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x86, 0x98, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x41, 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
    static const char PROGMEM prep[][ANIM_SIZE] = {
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc1, 0x01, 0x01, 0x02, 0x02, 0x04, 0x84, 0x44, 0x44, 0x42, 0x82, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x80, 0x80, 0x40, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x64, 0x18, 0x04, 0x12, 0xc2, 0xca, 0x24, 0x88, 0xf0, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x06, 0x01, 0x00, 0x00, 0x0c, 0x03, 0x00, 0x02, 0x18, 0x19, 0x00, 0x05, 0xfe, 0x80, 0x83, 0x83, 0x40, 0x40, 0x40, 0x40, 0x20, 0x21, 0x21, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc1, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x80, 0x80, 0x40, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x64, 0x18, 0x04, 0x12, 0xc2, 0xca, 0x24, 0x88, 0xf0, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x83, 0x83, 0x40, 0x40, 0x40, 0x40, 0x20, 0x21, 0x21, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x41, 0x42, 0x24, 0x98, 0xc0, 0x88, 0x88, 0x8c, 0x9c, 0x1c, 0x1e, 0x0e, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc1, 0x01, 0x01, 0x02, 0x02, 0x04, 0x84, 0x44, 0x44, 0x42, 0x82, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x80, 0x80, 0x40, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x06, 0x01, 0x00, 0x00, 0x0c, 0x03, 0x00, 0x02, 0x18, 0x19, 0x00, 0x05, 0xfe, 0x80, 0x83, 0x83, 0x40, 0x40, 0x40, 0x40, 0x20, 0x21, 0x21, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x30, 0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x86, 0x98, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0f, 0x0f, 0x07, 0x03, 0x03, 0x61, 0xf0, 0xf8, 0xfc, 0x60, 0x01, 0x01, 0x01, 0x3c, 0x78, 0xf8, 0xf0, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    };

    void animation_phase(void) {
        if (get_current_wpm() <= IDLE_SPEED) {
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
        }
        if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED) {
            oled_write_raw_P(prep[0], ANIM_SIZE);
        }
        if (get_current_wpm() >= TAP_SPEED) {
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
        }
    }
    if (get_current_wpm() != 000) {
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
    }
}

bool oled_task_user(void) {
    static bool finished_timer = false;
    if (!finished_timer && (timer_elapsed(startup_timer) < 3000)) {
        render_logo();
    } else {
        if (!finished_timer) {
            oled_clear();
            finished_timer = true;
        }
        if (wpm) {
            render_cat();
            oled_set_cursor(0, 0);
            char string[10];
            uint16_t m = get_current_wpm();
            string[3] = '\0';
            string[2] = '0' + m % 10;
            string[1] = ( m /= 10) % 10 ? '0' + (m) % 10 : (m / 10) % 10 ? '0' : ' ';
            string[0] =  m / 10 ? '0' + m / 10 : ' ';
            oled_write_P(PSTR("WPM:"), false);
            oled_write(string, false);
        } else {
            render_layer();
        }
    }
    return false;
}
#endif

/* Resets via on eep reset - thank you drashna! */
void eeconfig_init_kb(void) {
    via_eeprom_set_valid(false);
    via_init();
    eeconfig_init_user();
}
