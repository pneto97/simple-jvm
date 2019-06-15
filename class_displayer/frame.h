#include "j8_class_structure.h"

typedef struct frame {
    local_variables *local_vars;
    cp_info *constant_pool;
    operand_stack *op_stack;
    uint32_t pc;
} frame;

typedef struct local_variables {
    // ????????
} local_variables;

typedef struct operand_stack {
    operand_stack *next;
    // ??? byte value;
} operand_stack;