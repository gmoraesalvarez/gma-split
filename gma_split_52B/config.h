#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    qmkbuilder
#define PRODUCT         gma_split_52
#define DESCRIPTION     Keyboard

//#define MASTER_LEFT
#define SPLIT_HAND_PIN B12
#define	SPLIT_HAND_PIN_LOW_IS_LEFT
//#define SPLIT_USB_DETECT
/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6



/* key matrix pins */
//#define MATRIX_COL_PINS { B12, B13, B14, B15, A8, A15, B4, B5, B6, B7, B8, B9 }
#define MATRIX_COL_PINS { B9, B8, B7, B6, B5, B4 }
#define MATRIX_ROW_PINS { B10, B1, B0, A7, A6 }
//#define MATRIX_COL_PINS_RIGHT { B9, B8, B5, B4, B3, A15 }
//#define MATRIX_ROW_PINS_RIGHT { B10, B1, B0, A7, A6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TOGGLE 2
/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 6

//#define SOFT_SERIAL_PIN A9
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN A2     // USART TX pin
#define SERIAL_USART_RX_PIN A3     // USART RX pin
#define SELECT_SOFT_SERIAL_SPEED 1 // or 0, 2, 3, 4, 5
#define SERIAL_USART_DRIVER SD2    // USART driver of TX and RX pin. default: SD1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_RX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
//#define SERIAL_USART_TIMEOUT 20    // USART driver timeout. default 20


