#ifndef GLOBAL_H
#define GLOBAL_H
#include "frame.h"

// Área de Métodos
method_area *GLOBAL_method_area;
// Pilha da JVM
jvm_stack *GLOBAL_jvm_stack;

/**
 * @brief Inicializa a Área de Métodos Global
 */
void initMethodArea();

/**
 * @brief Inicializa a Pilha da JVM Global
 */
void initJVMStack();

#endif