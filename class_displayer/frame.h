#include "j8_class_structure.h"

typedef struct frame {
    local_variables *local_vars;
    cp_info *constant_pool;
    operand_stack *op_stack;
    uint32_t pc;

    frame *next;
} frame;

typedef struct jvm_stack
{
    frame *top;
    int frame_size;
} jvm_stack;

typedef struct local_variables {
    // ????????
} local_variables;

typedef struct operand_stack {
    operand_stack *next;
    // ??? byte value;
} operand_stack;

void pop_jvm_stack(jvm_stack *stack);
void push_jvm_stack(jvm_stack *stack, frame *new_frame);
void free_frame(...);