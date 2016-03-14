#ifndef __4D_PSE2_HELPERS_H__
#define __4D_PSE2_HELPERS_H__

// src: avr-include/stdint.h
#ifdef __CONCAT
#  undef __CONCAT
#endif
#ifndef __CONCAT
#  define __CONCATenate(left, right) left ## right
#  define __CONCAT(left, right) __CONCATenate(left, right)
#endif

#ifdef __CONCAT3
#  undef __CONCAT3
#endif
#ifndef __CONCAT3
#  define __CONCAT3enate(left, middle, right) left ## middle ## right
#  define __CONCAT3(left, middle, right) __CONCAT3enate(left, middle, right)
#endif

// src: avr-include/avr/interrupt.h
#ifdef __STRINGIFY
#  undef __STRINGIFY
#endif
#ifndef __STRINGIFY
#  define __STRINGIFY2(x) #x
#  define __STRINGIFY(x) __m_STRINGIFY2(x)
#endif

// src: unknown
#define VA_NARGS_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define VA_NARGS(...) VA_NARGS_IMPL(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#define __ARGS1(type_t) type_t value1
#define __ARGS2(type_t, ...) type_t value2, __ARGS1(__VA_ARGS__)
#define __ARGS3(type_t, ...) type_t value3, __ARGS2(__VA_ARGS__)
#define __ARGS4(type_t, ...) type_t value4, __ARGS3(__VA_ARGS__)
#define __ARGS5(type_t, ...) type_t value5, __ARGS4(__VA_ARGS__)
#define __ARGS6(type_t, ...) type_t value6, __ARGS5(__VA_ARGS__)
#define __ARGS7(type_t, ...) type_t value7, __ARGS6(__VA_ARGS__)
#define __ARGS8(type_t, ...) type_t value8, __ARGS7(__VA_ARGS__)
#define __ARGS9(type_t, ...) type_t value9, __ARGS8(__VA_ARGS__)
#define __ARGS(...) __CONCAT(__ARGS, VA_NARGS(__VA_ARGS__))(__VA_ARGS__)

#define __CMDS1() L4D_PSE2_PUTWORD(value1);
#define __CMDS2() L4D_PSE2_PUTWORD(value2); __CMDS1()
#define __CMDS3() L4D_PSE2_PUTWORD(value3); __CMDS2()
#define __CMDS4() L4D_PSE2_PUTWORD(value4); __CMDS3()
#define __CMDS5() L4D_PSE2_PUTWORD(value5); __CMDS4()
#define __CMDS6() L4D_PSE2_PUTWORD(value6); __CMDS5()
#define __CMDS7() L4D_PSE2_PUTWORD(value7); __CMDS6()
#define __CMDS8() L4D_PSE2_PUTWORD(value8); __CMDS7()
#define __CMDS9() L4D_PSE2_PUTWORD(value9); __CMDS8()
#define __CMDS(num) __CONCAT(__CMDS, num)()


#endif
