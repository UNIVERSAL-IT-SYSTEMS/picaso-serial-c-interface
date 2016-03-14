// as usual, include our own header, which will define the write and read
// functions for the actual implementation
#include "4d_pse2_example.h"
// include the library function implementations.
#include "4d_pse2_impl/4d_pse2_v1.3.inc.c"

// includes for this example
#include <stdio.h>

void serial_putchar(uint8_t value) {
    printf("> 0x%x\n", value);
}
uint8_t serial_getchar(void) {
    printf("< 0x06\n");
    return 0x06;
}


int main(void) {
    const l4d_pse2_colour_t red = L4D_PSE2_RGB(255, 0, 0);

    l4d_pse2_gfx_Cls();
    l4d_pse2_gfx_Circle(100, 100, 5, red);
}
