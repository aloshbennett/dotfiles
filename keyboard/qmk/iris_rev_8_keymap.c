#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _NAV,
  _SYM,
  _GAME,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,           KC_H,    RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_LALT,          KC_CAPS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_RCTL, MO(_NAV),KC_SPC,                    KC_ENT,  MO(_SYM), KC_RGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILDE,  KC_F1,   KC_F2,    KC_F3,  KC_F4,  KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_ESC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  KC_HOME,   KC_UP, KC_END,  KC_PGUP,                           XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX,  KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN,                           XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,  XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX,C(KC_LEFT),XXXXXXX,C(KC_RIGHT),XXXXXXX,_______,       XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, XXXXXXX, XXXXXXX,                    KC_0,  XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //     ~
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //              ^        #        (        )                                                     =        |        \       %
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //              @        $        {        }                                                     *        +        -       ?
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //              !        &        [        ]                                                     ;        :        /       _
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILDE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            TG(_GAME), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_CIRC,  KC_HASH, KC_LPRN, KC_RPRN, XXXXXXX,                            XXXXXXX, KC_EQL,  KC_PIPE, KC_BSLS, KC_PERC, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_AT,   KC_DLR,  KC_LCBR, KC_RCBR,  XXXXXXX,                            XXXXXXX, KC_ASTR, KC_PLUS, KC_MINS, KC_QUES, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM,  KC_AMPR, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,  KC_P,    S(KC_P), KC_SLSH, KC_UNDS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, XXXXXXX, XXXXXXX,                    XXXXXXX,  XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
 ),


  [_GAME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILDE,  KC_F1,   KC_F2,    KC_F3,  KC_F4,  KC_F5,                             TG(_GAME),   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_ESC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  XXXXXXX,   KC_UP, XXXXXXX,  XXXXXXX,                           XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX,  KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,                           XXXXXXX, KC_4,    KC_5,     KC_6,    XXXXXXX,  XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,  KC_LALT,         XXXXXXX, KC_0,    KC_1,    KC_COMM, KC_DOT,   XXXXXXX, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_RCTL, XXXXXXX, XXXXXXX,                   XXXXXXX,  XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

