#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _GAME_1 4
#define _GAME_2 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |ALT(Q)|   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |ALT(P)|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |CTL(A)|   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |CTL(;)|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |SFT(Z)|   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |SFT(/)|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |  OS  | LOWER|      |    |      | RAISE|  Tab |
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT_split_3x5_3(
  LALT_T(KC_Q),    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    RALT_T(KC_P),
  LCTL_T(KC_A),    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    RCTL_T(KC_SCLN),
  LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                        KC_LGUI, MO(_LOWER), KC_SPC,        KC_BSPC, MO(_RAISE), KC_TAB
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc | Home |  Up  | End  | P Up |           |  Ins |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ~  | Left | Down | Right|P Down|           |  Del |      |      |   |  |   "  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |  OS  |      |      |    |      |ADJUST|  Tab |
 *                  `-------------| Space|    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_INS,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  KC_TILD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_DEL,  _______, _______, KC_PIPE,  KC_DQT,
                    KC_LGUI, _______, KC_SPC,       KC_ENT,  MO(_ADJUST), KC_TAB
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Mse3 | Mse1 | MseUp| Mse2 |Whl Up|           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  `   |MseLft|MseDwn|MseRgt|WhlDwn|           |MseAc0|MseAc1|MseAc2|   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |  OS  |ADJUST|      |    |      |      |  Tab |
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  KC_GRV,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,      KC_ACL0, KC_ACL1, KC_ACL2, KC_BSLS,  KC_QUOT,
                  KC_LGUI, MO(_ADJUST), KC_SPC,     KC_BSPC, _______, KC_TAB
),

/* Adjust
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      | Game1|           | VolUp|VolDwn|BrtDwn| BrtUp|  F11 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           | Mute | Prev | Play | Next |  F12 |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT_split_3x5_3(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  _______, _______, _______, _______, TO(_GAME_1),  KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, KC_F11,
  RESET,   _______, _______, _______, _______,      KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT,  KC_F12,
                    _______, _______, _______,      _______, _______, _______
),

/* Game 1
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | LSft |   Z  |   X  |   C  |   V  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Game2| LCTL |      |    |      |QWERTY| LAlt |
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_GAME_1] =  LAYOUT_split_3x5_3(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,         KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,         KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,
                MO(_GAME_2), KC_LCTL, KC_SPC,       KC_BSPC, TO(_QWERTY), KC_LALT
),

/* Game 2
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | LSft |   <  |   >  |   ?  | Caps |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LCTL |      |    |      |      |      |
 *                  `-------------| Space|    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_GAME_2] =  LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        _______, _______, _______, _______, _______,
  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,        _______, _______, _______, _______, _______,
  KC_LSFT, KC_LT,   KC_GT,   KC_QUES, KC_CAPS,     _______, _______, _______, _______, _______,
                    _______, KC_LCTL, KC_SPC,      _______, _______, _______
)
};

void matrix_init_user(void) {
  set_single_persistent_default_layer(_QWERTY);
};