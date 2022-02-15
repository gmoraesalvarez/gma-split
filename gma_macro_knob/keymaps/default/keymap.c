/*
Copyright 2021 CapsUnlocked

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
//#include QMK_KEYBOARD_H
#include "cu7.h"
enum layers {
  NORMAL_LAYER = 0,
  SECOND_LAYER,
  THIRD_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [NORMAL_LAYER] = LAYOUT_knob(
    KC_PLUS,  KC_MINUS, TT(2), KC_NO,
    KC_I,     KC_O,     KC_T,  KC_NO,
    LCTL_T(KC_SPACE), KC_C,     KC_V,   TT(1)),
  [SECOND_LAYER] = LAYOUT_knob(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [THIRD_LAYER] = LAYOUT_knob(
    KC_Q, KC_W, KC_TRNS, KC_NO,
    KC_A, KC_S, KC_D, KC_NO,
    LCTL_T(KC_DEL), KC_SFTENT, RALT_T(KC_SPACE), KC_TRNS
  )
};

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(1)){
    if (clockwise) {
      tap_code_delay(KC_J, 10);
    }
    else {
      tap_code_delay(KC_L, 10);
    }
  }
  else {
    if (clockwise) {
      tap_code_delay(KC_RIGHT, 10);
    }
    else {
      tap_code_delay(KC_LEFT, 10);
    }
  }
  return true;
}
