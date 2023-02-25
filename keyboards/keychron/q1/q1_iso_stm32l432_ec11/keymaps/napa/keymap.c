/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <print.h>
#include "features/color_layer.h"

// clang-format off

enum layers{
  WIN_BASE,
  WIN_FN1,
  WIN_FN2,
  GAME_BASE,
  GAME_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER
};

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

// Unicode
enum unicode_names {
    AE,
    AE_C,
    OE,
    OE_C,
    AO,
    AO_C
};

const uint32_t PROGMEM unicode_map[] = {
    [AE] = 0x00E4,
    [AE_C] = 0x00C4,
    [OE] = 0x00F6,
    [OE_C] = 0x00D6,
    [AO] = 0x00E5,
    [AO_C] = 0x00C5,
};


// Home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };
// Fillers to make layering more clear
#define ___(x) KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_iso_83(
        KC_ESC,         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MPLY,
        KC_GRV,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        LCTL_T(KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,        KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        MO(WIN_FN1),    KC_LALT,  MO(WIN_FN2),                            KC_SPC,                              MO(WIN_FN1), KC_LGUI, MO(WIN_FN2), KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN1] = LAYOUT_iso_83(
         _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    KC_PSCR,   QK_RBT,            QK_BOOT,
         _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,       _______,  _______,  _______,  _______,  _______,  _______,     KC_7,     KC_8,     KC_9,  _______, XP(AO, AO_C), _______,                     _______,
         _______,       _______,  _______,  _______,  _______,  _______,  _______,     KC_4,     KC_5,     KC_6, XP(OE, OE_C), XP(AE, AE_C), _______, _______,        _______,
         _______,       _______,  _______,  _______,  _______,  _______,  _______,     KC_0,     KC_1,     KC_2,     KC_3, KC_KP_DOT,             _______,  _______,
         _______,       _______,  _______,                                CAPSWRD,                                _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_FN2] = LAYOUT_iso_83(
         _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    KC_PSCR,   QK_RBT,            QK_BOOT,
         _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,       _______,  _______,  _______,  _______,  _______,  _______,  KC_PGDN,  KC_PGUP,     KC_O,  _______, XP(AO, AO_C), _______,                     _______,
         _______,       _______,  KC_DEL,   KC_BSPC,   KC_ENT,  _______,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT, XP(OE, OE_C), XP(AE, AE_C), _______, _______,        _______,
         _______,       _______,  _______,  _______,  _______,  _______,  _______,     KC_N,     KC_M,  KC_HOME,   KC_END,  KC_SLSH,              _______,  _______,
         _______,       _______,  _______,                                CAPSWRD,                                _______,  _______,    _______,  _______,  _______,  _______),

    [GAME_BASE] = LAYOUT_iso_83(
         KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MPLY,
         KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_GRV,   KC_BSPC,            KC_PGUP,
         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
         KC_RCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
         KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,   KC_DOT,  KC_SLSH,              KC_RSFT,  KC_UP,
         KC_LCTL,  KC_LALT,  KC_RSFT,                                KC_SPC,                            MO(GAME_FN), KC_LGUI, MO(GAME_FN), KC_LEFT,  KC_DOWN,  KC_RGHT),

    [GAME_FN] = LAYOUT_iso_83(
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    KC_PSCR,   QK_RBT,            _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
         _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______)
};

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;   // Process all other keycodes normally
    }
}

void keyboard_post_init_user() {
    // debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;

    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(0, 0, 128);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

#ifdef DIP_SWITCH_ENABLE

// dip_switch_update_user() is forced in boot sequence after keyboard_post_init_user(),
// which will guarantee that it is set properly after reset
bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        if (active) {
            default_layer_set(1UL << GAME_BASE);
            combo_disable();
            color_layer_set(HS_GAME);
        } else {
            default_layer_set(1UL << WIN_BASE);
            combo_enable();
            color_layer_set(HS_WIN);
        }
        return false;
    }
    return true;
}

#endif // DIP_SWITCH_ENABLE

// LEADER KEY
LEADER_EXTERNS();
#define SEQ_START_ONE_KEY(key) if (leader_sequence[0] == (key))

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;

        SEQ_ONE_KEY(KC_LEAD) {
            print("Double leader\n");
        }

        SEQ_START_ONE_KEY(KC_Q) {
            switch (leader_sequence[1])
            {
            case KC_Q:
                break;

            default:
                break;
            }
        }

        leader_end();
    }
}

void leader_start(void) {
    color_layer_set(HS_LEADER);
}

void leader_end() {
    color_layer_restore();
}

// Combos
enum combos {
  DF_BSPC,
  SD_DEL,
  JK_ENTER,
  ESCDEL_EECLR,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM escdel_combo[] = {KC_ESC, KC_DEL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DF_BSPC] = COMBO(df_combo, KC_BSPC),
  [SD_DEL] = COMBO(sd_combo, KC_DEL),
  [JK_ENTER] = COMBO(jk_combo, KC_ENT),
  [ESCDEL_EECLR] = COMBO(escdel_combo, EE_CLR),
};

void shutdown_user() {
    print("User shutdown");
    color_layer_set(HS_SHUTDOWN);
}
