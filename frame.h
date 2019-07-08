/**
 * @file frame.h
 * @brief Arquivos com as estruturas de frames da JVM e pilha de operandos
 * 
 */

#ifndef FRAME_H
#define FRAME_H
#include "class_structure.h"
#include "data_type.h"

typedef struct operand
{
    cat_type cat;
    data_type type;
    uint32_t data;

} operand;

typedef struct operand_item
{
    operand op;
    struct operand_item *next;
} operand_item;


typedef struct operand_stack {
    operand_item *top;
    int size; //nao sabemos se vamos usar
} operand_stack;

typedef struct frame {
    operand *local_vars;
    int local_vars_size;
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

typedef uint32_t var_cat1;

typedef struct var_cat2{
    uint32_t high;
    uint32_t low;
}var_cat2;

typedef union data{
    var_cat1 datac1;
    var_cat2 datac2;
} data;

typedef struct field{
    uint8_t *name;
    uint8_t *class_name;
    data_type type;
    data data;
} field;

typedef struct class_loaded{
    uint8_t *name;
    class_structure *class_str;
    field *fields; // fields estáticos

    struct class_loaded *next;
}class_loaded;

typedef struct class_instance{
    uint8_t *name;
    class_loaded *class; 
    field *fields;  // fields da instância
} class_instance;

typedef struct method_area{
    class_loaded *first;
    class_loaded *last;
} method_area;

typedef union object{
    class_instance *class_inst;
    // interface_instance;
    // array array;
    // null;
} object;

typedef struct object_handler{
    class_loaded *class;
    class_instance *class_instance;
} objectref;

typedef struct array{
    uint16_t **data;
    int arraysize;
} array;

// typedef struct heap{
//     // LIsta/vetor/pilha de object
// }

// typedef struct interface_instance{
//     data;
//     fields;
//     class_structure *class;
// }

// MethodArea -> Classes

//classLoader(nome){
    // SE classe não existe nas Classes carregadas
        // busca o arquivo, cria class_structure
        // Instaciar os fields estáticos da classe 
        // retorna endereço da nova classe carregada
    // retorna endereço da nova classe carregada
//}

//newClassInstance(){
    // IF not ifClassLoaded()
        // class = classLoader()
 
    // class_inst = createClassInstance(class) <- Instacia os fields da classe na heap
    // 

    // Retornar class_inst
//}

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
operand pop_op_stack(operand_stack *stack);

/**
 * @brief Realiza o push da pilha de operandos
 * 
 * @param stack Refêrencia a pilha de operandos
 * @param new_frame Referência ao operando a ser inserido
 */
void push_op_stack(operand_stack *stack, operand new_operand);

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

class_loaded * findClassLoaded(uint8_t *name);

void getFieldType(field *field, int field_index, class_structure *jclass);

class_loaded * loadClass(char *path, char *name);

void getFieldName(field *field, int field_index, class_structure *jclass);

method_info * findMain(class_loaded *lclass);

code_attribute * findCode(class_loaded *lclass, method_info  *method);

frame * createFrame(code_attribute *code, cp_info *cp);

void execute(code_attribute *code);

void PrintLocalVar();

void PrintOpStack();

#endif