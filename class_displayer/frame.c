#include "frame.h"

void pop_jvm_stack(jvm_stack *stack) {
    frame *aux = stack->top;
    stack->top = stack->top->next;
    stack->frame_size--;
    free_frame(aux);
}

void push_jvm_stack(jvm_stack *stack, frame *new_frame) {
    new_frame->next = stack;
    stack->top      = new_frame;
    stack->frame_size++;
}
