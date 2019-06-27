#include "j8_class_structure.h"
#include "data_type.h"
/**
 * @file
 * @brief Arquivos com as estruturas de frames da JVM
 * 
 */


typedef struct local_variables {
    //data_type *var_type;
    // ????????
} local_variables;

typedef struct operand
{
    cat_type cat;
    data_type type;
    uint32_t data;
    struct operand *next;
} operand;

typedef struct operand_stack {
    operand *top;
    int size; //nao sabemos se vamos usar
} operand_stack;

typedef struct frame {
    local_variables *local_vars;
    cp_info *constant_pool;
    operand_stack *op_stack;
    uint32_t pc;

    struct frame *next;
} frame;

typedef struct jvm_stack
{
    frame *top;
    int frame_size;
} jvm_stack;

/**
 * @brief Realiza o pop na pilha da JVM
 * 
 * @param stack Ponteiro para a pliha da JVM
 */
void pop_jvm_stack(jvm_stack *stack);
void push_jvm_stack(jvm_stack *stack, frame *new_frame);
void pop_op_stack(operand_stack *stack);
void push_op_stack(operand_stack *stack, operand *new_frame);
void free_frame(frame *frame_trash);