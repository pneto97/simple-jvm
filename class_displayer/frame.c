#include "frame.h"
#include <stdlib.h>
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

