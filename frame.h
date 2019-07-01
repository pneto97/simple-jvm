/**
 * @file frame.h
 * @brief Arquivos com as estruturas de frames da JVM e pilha de operandos
 * 
 */

#ifndef FRAME_H
#define FRAME_H
#include "class_structure.h"
#include "data_type.h"

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
    code_attribute *code;

    struct frame *next;
} frame;

typedef struct jvm_stack
{
    frame *top;
    int frame_size;
} jvm_stack;

typedef struct class_instance{
    uint8_t *name;
    class_structure *class;
    struct class_instance *next;
} class_instance;

typedef struct method_area{
    class_instance *first;
    class_instance *last;
} method_area;

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

/**
 * @brief Cria uma instância de uma class
 * 
 * @param jclass Ponteiro para a estrutura da classe
 * @return class_instance* Retorna ponteiro para a instância da classe
 */
class_instance * createClassInstance(class_structure *jclass);

/**
 * @brief Insere na Área de Métodos Global uma estrutura de classe
 * 
 * @param iclass Instância de uma classe
 * @return class_instance* Retorna ponteiro para a instância da classe
 */
class_instance * insertClassStructure(class_structure *iclass);

uint16_t findMain(class_instance *iclass);

code_attribute findCode(class_instance *iclass, uint16_t method_index);

frame * createFrame(code_attribute *code, cp_info *cp);

void execute();

#endif