#include "frame.h"
#include <stdlib.h>
#include "global.h"
#include <string.h>
#include <stdio.h>
#include "class_structure.h"
#include "attribute.h"
#include "class_displayer.h"

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

void free_frame(frame *trash){
    return;
}

class_instance * createClassInstance(class_structure *jclass){
    uint16_t name_index_pos = jclass->constant_pool[jclass->this_class - 1].info.classInfo.name_index;
    uint8_t *name = (uint8_t *)jclass->constant_pool[name_index_pos - 1].info.utf8Info.bytes;

    class_instance *classInstance = (class_instance *) malloc(sizeof(classInstance));
    if(classInstance == NULL){
        printf("Erro na alocação de memória");
        exit(1);
    }

    classInstance->name = name;
    classInstance->class = jclass;
    classInstance->next = NULL;
    return classInstance;
}

class_instance * insertClassStructure(class_structure *jclass){
    class_instance *iclass = createClassInstance(jclass);
    if(GLOBAL_method_area->last != NULL){
        GLOBAL_method_area->last->next = iclass;
    }
    GLOBAL_method_area->last = iclass;
    iclass->next = NULL;

    return iclass;
}

uint16_t findMain(class_instance *iclass){

    class_structure* jclass = iclass->class;
    for(uint16_t i=0; i< jclass->methods_count; i++){
        uint16_t name_index = jclass->methods[i].name_index;
        char *name = (char *) jclass->constant_pool[name_index-1].info.utf8Info.bytes;

        if(!strcmp(name, "main"))
            return i;
    }
    printf("Main não encontrada\n");
    exit(2);
}

code_attribute findCode(class_instance *iclass, uint16_t method_index){
    class_structure* jclass = iclass->class;
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

    fr->code = code;
    fr->constant_pool = cp;
    fr->local_vars = (local_variable *)malloc(code->max_locals*sizeof(local_variable));
    fr->op_stack = (operand_stack *)malloc(sizeof(operand_stack));
    fr->pc = 0;

    push_jvm_stack(GLOBAL_jvm_stack, fr);

    return fr;
}

void execute(){
    frame *fr = GLOBAL_jvm_stack->top;

    code_attribute *code = fr->code;
    
    for(uint16_t i = 0; i< code->code_length; i++){
        //instruction(code.code[i]);
        printf("%d -> %x\n", i,code->code[i]);
    }
}