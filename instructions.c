#include <stdio.h>
#include <stdint.h>
#include "frame.h"
#include "global.h"

void Nop         (void){
    printf("NOP\n");
}
void Aconst_null (void){}
void Iconst_m1   (void){}
void Iconst_0    (void){}
void Iconst_1    (void){}
void Iconst_2    (void){}
void Iconst_3    (void){}
void Iconst_4    (void){}
void Iconst_5    (void){}
void Lconst_0    (void){}
void Lconst_1    (void){}
void Fconst_0    (void){}
void Fconst_1    (void){}
void Fconst_2    (void){}
void Dconst_0    (void){}
void Dconst_1    (void){}

void Bipush (void){
    int8_t byte;
    int32_t extended;
    operand op_variable;

    extended = (int32_t)byte;
    op_variable.data = (uint32_t)extended;
    op_variable.cat = UNIQUE;

    push_op_stack(GLOBAL_jvm_stack->top->op_stack, op_variable);

}

void Sipush      (void){}
void Ldc         (void){}
void Ldc_w       (void){}
void Ldc2_w      (void){}
void Iload  (void){
    uint8_t index = GLOBAL_code->code[GLOBAL_jvm_stack->top->pc++];
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Lload  (void){}
void Fload  (void){}
void Dload  (void){}
void Aload  (void){}
void Iload_0(void){
    uint8_t index = 0;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Iload_1(void){
    uint8_t index = 1;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Iload_2(void){
    uint8_t index = 2;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Iload_3(void){
    uint8_t index = 3;
    operand value = GLOBAL_jvm_stack->top->local_vars[index];
    push_op_stack(GLOBAL_jvm_stack->top->op_stack, value);
}
void Lload_0(void){}
void Lload_1(void){}
void Lload_2(void){}
void Lload_3(void){}
void Fload_0(void){}
void Fload_1(void){}
void Fload_2(void){}
void Fload_3(void){}
void Dload_0(void){}
void Dload_1(void){}
void Dload_2(void){}
void Dload_3(void){}
void Aload_0(void){}
void Aload_1(void){}
void Aload_2(void){}
void Aload_3(void){}
void Iaload (void){}
void Laload (void){}
void Faload (void){}
void Daload (void){}
void Aaload (void){}
void Baload (void){}
void Caload (void){}
void Saload (void){}

void Istore (void){
    uint8_t index = GLOBAL_code->code[GLOBAL_jvm_stack->top->pc++];
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Lstore   (void){}
void Fstore   (void){}
void Dstore   (void){}
void Astore   (void){}

void Istore_0 (void){
    uint8_t index = 0;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}

void Istore_1 (void){
    uint8_t index = 1;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Istore_2 (void){
    uint8_t index = 2;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Istore_3 (void){
    uint8_t index = 3;
    operand value = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    GLOBAL_jvm_stack->top->local_vars[index] = value;
}
void Lstore_0 (void){}
void Lstore_1 (void){}
void Lstore_2 (void){}
void Lstore_3 (void){}
void Fstore_0 (void){}
void Fstore_1 (void){}
void Fstore_2 (void){}
void Fstore_3 (void){}
void Dstore_0 (void){}
void Dstore_1 (void){}
void Dstore_2 (void){}
void Dstore_3 (void){}
void Astore_0 (void){}
void Astore_1 (void){}
void Astore_2 (void){}
void Astore_3 (void){}
void Iastore  (void){}
void Lastore  (void){}
void Fastore  (void){}
void Dastore  (void){}
void Aastore  (void){}
void Bastore  (void){}
void Castore  (void){}
void Sastore  (void){}
void Pop      (void){}
void Pop2     (void){}
void Dup      (void){}
void Dup_x1   (void){}
void Dup_x2   (void){}
void Dup2     (void){}
void Dup2_x1  (void){}
void Dup2_x2  (void){}
void Swap     (void){}
void Iadd   (void){
    operand op;
    operand value1 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);
    operand value2 = pop_op_stack(GLOBAL_jvm_stack->top->op_stack);

    int32_t result = (int32_t)value1.data + (int32_t)value2.data;
    op.data = result;
    op.cat = UNIQUE;
    op.type = INT_TYPE;
    push_op_stack(GLOBAL_jvm_stack->top->op_stack,op);
} 
void Ladd   (void){} 
void Fadd   (void){} 
void Dadd   (void){} 
void Isub   (void){} 
void Lsub   (void){} 
void Fsub   (void){} 
void Dsub   (void){} 
void Imul   (void){} 
void Lmul   (void){} 
void Fmul   (void){} 
void Dmul   (void){} 
void Idiv   (void){} 
void Ldiv   (void){} 
void Fdiv   (void){} 
void Ddiv   (void){} 
void Irem   (void){} 
void Lrem   (void){} 
void Frem   (void){} 
void Drem   (void){} 
void Ineg   (void){} 
void Lneg   (void){} 
void Fneg   (void){} 
void Dneg   (void){} 
void Ishl   (void){} 
void Lshl   (void){} 
void Ishr   (void){} 
void Lshr   (void){} 
void Iushr   (void){}
void Lushr   (void){}
void Iand   (void){} 
void Land   (void){} 
void Ior    (void){} 
void Lor    (void){} 
void Ixor   (void){} 
void Lxor   (void){} 
void Iinc   (void){}
void I2l (void){}
void I2f (void){}
void I2d (void){}
void L2i (void){}
void L2f (void){}
void L2d (void){}
void F2i (void){}
void F2l (void){}
void F2d (void){}
void D2i (void){}
void D2l (void){}
void D2f (void){}
void I2b (void){}
void I2c (void){}
void I2s (void){}
void Lcmp     (void){}
void Fcmpl    (void){}
void Fcmpg    (void){}
void Dcmpl    (void){}
void Dcmpg    (void){}
void Ifeq     (void){}
void Ifne     (void){}
void Iflt     (void){}
void Ifge     (void){}
void Ifgt     (void){}
void Ifle     (void){}
void If_icmpeq(void){}
void If_icmpne(void){}
void If_icmplt(void){}
void If_icmpge(void){}
void If_icmpgt(void){}
void If_icmple(void){}
void If_acmpeq(void){}
void If_acmpne(void){}
void GoTo        (void){}
void Jsr         (void){}
void Ret         (void){}
void Tableswitch (void){}
void Lookupswitch(void){}
void Ireturn     (void){}
void Lreturn     (void){}
void Freturn     (void){}
void Dreturn     (void){}
void Areturn     (void){}
void Return      (void){}
void Getstatic      (void){}
void Putstatic      (void){}
void Getfield       (void){}
void Putfield       (void){}
void Invokevirtual  (void){}
void Invokespecial  (void){}
void Invokestatic   (void){}
void Invokeinterface(void){}
void Invokedynamic  (void){}
void New            (void){}
void Newarray       (void){}
void Anewarray(void){}
void Arraylength(void){}
void Athrow(void){}
void Checkcast(void){}
void Instanceof(void){}
void Monitorenter   (void){}
void Monitorexit(void){}
void Wide            (void){}
void Multianewarray(void){}
void Ifnull(void){}
void Ifnonnull(void){}
void Goto_w(void){}
void Jsr_w(void){}
void Breakpoint(void){}
void Impdep1(void){}
void Impdep2(void){}