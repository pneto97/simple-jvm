#include "global.h"
#include <stdlib.h>

void initMethodArea(){
    GLOBAL_method_area = (method_area *)malloc(sizeof(method_area));
    GLOBAL_method_area->first = NULL;
    GLOBAL_method_area->last = NULL;
}

void initJVMStack(){
    GLOBAL_jvm_stack = (jvm_stack *)malloc(sizeof(jvm_stack));

    GLOBAL_jvm_stack->top = NULL;
    GLOBAL_jvm_stack->frame_size = 0;
}

void freeJVMStack(){
    if(GLOBAL_jvm_stack != NULL)
        free(GLOBAL_jvm_stack);
}

void freeMethodArea(){
    if(GLOBAL_method_area != NULL)
        free(GLOBAL_method_area);
}