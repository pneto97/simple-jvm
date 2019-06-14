#include "j8_primitive_types.h"
#include <stdio.h>

void printPrimitiveType(int8_t atype) {
    switch (atype) {
    case T_BOOLEAN: printf("(boolean)"); break;
    case T_CHAR: printf("(char)"); break;
    case T_FLOAT: printf("(float)"); break;
    case T_DOUBLE: printf("(double)"); break;
    case T_BYTE: printf("(byte)"); break;
    case T_SHORT: printf("(short)"); break;
    case T_INT: printf("(int)"); break;
    case T_LONG: printf("(long)"); break;
    default: printf("Primitive Type ERROR!");
    }
}
