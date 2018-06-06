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
#define _HARDWARETEST 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN,
  HARDWARETEST,
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
 * |      |      | Alt  | OS   | Lower| Space| Enter| Raise| OS   | Alt  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSPC, \
   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   FN,      \
   HARDWARETEST, _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_RGUI, KC_RALT, _______,   RESET  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      |      |      |  - _ |  = + |  \ | |  ` ~ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      | L-Clk| R-Clk|      | Left | Down | Up   | Right|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Adjust|      | Alt  | OS   |      |      |      | IME  | OS   | Alt  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_ESC,  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,   KC_BSLS, KC_TILD, \
  KC_LCTL, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______, _______, \
  KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  ADJUST,  _______, KC_LALT, KC_LGUI, _______, _______, _______, KC_LANG5,KC_RGUI, KC_RALT,  _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      |      |      |  [ { |  ] } |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Alt  | OS   | IME  |      |      |      | OS   | Alt  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, \
  KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, \
  KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_LALT, KC_LGUI, KC_LANG5,_______, _______, _______, KC_RGUI, KC_RALT, _______, _______  \
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      | Home | PgUp | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      | End  | PgDn |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Alt  | OS   |      |      |      |      | OS   | Alt  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_LCTL, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_DEL,  KC_RBRC, \
  KC_LSFT, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, _______, \
  _______, _______, KC_LALT, KC_LGUI, _______, _______, _______, _______, KC_RGUI, KC_RALT, _______, _______  \
),

/* HardwareTest
 * ,-----------------------------------------------------------------------------------.
 * | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | 1    | 2    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | 1    | 2    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | 1    | 2    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | 1    | 2    |
 * `-----------------------------------------------------------------------------------'
 */
[_HARDWARETEST] = LAYOUT_ortho_4x12( \
  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_1,  KC_2, \
  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_1,  KC_2, \
  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_1,  KC_2, \
  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_1,  KC_2  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
