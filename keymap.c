#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FN 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; : |  ' " |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |  / ? | Fn   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Alt  | OS   | Sp/Lw| En/Rs| OS   | Alt  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSPC, \
   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   MO(_FN), \
   _______, _______, _______, KC_LALT, KC_LGUI, LT(_LOWER,KC_SPC), LT(_RAISE,KC_ENT), KC_RGUI,KC_RALT, _______, _______,   _______  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      |      |      |  - _ |  = + |  \ | |  ` ~ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      | R-Clk| L-Clk|      | Left | Down | Up   | Right|  [ { |  ] } |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Adjust|      |      | Alt  | OS   | Lower| IME  | OS   | Alt  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_ESC,  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,   KC_BSLS, KC_GRV,  \
  KC_LCTL, _______, _______, KC_BTN2, KC_BTN1, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_LBRC, KC_RBRC, \
  KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  MO(_ADJUST), _______,  _______, KC_LALT, KC_LGUI, KC_TRNS, LSFT(KC_CAPS),KC_RGUI, KC_RALT, _______,  _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | Alt  | OS   | IME  | Raise| OS   | Alt  |      |      |Adjust|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_ADJUST), \
  _______, _______, _______, KC_LALT, KC_LGUI, LSFT(KC_CAPS), KC_TRNS, KC_RGUI, KC_RALT, _______, _______, MO(_ADJUST)  \
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      | Home | PgUp | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      | End  | PgDn |      | Fn   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | Alt  | OS   |      |      | OS   | Alt  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_LCTL, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_DEL,  _______, \
  KC_LSFT, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, KC_TRNS, \
  _______, _______, _______, KC_LALT, KC_LGUI, _______, _______, KC_RGUI, KC_RALT, _______, _______, _______  \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust|      |      |      |      | Lower| Raise|      |      |      |      |Adjust|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_TRNS, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______, _______, _______, _______, KC_TRNS  \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
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
