#include "global.h"
#include "primitive_types.h"
#include <stdio.h>

char *getUtf8Class(uint16_t index) {
    cp_info field       = GLOBAL_jvm_stack->top->constant_pool[index - 1];
    cp_info class_name2 = GLOBAL_jvm_stack->top->constant_pool[field.info.refInfo.class_index - 1];
    cp_info class_name3 = GLOBAL_jvm_stack->top->constant_pool[class_name2.info.refInfo.class_index - 1];

    // printf("%s\n", class_name3.info.utf8Info.bytes);
    return (char *)class_name3.info.utf8Info.bytes;
}
char *getUtf8Name(uint16_t index) {
    cp_info field          = GLOBAL_jvm_stack->top->constant_pool[index - 1];
    cp_info name_and_type2 = GLOBAL_jvm_stack->top->constant_pool[field.info.refInfo.name_and_type_index - 1];
    cp_info name           = GLOBAL_jvm_stack->top->constant_pool[name_and_type2.info.refInfo.class_index - 1];

    // printf("%s\n", name.info.utf8Info.bytes);
    return (char *)name.info.utf8Info.bytes;
}
char *getUtf8Type(uint16_t index) {
    cp_info field          = GLOBAL_jvm_stack->top->constant_pool[index - 1];
    cp_info name_and_type2 = GLOBAL_jvm_stack->top->constant_pool[field.info.refInfo.name_and_type_index - 1];
    cp_info descriptor     = GLOBAL_jvm_stack->top->constant_pool[name_and_type2.info.refInfo.name_and_type_index - 1];

    // printf("%s\n", descriptor.info.utf8Info.bytes);
    return (char *)descriptor.info.utf8Info.bytes;
}

double makeDouble(uint32_t high, uint32_t low) {
    uint64_t number;

    number = (((uint64_t)high) << 32) | ((uint64_t)low);

    return *(double *)&number;
}

long makeLong(uint32_t high, uint32_t low) {
    uint64_t number;

    number = (((uint64_t)high) << 32) | ((uint64_t)low);

    return *(long *)&number;
}

float makeFloat(uint32_t bytes) {
    return *(float *)&bytes;
}

uint64_t doubleToUint64(double number) {
    return *(uint64_t *)&number;
}

uint64_t longToUint64(long number) {
    return *(uint64_t *)&number;
}


uint32_t floatToUint32(float bytes) {
    return *(uint32_t *)&bytes;
}

data_type PrimitiveType(int8_t atype) {
    switch (atype) {
    case T_BOOLEAN: return BOOLEAN_TYPE; break;
    case T_CHAR: return CHAR_TYPE; break;
    case T_FLOAT: return FLOAT_TYPE; break;
    case T_DOUBLE: return DOUBLE_TYPE; break;
    case T_BYTE: return BYTE_TYPE; break;
    case T_SHORT: return SHORT_TYPE; break;
    case T_INT: return INT_TYPE; break;
    case T_LONG: return LONG_TYPE; break;
    default: 
        printf("Primitive Type ERROR!");
        return NULL_TYPE;
    }
}
