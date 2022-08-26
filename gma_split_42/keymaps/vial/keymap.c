#include "gma_split_42.h"
//#include QMK_KEYBOARD_H

enum layers {
  NORMAL_LAYER = 0,
  SECOND_LAYER,
  THIRD_LAYER,
  FOURTH_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[NORMAL_LAYER] = LAYOUT( 
		LT(2,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		LSFT_T(KC_QUOT), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_GRV, 
		LCTL_T(KC_ESC), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, 
		KC_NO, KC_NO, KC_NO, KC_LALT, TT(1), KC_SPC, RGUI_T(KC_SPC), RALT_T(KC_MINS), KC_DEL, KC_NO, KC_NO, KC_NO),
	[SECOND_LAYER] = LAYOUT(
		KC_TRNS, KC_VOLD, KC_VOLU, KC_LPRN, KC_RPRN, KC_AT, KC_7, KC_8, KC_9, KC_ASTR, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_PGUP, KC_LEFT, KC_RGHT, KC_UP, KC_LBRC, KC_4, KC_5, KC_6, KC_PLUS, KC_TRNS, KC_EQL, 
		KC_TRNS, KC_PGDN, KC_HOME, KC_END, KC_DOWN, KC_RBRC, KC_1, KC_2, KC_3, KC_TRNS, KC_BSLS, KC_TRNS,  
		KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_NO, KC_NO, KC_NO),
	[THIRD_LAYER] = LAYOUT(
		KC_TRNS, LCTL_T(KC_ESC), LALT_T(KC_DEL), KC_BSPC, KC_F17, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_HOME, KC_UP, KC_END, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_LEFT, KC_DOWN, KC_RGHT, 
		KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO),
	[FOURTH_LAYER] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO)
};


/*void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

} */
