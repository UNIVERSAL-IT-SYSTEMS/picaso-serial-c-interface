#ifndef __L4D_PSE2_H__
#define __L4D_PSE2_H__ 1

#if !defined(L4D_PSE2_PUTCHAR) || !defined(L4D_PSE2_GETCHAR)
#  error "This library requires definitions for L4D_PSE2_PUTCHAR and L4D_PSE2_GETCHAR. Read README.md for details."
#else

#include <inttypes.h>
#include "4d_pse2_helpers.h"

// helpers
#ifndef L4D_PSE2_PREFIX
#  define L4D_PSE2_PREFIX l4d_pse2_
#endif
#define __(name) __CONCAT(L4D_PSE2_PREFIX, name)

// Types

typedef int16_t __(status_t);
typedef struct {
	__(status_t) status;
	uint16_t value;
} __(result_t);


// color format: R4 R3 R2 R1 R0  G5 G4 G3 G2 G1 G0  B4 B3 B2 B1 B0
typedef uint16_t __(colour_t);
#define L4D_PSE2_RGB(red, green, blue) \
	((uint16_t)( \
		(((red) & 0xff) >> 3) << 11 | \
		(((green) & 0xff) >> 2) << 5 | \
		(((blue) & 0xff) >> 3) \
	))


typedef enum {
	L4D_PSE2_ACK = 0x06,
	L4D_PSE2_NACK = 0x15,
} __(response_t);

#define L4D_PSE2_OK(val) ((val) == L4D_PSE2_ACK)

typedef enum {
	L4D_PSE2_BOLD = 0x10,
	L4D_PDE2_ITALIC = 0x20,
	L4D_PSE2_INVERSE = 0x40,
	L4D_PSE2_UNDERLINED = 0x80,
} __(text_attribute_t);

typedef enum {
	L4D_PSE2_BAUD_110 = 0,
	L4D_PSE2_BAUD_300 = 1,
	L4D_PSE2_BAUD_600 = 2,
	L4D_PSE2_BAUD_1200 = 3,
	L4D_PSE2_BAUD_2400 = 4,
	L4D_PSE2_BAUD_4800 = 5,
	L4D_PSE2_BAUD_9600 = 6,
	L4D_PSE2_BAUD_14400 = 7,
	L4D_PSE2_BAUD_19200 = 8,
	L4D_PSE2_BAUD_31250 = 9,
	L4D_PSE2_BAUD_38400 = 10,
	L4D_PSE2_BAUD_56000 = 11,
	L4D_PSE2_BAUD_57600 = 12,
	L4D_PSE2_BAUD_115200 = 13,
	L4D_PSE2_BAUD_128000 = 14,
	L4D_PSE2_BAUD_256000 = 15,
	L4D_PSE2_BAUD_300000 = 16,
	L4D_PSE2_BAUD_375000 = 17,
	L4D_PSE2_BAUD_500000 = 18,
	L4D_PSE2_BAUD_600000 = 19,
} __(baud_rate_t);

typedef enum {
	L4D_PSE2_LANDSCAPE,
	L4D_PSE2_LANDSCAPE_R,
	L4D_PSE2_PORTRAIT,
	L4D_PSE2_PORTRAIT_R,
} __(orientation_t);

typedef enum {
	L4D_PSE2_TOUCH_ENABLE = 0x00,
	L4D_PSE2_TOUCH_DISABLE = 0x01,
	L4D_PSE2_TOUCH_RESET = 0x02,
} __(touch_mode_t);

typedef enum {
	L4D_PSE2_TOUCH_STATUS = 0x00,
	L4D_PSE2_TOUCH_X_COORD = 0x01,
	L4D_PSE2_TOUCH_Y_COORD = 0x02,
} __(touch_status_t);


#ifndef L4D_PSE2_BUILD_PROTOTYPES
#  include "4d_pse2_prototypes.h"
#endif

#endif
#endif
