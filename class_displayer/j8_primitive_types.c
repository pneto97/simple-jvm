#include "j8_primitive_types.h"
#include <stdio.h>

void printPrimitiveType(int8_t atype) {
    switch (atype) {
    case T_BOOLEAN: printf("BOOLEAN"); break;
    case T_CHAR: printf("CHAR"); break;
    case T_FLOAT: printf("FLOAT"); break;
    case T_DOUBLE: printf("DOUBLE"); break;
    case T_BYTE: printf("BYTE"); break;
    case T_SHORT: printf("SHORT"); break;
    case T_INT: printf("INT"); break;
    case T_LONG: printf("LONG"); break;
    default: printf("Primitive Type ERROR!");
    }
}
