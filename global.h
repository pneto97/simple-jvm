#ifndef GLOBAL_H
#define GLOBAL_H
#include "frame.h"

// Área de Métodos
method_area *GLOBAL_method_area;
// Pilha da JVM
jvm_stack *GLOBAL_jvm_stack;

//code Global
code_attribute *GLOBAL_code;

//Path Global
char *GLOBAL_path;

/**
 * @brief Inicializa a Área de Métodos Global
 */
void initMethodArea();

/**
 * @brief Inicializa a Pilha da JVM Global
 */
void initJVMStack();

/**
 * @brief Libera a pilha de frames
 */
void freeJVMStack();

/**
 * @brief Libera a Área de métodos
 */
void freeMethodArea();

#endif