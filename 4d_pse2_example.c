#include "4d_pse2_example.h"
#include "4d_pse2_impl/4d_pse2_v1.3.inc.c"

#include <stdio.h>

void serial_putchar(uint8_t value) {
    printf("> 0x%x\n", value);
}
uint8_t serial_getchar(void) {
    printf("< 0x06\n");
    return 0x06;
}


int main(void) {
    l4d_pse2_gfx_Cls();
}