#include "frame.h"
#include "global.h"
#include "instruction_helpers.h"
#include "read_utils.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

void Nop(code_attribute *code) {
    if (DEBUG) printf("NOP\n");
}
void Aconst_null(code_attribute *code) {
    if (DEBUG) printf("ACONST_NULL\n");

    operand op_variable;
    op_variable.data.bytes = 0;
    op_variable.type = NULL_TYPE;
    op_variable.cat  = UNIQUE;
    //*op_variable.data.bytes = NULL; Verificar se será um tipo de objeto (corretude)
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_m1(code_attribute *code) {
    if (DEBUG) printf("ICONST_M1\n");

    operand op_variable;
    op_variable.data.bytes = -1;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_0(code_attribute *code) {
    if (DEBUG) printf("ICONST_0\n");

    operand op_variable;
    op_variable.data.bytes = 0;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_1(code_attribute *code) {
    if (DEBUG) printf("ICONST_1\n");

    operand op_variable;
    op_variable.data.bytes = 1;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_2(code_attribute *code) {
    if (DEBUG) printf("ICONST_2\n");

    operand op_variable;
    op_variable.data.bytes = 2;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_3(code_attribute *code) {
    if (DEBUG) printf("ICONST_3\n");

    operand op_variable;
    op_variable.data.bytes = 3;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_4(code_attribute *code) {
    if (DEBUG) printf("ICONST_4\n");

    operand op_variable;
    op_variable.data.bytes = 4;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_5(code_attribute *code) {
    if (DEBUG) printf("ICONST_5\n");

    operand op_variable;
    op_variable.data.bytes = 5;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}

void Lconst_0(code_attribute *code) {
    if (DEBUG) printf("LCONST_0\n");

    operand hi, low;
    hi.data.bytes  = 0x0;
    hi.type  = LONG_TYPE;
    hi.cat   = FIRST;
    low.data.bytes = 0x0;
    low.type = LONG_TYPE;
    low.cat  = SECOND;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, low);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, hi);
}

void Lconst_1(code_attribute *code) {
    if (DEBUG) printf("LCONST_1\n");
    operand hi, low;
    hi.data.bytes  = 0x0;
    hi.type  = LONG_TYPE;
    hi.cat   = FIRST;
    low.data.bytes = 0x1;
    low.type = LONG_TYPE;
    low.cat  = SECOND;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, low);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, hi);
}
void Fconst_0(code_attribute *code) {
    if (DEBUG) printf("FCONST_0\n");

    operand op_variable;
    float var = 0;

    op_variable.data.bytes = floatToUint32(var);
    op_variable.type = FLOAT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Fconst_1(code_attribute *code) {
    if (DEBUG) printf("FCONST_1\n");

    operand op_variable;
    float var        = 1;
    op_variable.data.bytes = floatToUint32(var);
    op_variable.type = FLOAT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Fconst_2(code_attribute *code) {
    if (DEBUG) printf("FCONST_2\n");
    operand op_variable;
    float var        = 2;
    op_variable.data.bytes = floatToUint32(var);
    op_variable.type = FLOAT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Dconst_0(code_attribute *code) {
    if (DEBUG) printf("DCONST_0\n");
    operand op_high, op_low;
    uint32_t high, low;
    uint64_t var = doubleToUint64(0);
    high         = (uint32_t)((var >> 32) & 0x00000000ffffffff);
    low          = (uint32_t)((var)&0x00000000ffffffff);
    op_high.data.bytes = high;
    op_high.type = DOUBLE_TYPE;
    op_high.cat  = FIRST;
    op_low.data.bytes  = low;
    op_low.type  = DOUBLE_TYPE;
    op_low.cat   = SECOND;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_low);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_high);
}
void Dconst_1(code_attribute *code) {
    if (DEBUG) printf("DCONST_1\n");
    operand op_high, op_low;
    uint32_t high, low;
    uint64_t var = doubleToUint64(1);
    high         = (uint32_t)((var >> 32) & 0x00000000ffffffff);
    low          = (uint32_t)((var)&0x00000000ffffffff);
    op_high.data.bytes = high;
    op_high.type = DOUBLE_TYPE;
    op_high.cat  = FIRST;
    op_low.data.bytes  = low;
    op_low.type  = DOUBLE_TYPE;
    op_low.cat   = SECOND;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_low);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_high);
}

void Bipush(code_attribute *code) {
    if (DEBUG) printf("BIPUSH\n");

    GLOBAL_jvm_stack->top->pc++;
    int8_t value = code->code[GLOBAL_jvm_stack->top->pc];
    operand op;

    op.type = BYTE_TYPE;
    op.data.bytes = (int32_t)value;
    op.cat  = UNIQUE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}

void Sipush(code_attribute *code) {
    if (DEBUG) printf("SIPUSH\n");
    GLOBAL_jvm_stack->top->pc++;
    uint8_t byte1 = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc++;
    uint8_t byte2 = code->code[GLOBAL_jvm_stack->top->pc];
    operand op;
    uint16_t value = (((int16_t)byte1 << 8) | (int16_t)byte2);
    op.type = SHORT_TYPE;
    op.data.bytes = (int32_t)value;
    op.cat  = UNIQUE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Ldc(code_attribute *code) {
    if (DEBUG) printf("LDC\n");
    operand op;
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index             = code->code[GLOBAL_jvm_stack->top->pc];
    cp_info cp                = GLOBAL_jvm_stack->top->constant_pool[index - 1];

    switch (cp.tag) {
    case CONSTANT_Integer:
        op.data.bytes = cp.info.integerInfo.bytes;
        op.cat  = UNIQUE;
        op.type = INT_TYPE;
        break;
    case CONSTANT_Float:
        op.data.bytes = cp.info.floatInfo.bytes;
        op.cat  = UNIQUE;
        op.type = FLOAT_TYPE;
        break;
    case CONSTANT_String:
        op.data.bytes = (uint32_t)GLOBAL_jvm_stack->top->constant_pool[cp.info.stringInfo.string_index - 1].info.utf8Info.bytes;
        op.cat  = UNIQUE;
        op.type = CHAR_TYPE;
        break;
    //case CONSTANT_Class:
        // op.data.bytes = cp.info.classInfo.name_index;
        // op.cat = UNIQUE;
        // op.type = CLASS_TYPE;
        //printf("LDC: CONSTANT_CLASS N IMPLEMENTADO\n");
        //break;
    default:
        op.data.bytes = 0;
        op.cat  = UNIQUE;
        op.type = NULL_TYPE;
        printf("Deu ruim no LDC\n");
        break;
    }
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Ldc_w(code_attribute *code) {
    if (DEBUG) printf("LDC_W\n");
    operand op;
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte1        = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte2        = code->code[GLOBAL_jvm_stack->top->pc];
    uint16_t index            = (((uint16_t)indexbyte1 << 8) | (uint16_t)indexbyte2);

    cp_info cp = GLOBAL_jvm_stack->top->constant_pool[index - 1];

    switch (cp.tag) {
    case CONSTANT_Integer:
        op.data.bytes = cp.info.integerInfo.bytes;
        op.cat  = UNIQUE;
        op.type = INT_TYPE;
        break;
    case CONSTANT_Float:
        op.data.bytes = cp.info.floatInfo.bytes;
        op.cat  = UNIQUE;
        op.type = FLOAT_TYPE;
        break;
    case CONSTANT_String:
        op.data.bytes = (uint32_t)GLOBAL_jvm_stack->top->constant_pool[cp.info.stringInfo.string_index - 1].info.utf8Info.bytes;
        op.cat  = UNIQUE;
        op.type = CHAR_TYPE;
        break;
    //case CONSTANT_Class:
        // op.data.bytes = cp.info.classInfo.name_index;
        // op.cat = UNIQUE;
        // op.type = CLASS_TYPE;
        //printf("LDC_W: CONSTANT_CLASS N IMPLEMENTADO\n");
        //break;
    default:
        op.data.bytes = 0;
        op.cat  = UNIQUE;
        op.type = NULL_TYPE;
        printf("Deu ruim no LDC\n");
        break;
    }
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Ldc2_w(code_attribute *code) {
    if (DEBUG) printf("LDC2_W\n");
    operand op_high, op_low;
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte1        = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte2        = code->code[GLOBAL_jvm_stack->top->pc];
    uint16_t index            = ((uint16_t)indexbyte1 << 8) | (uint16_t)indexbyte2;
    cp_info cp                = GLOBAL_jvm_stack->top->constant_pool[index - 1];

    if (cp.tag == CONSTANT_Long) {
        op_high.data.bytes = cp.info.longInfo.high_bytes;
        op_high.cat  = FIRST;
        op_high.type = LONG_TYPE;

        op_low.data.bytes = cp.info.longInfo.low_bytes;
        op_low.cat  = SECOND;
        op_low.type = LONG_TYPE;
    } else {
        op_high.data.bytes = cp.info.doubleInfo.high_bytes;
        op_high.cat  = FIRST;
        op_high.type = DOUBLE_TYPE;

        op_low.data.bytes = cp.info.doubleInfo.low_bytes;
        op_low.cat  = SECOND;
        op_low.type = DOUBLE_TYPE;
    }
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_low);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_high);
}
void Iload(code_attribute *code) {
    if (DEBUG) printf("ILOAD\n");

    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index             = code->code[GLOBAL_jvm_stack->top->pc];
    operand value             = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Lload(code_attribute *code) {
    if (DEBUG) printf("LLOAD  \n");

    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index_hi          = code->code[GLOBAL_jvm_stack->top->pc];
    operand value_hi          = GLOBAL_jvm_stack->top->local_vars[index_hi];
    uint8_t index_lo          = index_hi + 1;
    operand value_lo          = GLOBAL_jvm_stack->top->local_vars[index_lo];

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Fload(code_attribute *code) {
    if (DEBUG) printf("FLOAD  \n");

    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index             = code->code[GLOBAL_jvm_stack->top->pc];
    operand value             = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Dload(code_attribute *code) {
    if (DEBUG) printf("DLOAD  \n");

    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index_hi          = code->code[GLOBAL_jvm_stack->top->pc];
    operand value_hi          = GLOBAL_jvm_stack->top->local_vars[index_hi];
    uint8_t index_lo          = index_hi + 1;
    operand value_lo          = GLOBAL_jvm_stack->top->local_vars[index_lo];

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Aload(code_attribute *code) {
    if (DEBUG) printf("ALOAD  \n");

    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index             = code->code[GLOBAL_jvm_stack->top->pc];
    operand value             = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Iload_0(code_attribute *code) {
    if (DEBUG) printf("ILOAD_0\n");

    uint8_t index = 0;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Iload_1(code_attribute *code) {
    if (DEBUG) printf("ILOAD_1\n");

    uint8_t index = 1;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Iload_2(code_attribute *code) {
    if (DEBUG) printf("ILOAD_2\n");

    uint8_t index = 2;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Iload_3(code_attribute *code) {
    if (DEBUG) printf("ILOAD_3\n");
    uint8_t index = 3;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Lload_0(code_attribute *code) {
    if (DEBUG) printf("LLOAD_0\n");

    uint8_t index_hi = 0;
    uint8_t index_lo = 1;
    operand value_hi = GLOBAL_jvm_stack->top->local_vars[index_hi];
    operand value_lo = GLOBAL_jvm_stack->top->local_vars[index_lo];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Lload_1(code_attribute *code) {
    if (DEBUG) printf("LLOAD_1\n");

    uint8_t index_hi = 1;
    uint8_t index_lo = 2;
    operand value_hi = GLOBAL_jvm_stack->top->local_vars[index_hi];
    operand value_lo = GLOBAL_jvm_stack->top->local_vars[index_lo];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Lload_2(code_attribute *code) {
    if (DEBUG) printf("LLOAD_2\n");

    uint8_t index_hi = 2;
    uint8_t index_lo = 3;
    operand value_hi = GLOBAL_jvm_stack->top->local_vars[index_hi];
    operand value_lo = GLOBAL_jvm_stack->top->local_vars[index_lo];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Lload_3(code_attribute *code) {
    if (DEBUG) printf("LLOAD_3\n");

    uint8_t index_hi = 3;
    uint8_t index_lo = 4;
    operand value_hi = GLOBAL_jvm_stack->top->local_vars[index_hi];
    operand value_lo = GLOBAL_jvm_stack->top->local_vars[index_lo];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Fload_0(code_attribute *code) {
    if (DEBUG) printf("FLOAD_0\n");
    uint8_t index = 0;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Fload_1(code_attribute *code) {
    if (DEBUG) printf("FLOAD_1\n");
    uint8_t index = 1;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Fload_2(code_attribute *code) {
    if (DEBUG) printf("FLOAD_2\n");
    uint8_t index = 2;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Fload_3(code_attribute *code) {
    if (DEBUG) printf("FLOAD_3\n");
    uint8_t index = 3;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Dload_0(code_attribute *code) {
    if (DEBUG) printf("DLOAD_0\n");

    uint8_t index_hi = 0;
    uint8_t index_lo = 1;
    operand value_hi = GLOBAL_jvm_stack->top->local_vars[index_hi];
    operand value_lo = GLOBAL_jvm_stack->top->local_vars[index_lo];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Dload_1(code_attribute *code) {
    if (DEBUG) printf("DLOAD_1\n");

    uint8_t index_hi = 1;
    uint8_t index_lo = 2;
    operand value_hi = GLOBAL_jvm_stack->top->local_vars[index_hi];
    operand value_lo = GLOBAL_jvm_stack->top->local_vars[index_lo];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Dload_2(code_attribute *code) {
    if (DEBUG) printf("DLOAD_2\n");

    uint8_t index_hi = 2;
    uint8_t index_lo = 3;
    operand value_hi = GLOBAL_jvm_stack->top->local_vars[index_hi];
    operand value_lo = GLOBAL_jvm_stack->top->local_vars[index_lo];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Dload_3(code_attribute *code) {
    if (DEBUG) printf("DLOAD_3\n");

    uint8_t index_hi = 3;
    uint8_t index_lo = 4;
    operand value_hi = GLOBAL_jvm_stack->top->local_vars[index_hi];
    operand value_lo = GLOBAL_jvm_stack->top->local_vars[index_lo];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value_hi);
}
void Aload_0(code_attribute *code) {
    if (DEBUG) printf("ALOAD_0\n");
    uint8_t index = 0;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Aload_1(code_attribute *code) {
    if (DEBUG) printf("ALOAD_1\n");
    uint8_t index = 1;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Aload_2(code_attribute *code) {
    if (DEBUG) printf("ALOAD_2\n");
    uint8_t index = 2;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Aload_3(code_attribute *code) {
    if (DEBUG) printf("ALOAD_3\n");
    uint8_t index = 3;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Iaload(code_attribute *code) {
    if (DEBUG) printf("IALOAD \n");
    
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->low[index]);

}
void Laload(code_attribute *code) {
    if (DEBUG) printf("LALOAD \n");
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->low[index]);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->high[index]);
}
void Faload(code_attribute *code) {
    if (DEBUG) printf("FALOAD \n");

    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->low[index]);
}

void Daload(code_attribute *code) {
    if (DEBUG) printf("DALOAD \n");
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->low[index]);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->high[index]);
}
void Aaload(code_attribute *code) {
    if (DEBUG) printf("AALOAD \n");
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->low[index]);
}
void Baload(code_attribute *code) {
    if (DEBUG) printf("BALOAD \n");
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->low[index]);
}
void Caload(code_attribute *code) {
    if (DEBUG) printf("CALOAD \n");
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->low[index]);
}
void Saload(code_attribute *code) {
    if (DEBUG) printf("SALOAD \n");
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, array_ref->arrayref->low[index]);
}

void Istore(code_attribute *code) {
    if (DEBUG) printf("ISTORE\n");
    GLOBAL_jvm_stack->top->pc                = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index                            = code->code[GLOBAL_jvm_stack->top->pc];
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Lstore(code_attribute *code) {
    if (DEBUG) printf("LSTORE\n");
    GLOBAL_jvm_stack->top->pc                    = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index                                = code->code[GLOBAL_jvm_stack->top->pc];
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = lo;
}
void Fstore(code_attribute *code) {
    if (DEBUG) printf("FSTORE\n");
    GLOBAL_jvm_stack->top->pc                = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index                            = code->code[GLOBAL_jvm_stack->top->pc];
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Dstore(code_attribute *code) {
    if (DEBUG) printf("DSTORE\n");
    GLOBAL_jvm_stack->top->pc                    = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index                                = code->code[GLOBAL_jvm_stack->top->pc];
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = lo;
}
void Astore(code_attribute *code) {
    if (DEBUG) printf("ASTORE\n");
    GLOBAL_jvm_stack->top->pc                = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t index                            = code->code[GLOBAL_jvm_stack->top->pc];
    operand reference                        = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = reference;
}

void Istore_0(code_attribute *code) {
    if (DEBUG) printf("ISTORE_0\n");
    uint8_t index                            = 0;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}

void Istore_1(code_attribute *code) {
    if (DEBUG) printf("ISTORE_1\n");
    uint8_t index                            = 1;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Istore_2(code_attribute *code) {
    if (DEBUG) printf("ISTORE_2\n");
    uint8_t index                            = 2;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Istore_3(code_attribute *code) {
    if (DEBUG) printf("ISTORE_3\n");
    uint8_t index                            = 3;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Lstore_0(code_attribute *code) {
    if (DEBUG) printf("LSTORE_0\n");
    uint8_t index                                = 0;
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand low                                  = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = low;
}
void Lstore_1(code_attribute *code) {
    if (DEBUG) printf("LSTORE_1\n");
    uint8_t index                                = 1;
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand low                                  = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = low;
}
void Lstore_2(code_attribute *code) {
    if (DEBUG) printf("LSTORE_2\n");
    uint8_t index                                = 2;
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand low                                  = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = low;
}
void Lstore_3(code_attribute *code) {
    if (DEBUG) printf("LSTORE_3\n");
    uint8_t index                                = 3;
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand low                                  = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = low;
}
void Fstore_0(code_attribute *code) {
    if (DEBUG) printf("FSTORE_0\n");
    uint8_t index                            = 0;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Fstore_1(code_attribute *code) {
    if (DEBUG) printf("FSTORE_1\n");
    uint8_t index                            = 1;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Fstore_2(code_attribute *code) {
    if (DEBUG) printf("FSTORE_2\n");
    uint8_t index                            = 2;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Fstore_3(code_attribute *code) {
    if (DEBUG) printf("FSTORE_3\n");
    uint8_t index                            = 3;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Dstore_0(code_attribute *code) {
    if (DEBUG) printf("DSTORE_0\n");
    uint8_t index                                = 0;
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand low                                  = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = low;
}
void Dstore_1(code_attribute *code) {
    if (DEBUG) printf("DSTORE_1\n");
    uint8_t index                                = 1;
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand low                                  = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = low;
}
void Dstore_2(code_attribute *code) {
    if (DEBUG) printf("DSTORE_2\n");
    uint8_t index                                = 2;
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand low                                  = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = low;
}
void Dstore_3(code_attribute *code) {
    if (DEBUG) printf("DSTORE_3\n");
    uint8_t index                                = 3;
    operand hi                                   = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand low                                  = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = hi;
    GLOBAL_jvm_stack->top->local_vars[index + 1] = low;
}
void Astore_0(code_attribute *code) {
    if (DEBUG) printf("ASTORE_0\n");
    uint8_t index                            = 0;
    operand reference                        = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = reference;
}
void Astore_1(code_attribute *code) {
    if (DEBUG) printf("ASTORE_1\n");
    uint8_t index                            = 1;
    operand reference                        = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = reference;
}
void Astore_2(code_attribute *code) {
    if (DEBUG) printf("ASTORE_2\n");
    uint8_t index                            = 2;
    operand reference                        = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = reference;
}
void Astore_3(code_attribute *code) {
    if (DEBUG) printf("ASTORE_3\n");
    uint8_t index                            = 3;
    operand reference                        = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = reference;
}
void Iastore(code_attribute *code) {
    if (DEBUG) printf("IASTORE\n");
    uint32_t value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    array_ref->arrayref->low[index].data.bytes = (int32_t) value;

}
void Lastore(code_attribute *code) {
    if (DEBUG) printf("LASTORE\n");
    uint32_t hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }
    array_ref->arrayref->high[index].data.bytes = hi;
    array_ref->arrayref->low[index].data.bytes = lo;
}
void Fastore(code_attribute *code) {
    if (DEBUG) printf("FASTORE\n");
    uint32_t value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    array_ref->arrayref->low[index].data.bytes = value;
}
void Dastore(code_attribute *code) {
    if (DEBUG) printf("DASTORE\n");

    uint32_t hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }
    array_ref->arrayref->high[index].data.bytes = (uint32_t) hi;
    array_ref->arrayref->low[index].data.bytes = (uint32_t) lo;
}
void Aastore(code_attribute *code) {
    if (DEBUG) printf("AASTORE\n");
    reference_type * value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    array_ref->arrayref->low[index].data.ref = value;
}
void Bastore(code_attribute *code) {
    if (DEBUG) printf("BASTORE\n");

    uint32_t value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    uint32_t prev_value = array_ref->arrayref->low[index].data.bytes & 0xFFFFFF00;
    value = (value & 0x000000FF) | prev_value;

    array_ref->arrayref->low[index].data.bytes = value;
}
void Castore(code_attribute *code) {
    if (DEBUG) printf("CASTORE\n");

    uint32_t value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    uint32_t prev_value = array_ref->arrayref->low[index].data.bytes & 0xFFFFFF00;
    value = (value & 0x000000FF) | prev_value;

    array_ref->arrayref->low[index].data.bytes = value;
}
void Sastore(code_attribute *code) {
    if (DEBUG) printf("SASTORE\n");

    uint32_t value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    reference_type * array_ref = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;

    if (array_ref == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }

    uint32_t prev_value = array_ref->arrayref->low[index].data.bytes & 0xFFFF0000;
    value = (value & 0x0000FFFF) | prev_value;

    array_ref->arrayref->low[index].data.bytes = value;
}
void Pop(code_attribute *code) {
    if (DEBUG) printf("POP\n");

    pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
}
void Pop2(code_attribute *code) {
    if (DEBUG) printf("POP2\n");

    pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
}
void Dup(code_attribute *code) {
    if (DEBUG) printf("DUP\n");

    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Dup_x1(code_attribute *code) {
    if (DEBUG) printf("DUP_X1\n");

    operand op1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
}
void Dup_x2(code_attribute *code) {
    if (DEBUG) printf("DUP_X2\n");

    operand op1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op3 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op3);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
}
void Dup2(code_attribute *code) {
    if (DEBUG) printf("DUP2\n");

    operand op1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
}
void Dup2_x1(code_attribute *code) {
    if (DEBUG) printf("DUP2_X1\n");

    operand op1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op3 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op3);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
}
void Dup2_x2(code_attribute *code) {
    if (DEBUG) printf("DUP2_X2\n");

    operand op1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op3 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op4 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op4);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op3);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
}
void Swap(code_attribute *code) {
    if (DEBUG) printf("SWAP\n");

    operand op1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op1);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op2);
}
void Iadd(code_attribute *code) {
    if (DEBUG) printf("IADD\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int32_t result = (int32_t)value1.data.bytes + (int32_t)value2.data.bytes;
    op.data.bytes        = result;
    op.cat         = UNIQUE;
    op.type        = INT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Ladd(code_attribute *code) {
    if (DEBUG) printf("LADD\n");
    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = longToUint64(makeLong(value1_hi.data.bytes, value1_lo.data.bytes) + (makeLong(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Fadd(code_attribute *code) {
    if (DEBUG) printf("FADD\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    float result = makeFloat(value1.data.bytes) + makeFloat(value2.data.bytes);
    op.data.bytes      = floatToUint32(result);
    op.cat       = UNIQUE;
    op.type      = FLOAT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Dadd(code_attribute *code) {
    if (DEBUG) printf("DADD\n");

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = doubleToUint64(makeDouble(value1_hi.data.bytes, value1_lo.data.bytes) + (makeDouble(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = DOUBLE_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Isub(code_attribute *code) {
    if (DEBUG) printf("ISUB\n");
    operand op;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int32_t result = (int32_t)value1.data.bytes - (int32_t)value2.data.bytes;
    op.data.bytes        = result;
    op.cat         = UNIQUE;
    op.type        = INT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Lsub(code_attribute *code) {
    if (DEBUG) printf("LSUB\n");
    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = longToUint64(makeLong(value1_hi.data.bytes, value1_lo.data.bytes) - (makeLong(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Fsub(code_attribute *code) {
    if (DEBUG) printf("FSUB\n");
    operand op;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    float result = makeFloat(value1.data.bytes) - makeFloat(value2.data.bytes);
    op.data.bytes      = floatToUint32(result);
    op.cat       = UNIQUE;
    op.type      = FLOAT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Dsub(code_attribute *code) {
    if (DEBUG) printf("DSUB\n");
    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = doubleToUint64(makeDouble(value1_hi.data.bytes, value1_lo.data.bytes) - (makeDouble(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = DOUBLE_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Imul(code_attribute *code) {
    if (DEBUG) printf("IMUL\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int32_t result = (int32_t)value1.data.bytes * (int32_t)value2.data.bytes;
    op.data.bytes        = result;
    op.cat         = UNIQUE;
    op.type        = INT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Lmul(code_attribute *code) {
    if (DEBUG) printf("LMUL\n");
    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = longToUint64(makeLong(value1_hi.data.bytes, value1_lo.data.bytes) * (makeLong(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Fmul(code_attribute *code) {
    if (DEBUG) printf("FMUL\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    float result = makeFloat(value1.data.bytes) * makeFloat(value2.data.bytes);
    op.data.bytes      = floatToUint32(result);
    op.cat       = UNIQUE;
    op.type      = FLOAT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Dmul(code_attribute *code) {
    if (DEBUG) printf("DMUL\n");
    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = doubleToUint64(makeDouble(value1_hi.data.bytes, value1_lo.data.bytes) * (makeDouble(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = DOUBLE_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Idiv(code_attribute *code) {
    if (DEBUG) printf("IDIV\n");
    operand op;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    int32_t result;
    if ((value1.data.bytes == 0x8000000) && (value2.data.bytes == 0xFFFFFFFF))
        result = value1.data.bytes;
    else if (value2.data.bytes == 0) {
        printf("ArithmeticException\n");
        exit(3);
    } else {
        result  = (int32_t)value1.data.bytes / (int32_t)value2.data.bytes;
        op.data.bytes = result;
        op.cat  = UNIQUE;
        op.type = INT_TYPE;
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
    }
}
void Ldiv(code_attribute *code) {
    if (DEBUG) printf("LDIV\n");
    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = longToUint64(makeLong(value1_hi.data.bytes, value1_lo.data.bytes) / (makeLong(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Fdiv(code_attribute *code) {
    if (DEBUG) printf("FDIV\n");
    operand op;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    float result = makeFloat(value1.data.bytes) / makeFloat(value2.data.bytes);
    op.data.bytes      = floatToUint32(result);
    op.cat       = UNIQUE;
    op.type      = FLOAT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Ddiv(code_attribute *code) {
    if (DEBUG) printf("DDIV\n");
    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = doubleToUint64(makeDouble(value1_hi.data.bytes, value1_lo.data.bytes) / (makeDouble(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = DOUBLE_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Irem(code_attribute *code) {
    if (DEBUG) printf("IREM\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if (value2.data.bytes == 0) {
        printf("ArithmeticException\n");
        exit(3);
    } else {
        int32_t result = (int32_t)value1.data.bytes % (int32_t)value2.data.bytes;
        op.data.bytes        = result;
        op.cat         = UNIQUE;
        op.type        = INT_TYPE;
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
    }
}
void Lrem(code_attribute *code) {
    if (DEBUG) printf("LREM\n");
    if (DEBUG) printf("LADD\n");
    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int64_t long1  = (((int64_t)value1_hi.data.bytes << 32) | (int64_t)value1_lo.data.bytes);
    int64_t long2  = (((int64_t)value2_hi.data.bytes << 32) | (int64_t)value2_lo.data.bytes);
    int64_t result = long1 % long2;

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x0000FFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x0000FFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Frem(code_attribute *code) {
    if (DEBUG) printf("FREM\n");
    operand op;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    float result = fmod(makeFloat(value1.data.bytes), makeFloat(value2.data.bytes));
    op.data.bytes      = floatToUint32(result);
    op.cat       = UNIQUE;
    op.type      = FLOAT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Drem(code_attribute *code) {
    if (DEBUG) printf("DREM\n");
    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = doubleToUint64(fmod(makeDouble(value1_hi.data.bytes, value1_lo.data.bytes), (makeDouble(value2_hi.data.bytes, value2_lo.data.bytes))));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = DOUBLE_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Ineg(code_attribute *code) {
    if (DEBUG) printf("INEG\n");

    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    op.data.bytes = -1 * (int32_t)op.data.bytes;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Lneg(code_attribute *code) {
    if (DEBUG) printf("LNEG\n");

    operand hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = longToUint64(0 - makeLong(hi.data.bytes, lo.data.bytes));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Fneg(code_attribute *code) {
    if (DEBUG) printf("FNEG\n");

    operand op;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    float result = 0 - makeFloat(value.data.bytes);
    op.data.bytes      = floatToUint32(result);
    op.cat       = UNIQUE;
    op.type      = FLOAT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Dneg(code_attribute *code) {
    if (DEBUG) printf("DNEG\n");

    operand hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = doubleToUint64(0 - makeDouble(hi.data.bytes, lo.data.bytes));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = DOUBLE_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Ishl(code_attribute *code) {
    if (DEBUG) printf("ISHL\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Value to shift

    uint32_t shift = value2.data.bytes & 0x1f;

    value1.data.bytes <<= shift;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lshl(code_attribute *code) {
    if (DEBUG) printf("LSHL\n");

    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint32_t shift = value.data.bytes & 0x3f;

    uint64_t result = longToUint64(makeLong(hi.data.bytes, lo.data.bytes) << shift);

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Ishr(code_attribute *code) {
    if (DEBUG) printf("ISHR\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Value to shift

    uint32_t shift = value2.data.bytes & 0x1f;

    value1.data.bytes >>= shift;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lshr(code_attribute *code) {
    if (DEBUG) printf("LSHR\n");

    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint32_t shift = value.data.bytes & 0x3f;

    uint64_t result = longToUint64(makeLong(hi.data.bytes, lo.data.bytes) >> shift);

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Iushr(code_attribute *code) {
    if (DEBUG) printf("IUSHR\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Value to shift
    int32_t shift  = value2.data.bytes & 0x1f;

    if ((int32_t)value1.data.bytes < 0) {
        value1.data.bytes = (value1.data.bytes >> shift) + (2 << ~shift);
    } else {
        value1.data.bytes >>= shift;
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lushr(code_attribute *code) {
    if (DEBUG) printf("LUSHR\n");

    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint32_t shift = value.data.bytes & 0x3f;
    long long_val = makeLong(hi.data.bytes, lo.data.bytes);

    if (long_val < 0) {
        long_val = (long_val >> shift) + (2L << ~shift);
    } else {
        long_val >>= shift;
    }

    uint64_t result = longToUint64(long_val);

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Iand(code_attribute *code) {
    if (DEBUG) printf("IAND\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    value1.data.bytes &= value2.data.bytes;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Land(code_attribute *code) {
    if (DEBUG) printf("LAND\n");


    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = longToUint64(makeLong(value2_hi.data.bytes, value2_lo.data.bytes) & makeLong(value1_hi.data.bytes, value1_lo.data.bytes));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Ior(code_attribute *code) {
    if (DEBUG) printf("IOR\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    value1.data.bytes |= value2.data.bytes;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lor(code_attribute *code) {
    if (DEBUG) printf("LOR\n");

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = longToUint64(makeLong(value1_hi.data.bytes, value1_lo.data.bytes) | (makeLong(value2_hi.data.bytes, value2_lo.data.bytes)));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Ixor(code_attribute *code) {
    if (DEBUG) printf("IXOR\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    value1.data.bytes ^= value2.data.bytes;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lxor(code_attribute *code) {
    if (DEBUG) printf("LXOR\n");

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t result = longToUint64(makeLong(value2_hi.data.bytes, value2_lo.data.bytes) ^ makeLong(value1_hi.data.bytes, value1_lo.data.bytes));

    operand op_hi, op_lo;
    op_hi.data.bytes = (uint32_t)(result >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(result & 0x00000000FFFFFFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Iinc(code_attribute *code) {
    if (DEBUG) printf("IINC\n");

    GLOBAL_jvm_stack->top->pc++;
    uint8_t index = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc++;
    uint8_t const_inc = code->code[GLOBAL_jvm_stack->top->pc];

    GLOBAL_jvm_stack->top->local_vars[index].data.bytes += const_inc;
}
void I2l(code_attribute *code) {
    if (DEBUG) printf("I2L\n");

    operand op_int = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op_hi, op_lo;
    op_hi.cat = FIRST;
    op_lo.cat = SECOND;
    op_hi.type = op_lo.type = LONG_TYPE;

    int64_t longVal = (int64_t) op_int.data.bytes;
    uint64_t finalVal = (uint64_t) longVal;

    op_hi.data.bytes = (uint32_t)(finalVal >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(finalVal & 0x00000000FFFFFFFF);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);

}
void I2f(code_attribute *code) {
    if (DEBUG) printf("I2F\n");

    operand op_int = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_float;
    op_float.cat = UNIQUE;
    op_float.type = FLOAT_TYPE;

    float floatValue = (float) ((int32_t)op_int.data.bytes);

    op_float.data.bytes = floatToUint32(floatValue);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_float);
}
void I2d(code_attribute *code) {
    if (DEBUG) printf("I2D\n");

    operand op_int = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op_hi, op_lo;
    op_hi.cat = FIRST;
    op_lo.cat = SECOND;
    op_hi.type = op_lo.type = DOUBLE_TYPE;

    double doubleVal = (double) op_int.data.bytes;
    uint64_t finalVal = doubleToUint64(doubleVal);

    op_hi.data.bytes = (uint32_t)(finalVal >> 32) & 0x00000000FFFFFFFF;
    op_lo.data.bytes = (uint32_t)(finalVal & 0x00000000FFFFFFFF);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);

}
void L2i(code_attribute *code) {
    if (DEBUG) printf("L2I\n");

    operand op_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_int;
    op_int.cat = UNIQUE;
    op_int.type = INT_TYPE;

    int64_t longVal = (int64_t)((((uint64_t) op_hi.data.bytes) << 32) | ((uint64_t)op_lo.data.bytes));

    int32_t intVal = (int32_t) longVal;

    op_int.data.bytes = (uint32_t) intVal;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_int);

}
void L2f(code_attribute *code) {
    if (DEBUG) printf("L2F\n");

    operand op_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_float;
    op_float.cat = UNIQUE;
    op_float.type = FLOAT_TYPE;

    int64_t longVal = (int64_t)((((uint64_t) op_hi.data.bytes) << 32) | ((uint64_t)op_lo.data.bytes));
    float floatValue = (float) longVal;

    op_float.data.bytes = floatToUint32(floatValue);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_float);
}
void L2d(code_attribute *code) {
    if (DEBUG) printf("L2D\n");

    operand op_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_double_hi, op_double_lo;
    op_double_hi.type = op_double_lo.type = DOUBLE_TYPE;
    op_double_hi.cat = FIRST;
    op_double_lo.cat = SECOND;

    double doubleVal = (double) makeLong(op_hi.data.bytes, op_lo.data.bytes);

    uint64_t finalVal = doubleToUint64(doubleVal);

    op_double_hi.data.bytes = (uint32_t)(finalVal >> 32) & 0x00000000FFFFFFFF;
    op_double_lo.data.bytes = (uint32_t)(finalVal & 0x00000000FFFFFFFF);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_double_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_double_hi);

}
void F2i(code_attribute *code) {
    if (DEBUG) printf("F2I\n");

    operand op_float = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_int;
    op_int.cat = UNIQUE;
    op_int.type = INT_TYPE;

    float floatVal = makeFloat(op_float.data.bytes);

    int32_t intVal = (int32_t) floatVal;

    op_int.data.bytes = (uint32_t) intVal;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_int);
    
}
void F2l(code_attribute *code) {
    if (DEBUG) printf("F2L\n");

    operand op_float = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_long_hi, op_long_lo;
    op_long_hi.cat = FIRST;
    op_long_lo.cat = SECOND;
    op_long_hi.type = op_long_lo.type = LONG_TYPE;

    float floatVal = makeFloat(op_float.data.bytes);

    int64_t longVal = (int64_t) floatVal;

    //uint64_t finalVal = longToUint64(longVal);
    uint64_t finalVal = (uint64_t) longVal;

    op_long_hi.data.bytes = (uint32_t)(finalVal >> 32) & 0x00000000FFFFFFFF;
    op_long_lo.data.bytes = (uint32_t)(finalVal & 0x00000000FFFFFFFF);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_long_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_long_hi);
}
void F2d(code_attribute *code) {
    if (DEBUG) printf("F2D\n");

    operand op_float = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_double_hi, op_double_lo;
    op_double_hi.cat = FIRST;
    op_double_lo.cat = SECOND;
    op_double_hi.type = op_double_lo.type = DOUBLE_TYPE;

    float floatVal = makeFloat(op_float.data.bytes);

    double doubleVal = (double) floatVal;

    uint64_t finalVal = doubleToUint64(doubleVal);

    op_double_hi.data.bytes = (uint32_t)(finalVal >> 32) & 0x00000000FFFFFFFF;
    op_double_lo.data.bytes = (uint32_t)(finalVal & 0x00000000FFFFFFFF);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_double_hi);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_double_lo);
}
void D2i(code_attribute *code) {
    if (DEBUG) printf("D2I\n");

    operand op_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_int;
    op_int.cat = UNIQUE;
    op_int.type = INT_TYPE;

    double doubleVal = (double) makeDouble(op_hi.data.bytes, op_lo.data.bytes); 

    int32_t intVal = (int32_t) doubleVal;

    op_int.data.bytes = (uint32_t) intVal;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_int);
}
void D2l(code_attribute *code) {
    if (DEBUG) printf("D2L\n");

    operand op_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_long_hi, op_long_lo;
    op_long_hi.cat = FIRST;
    op_long_lo.cat = SECOND;
    op_long_hi.type = op_long_lo.type = LONG_TYPE;

    double doubleVal = (double) makeDouble(op_hi.data.bytes, op_lo.data.bytes); 

    int64_t longVal = (int64_t) doubleVal;

    uint64_t finalVal = (uint64_t) longVal;

    op_long_hi.data.bytes = (uint32_t)(finalVal >> 32) & 0x00000000FFFFFFFF;
    op_long_lo.data.bytes = (uint32_t)(finalVal & 0x00000000FFFFFFFF);

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_long_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_long_hi);
 
}
void D2f(code_attribute *code) {
    if (DEBUG) printf("D2F\n");

    operand op_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand op_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_float;
    op_float.cat = UNIQUE;
    op_float.type = FLOAT_TYPE;

    double doubleVal = (double) makeDouble(op_hi.data.bytes, op_lo.data.bytes); 

    float floatVal = (float) doubleVal;

    uint32_t finalVal = floatToUint32(floatVal);

    op_float.data.bytes = finalVal;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_float);
}
void I2b(code_attribute *code) {
    if (DEBUG) printf("I2B\n");

    operand op_int = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_byte;
    op_byte.cat = UNIQUE;
    op_byte.type = BYTE_TYPE;

    int32_t byteVal = (int32_t)((int8_t) op_int.data.bytes);

    op_byte.data.bytes = (uint32_t) byteVal;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_byte);
}
void I2c(code_attribute *code) {
    if (DEBUG) printf("I2C\n");

    operand op_int = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_char;
    op_char.cat = UNIQUE;
    op_char.type = CHAR_TYPE;

    uint32_t charVal = (uint32_t)((int8_t) op_int.data.bytes);

    op_char.data.bytes = charVal;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_char);

}
void I2s(code_attribute *code) {
    if (DEBUG) printf("I2S\n");

    operand op_int = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand op_byte;
    op_byte.cat = UNIQUE;
    op_byte.type = SHORT_TYPE;

    int32_t byteVal = (int32_t)((int16_t) op_int.data.bytes);

    op_byte.data.bytes = (uint32_t) byteVal;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_byte);
}
void Lcmp(code_attribute *code) {
    if (DEBUG) printf("LCMP\n");

    int32_t result;

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int64_t long1 = (((int64_t)value1_hi.data.bytes << 32) + (int64_t)value1_lo.data.bytes);
    int64_t long2 = (((int64_t)value2_hi.data.bytes << 32) + (int64_t)value2_lo.data.bytes);

    if (long1 > long2)
        result = 1;
    else if (long1 < long2)
        result = -1;
    else
        result = 0;

    operand op;
    op.data.bytes = result;
    op.cat  = UNIQUE;
    op.type = INT_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Fcmpl(code_attribute *code) {
    if (DEBUG) printf("FCMPL\n");
    uint32_t result;
    float fvalue1, fvalue2;

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    fvalue1 = makeFloat(value1.data.bytes);
    fvalue2 = makeFloat(value2.data.bytes);

    if (fvalue1 < fvalue2)
        result = 1;
    else if (fvalue1 > fvalue2)
        result = -1;
    else
        result = 0;
    operand op;
    op.data.bytes = result;
    op.cat  = UNIQUE;
    op.type = INT_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Fcmpg(code_attribute *code) {
    if (DEBUG) printf("FCMPG\n");
    uint32_t result;
    float fvalue1, fvalue2;

    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    fvalue1 = makeFloat(value1.data.bytes);
    fvalue2 = makeFloat(value2.data.bytes);

    if (fvalue1 > fvalue2)
        result = 1;
    else if (fvalue1 < fvalue2)
        result = -1;
    else
        result = 0;

    operand op;
    op.data.bytes = result;
    op.cat  = UNIQUE;
    op.type = INT_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Dcmpl(code_attribute *code) {
    if (DEBUG) printf("DCMPL\n");

    uint32_t result;
    double dvalue1, dvalue2;

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    dvalue1 = makeDouble(value1_hi.data.bytes, value1_lo.data.bytes);
    dvalue2 = makeDouble(value2_hi.data.bytes, value2_lo.data.bytes);

    if (isnan(dvalue1) || isnan(dvalue2))
        result = -1;
    else if (dvalue1 < dvalue2)
        result = 1;
    else if (dvalue1 > dvalue2)
        result = -1;
    else
        result = 0;

    operand op;
    op.data.bytes = result;
    op.cat  = UNIQUE;
    op.type = INT_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Dcmpg(code_attribute *code) {
    if (DEBUG) printf("DCMPG\n");

    uint32_t result;
    double dvalue1, dvalue2;

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    dvalue1 = makeDouble(value1_hi.data.bytes, value1_lo.data.bytes);
    dvalue2 = makeDouble(value2_hi.data.bytes, value2_lo.data.bytes);

    if (isnan(dvalue1) || isnan(dvalue2))
        result = 1;
    else if (dvalue1 > dvalue2)
        result = 1;
    else if (dvalue1 < dvalue2)
        result = -1;
    else
        result = 0;

    operand op;
    op.data.bytes = result;
    op.cat  = UNIQUE;
    op.type = INT_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Ifeq(code_attribute *code) {
    if (DEBUG) printf("IFEQ\n");
    int16_t offset;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value.data.bytes == 0) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void Ifne(code_attribute *code) {
    if (DEBUG) printf("IFNE\n");
    int16_t offset;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value.data.bytes != 0) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    if (DEBUG) printf("Offset: %d\n", offset);
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void Iflt(code_attribute *code) {
    if (DEBUG) printf("IFLT\n");
    int16_t offset;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value.data.bytes < 0) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void Ifge(code_attribute *code) {
    if (DEBUG) printf("IFGE\n");
    int16_t offset;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value.data.bytes >= 0) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void Ifgt(code_attribute *code) {
    if (DEBUG) printf("IFGT\n");
    int16_t offset;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value.data.bytes > 0) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void Ifle(code_attribute *code) {
    if (DEBUG) printf("IFLE\n");
    int16_t offset;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value.data.bytes <= 0) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void If_icmpeq(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPEQ\n");
    int16_t offset;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value1.data.bytes == (int32_t)value2.data.bytes) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void If_icmpne(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPNE\n");
    int16_t offset;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value1.data.bytes != (int32_t)value2.data.bytes) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void If_icmplt(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPLT\n");
    int16_t offset;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value1.data.bytes < (int32_t)value2.data.bytes) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void If_icmpge(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPGE\n");
    int16_t offset;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value1.data.bytes >= (int32_t)value2.data.bytes) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void If_icmpgt(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPGT\n");
    int16_t offset;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value1.data.bytes > (int32_t)value2.data.bytes) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void If_icmple(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPLE\n");
    int16_t offset;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t)value1.data.bytes <= (int32_t)value2.data.bytes) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void If_acmpeq(code_attribute *code) {
    if (DEBUG) printf("IF_ACMPEQ\n");
    int16_t offset;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if (value1.data.bytes == value2.data.bytes) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void If_acmpne(code_attribute *code) {
    if (DEBUG) printf("IF_ACMPNE\n");
    int16_t offset;
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if (value1.data.bytes != value2.data.bytes) {
        uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
        uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
        offset              = (branchbyte1 << 8) | branchbyte2;
    } else
        offset = 3;
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void GoTo(code_attribute *code) {
    if (DEBUG) printf("GOTO\n");

    int16_t offset;
    uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset              = (branchbyte1 << 8) | branchbyte2;

    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void Jsr(code_attribute *code) {
    if (DEBUG) printf("JSR\n");
    int32_t offset;
    uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset = (int32_t)((branchbyte1 << 8) | branchbyte2);

    operand op;
    op.data.bytes = GLOBAL_jvm_stack->top->pc + 1;
    op.cat  = UNIQUE;
    op.type = RETURN_ADDR_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void Ret(code_attribute *code) {
    if (DEBUG) printf("RET\n");
    GLOBAL_jvm_stack->top->pc++;
    uint8_t index = code->code[GLOBAL_jvm_stack->top->pc];

    operand op = GLOBAL_jvm_stack->top->local_vars[index];

    GLOBAL_jvm_stack->top->pc += op.data.bytes - 1;
}
void Tableswitch(code_attribute *code) {
    if (DEBUG) printf("TABLESWITCH\n");
    // uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    int resto     = 3 - (GLOBAL_jvm_stack->top->pc % 4);
    int pc_offset = resto + GLOBAL_jvm_stack->top->pc; 

    uint32_t default_variable = build32(code->code[pc_offset + 1 ], code->code[pc_offset + 2], code->code[pc_offset + 3], code->code[pc_offset + 4]);
    uint32_t low_variable     = build32(code->code[pc_offset + 5], code->code[pc_offset + 6], code->code[pc_offset + 7], code->code[pc_offset + 8]);
    uint32_t high_variable    = build32(code->code[pc_offset + 9], code->code[pc_offset + 10], code->code[pc_offset + 11], code->code[pc_offset + 12]);

    uint32_t return_amount = 0xFFFF;

    uint32_t index = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;

    int32_t * jump_table = (int32_t * ) malloc ((high_variable - low_variable + 1) * sizeof(int32_t)); 
    int32_t offset;
    for (int j = 0; j < high_variable - low_variable + 1; j++) {
        int aux_off     = resto + GLOBAL_jvm_stack->top->pc + j * 4;
        int jump_amount = build32(code->code[aux_off + 13], code->code[aux_off + 14], code->code[aux_off + 15], code->code[aux_off + 16]);
        jump_table[j] = jump_amount;
        
        if (DEBUG) printf("\t\t%d: %d (+%d)\n", j + low_variable, jump_amount + GLOBAL_jvm_stack->top->pc, jump_amount);

        if (return_amount > jump_amount) return_amount = jump_amount;
    }

    if (index < low_variable || index > high_variable) {
        offset = default_variable;
    }
    else {
        offset = jump_table[index - low_variable];
    }
    
    if (DEBUG) printf(" %d to %d\n", low_variable, high_variable);
    if (DEBUG) printf("\t\tdefault: %d (+%d)\n", GLOBAL_jvm_stack->top->pc + default_variable, default_variable);
    GLOBAL_jvm_stack->top->pc += offset-1;
    free(jump_table);
}
void Lookupswitch(code_attribute *code) {
    if (DEBUG) printf("LOOKUPSWITCH\n");
    uint32_t key = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;

    int32_t offset;
    int resto     = 3 - (GLOBAL_jvm_stack->top->pc % 4);
    int pc_offset = resto + GLOBAL_jvm_stack->top->pc;

    uint32_t default_variable = build32(code->code[pc_offset + 1], code->code[pc_offset + 2], code->code[pc_offset + 3], code->code[pc_offset + 4]);
    uint32_t n_pairs          = build32(code->code[pc_offset + 5], code->code[pc_offset + 6], code->code[pc_offset + 7], code->code[pc_offset + 8]);
    int32_t * match_offset_table = (int32_t * ) malloc ((n_pairs) * sizeof(int32_t)); 
    int32_t * match_table = (int32_t * ) malloc ((n_pairs) * sizeof(int32_t)); 

    uint32_t return_amount = 0xFFFF;

    if (DEBUG) printf(" // %d\n", n_pairs);
    for (int j = 0; j < n_pairs * 2; j += 2) {
        int aux_off     = resto + GLOBAL_jvm_stack->top->pc + j * 4;
        int index       = build32(code->code[aux_off + 9], code->code[aux_off + 10], code->code[aux_off + 11], code->code[aux_off + 12]);
        int jump_amount = build32(code->code[aux_off + 13], code->code[aux_off + 14], code->code[aux_off + 15], code->code[aux_off + 16]);
        match_offset_table[j/2] = jump_amount;
        match_table[j/2] = index;
        if (DEBUG) printf("\t\t%d: %d (+%d)\n", index, jump_amount + GLOBAL_jvm_stack->top->pc, jump_amount);

        if (return_amount > jump_amount) return_amount = jump_amount;
    }
    if (DEBUG) printf("\t\tdefault: %d (+%d)\n", GLOBAL_jvm_stack->top->pc + default_variable, default_variable);

    for(int i = 0; i< n_pairs; i++){
        if(key == match_table[i]){
            if (DEBUG) printf("\tkey: %d match_table:(+%d)\n", key, match_table[i]);
            offset = match_offset_table[i];
            break;
        }
        else {
            offset = default_variable;
        }
    }
    if (DEBUG) printf("offset: %d\n",offset);
    GLOBAL_jvm_stack->top->pc += offset-1;
    free(match_offset_table);
    free(match_table);

}
void Ireturn(code_attribute *code) {
    if (DEBUG) printf("IRETURN\n");

    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    pop_jvm_stack(GLOBAL_jvm_stack);
    if(GLOBAL_jvm_stack->top != NULL)
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Lreturn(code_attribute *code) {
    if (DEBUG) printf("LRETURN\n");

    operand hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    pop_jvm_stack(GLOBAL_jvm_stack);
    if(GLOBAL_jvm_stack->top != NULL){
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, lo);
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, hi);
    }
}
void Freturn(code_attribute *code) {
    if (DEBUG) printf("FRETURN\n");

    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    pop_jvm_stack(GLOBAL_jvm_stack);
    if(GLOBAL_jvm_stack->top != NULL)
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);

}
void Dreturn(code_attribute *code) {
    if (DEBUG) printf("DRETURN\n");

    operand hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    pop_jvm_stack(GLOBAL_jvm_stack);
    if(GLOBAL_jvm_stack->top != NULL){
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, lo);
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, hi);
    }
}
void Areturn(code_attribute *code) {
    if (DEBUG) printf("ARETURN\n");

    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    pop_jvm_stack(GLOBAL_jvm_stack);
    if(GLOBAL_jvm_stack->top != NULL)
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Return(code_attribute *code) {
    if (DEBUG) printf("RETURN\n");

    pop_jvm_stack(GLOBAL_jvm_stack);
}
void Getstatic(code_attribute *code) {
    if (DEBUG) printf("GETSTATIC\n");

    char *class_name, *name, *type;

    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte1        = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte2        = code->code[GLOBAL_jvm_stack->top->pc];
    uint16_t index            = 0x0;
    index                     = (indexbyte1 << 8) | indexbyte2;
    class_name                = getUtf8Class(index);
    name                      = getUtf8Name(index);
    type                      = getUtf8Type(index);

    field *f = NULL;
    class_loaded *lclass = NULL;

    if(DEBUG) printf("classname : %s\n", class_name);
    if(DEBUG) printf("name : %s\n", name);
    if(DEBUG) printf("type : %s\n", type);

    if (!strcmp(class_name, "java/lang/System")) return;

    do{
        if(DEBUG) printf("classname: %s\n", class_name);
        // Achar a classe
        lclass = findClassLoaded((uint8_t *)class_name);

        // Ver se ela ta carregada
        if(lclass != NULL)
            loadClass(GLOBAL_path, class_name);

        // Pegar o operando do field
        f = getField(lclass, name, type);

        // Buscar nas classes pais
        if(f == NULL){
            class_name = getSuperClassName(lclass->class_str);
            if(DEBUG) printf("SuperClass: %s", class_name);
            if (!strcmp(class_name, "java/lang/Object")) return;
        }

    }while(f == NULL);
    

    // Carrega na pilha de operandos
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, f->lo);
    if(DEBUG) printf("\tf->lo: %x\n", f->lo.data.bytes);
    if(f->type == DOUBLE_TYPE || f->type == LONG_TYPE){
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, f->hi);
        if(DEBUG) printf("\tf->hi: %x\n", f->hi.data.bytes);
    }

}
void Putstatic(code_attribute *code) {
    if (DEBUG) printf("PUTSTATIC\n");


    char *class_name, *name, *type;

    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte1        = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte2        = code->code[GLOBAL_jvm_stack->top->pc];
    uint16_t index            = 0x0;
    index                     = (indexbyte1 << 8) | indexbyte2;
    class_name                = getUtf8Class(index);
    name                      = getUtf8Name(index);
    type                      = getUtf8Type(index);

    field *f = NULL;
    class_loaded *lclass = NULL;

    if(DEBUG) printf("classname : %s\n", class_name);
    if(DEBUG) printf("name : %s\n", name);
    if(DEBUG) printf("type : %s\n", type);

    if (!strcmp(class_name, "java/lang/System")) return;

    do{
        // Achar a classe
        lclass = findClassLoaded((uint8_t *)class_name);

        // Ver se ela ta carregada
        if(lclass != NULL)
            loadClass(GLOBAL_path, class_name);

        // Pegar o operando do field
        f = getField(lclass, name, type);

        // Buscar nas classes pais
        if(f == NULL){
            class_name = getSuperClassName(lclass->class_str);
            if (!strcmp(class_name, "java/lang/Object")) return;
        }

    }while(f == NULL);
    

    // Carrega no field
    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if(f->type == DOUBLE_TYPE || f->type == LONG_TYPE){
        f->hi = op;
        f->lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
        if(DEBUG) printf("\tf->hi: %x\n", f->hi.data.bytes);
        if(DEBUG) printf("\tf->lo: %x\n", f->lo.data.bytes);
    }else{
        f->lo = op;
        if(DEBUG) printf("\tf->lo: %x\n", f->lo.data.bytes);
    }
}
void Getfield(code_attribute *code) {
    if (DEBUG) printf("GETFIELD\n");
}
void Putfield(code_attribute *code) {
    if (DEBUG) printf("PUTFIELD\n");
}
void Invokevirtual(code_attribute *code) {
    if (DEBUG) printf("INVOKEVIRTUAL\n");

    GLOBAL_jvm_stack->top->pc++;
    int8_t indexbyte1 = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc++;
    int8_t indexbyte2 = code->code[GLOBAL_jvm_stack->top->pc];

    /* Constrói a referência */
    uint16_t index = (indexbyte1 << 8) | indexbyte2;

    char *class_name = getUtf8Class(index);
    char *name       = getUtf8Name(index);
    char *type       = getUtf8Type(index);

    operand op2;

    printf("CLASS NAME:  %s\n", class_name);
    printf("METHOD NAME: %s\n", name);
    printf("TYPE:        %s\n", type);

    // /* Inicia-se o procedimento para verificar se o metodo a ser chamado é um print f */
    int isPrint = !strcmp(class_name, "java/io/PrintStream") &&
        (!strcmp(name, "println") || !strcmp(name, "print"));

    // printf("Print? : %d \n", isPrint);
    if (isPrint) {

        if (strcmp(type, "()V")) {
            operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
            switch (op.type) {
            // case CONSTANT_String:
            //     std::cout << *(op->type_string);
            //     break;
            case RETURN_ADDR_TYPE:
            case ARRAY_TYPE:
            case INTERFACE_TYPE:
                printf("====FALTA IMPLEMENTAR====");
                break;
            case INT_TYPE:
                printf("%d", (int32_t)op.data.bytes);
                break;
            case FLOAT_TYPE:
                printf("%f", makeFloat(op.data.bytes));
                break;
            case BYTE_TYPE:
                printf("%x", (uint8_t)op.data.bytes);
                break;
            case CHAR_TYPE:
                printf("%c", (char)op.data.bytes);
                break;
            case SHORT_TYPE:
                printf("%d", (int16_t)op.data.bytes);
                break;
            case BOOLEAN_TYPE:
                op.data.bytes == 0 ? printf("false") : printf("true");
                break;
            case LONG_TYPE:
                op2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
                printf("%ld", makeLong(op.data.bytes, op2.data.bytes));
                break;
            case NULL_TYPE:
                printf("NULL");
                break;
            case DOUBLE_TYPE: {
                op2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
                printf("%lf", makeDouble(op.data.bytes, op2.data.bytes));
                break;
            }
            case CLASS_TYPE: {
                //             Instance *class_instance  = op->class_instance;
                //             ClassLoader *class_loader = class_instance->classe;
                //             std::string class_name    = cpAttrAux.getUTF8(class_loader->getConstPool(), class_loader->getThisClass());
                //             std::cout << class_name << "@" << class_instance;
                printf("INVOKEVIRTUAL: CLASS_TYPE N IMPLEMENTADO\n");
                break;
            }
            default:
                printf("====BUG====");
                break;
            }

            if (!strcmp(name, "println")) printf("\n");
        }
    } else if (!strcmp(class_name, "java/lang/StringBuilder") && !strcmp(name, "append")) {
        //     MethodsArea maux;
        //     Operand *op = this_frame->operand_stack.top();
        //     this_frame->operand_stack.pop();
        //     Operand *string_operand = this_frame->operand_stack.top();
        //     this_frame->operand_stack.pop();

        //     switch (op->tag) {
        //     case CONSTANT_String:
        //         *string_operand->type_string += (*op->type_string);
        //         break;
        //     case CONSTANT_Integer:
        //         *string_operand->type_string += (patch::to_string(op->type_int));
        //         break;
        //     case CONSTANT_Long:
        //         *string_operand->type_string += (patch::to_string(op->type_long));
        //         break;
        //     case CONSTANT_Float:
        //         *string_operand->type_string += (patch::to_string(op->type_float));
        //         break;
        //     case CONSTANT_Double:
        //         *string_operand->type_string += (patch::to_string(op->type_double));
        //         break;
        //     case CONSTANT_Short:
        //         *string_operand->type_string += (patch::to_string(op->type_short));
        //         break;
        //     case CONSTANT_Char:
        //         *string_operand->type_string += (patch::to_string(op->type_char));
        //         break;
        //     case CONSTANT_Byte:
        //         *string_operand->type_string += (patch::to_string(op->type_byte));
        //         break;
        //     case CONSTANT_Boolean:
        //         if (op->type_bool == 0)
        //             *string_operand->type_string += "false";
        //         else
        //             *string_operand->type_string += "true";
        //         break;
        //     case CONSTANT_Class:
        //         // @TODO colocar enderec
        //         *string_operand->type_string += op->class_instance->name + "@";
        //         break;
        //     case CONSTANT_Array:
        //         *string_operand->type_string += "Array[]";
        //         break;
        //     }
        //     this_frame->operand_stack.push(string_operand);
        // } else if (class_name == "java/lang/String" && method_name == "length") {
        //     auto strOp = this_frame->operand_stack.top();
        //     this_frame->operand_stack.pop();

        //     Operand *strLen  = (Operand *)calloc(1, sizeof(Operand));
        //     strLen->tag      = CONSTANT_Integer;
        //     strLen->type_int = strOp->type_string->size();

        //     this_frame->operand_stack.push(strLen);
    } else {

        //     int argsCount  = 0;
        //     uint16_t count = 1;
        //     while (method_deor.at(count) != ')') {

        //         if (method_deor.at(count) == 'L') {
        //             while (method_deor.at(++count) != ';')
        //                 ;
        //         }

        //         else if (method_deor.at(count) == '[') {
        //             while (method_deor.at(++count) != '[')
        //                 ;

        //             if (method_deor[count] == 'L')
        //                 while (method_deor.at(++count) != ';')
        //                     ;
        //         }
        //         argsCount++;
        //         count++;
        //     }

        //     std::vector<Operand *> args;

        //     for (int i = 0; i < argsCount; ++i) { //verificar esta linha.

        //         auto arg = this_frame->operand_stack.top();
        //         this_frame->operand_stack.pop();

        //         args.insert(args.begin(), arg);
        //         if (arg->tag == CONSTANT_Double || arg->tag == CONSTANT_Long) args.insert(args.begin() + 1, Interpreter::createType("P"));
        //     }
        //     auto this_class = this_frame->operand_stack.top();
        //     this_frame->operand_stack.pop();

        //     args.insert(args.begin(), this_class);
        //     auto instance = this_class->class_instance;

        //     MethodsArea auxMeth;
        //     //fdasfds
        //     auto methods  = auxMeth.findMethodByNameOrDeor(instance->classe, method_name, method_deor);
        //     auto newFrame = new Frame(instance->classe->getConstPool(), methods);

        //     for (unsigned i = 0; i < args.size(); ++i) {
        //         newFrame->local_variables.at(i) = args.at(i);
        //     }
        //     Interpreter auxInter;
        //     auxInter.frame_stack.push(newFrame);
    }
}
void Invokespecial(code_attribute *code) {
    if (DEBUG) printf("INVOKESPECIAL\n");
}
void Invokestatic(code_attribute *code) {
    if (DEBUG) printf("INVOKESTATIC\n");
}
void Invokeinterface(code_attribute *code) {
    if (DEBUG) printf("INVOKEINTERFACE\n");
}
void Invokedynamic(code_attribute *code) {
    if (DEBUG) printf("INVOKEDYNAMIC\n");
}
void New(code_attribute *code) {
    if (DEBUG) printf("NEW\n");

    GLOBAL_jvm_stack->top->pc++;
    uint8_t indexbyte1 = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc++;
    uint8_t indexbyte2 = code->code[GLOBAL_jvm_stack->top->pc];

    int16_t index = (indexbyte1 << 8) | indexbyte2;

    char * class_name;
    class_name = getUtf8Ref(index);

    class_loaded *lclass = findClassLoaded((uint8_t*) class_name);
    //Verificar se esta na area de metodos antes
    if (lclass == NULL)
    {
        lclass = loadClass(GLOBAL_path, class_name);
        if(lclass == NULL){
            printf("InstantiationError: %s\n", class_name);
            exit(3);
        }
    }

    // Criar class instance via malloc
    class_instance *instance = (class_instance *)malloc(sizeof(instance));
    instance->name = lclass->name;

    object *obj = buildObject(lclass);

    reference_type * ref = (reference_type * ) malloc (sizeof(reference_type));
    ref->objectref = obj;

    operand op;
    op.data.ref = ref;
    op.type = CLASS_TYPE;

    // printf("NEW CLASS LOAD\n");
    // printf("CLASS NAME: %s\n", op.data.ref->objectref->class->name);
    // printf("STATIC FIELD COUNT: %d\n", op.data.ref->objectref->class->field_count);
    // printf("DYNAMIC FIELD COUNT: %d\n", op.data.ref->objectref->class_instance->field_count);
    // for (int i = 0; i < op.data.ref->objectref->class->field_count; i++)
    // {
    //     printf("STATIC FIELDS: %s\n", op.data.ref->objectref->class->fields[i].name);
    // } 
    // for (int i = 0; i < op.data.ref->objectref->class_instance->field_count; i++)
    // {
    //     printf("DYNAMIC FIELDS: %s\n", op.data.ref->objectref->class_instance->fields[i].name);
    // }    

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Newarray(code_attribute *code) {
    if (DEBUG) printf("NEWARRAY\n");
    int32_t count = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    if (count < 0) {
        printf("NegativeArraySizeException\n");
        exit(3);
    }
    operand op;
    GLOBAL_jvm_stack->top->pc ++;
    uint8_t atype = code->code[GLOBAL_jvm_stack->top->pc];
    
    reference_type * arr = (reference_type * ) malloc ((1) * sizeof(reference_type));
    
    data_type type = PrimitiveType(atype);

    arr->arrayref = (array * ) malloc ((1) * sizeof(array));

    arr->arrayref->low = (operand *) malloc (count*sizeof(operand));
    if (type == LONG_TYPE || type == DOUBLE_TYPE){
        arr->arrayref->high = (operand *) malloc (count*sizeof(operand));
    }
    else{
        arr->arrayref->high = NULL;
    }

    for(int i = 0;i < count; i++){
        arr->arrayref->low[i].type = type;
        arr->arrayref->low[i].data.bytes = 0;
        if (arr->arrayref->high != NULL){
            arr->arrayref->high[i].type = type;
            arr->arrayref->high[i].data.bytes = 0;
        }
    }
    arr->arrayref->arraysize = count;

    op.data.ref= arr;
    op.type = ARRAY_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);


}
void Anewarray(code_attribute *code) {
    if (DEBUG) printf("ANEWARRAY\n");
    int32_t count = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
    if (count < 0) {
        printf("NegativeArraySizeException\n");
        exit(3);
    }
    operand op;
    GLOBAL_jvm_stack->top->pc ++;
    uint8_t indexbyte1 = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc ++;
    uint8_t indexbyte2 = code->code[GLOBAL_jvm_stack->top->pc];
    int16_t index = (indexbyte1 << 8) | indexbyte2;
    char * type;
    type = getUtf8Ref(index);
    cp_info cp = GLOBAL_jvm_stack->top->constant_pool[index - 1];
    if (DEBUG) printf("[%d]-> %s \n",cp.tag,type);


    reference_type * reference = (reference_type * ) malloc ((1) * sizeof(reference_type));
    
    reference->arrayref = (array * ) malloc ((1) * sizeof(array));
    reference->arrayref->low = (operand *) malloc (count*sizeof(operand));
    switch (cp.tag){
        case (CONSTANT_Class):
            for(int i = 0;i < count; i++){
                reference->arrayref->low[i].type = ARRAY_TYPE;
                reference->arrayref->low[i].data.ref = NULL;
            }
        reference->arrayref->arraysize = count;
        break;
        default:
            printf("ERRO ANEWARRAY!\n");
    }


    op.data.ref= reference;
    op.type = ARRAY_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
    
}
void Arraylength(code_attribute *code) {
    if (DEBUG) printf("ARRAYLENGTH\n");
    operand op;
    reference_type * arr = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.ref;
    if (arr == NULL) {
        printf("NullPointerException\n");
        exit(3);
    }
    op.data.bytes = arr->arrayref->arraysize;
    op.type = INT_TYPE;
    op.cat = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Athrow(code_attribute *code) {
    if (DEBUG) printf("ATHROW\n");
}
void Checkcast(code_attribute *code) {
    if (DEBUG) printf("CHECKCAST\n");
}
void Instanceof(code_attribute *code) {
    if (DEBUG) printf("INSTANCEOF\n");
}
void Monitorenter(code_attribute *code) {
    if (DEBUG) printf("MONITORENTER\n");
}
void Monitorexit(code_attribute *code) {
    if (DEBUG) printf("MONITOREXIT\n");
}
void Wide(code_attribute *code) {
    if (DEBUG) printf("WIDE\n");
}
void Multianewarray(code_attribute *code) {
    if (DEBUG) printf("MULTIANEWARRAY\n");
    operand op;
    GLOBAL_jvm_stack->top->pc ++;
    uint8_t indexbyte1 = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc ++;
    uint8_t indexbyte2 = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc ++;
    uint8_t dimensions = code->code[GLOBAL_jvm_stack->top->pc];
    int32_t * counts = (int32_t * ) malloc (dimensions * sizeof(int32_t)); 

    for (int i = 0;i<dimensions;i++){
        counts[i] = pop_op_stack(GLOBAL_jvm_stack->top->op_stack).data.bytes;
        if (DEBUG) printf("count[%d]:%d\n",i,counts[i]);
    }



    if (DEBUG) printf("Dimensões:%d\n",dimensions);
    int16_t index = (indexbyte1 << 8) | indexbyte2;
    char * type;
    type = getUtf8Ref(index);
    cp_info cp = GLOBAL_jvm_stack->top->constant_pool[index - 1];
    if (DEBUG) printf("[%d]-> %s \n",cp.tag,type);


    reference_type * reference = (reference_type * ) malloc ((1) * sizeof( reference_type));
    // if (DEBUG) printf("Buggggggggggggggggggg \n");
    reference->arrayref = (array * ) malloc ((1) * sizeof(array));
    for(int i=0;i<dimensions;i++){
        reference->arrayref->low = (operand *) malloc (counts[i]*sizeof(operand));
    }
    
    switch (cp.tag){
        case (CONSTANT_Class):
            for(int i = 0;i < dimensions; i++){
                for(int j = 0;j < counts[i]; j++){
                    reference->arrayref->low[j].type = ARRAY_TYPE;
                    reference->arrayref->low[j].data.ref = NULL;
                }
                reference->arrayref->arraysize = counts[i];
            }
        break;
        default:
            printf("ERRO MULTIANEWARRAY!\n");
    }


    op.data.ref= reference;
    op.type = ARRAY_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Ifnull(code_attribute *code) {
    if (DEBUG) printf("IFNULL\n");
    int32_t offset;

    GLOBAL_jvm_stack->top->pc ++;
    uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc ++;
    uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset = (int32_t)((branchbyte1 << 8) | branchbyte2);

    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    if(op.type == NULL_TYPE)
        GLOBAL_jvm_stack->top->pc += offset -1;
}
void Ifnonnull(code_attribute *code) {
    if (DEBUG) printf("IFNONNULL\n");

        int32_t offset;

    GLOBAL_jvm_stack->top->pc ++;
    uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc ++;
    uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset = (int32_t)((branchbyte1 << 8) | branchbyte2);

    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    if(op.type != NULL_TYPE)
        GLOBAL_jvm_stack->top->pc += offset -1;
}
void Goto_w(code_attribute *code) {
    if (DEBUG) printf("GOTO_W\n");

    int32_t offset;
    uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
    uint8_t branchbyte3 = code->code[GLOBAL_jvm_stack->top->pc + 3];
    uint8_t branchbyte4 = code->code[GLOBAL_jvm_stack->top->pc + 4];

    offset              = (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4;

    GLOBAL_jvm_stack->top->pc += offset - 1;
}
void Jsr_w(code_attribute *code) {
    if (DEBUG) printf("JSR_W\n");

    int32_t offset;
    uint8_t branchbyte1 = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2 = code->code[GLOBAL_jvm_stack->top->pc + 2];
    uint8_t branchbyte3 = code->code[GLOBAL_jvm_stack->top->pc + 3];
    uint8_t branchbyte4 = code->code[GLOBAL_jvm_stack->top->pc + 4];

    offset = (int32_t)((branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4);
    operand op;
    op.data.bytes = GLOBAL_jvm_stack->top->pc + 1;
    op.cat  = UNIQUE;
    op.type = RETURN_ADDR_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
    GLOBAL_jvm_stack->top->pc += offset - 1;
}