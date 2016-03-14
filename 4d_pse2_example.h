#ifndef L4D_PSE2_EXAMPLE_H
#define L4D_PSE2_EXAMPLE_H

// Define the 1 byte write and read function names for the library
// These macros are used within the library to link to the actual functions
#define L4D_PSE2_PUTCHAR serial_putchar
#define L4D_PSE2_GETCHAR serial_getchar
// Following could be used to remove the prefix from the library functions
//#define L4D_PSE2_PREFIX

// include the headers parts from the library
#include "4d_pse2_impl/4d_pse2.h"

// serial write and read function prototypes implemented in 4d_pse2_example.c
void serial_putchar(uint8_t);
uint8_t serial_getchar(void);

#endif
