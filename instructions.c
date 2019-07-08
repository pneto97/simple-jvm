#include "frame.h"
#include "global.h"
#include "instruction_helpers.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define DEBUG 1

void Nop(code_attribute *code) {
    if (DEBUG) printf("NOP\n");
}
void Aconst_null(code_attribute *code) {
    if (DEBUG) printf("ACONST_NULL\n");

    operand op_variable;
    op_variable.data = 0;
    op_variable.type = NULL_TYPE;
    op_variable.cat = UNIQUE;
    //*op_variable.data = NULL; Verificar se será um tipo de objeto (corretude)
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_m1(code_attribute *code) {
    if (DEBUG) printf("ICONST_M1\n");

    operand op_variable;
    op_variable.data = -1;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_0(code_attribute *code) {
    if (DEBUG) printf("ICONST_0\n");

    operand op_variable;
    op_variable.data = 0;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_1(code_attribute *code) {
    if (DEBUG) printf("ICONST_1\n");

    operand op_variable;
    op_variable.data = 1;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_2(code_attribute *code) {
    if (DEBUG) printf("ICONST_2\n");

    operand op_variable;
    op_variable.data = 2;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_3(code_attribute *code) {
    if (DEBUG) printf("ICONST_3\n");

    operand op_variable;
    op_variable.data = 3;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_4(code_attribute *code) {
    if (DEBUG) printf("ICONST_4\n");

    operand op_variable;
    op_variable.data = 4;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_5(code_attribute *code) {
    if (DEBUG) printf("ICONST_5\n");

    operand op_variable;
    op_variable.data = 5;
    op_variable.type = INT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}

void Lconst_0(code_attribute *code) {
    if (DEBUG) printf("LCONST_0\n");

    operand hi, low;
    hi.data  = 0x0;
    hi.type  = LONG_TYPE;
    hi.cat   = FIRST;
    low.data = 0x0;
    low.type = LONG_TYPE;
    low.cat  = SECOND;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, low);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, hi);
}

void Lconst_1(code_attribute *code) {
    if (DEBUG) printf("LCONST_1\n");
}
void Fconst_0(code_attribute *code) {
    if (DEBUG) printf("FCONST_0\n");

    operand op_variable;
    float var        = 0;
    op_variable.data = var;
    op_variable.type = FLOAT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Fconst_1(code_attribute *code) {
    if (DEBUG) printf("FCONST_1\n");

    operand op_variable;
    float var        = 1;
    op_variable.data = var;
    op_variable.type = FLOAT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Fconst_2(code_attribute *code) {
    if (DEBUG) printf("FCONST_2\n");

    operand op_variable;
    float var        = 2;
    op_variable.data = var;
    op_variable.type = FLOAT_TYPE;
    op_variable.cat  = UNIQUE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Dconst_0(code_attribute *code) {
    if (DEBUG) printf("DCONST_0\n");
}
void Dconst_1(code_attribute *code) {
    if (DEBUG) printf("DCONST_1\n");
}

void Bipush(code_attribute *code) {
    if (DEBUG) printf("BIPUSH\n");

    GLOBAL_jvm_stack->top->pc++;
    int8_t value = code->code[GLOBAL_jvm_stack->top->pc];
    operand op;

    op.type  = BYTE_TYPE;
    op.data = (int32_t)value;
    op.cat  = UNIQUE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}

void Sipush(code_attribute *code) {
    if (DEBUG) printf("SIPUSH\n");
}
void Ldc(code_attribute *code) {
    if (DEBUG) printf("LDC\n");
}
void Ldc_w(code_attribute *code) {
    if (DEBUG) printf("LDC_W\n");
}
void Ldc2_w(code_attribute *code) {
    if (DEBUG) printf("LDC2_W\n");
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
    uint8_t index_hi             = code->code[(GLOBAL_jvm_stack->top->pc)++];
    operand value_hi           = GLOBAL_jvm_stack->top->local_vars[index_hi];

    uint8_t index_lo            = code->code[GLOBAL_jvm_stack->top->pc];
    operand value_lo           = GLOBAL_jvm_stack->top->local_vars[index_lo];

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
    uint8_t index_hi             = code->code[(GLOBAL_jvm_stack->top->pc)++];
    operand value_hi           = GLOBAL_jvm_stack->top->local_vars[index_hi];

    uint8_t index_lo            = code->code[GLOBAL_jvm_stack->top->pc];
    operand value_lo           = GLOBAL_jvm_stack->top->local_vars[index_lo];

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
}
void Laload(code_attribute *code) {
    if (DEBUG) printf("LALOAD \n");
}
void Faload(code_attribute *code) {
    if (DEBUG) printf("FALOAD \n");
}
void Daload(code_attribute *code) {
    if (DEBUG) printf("DALOAD \n");
}
void Aaload(code_attribute *code) {
    if (DEBUG) printf("AALOAD \n");
}
void Baload(code_attribute *code) {
    if (DEBUG) printf("BALOAD \n");
}
void Caload(code_attribute *code) {
    if (DEBUG) printf("CALOAD \n");
}
void Saload(code_attribute *code) {
    if (DEBUG) printf("SALOAD \n");
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
}
void Fstore(code_attribute *code) {
    if (DEBUG) printf("FSTORE\n");
}
void Dstore(code_attribute *code) {
    if (DEBUG) printf("DSTORE\n");
}
void Astore(code_attribute *code) {
    if (DEBUG) printf("ASTORE\n");
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
    uint8_t index                                = 0;
    operand value                                = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = value;

}
void Fstore_1(code_attribute *code) {
    if (DEBUG) printf("FSTORE_1\n");
    uint8_t index                                = 1;
    operand value                                = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = value;
}
void Fstore_2(code_attribute *code) {
    if (DEBUG) printf("FSTORE_2\n");
    uint8_t index                                = 2;
    operand value                                = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = value;
}
void Fstore_3(code_attribute *code) {
    if (DEBUG) printf("FSTORE_3\n");
    uint8_t index                                = 3;
    operand value                                = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index]     = value;
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
}
void Astore_1(code_attribute *code) {
    if (DEBUG) printf("ASTORE_1\n");
}
void Astore_2(code_attribute *code) {
    if (DEBUG) printf("ASTORE_2\n");
}
void Astore_3(code_attribute *code) {
    if (DEBUG) printf("ASTORE_3\n");
}
void Iastore(code_attribute *code) {
    if (DEBUG) printf("IASTORE\n");
}
void Lastore(code_attribute *code) {
    if (DEBUG) printf("LASTORE\n");
}
void Fastore(code_attribute *code) {
    if (DEBUG) printf("FASTORE\n");
}
void Dastore(code_attribute *code) {
    if (DEBUG) printf("DASTORE\n");
}
void Aastore(code_attribute *code) {
    if (DEBUG) printf("AASTORE\n");
}
void Bastore(code_attribute *code) {
    if (DEBUG) printf("BASTORE\n");
}
void Castore(code_attribute *code) {
    if (DEBUG) printf("CASTORE\n");
}
void Sastore(code_attribute *code) {
    if (DEBUG) printf("SASTORE\n");
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

    int32_t result = (int32_t)value1.data + (int32_t)value2.data;
    op.data        = result;
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

    int64_t longao1 = (((int64_t)value1_hi.data << 32) + (int64_t)value1_lo.data);
    int64_t longao2 = (((int64_t)value2_hi.data << 32) + (int64_t)value2_lo.data);
    int64_t result  = longao1 + longao2;

    operand op_hi, op_lo;
    op_hi.data = (uint32_t)(result >> 32) & 0x0000FFFF;
    op_lo.data = (uint32_t)(result & 0x0000FFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);

}
void Fadd(code_attribute *code) {
    if (DEBUG) printf("FADD\n");
}
void Dadd(code_attribute *code) {
    if (DEBUG) printf("DADD\n");

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    uint64_t longao1 = (((uint64_t)value1_hi.data << 32) + (uint64_t)value1_lo.data);
    uint64_t longao2 = (((uint64_t)value2_hi.data << 32) + (uint64_t)value2_lo.data);
    uint64_t result  = (uint64_t) ((double) longao1 + (double) longao2);

    operand op_hi, op_lo;
    op_hi.data = (uint32_t)(result >> 32) & 0x0000FFFF;
    op_lo.data = (uint32_t)(result & 0x0000FFFF);

    op_hi.cat = FIRST;
    op_lo.cat = SECOND;

    op_hi.type = op_lo.type = LONG_TYPE;
    
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_lo);
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_hi);
}
void Isub(code_attribute *code) {
    if (DEBUG) printf("ISUB\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int32_t result = (int32_t)value1.data - (int32_t)value2.data;
    op.data        = result;
    op.cat         = UNIQUE;
    op.type        = INT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Lsub(code_attribute *code) {
    if (DEBUG) printf("LSUB\n");
}
void Fsub(code_attribute *code) {
    if (DEBUG) printf("FSUB\n");
}
void Dsub(code_attribute *code) {
    if (DEBUG) printf("DSUB\n");
}
void Imul(code_attribute *code) {
    if (DEBUG) printf("IMUL\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int32_t result = (int32_t)value1.data * (int32_t)value2.data;
    op.data        = result;
    op.cat         = UNIQUE;
    op.type        = INT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Lmul(code_attribute *code) {
    if (DEBUG) printf("LMUL\n");
}
void Fmul(code_attribute *code) {
    if (DEBUG) printf("FMUL\n");
}
void Dmul(code_attribute *code) {
    if (DEBUG) printf("DMUL\n");
}
void Idiv(code_attribute *code) {
    if (DEBUG) printf("IDIV\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    int32_t result;
    if ((value1.data== 0x8000000) && (value2.data == 0xFFFFFFFF)) result = value1.data;
    else if (value2.data == 0) {
        printf("ArithmeticException\n");
        exit(3);
    }
    else {
        result = (int32_t)value1.data / (int32_t)value2.data;
        op.data        = result;
        op.cat         = UNIQUE;
        op.type        = INT_TYPE;
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
    }
}
void Ldiv(code_attribute *code) {
    if (DEBUG) printf("LDIV\n");
}
void Fdiv(code_attribute *code) {
    if (DEBUG) printf("FDIV\n");
}
void Ddiv(code_attribute *code) {
    if (DEBUG) printf("DDIV\n");
}
void Irem(code_attribute *code) {
    if (DEBUG) printf("IREM\n");
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if (value2.data == 0) {
        printf("ArithmeticException\n");
        exit(3);
    }
    else {
        int32_t result = (int32_t) value1.data % (int32_t) value2.data;
        op.data        = result;
        op.cat         = UNIQUE;
        op.type        = INT_TYPE;
        push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
    }
}
void Lrem(code_attribute *code) {
    if (DEBUG) printf("LREM\n");
}
void Frem(code_attribute *code) {
    if (DEBUG) printf("FREM\n");
}
void Drem(code_attribute *code) {
    if (DEBUG) printf("DREM\n");
}
void Ineg(code_attribute *code) {
    if (DEBUG) printf("INEG\n");
    
    operand op = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    
    op.data = -1 * (int32_t) op.data;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Lneg(code_attribute *code) {
    if (DEBUG) printf("LNEG\n");
}
void Fneg(code_attribute *code) {
    if (DEBUG) printf("FNEG\n");
}
void Dneg(code_attribute *code) {
    if (DEBUG) printf("DNEG\n");
}
void Ishl(code_attribute *code) {
    if (DEBUG) printf("ISHL\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Value to shift

    uint32_t shift = value2.data & 0x1f;

    value1.data <<= shift;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lshl(code_attribute *code) {
    if (DEBUG) printf("LSHL\n");
}
void Ishr(code_attribute *code) {
    if (DEBUG) printf("ISHR\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Value to shift

    uint32_t shift = value2.data & 0x1f;

    value1.data >>= shift;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lshr(code_attribute *code) {
    if (DEBUG) printf("LSHR\n");
}
void Iushr(code_attribute *code) {
    if (DEBUG) printf("IUSHR\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Shift value
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack); //Value to shift
    int32_t shift = value2.data  & 0x1f;

    if((int32_t) value1.data < 0){
        value1.data = (value1.data >> shift) + (2 << ~shift);
    } else {
        value1.data >>= shift;
    }

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lushr(code_attribute *code) {
    if (DEBUG) printf("LUSHR\n");
}
void Iand(code_attribute *code) {
    if (DEBUG) printf("IAND\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    value1.data &= value2.data;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Land(code_attribute *code) {
    if (DEBUG) printf("LAND\n");
}
void Ior(code_attribute *code) {
    if (DEBUG) printf("IOR\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    value1.data |= value2.data;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lor(code_attribute *code) {
    if (DEBUG) printf("LOR\n");
}
void Ixor(code_attribute *code) {
    if (DEBUG) printf("IXOR\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    value1.data ^= value2.data;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value1);
}
void Lxor(code_attribute *code) {
    if (DEBUG) printf("LXOR\n");
}
void Iinc(code_attribute *code) {
    if (DEBUG) printf("IINC\n");

    GLOBAL_jvm_stack->top->pc++;
    uint8_t index             = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc++;
    uint8_t const_inc         = code->code[GLOBAL_jvm_stack->top->pc];

    GLOBAL_jvm_stack->top->local_vars[index].data += const_inc;
}
void I2l(code_attribute *code) {
    if (DEBUG) printf("I2L\n");
}
void I2f(code_attribute *code) {
    if (DEBUG) printf("I2F\n");
}
void I2d(code_attribute *code) {
    if (DEBUG) printf("I2D\n");
}
void L2i(code_attribute *code) {
    if (DEBUG) printf("L2I\n");
}
void L2f(code_attribute *code) {
    if (DEBUG) printf("L2F\n");
}
void L2d(code_attribute *code) {
    if (DEBUG) printf("L2D\n");
}
void F2i(code_attribute *code) {
    if (DEBUG) printf("F2I\n");
}
void F2l(code_attribute *code) {
    if (DEBUG) printf("F2L\n");
}
void F2d(code_attribute *code) {
    if (DEBUG) printf("F2D\n");
}
void D2i(code_attribute *code) {
    if (DEBUG) printf("D2I\n");
}
void D2l(code_attribute *code) {
    if (DEBUG) printf("D2L\n");
}
void D2f(code_attribute *code) {
    if (DEBUG) printf("D2F\n");
}
void I2b(code_attribute *code) {
    if (DEBUG) printf("I2B\n");
}
void I2c(code_attribute *code) {
    if (DEBUG) printf("I2C\n");
}
void I2s(code_attribute *code) {
    if (DEBUG) printf("I2S\n");
}
void Lcmp(code_attribute *code) {
    if (DEBUG) printf("LCMP\n");

    int32_t result;

    operand value2_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    operand value1_hi = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1_lo = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int64_t long1 = (((int64_t)value1_hi.data << 32) + (int64_t)value1_lo.data);
    int64_t long2 = (((int64_t)value2_hi.data << 32) + (int64_t)value2_lo.data);

    if(long1 > long2)
        result = 1;
    else if(long1 < long2)
        result = -1;
    else
        result = 0;
    
    operand op;
    op.data = result;
    op.cat = UNIQUE;
    op.type = INT_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Fcmpl(code_attribute *code) {
    if (DEBUG) printf("FCMPL\n");
    uint32_t result;
    float fvalue1, fvalue2;

    if (DEBUG) printf("Print depois do if\n");

    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    fvalue1 = makeFloat(value1.data);
    fvalue2 = makeFloat(value2.data);

    if(fvalue1 < fvalue2)
        result = 1;
    else if(fvalue1 > fvalue2)
        result = -1;
    else
        result = 0;
    operand op;
    op.data = result;
    op.cat = UNIQUE;
    op.type = INT_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Fcmpg(code_attribute *code) {
    if (DEBUG) printf("FCMPG\n");
    uint32_t result;
    float fvalue1, fvalue2;

    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    fvalue1 = makeFloat(value1.data);
    fvalue2 = makeFloat(value2.data);

    if(fvalue1 > fvalue2)
        result = 1;
    else if(fvalue1 < fvalue2)
        result = -1;
    else
        result = 0;

    operand op;
    op.data = result;
    op.cat = UNIQUE;
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

    dvalue1 = makeDouble(value1_hi.data, value1_lo.data);
    dvalue2 = makeDouble(value2_hi.data, value2_lo.data);

    if(isnan(dvalue1) || isnan(dvalue2))
        result = -1;
    else if(dvalue1 < dvalue2)
        result = 1;
    else if(dvalue1 > dvalue2)
        result = -1;
    else
        result = 0;

    operand op;
    op.data = result;
    op.cat = UNIQUE;
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

    dvalue1 = makeDouble(value1_hi.data, value1_lo.data);
    dvalue2 = makeDouble(value2_hi.data, value2_lo.data);

    if(isnan(dvalue1) || isnan(dvalue2))
        result = 1;
    else if(dvalue1 > dvalue2)
        result = 1;
    else if(dvalue1 < dvalue2)
        result = -1;
    else
        result = 0;

    operand op;
    op.data = result;
    op.cat = UNIQUE;
    op.type = INT_TYPE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op);
}
void Ifeq(code_attribute *code) {
    if (DEBUG) printf("IFEQ\n");
    uint16_t offset;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value.data == 0) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;

}
void Ifne(code_attribute *code) {
    if (DEBUG) printf("IFNE\n");
    uint16_t offset;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value.data != 0) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void Iflt(code_attribute *code) {
    if (DEBUG) printf("IFLT\n");
    uint16_t offset;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value.data < 0) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void Ifge(code_attribute *code) {
    if (DEBUG) printf("IFGE\n");
    uint16_t offset;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value.data >= 0) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void Ifgt(code_attribute *code) {
    if (DEBUG) printf("IFGT\n");
    uint16_t offset;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value.data > 0) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void Ifle(code_attribute *code) {
    if (DEBUG) printf("IFLE\n");
    uint16_t offset;
    operand value                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value.data <= 0) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void If_icmpeq(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPEQ\n");
    uint16_t offset;
    operand value1                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value1.data == (int32_t) value2.data) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void If_icmpne(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPNE\n");
    uint16_t offset;
    operand value1                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value1.data != (int32_t) value2.data) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void If_icmplt(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPLT\n");
    uint16_t offset;
    operand value1                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value1.data < (int32_t) value2.data) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void If_icmpge(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPGE\n");
    uint16_t offset;
    operand value1                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value1.data >= (int32_t) value2.data) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void If_icmpgt(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPGT\n");
    uint16_t offset;
    operand value1                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value1.data > (int32_t) value2.data) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void If_icmple(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPLE\n");
    uint16_t offset;
    operand value1                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if ((int32_t) value1.data <= (int32_t) value2.data) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void If_acmpeq(code_attribute *code) {
    if (DEBUG) printf("IF_ACMPEQ\n");
    uint16_t offset;
    operand value1                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if (value1.data == value2.data) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void If_acmpne(code_attribute *code) {
    if (DEBUG) printf("IF_ACMPNE\n");
    uint16_t offset;
    operand value1                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2                            = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    if (value1.data != value2.data) {
    uint8_t branchbyte1        = code->code[GLOBAL_jvm_stack->top->pc + 1];
    uint8_t branchbyte2        = code->code[GLOBAL_jvm_stack->top->pc + 2];
    offset                    = (branchbyte1 << 8) | branchbyte2; 
    }
    else offset = 3;
    GLOBAL_jvm_stack->top->pc += offset;
}
void GoTo(code_attribute *code) {
    if (DEBUG) printf("GOTO\n");
}
void Jsr(code_attribute *code) {
    if (DEBUG) printf("JSR\n");
}
void Ret(code_attribute *code) {
    if (DEBUG) printf("RET\n");
}
void Tableswitch(code_attribute *code) {
    if (DEBUG) printf("TABLESWITCH\n");
}
void Lookupswitch(code_attribute *code) {
    if (DEBUG) printf("LOOKUPSWITCH\n");
}
void Ireturn(code_attribute *code) {
    if (DEBUG) printf("IRETURN\n");
}
void Lreturn(code_attribute *code) {
    if (DEBUG) printf("LRETURN\n");
}
void Freturn(code_attribute *code) {
    if (DEBUG) printf("FRETURN\n");
}
void Dreturn(code_attribute *code) {
    if (DEBUG) printf("DRETURN\n");
}
void Areturn(code_attribute *code) {
    if (DEBUG) printf("ARETURN\n");
}
void Return(code_attribute *code) {
    if (DEBUG) printf("RETURN\n");
}
void Getstatic(code_attribute *code) {
    if (DEBUG) printf("GETSTATIC\n");
    char *class_name, *name, *type;
    // GLOBAL_jvm_stack->top->pc = 10;
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte1        = code->code[GLOBAL_jvm_stack->top->pc];
    GLOBAL_jvm_stack->top->pc = GLOBAL_jvm_stack->top->pc + 1;
    uint8_t indexbyte2        = code->code[GLOBAL_jvm_stack->top->pc];
    uint16_t index            = 0x0;
    index                     = (indexbyte1 << 8) | indexbyte2;
    class_name                = getUtf8Class(index);
    name                      = getUtf8Name(index);
    type                      = getUtf8Type(index);

    if (!strcmp(class_name, "java/lang/System")) return;

    printf("%s\n", class_name);
    printf("%s\n", name);
    printf("%s\n", type);
}
void Putstatic(code_attribute *code) {
    if (DEBUG) printf("PUTSTATIC\n");
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
    uint64_t longao;

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
                printf("%d", (int32_t)op.data);
                break;
            case FLOAT_TYPE:
                printf("%f", (float)op.data);
                break;
            case BYTE_TYPE:
                printf("%x", (uint8_t)op.data);
                break;
            case CHAR_TYPE:
                printf("%c", (char)op.data);
                break;
            case SHORT_TYPE:
                printf("%d", (int16_t)op.data);
                break;
            case BOOLEAN_TYPE:
                op.data == 0 ? printf("false") : printf("true");
                break;
            case LONG_TYPE:
                op2    = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
                longao = (((uint64_t)op.data << 32) | (uint64_t)op2.data);
                printf("%lld", longao);
                break;
            case NULL_TYPE:
                printf("NULL");
                break;
            case DOUBLE_TYPE: {
                op2    = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
                longao = (((uint64_t)op.data << 32) | (uint64_t)op2.data);
                printf("%lf", (double)longao);
                break;
            }
            case CLASS_TYPE: {
                //             Instance *class_instance  = op->class_instance;
                //             ClassLoader *class_loader = class_instance->classe;
                //             std::string class_name    = cpAttrAux.getUTF8(class_loader->getConstPool(), class_loader->getThisClass());
                //             std::cout << class_name << "@" << class_instance;
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
}
void Newarray(code_attribute *code) {
    if (DEBUG) printf("NEWARRAY\n");
}
void Anewarray(code_attribute *code) {
    if (DEBUG) printf("ANEWARRAY\n");
}
void Arraylength(code_attribute *code) {
    if (DEBUG) printf("ARRAYLENGTH\n");
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
}
void Ifnull(code_attribute *code) {
    if (DEBUG) printf("IFNULL\n");
}
void Ifnonnull(code_attribute *code) {
    if (DEBUG) printf("IFNONNULL\n");
}
void Goto_w(code_attribute *code) {
    if (DEBUG) printf("GOTO_W\n");
}
void Jsr_w(code_attribute *code) {
    if (DEBUG) printf("JSR_W\n");
}
void Breakpoint(code_attribute *code) {
    if (DEBUG) printf("BREAKPOINT\n");
}
void Impdep1(code_attribute *code) {
    if (DEBUG) printf("IMPDEP1\n");
}
void Impdep2(code_attribute *code) {
    if (DEBUG) printf("IMPDEP2\n");
}
