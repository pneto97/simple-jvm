/**
 * @file frame.h
 * @brief Arquivos com as estruturas de frames da JVM e pilha de operandos
 * 
 */

#ifndef FRAME_H
#define FRAME_H
#include "class_structure.h"
#include "data_type.h"
/**
 * @brief Estrutura que representa um dado do tipo operand
 * Contêm o tipo de dado, sua categoria e uma union com uma referencia ou um dado.
 */
typedef struct operand
{   
    cat_type cat;
    data_type type;
    union {
        uint32_t bytes;
        union reference_type * ref;
    }data;

} operand;
/**
 * @brief Estrutura que representa um dado do tipo field
 * Possui um ponteiro para seu nome, um para o nome da classe um tipo de dado e operandos high e low.
 * 
 */
typedef struct field{
    uint8_t *name;
    uint8_t *class_name;
    data_type type;
    operand hi;
    operand lo;
} field;

/**
 * @brief Estrutura que representa um dado de classe carregada
 * Possui Ponteiro para o nome da classe, a estrutura da classe, ponteiro para os fields estáticos da classe e a contagem desses fields.
 * Além disso, possui ponteiro para a próxima classe. 
 */
typedef struct class_loaded{
    uint8_t *name;
    class_structure *class_str;
    field *fields; // fields estáticos
    int field_count;

    struct class_loaded *next;
}class_loaded;

/**
 * @brief Estrutura que representa uma classe instanciada
 * Possui ponteiro para o nome da classe, ponteiro para seus fields de instância e contagem para dos fields.
 */
typedef struct class_instance{
    uint8_t *name;
    field *fields;  // fields da instância
    int field_count; // fields dinamicos
} class_instance;

/**
 * @brief Estrutura que representa uma array
 * Possui ponteiro para operand high (utilizado em dados cat2) e ponteiro para operand low (sempre utilizado).
 */
typedef struct array{
    operand * high; // Utilizado só para dados cat2
    operand * low; // Utilizado sempre
    int arraysize;
} array;

/**
 * @brief Estrutura que representa um object handler
 * Possui ponteiro para class_loaded e ponteiro para class_instance.
 */
typedef struct object_handler{
    class_loaded *class;
    class_instance *class_instance;
} object;

/**
 * @brief Estrutura que representa um tipo de referência
 * Possui ponteiro para object (caso seja referência para objeto) e para array (caso seja referência para array).
 */
typedef union reference_type{
    object * objectref;
    array * arrayref;
    // interface_instance;
    // null;
} reference_type;

/**
 * @brief Estrutura que representa um item da estrutura operand
 * Possui ponteiro para o próximo item e um operand.
 */
typedef struct operand_item
{
    operand op;
    struct operand_item *next;
} operand_item;

/**
 * @brief Estrutura que representa um item da pilha de operando
 * Possui ponteiro para um item operando que representa o topo da pilha.
 */
typedef struct operand_stack {
    operand_item *top;
    int size; //nao sabemos se vamos usar
} operand_stack;

/**
 * @brief Estrutura que representa um frame
 * Possui ponteiro para operando representando a array de variáveis locais.
 * Um inteiro com o tamanho da array de variáveis locais.
 * Ponteiro para o constant pool.
 * Ponteiro para a pilha de operandos.
 * Inteiro que representa o pc.
 * Estrutura para o próximo frame.
 */
typedef struct frame {
    operand *local_vars;
    int local_vars_size;
    cp_info *constant_pool;
    operand_stack *op_stack;
    uint32_t pc;
    struct frame *next;
} frame;
/**
 * @brief Estrutura que representa a pilha da jvm
 * Ponteiro para o frame do topo.
 * Inteiro com o tamanho de cada frame
 */
typedef struct jvm_stack
{
    frame *top;
    int frame_size;
} jvm_stack;

/**
 * @brief Estrutura que representa a area de metodos
 * Possui ponteiro para a primeira classe carregada.
 * Possui ponteiro para a última classe carregada
 */ 
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

/**
 * @brief Adquire o tipo do field
 * 
 * @param field Ponteiro para field
 * @param field_index Index para constant pool
 * @param jclass ponteiro para estrutura da classe
 */
void getFieldType(field *field, int field_index, class_structure *jclass);

/**
 * @brief Carrega a classe
 * 
 * @param path Diretório para a classe
 * @param name Nome da classe
 * @return class_loaded* 
 */
class_loaded * loadClass(char *path, char *name);

/**
 * @brief Adquire o nome do field
 * 
 * @param field Ponteiro para o field
 * @param field_index Index do field para o cp
 * @param jclass Estrutura do .class
 */
void getFieldName(field *field, int field_index, class_structure *jclass);

/**
 * @brief Realiza a busca pelo metodo main
 * 
 * @param lclass 
 * @return method_info* 
 */
method_info * findMain(class_loaded *lclass);

/**
 * @brief Realiza a busca pelo atributo do tipo code
 * 
 * @param lclass Ponteiro para classe carregada
 * @param method Ponteiro para o método 
 * @return code_attribute* Retorna o code encontrado 
 */
code_attribute * findCode(class_loaded *lclass, method_info  *method);

/**
 * @brief Cria um frame
 * 
 * @param code Um ponteiro para code 
 * @param cp Um ponteiro para constant pool
 * @return frame* Retorna ponteiro para o frame criado
 */
frame * createFrame(code_attribute *code, cp_info *cp);

/**
 * @brief Executa as instruções contidas no Code
 * 
 * @param code Ponteiro para o atributo code
 */
void execute(code_attribute *code);

/**
 * @brief Realiza o print da array de variáveis locais (debug)
 * 
 */
void PrintLocalVar();

/**
 * @brief Realiza o print da pilha de operandos (debug)
 * 
 */
void PrintOpStack();

/**
 * @brief Coloca uma classe na área de métodos
 * 
 * @param lclass Ponteiro para a classe carregada a ser inserida na área de métodos
 */
void pushMethodArea(class_loaded *lclass);

/**
 * @brief Adquire os Field de uma classe
 * 
 * @param lclass Ponteiro para uma classe carregada 
 * @param name String com o nome
 * @param type Tipo de field
 * @return field* Retorna um ponteiro para o field 
 */
field * getField(class_loaded *lclass, char *name, char *type);

/**
 * @brief Adquire o nome da super classe
 * 
 * @param jclass Ponteiro para a estrutura da classe
 * @return char* Retorna o nome da super classe
 */
char * getSuperClassName(class_structure *jclass);

/**
 * @brief Insere um nome para fields dinâmicos
 * 
 * @param field Ponteiro para field
 * @param field_index Index para o pool de constantes
 * @param obj Ponteiro para o object
 */
void insertDynamicFieldName(field *field, int field_index, object *obj);
/**
 * @brief Insere um tipo para fields dinâmicos
 * 
 * @param field Ponteiro para field
 * @param field_index Index para o pool de constantes
 * @param obj Ponteiro para o object
 */
void insertDynamicFieldType(field *field, int field_index, object *obj);

data_type getDataType(char *utf8);

field * getStaticField(class_instance *iclass, char *name, char *type);

method_info *findMethod(class_loaded *lclass, char *method_name, char *type);

#endif