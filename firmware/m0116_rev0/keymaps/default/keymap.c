/* Copyright 2021 djvs
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    /*[_BASE] = LAYOUT(
      KC_ESC     ,KC_F2      ,KC_F3      ,KC_F4      ,KC_F5      ,KC_F6      ,KC_F7          ,KC_F8      ,KC_F9              ,KC_F11     ,\
      KC_GRAVE   ,KC_2       ,KC_4       ,KC_6       ,KC_8       ,KC_0       ,KC_BACKSLASH   ,KC_NO      ,KC_AUDIO_VOL_DOWN  ,KC_PAUSE ,\
      KC_TAB     ,KC_W       ,KC_R       ,KC_Y       ,KC_I       ,KC_P       ,KC_RBRC        ,KC_NO      ,KC_PGUP            ,KC_WWW_HOME ,\
      KC_LCTL    ,KC_A       ,KC_D       ,KC_G       ,KC_J       ,KC_L       ,KC_QUOTE       ,KC_NO      ,KC_HOME            ,KC_END ,\
      KC_NO      ,KC_Z       ,KC_C       ,KC_B       ,KC_M       ,KC_DOT     ,KC_ENTER       ,KC_HOME    ,KC_LEFT            ,KC_RIGHT ,\
      KC_LSFT    ,KC_LGUI    ,KC_LALT    ,KC_SPACE   ,KC_NO      ,KC_SLASH   ,KC_DELETE      ,KC_INSERT  ,KC_DOWN            ,KC_KP_ENTER    ,\
      KC_CAPS    ,KC_X       ,KC_V       ,KC_N       ,KC_COMMA   ,KC_SEMICOLON,KC_MY_COMPUTER,KC_PGDN    ,KC_UP              ,KC_SCROLL_LOCK ,\
      KC_Q       ,KC_S       ,KC_F       ,KC_H       ,KC_K       ,KC_LBRC    ,KC_NO          ,KC_PGUP    ,KC_PGDN            ,KC_WWW_FAVORITES ,\
      KC_1       ,KC_E       ,KC_T       ,KC_U       ,KC_O       ,KC_MINUS   ,KC_ENTER       ,KC_NO      ,KC_AUDIO_VOL_UP    ,MU_TOGG ,\
      KC_F1      ,KC_3       ,KC_5       ,KC_7       ,KC_9       ,KC_EQUAL   ,KC_BACKSPACE   ,KC_NO      ,KC_F10             ,KC_F12 \
    ) ,*/
    [_BASE] = LAYOUT(
        KC_ESC,    KC_1,     KC_2,    KC_3,    KC_4,     KC_MY_COMPUTER, KC_6,        KC_7,             KC_8,     KC_9,    KC_0,         KC_MINUS,  KC_EQUAL, KC_BACKSPACE, KC_NUM_LOCK, KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK, \
        KC_TAB,    KC_Q,     KC_W,    KC_E,    KC_R,     KC_5,           KC_Y,        KC_U,             KC_I,     KC_O,    KC_P,         KC_LBRC,   KC_RBRC,  KC_BACKSLASH, KC_KP_7,     KC_KP_8,     KC_KP_9,     KC_KP_PLUS, \
        KC_LCTL,   KC_A,     KC_S,    KC_D,    KC_F,     KC_T,           KC_H,        KC_J,             KC_K,     KC_L,    KC_SEMICOLON, KC_QUOTE,  KC_ENTER, KC_NO,        KC_KP_4,     KC_KP_5,     KC_KP_6,     KC_KP_MINUS, \
        KC_LSFT,   KC_Z,     KC_X,    KC_C,    KC_V,     KC_G,           KC_N,        KC_M,             KC_COMMA, KC_DOT,  KC_SLASH,     KC_RSFT,   KC_UP,    KC_NO,        KC_KP_1,     KC_KP_2,     KC_KP_3,     KC_KP_ENTER, \
        KC_F1,     KC_LCTL,  KC_LGUI, KC_LALT, KC_SPACE, KC_B,           KC_WWW_HOME, KC_WWW_FAVORITES, KC_RALT,  KC_RGUI, KC_RCTL,      KC_PAUSE,  KC_UP,    MU_TOGG,      KC_KP_EQUAL, KC_KP_0,     KC_KP_DOT,   KC_KP_ENTER \
    ) /*,
    [_FN] = LAYOUT(
        QMKBEST, QMKURL,  _______,
            RESET,    XXXXXXX
    ) */
};

float music_scale[][2]     = SONG(E__NOTE(_GS2));

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    PLAY_SONG(music_scale);
    switch (keycode) {
    }
    return true;
}

const rgblight_segment_t PROGMEM my_capslock_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_PURPLE});

const rgblight_segment_t PROGMEM my_numlock_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({2, 1, HSV_BLUE});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] =
    RGBLIGHT_LAYERS_LIST(my_capslock_layer, my_numlock_layer);

void keyboard_post_init_user(void) { rgblight_layers = my_rgb_layers; };

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  rgblight_set_layer_state(1, led_state.num_lock);
  return true;
};
