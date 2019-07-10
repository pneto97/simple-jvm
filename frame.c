#include "frame.h"
#include "attribute.h"
#include "class_displayer.h"
#include "class_reader.h"
#include "class_structure.h"
#include "global.h"
#include "instructions.h"
#include "opcode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

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

operand pop_op_stack(operand_stack *stack) {
    operand_item *aux = stack->top;
    stack->top        = stack->top->next;
    operand ret       = aux->op;
    free(aux);
    return ret;
}

void push_op_stack(operand_stack *stack, operand new_operand) {
    operand_item *op_item = (operand_item *)malloc(sizeof(operand_item));
    op_item->op           = new_operand;
    op_item->next         = stack->top;
    stack->top            = op_item;
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

class_loaded *findClassLoaded(uint8_t *name) {

    class_loaded *p = GLOBAL_method_area->first;
    while (p != NULL) {
        if (!strcmp((char *)name, (char *)p->name))
            return p;
        p = p->next;
    }

    // Se classe não foi encontrada
    return NULL;
}

void getFieldType(field *field, int field_index, class_structure *jclass) {
    uint16_t descriptor_index = jclass->fields[field_index].descriptor_index;
    uint8_t *utf8             = jclass->constant_pool[descriptor_index - 1].info.utf8Info.bytes;
    uint8_t *class_name       = NULL;
    field->class_name         = NULL;
    printf("utf8 - %c\n", utf8[0]);
    switch ((char)utf8[0]) {
    case 'B':
        field->type = BYTE_TYPE;
        break;
    case 'C':
        field->type = CHAR_TYPE;
        break;
    case 'D':
        field->type = DOUBLE_TYPE;
        break;
    case 'F':
        field->type = FLOAT_TYPE;
        break;
    case 'I':
        field->type = INT_TYPE;
        break;
    case 'J':
        field->type = LONG_TYPE;
        break;
    case 'L':
        class_name = (uint8_t *)calloc(strlen((char *)utf8) - 1, sizeof(uint8_t));
        if (class_name == NULL) {
            printf("Erro na alocação de memória");
            exit(1);
        }
        for (int i = 0, j = 0; i < strlen((char *)utf8) + 1; i++) {
            if (i != 0 && i != (strlen((char *)utf8) - 1)) {
                class_name[j] = utf8[i]; // LClass;\0 -> retira o L e o ;
                j++;
            }
        }
        field->class_name = class_name;
        field->type       = CLASS_TYPE;
        break;
    case 'S':
        field->type = SHORT_TYPE;
        break;
    case 'Z':
        field->type = BOOLEAN_TYPE;
        break;
    case '[':
        field->type = ARRAY_TYPE;
        break;
    default:
        field->type = 0;
        break;
    }
    printf("class name - %s\n", field->class_name);
}

class_loaded *loadClass(char *path, char *name) {

    char *complete_path = (char *)calloc((strlen(path) + strlen(name) + 7), sizeof(char));
    class_structure *jclass;
    FILE *class_file;
    class_loaded *lclass = NULL;

    // Concatenando strings
    strcat(complete_path, path);
    strcat(complete_path, name);
    strcat(complete_path, ".class");

    // Buscar o arquivo
    class_file = fopen(complete_path, "rb");
    if (class_file == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", complete_path);
        exit(1);
    }

    // Lê o .class
    jclass = readClassFile(class_file);
    checkConsistency(jclass, complete_path);

    // Cria o class_loaded
    lclass = (class_loaded *)malloc(sizeof(class_loaded));
    if (lclass == NULL) {
        printf("Erro na alocação de memória");
        exit(1);
    }

    lclass->class_str = jclass;
    lclass->name      = (uint8_t *)name;
    lclass->next      = NULL;

    int static_field_count = 0;
    int field_count        = jclass->fields_count;
    // printf("fields count: %d\n",field_count );
    // Obtendo quantidade de fields
    for (int i = 0; i < field_count; i++)
        if (jclass->fields->access_flags & ACC_STATIC)
            static_field_count++;

    for (int i = 0, j = 0; i < field_count; i++) {
        field *fields = (field *)calloc(static_field_count, sizeof(field));
        if (fields == NULL) {
            printf("Erro na alocação de memória");
            exit(1);
        }
        if (jclass->fields->access_flags & ACC_STATIC) {
            // printf("Entrou no if do getFieldNAme\n");
            getFieldType(&fields[j], i, jclass);
            getFieldName(&fields[j], i, jclass);
            lclass->field_count = static_field_count;
            j++;
        }
    }

    pushMethodArea(lclass);

    return lclass;
}

void getFieldName(field *field, int field_index, class_structure *jclass) {
    uint16_t name_index = jclass->fields[field_index].name_index;
    uint8_t *utf8       = jclass->constant_pool[name_index - 1].info.utf8Info.bytes;
    uint8_t *name       = (uint8_t *)calloc((strlen((char *)utf8) + 1), sizeof(uint8_t));
    strcpy((char *)name, (char *)utf8);
    field->name = name;
}

uint8_t *getClassName(class_structure *jclass) {
    uint16_t name_index = jclass->this_class;
    uint8_t *utf8       = jclass->constant_pool[name_index - 1].info.utf8Info.bytes;
    uint8_t *name       = (uint8_t *)calloc((strlen((char *)utf8) + 1), sizeof(uint8_t));
    strcpy((char *)name, (char *)utf8);
    return name;
}

method_info *findMain(class_loaded *lclass) {

    class_structure *jclass = lclass->class_str;
    for (uint16_t i = 0; i < jclass->methods_count; i++) {
        uint16_t name_index = jclass->methods[i].name_index;
        char *name          = (char *)jclass->constant_pool[name_index - 1].info.utf8Info.bytes;

        if (!strcmp(name, "main"))
            return &jclass->methods[i];
    }
    printf("Main não encontrada\n");
    exit(2);
}

code_attribute *findCode(class_loaded *lclass, method_info *method) {
    class_structure *jclass = lclass->class_str;
    attribute_info *attr    = method->attributes;

    for (uint16_t i = 0; i < jclass->attributes_count; i++) {
        uint16_t name_index = attr[i].attribute_name_index;
        char *name          = (char *)jclass->constant_pool[name_index - 1].info.utf8Info.bytes;

        if (!strcmp(name, "Code")) {
            return &attr[i].info.code_attribute;
        }
    }
    printf("Code não encontrado\n");
    exit(2);
}

frame *createFrame(code_attribute *code, cp_info *cp) {
    frame *fr = (frame *)malloc(sizeof(frame));

    fr->constant_pool   = cp;
    fr->local_vars_size = code->max_locals;
    fr->local_vars      = (operand *)calloc(code->max_locals, sizeof(operand));
    fr->op_stack        = (operand_stack *)malloc(sizeof(operand_stack));
    fr->op_stack->top   = NULL;
    fr->pc              = 0;

    push_jvm_stack(GLOBAL_jvm_stack, fr);

    return fr;
}

void free_frame(frame *f) {

    if (f != NULL) {
        if (f->local_vars != NULL)
            free(f->local_vars);

        if (f->op_stack != NULL)
            free(f->op_stack);

        free(f);
    }
}

void execute(code_attribute *code) {
    // frame *fr = GLOBAL_jvm_stack->top;

    // inst_vector[0xb2](code);

    while (GLOBAL_jvm_stack->top->pc < code->code_length) {
        // printf("pc: %d\n",GLOBAL_jvm_stack->top->pc);
        // printOpcode(code->code[GLOBAL_jvm_stack->top->pc]);
        // printf("\n");
        inst_vector[code->code[GLOBAL_jvm_stack->top->pc]](code);
        // printf("\n");
        if (GLOBAL_jvm_stack->top == NULL) break;
        if (DEBUG) {
            PrintLocalVar();
            PrintOpStack();
        }
        GLOBAL_jvm_stack->top->pc++;
    }

    // pop frame
}

void PrintLocalVar() {
    frame *fr = GLOBAL_jvm_stack->top;
    if (fr != NULL){
        printf("LOCAL VARS: \n");
        for (int i = 0; i < fr->local_vars_size; i++) {
            printf("[%d]->%x | ", i, fr->local_vars[i].data.bytes);
        }
        printf("\n");
    }
}

void PrintOpStack() {
    if (GLOBAL_jvm_stack->top != NULL){
        operand_item *op_item = GLOBAL_jvm_stack->top->op_stack->top;
        int i = 0;

        printf("OPERAND STACK: \n");
        while (op_item != NULL) {
            printf("[%d]->%x | ", i, op_item->op.data.bytes);
            op_item = op_item->next;
            i++;
        }
        printf("\n\n");
    }
}


void pushMethodArea(class_loaded *lclass){

    if (GLOBAL_method_area->last != NULL) {
        GLOBAL_method_area->last->next = lclass;
    } else {
        GLOBAL_method_area->last = lclass;
    }
    if(GLOBAL_method_area->first == NULL)
        GLOBAL_method_area->first = lclass;
        
    lclass->next = NULL;
}

field * getField(class_loaded *lclass, char *name, char *type){
    
    for (int i = 0; i < lclass->field_count; i++)
    {
        if(!strcmp((char*)lclass->fields[i].name, name)){
            return &lclass->fields[i];
        }
    }
    return NULL;
}

