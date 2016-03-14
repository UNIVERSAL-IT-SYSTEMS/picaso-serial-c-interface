#ifndef L4D_PSE2_EXAMPLE_H
#define L4D_PSE2_EXAMPLE_H

#define L4D_PSE2_PUTCHAR serial_putchar
#define L4D_PSE2_GETCHAR serial_getchar

#include "4d_pse2_impl/4d_pse2.h"

extern void serial_putchar(uint8_t);
extern uint8_t serial_getchar(void);

#endif
