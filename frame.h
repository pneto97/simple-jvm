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
    union {
        uint32_t bytes;
        union reference_type * ref;
    }data;

} operand;

typedef struct field{
    uint8_t *name;
    uint8_t *class_name;
    data_type type;
    operand hi;
    operand lo;
} field;

typedef struct class_loaded{
    uint8_t *name;
    class_structure *class_str;
    field *fields; // fields estáticos
    int field_count;

    struct class_loaded *next;
}class_loaded;

typedef struct class_instance{
    uint8_t *name;
    field *fields;  // fields da instância
    int field_count; // fields dinamicos
} class_instance;

typedef struct array{
    operand * high; // Utilizado só para dados cat2
    operand * low; // Utilizado sempre
    int arraysize;
} array;

typedef struct object_handler{
    class_loaded *class;
    class_instance *class_instance;
} object;

typedef union reference_type{
    object * objectref;
    array * arrayref;
    // interface_instance;
    // null;
} reference_type;

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




typedef struct method_area{
    class_loaded *first;
    class_loaded *last;
} method_area;




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

void pushMethodArea(class_loaded *lclass);

field * getField(class_loaded *lclass, char *name, char *type);

char * getSuperClassName(class_structure *jclass);

void insertDynamicFieldName(field *field, int field_index, object *obj);
void insertDynamicFieldType(field *field, int field_index, object *obj);

#endif