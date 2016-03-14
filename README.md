Picaso Serial C Interface
=========================

_Unofficial_ C library implementation for 4D Systems Serial Environment for Picaso based modules.

For official implementations look for [4D Systems github page](https://github.com/4dsystems).

This library contains only function parts that will turn parameters to correct byte sequences using provided macros for sending and receiving bytes over serial line. Thus this library should be usable in multiple environments and actual libraries.

This implementation also allows to namespace these library functions as user likes to or to use different serial implementations or interfaces. Though, for now asyncronous use is not tested or thought about, but syncronous should work in multiple instances.

*NOTE*: Only some functions are implemented so far. Feel free to create PR to fill in.

Installation and usage
----------------------

Copy or use git submodule to get this library to e.g. subfolder "lib" of your project/library. Create 2 files based on `4d_pse2_example.h` and `4d_pse2_example.c` in your project and make sure the include directives work correctly. You can use relative paths or add this library to gcc search path.

Macros you can use
------------------

`L4D_PSE2_PUTCHAR` *required*: Define this to be the function name (or callable macro) of function that _writes_ byte to the serial interface. This function/macro doesn't return anything and takes single byte as an argument.

`L4D_PSE2_GETCHAR` *required*: Define this to be the function name (or callable macro) of function that _reads_ byte from the serial interface. This function/macro doesn't take argument, but returns 16 bit int (int16_t) and takes no arguments. Negative value means error. Positive is presumed to be single byte (uint8_t).

`L4D_PSE2_PUTWORD`: You can have more optimal defition to writing word than calling `L4D_PSE2_PUTCHAR` twice (which is done if this is not defined).

`L4D_PSE2_GETWORD`: Similar to above. Word implementation of `L4D_PSE2_GETCHAR`. FIXME: this should be able to return error.

`L4D_PSE2_PREFIX`: Prefix for all of the types and functions defined in this library. Default prefix is `l4d_pse2_`. If you define this to be empty, no prefix is added.
