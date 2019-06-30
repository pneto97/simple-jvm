#include "class_structure.h"
#include "data_type.h"
/**
 * @file frame.h
 * @brief Arquivos com as estruturas de frames da JVM e pilha de operandos
 * 
 */

typedef struct local_variable {
    data_type *type;
    uint32_t data;
} local_variable;

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
    local_variable *local_vars;
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

/**
 * @brief Realiza o push na pilha da JVM
 * 
 * @param stack Referência a pilha da JVM
 * @param new_frame Referência ao frame a ser inserido na pilha
 */
void push_jvm_stack(jvm_stack *stack, frame *new_frame);

/**
 * @brief Realiza o pop na pilha de operandos
 * 
 * @param stack Referência a pilha de operandos
 */
void pop_op_stack(operand_stack *stack);

/**
 * @brief Realiza o push da pilha de operandos
 * 
 * @param stack Refêrencia a pilha de operandos
 * @param new_frame Referência ao operando a ser inserido
 */
void push_op_stack(operand_stack *stack, operand *new_operand);

/**
 * @brief Libera memória de um frame
 * 
 * @param frame_trash Frame a ser excluído
 */
void free_frame(frame *frame_trash);