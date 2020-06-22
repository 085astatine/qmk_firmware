#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                   KC_LBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_EQL,                    KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT,                   KC_RCTL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
    KC_LGUI, KC_GRV,  KC_LALT,          KC_ESC,  LOWER,   KC_SPC,  KC_DEL,  KC_BSPC, KC_ENT,  RAISE,            KC_RSFT, KC_LEFT, KC_RGHT, KC_DOWN),
  [_LOWER] = LAYOUT(
    KC_GRV,  KC_MINS, KC_PLUS, KC_EQL,  KC_UNDS, KC_PERC, KC_UNDS,                   KC_LCBR, KC_GRV,  KC_TILD, KC_EXLM, KC_ASTR, KC_RPRN, KC_DEL,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PLUS,                   KC_RCBR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQUO,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,                   _______, KC_LPRN, KC_RPRN, KC_LT,   KC_GT,   KC_QUES, KC_PGUP,
    _______, KC_TILD, _______,          _______, _______, _______, _______, _______, _______, _______,          _______, KC_HOME, KC_END,  KC_PGDN),
  [_RAISE] = LAYOUT(
    KC_GRV,  KC_BSLS, KC_SLSH, KC_COMM, KC_DOT,  KC_PIPE, KC_UNDS,                   KC_TILD, KC_MINS, KC_UNDS, KC_HASH, KC_DLR,  KC_CIRC, KC_NO,
    _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_QUOT, KC_PLUS,                   KC_GRV , KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
    _______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_DQUO, _______,                   _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_NO,   KC_NO,
    _______, KC_TILD, _______,          _______, _______, _______, _______, _______, _______, _______,          _______, KC_NO,   KC_INS,  KC_PSCR),
  [_ADJUST] = LAYOUT(
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,                     RESET,   RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, KC_NO,   KC_NO,
    KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_NO,                     KC_NO,   BL_TOGG, BL_BRTG, BL_INC,  BL_DEC,  KC_NO,   KC_NO,
    KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,                     KC_NO,   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO)
    };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
