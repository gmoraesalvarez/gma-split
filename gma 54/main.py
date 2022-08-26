import board

from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.scanners import DiodeOrientation
wrstpfw2bdg

keyboard = KMKKeyboard()

from kmk.modules.modtap import ModTap
modtap = ModTap()
# optional: set a custom tap timeout in ms
modtap.tap_time = 200
keyboard.modules.append(modtap)

from kmk.modules.layers import Layers
keyboard.modules.append(Layers())

keyboard.row_pins = (board.GP0, board.GP1, board.GP5, board.GP3, board.GP4,)
keyboard.col_pins = (board.GP9, board.GP10, board.GP11, board.GP12, board.GP13, board.GP14, board.GP8, board.GP16, board.GP17, board.GP18, board.GP19, board.GP20)
keyboard.diode_orientation = DiodeOrientation.COL2ROW

# Cleaner key names
_______ = KC.TRNS
XXXXXXX = KC.NO

#LOWER = KC.MO(1)
#RAISE = KC.MO(2)

keyboard.keymap = [
    [  #0
        KC.ESC,  KC.N1,   KC.N2,   KC.N3,   KC.N4,   KC.N5,   KC.N6,   KC.N7,   KC.N8,   KC.N9,   KC.N0,   KC.BSPC,
        KC.LT(1, KC.TAB, prefer_hold=True),  KC.Q,    KC.W,    KC.E,    KC.R,    KC.T,    KC.Y,    KC.U,    KC.I,    KC.O,    KC.P,    KC.EQL,
        KC.MT(KC.QUOT, KC.LSFT),  KC.A,    KC.S,    KC.D,    KC.F,    KC.G,    KC.H,    KC.J,    KC.K,    KC.L,    KC.SCLN, KC.MT(KC.GRV, KC.RSFT),
        KC.MT(KC.CAPS, KC.LCTRL), KC.Z,    KC.X,    KC.C,    KC.V,    KC.B,    KC.N,    KC.M,    KC.COMM, KC.DOT,  KC.SLSH, KC.ENT,
        XXXXXXX, XXXXXXX, XXXXXXX, KC.LALT, KC.TT(2), KC.SPC,  KC.MT(KC.SPC, KC.LGUI),  KC.MT(KC.MINS, KC.RALT),   KC.DEL, XXXXXXX, XXXXXXX, XXXXXXX,
    ],
    [  #1
        KC.F12,  KC.F1,   KC.F2,   KC.F3,   KC.F4,   KC.F5,   KC.F6,   KC.F7,   KC.F8,   KC.F9,   KC.F10,  KC.F11,
        _______, KC.LCTRL, KC.LALT, KC.DEL, KC.BSPC, _______, _______, _______, _______, _______, KC.PGUP, KC.PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC.HOME, KC.UP, KC.END,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC.LEFT, KC.DOWN, KC.RGHT,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,
    ],
    [  #2
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC.VOLD, KC.VOLU, _______, _______, _______, _______, KC.N4, KC.N5, KC.N6, _______, _______,
        _______, KC.PGUP, KC.LEFT, KC.RGHT, KC.UP, _______, _______, KC.N1, KC.N2, KC.N3, _______, _______,
        _______, KC.PGDN, KC.HOME, KC.END, KC.DOWN, _______, _______, KC.N0, _______, _______, KC.BSLS, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,
    ]
]

if __name__ == '__main__':
    keyboard.go()
