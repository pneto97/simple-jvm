#include "frame.h"
#include "global.h"
#include "instruction_helpers.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define DEBUG 1
#define VERBOSE 1

void Nop(code_attribute *code) {
    if (DEBUG) printf("NOP\n");
}
void Aconst_null(code_attribute *code) {
    if (DEBUG) printf("Aconst_null\n");

    operand op_variable;
    //*op_variable.data = NULL; Verificar se será um tipo de objeto (corretude)
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);
}
void Iconst_m1(code_attribute *code) {
    if (DEBUG) printf("ICONST_m1\n");

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

    op.cat  = BYTE_TYPE;
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
}
void Fload(code_attribute *code) {
    if (DEBUG) printf("FLOAD  \n");
}
void Dload(code_attribute *code) {
    if (DEBUG) printf("DLOAD  \n");
}
void Aload(code_attribute *code) {
    if (DEBUG) printf("ALOAD  \n");
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
}
void Lload_1(code_attribute *code) {
    if (DEBUG) printf("LLOAD_1\n");
}
void Lload_2(code_attribute *code) {
    if (DEBUG) printf("LLOAD_2\n");
}
void Lload_3(code_attribute *code) {
    if (DEBUG) printf("LLOAD_3\n");
}
void Fload_0(code_attribute *code) {
    if (DEBUG) printf("FLOAD_0\n");
}
void Fload_1(code_attribute *code) {
    if (DEBUG) printf("FLOAD_1\n");
}
void Fload_2(code_attribute *code) {
    if (DEBUG) printf("FLOAD_2\n");
}
void Fload_3(code_attribute *code) {
    if (DEBUG) printf("FLOAD_3\n");
}
void Dload_0(code_attribute *code) {
    if (DEBUG) printf("DLOAD_0\n");
}
void Dload_1(code_attribute *code) {
    if (DEBUG) printf("DLOAD_1\n");
}
void Dload_2(code_attribute *code) {
    if (DEBUG) printf("DLOAD_2\n");
}
void Dload_3(code_attribute *code) {
    if (DEBUG) printf("DLOAD_3\n");
}
void Aload_0(code_attribute *code) {
    if (DEBUG) printf("ALOAD_0\n");
}
void Aload_1(code_attribute *code) {
    if (DEBUG) printf("ALOAD_1\n");
}
void Aload_2(code_attribute *code) {
    if (DEBUG) printf("ALOAD_2\n");
}
void Aload_3(code_attribute *code) {
    if (DEBUG) printf("ALOAD_3\n");
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
}
void Lstore_1(code_attribute *code) {
    if (DEBUG) printf("LSTORE_1\n");
}
void Lstore_2(code_attribute *code) {
    if (DEBUG) printf("LSTORE_2\n");
}
void Lstore_3(code_attribute *code) {
    if (DEBUG) printf("LSTORE_3\n");
}
void Fstore_0(code_attribute *code) {
    if (DEBUG) printf("FSTORE_0\n");
}
void Fstore_1(code_attribute *code) {
    if (DEBUG) printf("FSTORE_1\n");
}
void Fstore_2(code_attribute *code) {
    if (DEBUG) printf("FSTORE_2\n");
}
void Fstore_3(code_attribute *code) {
    if (DEBUG) printf("FSTORE_3\n");
}
void Dstore_0(code_attribute *code) {
    if (DEBUG) printf("DSTORE_0\n");
}
void Dstore_1(code_attribute *code) {
    if (DEBUG) printf("DSTORE_1\n");
}
void Dstore_2(code_attribute *code) {
    if (DEBUG) printf("DSTORE_2\n");
}
void Dstore_3(code_attribute *code) {
    if (DEBUG) printf("DSTORE_3\n");
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
}
void Pop2(code_attribute *code) {
    if (DEBUG) printf("POP2\n");
}
void Dup(code_attribute *code) {
    if (DEBUG) printf("DUP\n");
}
void Dup_x1(code_attribute *code) {
    if (DEBUG) printf("DUP_X1\n");
}
void Dup_x2(code_attribute *code) {
    if (DEBUG) printf("DUP_X2\n");
}
void Dup2(code_attribute *code) {
    if (DEBUG) printf("DUP2\n");
}
void Dup2_x1(code_attribute *code) {
    if (DEBUG) printf("DUP2_X1\n");
}
void Dup2_x2(code_attribute *code) {
    if (DEBUG) printf("DUP2_X2\n");
}
void Swap(code_attribute *code) {
    if (DEBUG) printf("SWAP\n");
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
void Ladd(code_attribute *code) {}
void Fadd(code_attribute *code) {}
void Dadd(code_attribute *code) {}
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
}
void Lshl(code_attribute *code) {
    if (DEBUG) printf("LSHL\n");
}
void Ishr(code_attribute *code) {
    if (DEBUG) printf("ISHR\n");
}
void Lshr(code_attribute *code) {
    if (DEBUG) printf("LSHR\n");
}
void Iushr(code_attribute *code) {
    if (DEBUG) printf("IUSHR\n");
}
void Lushr(code_attribute *code) {
    if (DEBUG) printf("LUSHR\n");
}
void Iand(code_attribute *code) {
    if (DEBUG) printf("IAND\n");
}
void Land(code_attribute *code) {
    if (DEBUG) printf("LAND\n");
}
void Ior(code_attribute *code) {
    if (DEBUG) printf("IOR\n");
}
void Lor(code_attribute *code) {
    if (DEBUG) printf("LOR\n");
}
void Ixor(code_attribute *code) {
    if (DEBUG) printf("IXOR\n");
}
void Lxor(code_attribute *code) {
    if (DEBUG) printf("LXOR\n");
}
void Iinc(code_attribute *code) {
    if (DEBUG) printf("IINC\n");
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
}
void Fcmpl(code_attribute *code) {
    if (DEBUG) printf("FCMPL\n");
}
void Fcmpg(code_attribute *code) {
    if (DEBUG) printf("FCMPG\n");
}
void Dcmpl(code_attribute *code) {
    if (DEBUG) printf("DCMPL\n");
}
void Dcmpg(code_attribute *code) {
    if (DEBUG) printf("DCMPG\n");
}
void Ifeq(code_attribute *code) {
    if (DEBUG) printf("IFEQ\n");
}
void Ifne(code_attribute *code) {
    if (DEBUG) printf("IFNE\n");
}
void Iflt(code_attribute *code) {
    if (DEBUG) printf("IFLT\n");
}
void Ifge(code_attribute *code) {
    if (DEBUG) printf("IFGE\n");
}
void Ifgt(code_attribute *code) {
    if (DEBUG) printf("IFGT\n");
}
void Ifle(code_attribute *code) {
    if (DEBUG) printf("IFLE\n");
}
void If_icmpeq(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPEQ\n");
}
void If_icmpne(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPNE\n");
}
void If_icmplt(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPLT\n");
}
void If_icmpge(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPGE\n");
}
void If_icmpgt(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPGT\n");
}
void If_icmple(code_attribute *code) {
    if (DEBUG) printf("IF_ICMPLE\n");
}
void If_acmpeq(code_attribute *code) {
    if (DEBUG) printf("IF_ACMPEQ\n");
}
void If_acmpne(code_attribute *code) {
    if (DEBUG) printf("IF_ACMPNE\n");
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

    printf("CLASS NAME:  %s\n", class_name);
    printf("METHOD NAME: %s\n", name);
    printf("TYPE:        %s\n", type);

    // /* Inicia-se o procedimento para verificar se o metodo a ser chamado é um print f */
    int isPrint = !strcmp(class_name, "java/io/PrintStream") &&  
                (!strcmp(name, "println") || !strcmp(name, "print"));

    // printf("Print? : %d \n", isPrint);
    // if (isPrint) {

    //     if (method_deor != "()V") {
    //         Operand *op = this_frame->operand_stack.top();
    //         this_frame->operand_stack.pop();

    //         switch (op->tag) {
    //         case CONSTANT_String:
    //             std::cout << *(op->type_string);
    //             break;
    //         case CONSTANT_Integer:

    //             std::cout << (int32_t)op->type_int;
    //             break;
    //         case CONSTANT_Float:
    //             float converted_operand;
    //             memcpy(&converted_operand, &op->type_float, sizeof(float));

    //             std::cout << (float)converted_operand;
    //             break;
    //         case CONSTANT_Byte:
    //             std::cout << (int)op->type_byte;
    //             break;
    //         case CONSTANT_Char:
    //             std::cout << (char)op->type_char;
    //             break;
    //         case CONSTANT_Short:
    //             std::cout << (short)op->type_short;
    //             break;
    //         case CONSTANT_Boolean:
    //             std::cout << (bool)op->type_bool;
    //             break;
    //         case CONSTANT_Long:
    //             std::cout << (long)op->type_long;
    //             break;
    //         case CONSTANT_Empty:
    //             printf("null");
    //             break;
    //         case CONSTANT_Double: {
    //             double converted_operand;
    //             memcpy(&converted_operand, &op->type_double, sizeof(double));
    //             std::cout << (double)converted_operand;
    //             break;
    //         }
    //         case CONSTANT_Class: {
    //             Instance *class_instance  = op->class_instance;
    //             ClassLoader *class_loader = class_instance->classe;
    //             std::string class_name    = cpAttrAux.getUTF8(class_loader->getConstPool(), class_loader->getThisClass());
    //             std::cout << class_name << "@" << class_instance;
    //             break;
    //         }
    //         }

    //         if (method_name == "println") std::cout << std::endl;
    //     }
    // } else if (class_name == "java/lang/StringBuilder" && method_name == "append") {
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
    // } else {

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
    // }
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