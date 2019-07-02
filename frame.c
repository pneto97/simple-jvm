#include "frame.h"
#include <stdlib.h>
#include "global.h"
#include <string.h>
#include <stdio.h>
#include "class_structure.h"
#include "attribute.h"
#include "class_displayer.h"
#include "class_reader.h"

void pop_jvm_stack(jvm_stack *stack) {
    frame *aux = stack->top;
    stack->top = stack->top->next;
    stack->frame_size--;
    free_frame(aux);
}

void push_jvm_stack(jvm_stack *stack, frame *new_frame) {
    new_frame->next = stack->top;
    stack->top      = new_frame;
    stack->frame_size++;
}

void pop_op_stack(operand_stack *stack) {
    operand *aux = stack->top;
    stack->top = stack->top->next;
    //stack->--;
    free(aux);
}

void push_op_stack(operand_stack *stack, operand *new_operand) {
    new_operand->next = stack->top;
    stack->top      = new_operand;
    //stack->++;
}

// void free_frame(frame *trash){
//     return;
// }

//classLoader(nome){
    // SE classe não existe nas Classes carregadas
        // busca o arquivo, cria class_structure
        // Instaciar os fields estáticos da classe 
        // retorna endereço da nova classe carregada
    // retorna endereço da nova classe carregada
//}

class_loaded * findClassLoaded(uint8_t *name){

    class_loaded *p = GLOBAL_method_area->first;
    while(p != NULL)
    {
        if(!strcmp((char  *)name, (char *)p->name))
            return p;
        p = p->next;
    }

    // Se classe não foi encontrada
    return NULL;
}

data_type getFieldType(int field_index, class_structure *jclass){
    uint16_t descriptor_index = jclass->fields[field_index].descriptor_index;
    uint8_t  *utf8 = jclass->constant_pool[descriptor_index - 1].info.utf8Info.bytes;
    uint8_t *class_name = NULL;
    switch((char) utf8[0]){
        case 'B':
            return BYTE_TYPE;
        case 'C':
            return CHAR_TYPE;
        case 'D':
            return DOUBLE_TYPE;
        case 'F':
            return FLOAT_TYPE;
        case 'I':
            return INT_TYPE;
        case 'J':
            return LONG_TYPE;
        case 'L':
            class_name = (uint8_t *)calloc(strlen((char *)utf8) - 1 ,sizeof(uint8_t));
            if(class_name == NULL){
                printf("Erro na alocação de memória");
                exit(1);
            }
            for (int i = 0, j = 0; i < strlen((char *)utf8) + 1; i++){
                if(i != 0 && i != (strlen((char *)utf8) - 1)){
                    class_name[j] = utf8[i];    // LClass;\0 -> retira o L e o ;
                    j++;
                }
            }
            return CLASS_TYPE;
        case 'S':
            return SHORT_TYPE;
        case 'Z':
            return BOOLEAN_TYPE;
        case '[':
            return ARRAY_TYPE;
        default:
            return 0;
    }
}

class_loaded * createClassLoaded(char *path, char *name){

    char *complete_path = (char *)calloc((strlen(path)+strlen(name) + 1), sizeof(char)); 
    class_structure *jclass;
    FILE *class_file;
    class_loaded *lclass = (class_loaded *)malloc(sizeof(class_loaded));

    // Concatenando strings
    strcat(complete_path, path);
    strcat(complete_path, name);

    // Buscar o arquivo
    class_file = fopen(complete_path, "rb");
    if (class_file == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", complete_path);
        exit(1);
    }

    // Lê o .class
    jclass = readClassFile(class_file);
    checkConsistency(jclass, complete_path);

    // Cria o class_loader
    class_loaded *iclass = (class_loaded *) malloc(sizeof(class_loaded));
    if(iclass == NULL){
        printf("Erro na alocação de memória");
        exit(1);
    }

    lclass->class_str = jclass;
    lclass->name = (uint8_t *)name;
    lclass->next = NULL;

    int static_field_count = 0;
    int field_count = jclass->fields_count;

    // Obtendo quantidade de fields
    for (int i = 0; i < field_count; i++)
        if(jclass->fields->access_flags & ACC_STATIC)
            static_field_count++;

    for (int i = 0,j = 0; i < field_count; i++)
    {
        field *fields = (field *)calloc(static_field_count,sizeof(field));
        if(fields == NULL){
            printf("Erro na alocação de memória");
            exit(1);
        }
        if(jclass->fields->access_flags & ACC_STATIC){
            fields[j].type = getFieldType(i, jclass);
            fields[j].name = getFieldName(i, jclass);
        }
        j++;
    }

    return NULL;
}

uint8_t * getFieldName(){
    return 0;
}

class_loaded * loadClass(class_structure *jclass){
    // class_instance *lclass = createClassLoaded(jclass);
    // if(GLOBAL_method_area->last != NULL){
    //     GLOBAL_method_area->last->next = iclass;
    // }
    // GLOBAL_method_area->last = iclass;
    // iclass->next = NULL;

    // return lclass;

    return NULL;
}

uint16_t findMain(class_loaded *lclass){

    class_structure* jclass = lclass->class_str;
    for(uint16_t i=0; i< jclass->methods_count; i++){
        uint16_t name_index = jclass->methods[i].name_index;
        char *name = (char *) jclass->constant_pool[name_index-1].info.utf8Info.bytes;

        if(!strcmp(name, "main"))
            return i;
    }
    printf("Main não encontrada\n");
    exit(2);
}

code_attribute findCode(class_loaded *lclass, uint16_t method_index){
    class_structure* jclass = lclass->class_str;
    attribute_info *attr = jclass->methods[method_index].attributes;
    uint16_t attr_count = jclass->methods[method_index].attributes_count;

    for(uint16_t i=0; i< jclass->attributes_count; i++){
        uint16_t name_index = attr[i].attribute_name_index;
        char *name = (char *) jclass->constant_pool[name_index-1].info.utf8Info.bytes;

        if(!strcmp(name, "Code")){
            return attr[i].info.code_attribute;
        }
    }
    printf("Code não encontrado\n");
    exit(2);
}

frame * createFrame(code_attribute *code, cp_info *cp){
    frame *fr = (frame *)malloc(sizeof(frame));

    fr->constant_pool = cp;
    fr->local_vars = (local_variable *)malloc(code->max_locals*sizeof(local_variable));
    fr->op_stack = (operand_stack *)malloc(sizeof(operand_stack));
    fr->pc = 0;

    push_jvm_stack(GLOBAL_jvm_stack, fr);

    return fr;
}

void free_frame(frame* f){

    if(f != NULL){
        if(f->local_vars != NULL)
            free(f->local_vars);

        if(f->op_stack != NULL)
            free(f->op_stack);
        
        free(f);
    }
}

void execute(){
    frame *fr = GLOBAL_jvm_stack->top;
    
    // for(uint16_t i = 0; i< code->code_length; i++){
    //     //instruction(code.code[i]);
    //     printf("%d -> %x\n", i,code->code[i]);
    // }
}