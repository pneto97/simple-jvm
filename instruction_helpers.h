/**
 * @file instruction_helpers.h
 * @brief Arquivo contendo funcionalidades que auxiliam na realização de algumas instruções
 * 
 */
#ifndef INSTRUCTION_HELPERS_H
#define INSTRUCTION_HELPERS_H
#include <stdint.h>
#include "frame.h"

/**
 * @brief Pegar a class em Utf8
 * 
 * @param index Inteiro de 16 bits com o índice para o constant pool 
 * @return char* Retorna um ponteiro para char contendo o nome da class
 */
char *getUtf8Class(uint16_t index);
/**
 * @brief Pegar o nome em Utf8
 * 
 * @param index Inteiro de 16 bits com o índice para o constant pool 
 * @return char* Retorna um ponteiro para char contendo o nome requerido
 */
char *getUtf8Name(uint16_t index);
/**
 * @brief Pegar o tipo em Utf8
 * 
 * @param index Inteiro de 16 bits com o índice para o constant pool 
 * @return char* Retorna um ponteiro para char contendo o tipo requerido
 */
char *getUtf8Type(uint16_t index);
/**
 * @brief Pegar a referencia em Utf8
 * 
 * @param index Inteiro de 16 bits com o índice para o constant pool 
 * @return char* Retorna um ponteiro para char contendo a referência requerido
 */
char *getUtf8Ref(uint16_t index);
/**
 * @brief Realiza a montagem de um double a partir de dois inteiros de 32 bits
 * 
 * @param high Primeiros 32 bits do double
 * @param low Últimos 32 bits do double
 * @return double de 64 bits retornados
 */
double makeDouble(uint32_t high, uint32_t low);
/**
 * @brief Realiza a montagem de um double a partir de um inteiro de 32 bits
 * 
 * @param bytes Inteiro de 32 bits 
 * @return float valor retornado em ponto flutuante
 */
float makeFloat(uint32_t bytes);
/**
 * @brief Realiza a montagem de um long a partir de dois inteiros de 32 bits
 * 
 * @param high Primeiros 32 bits do double
 * @param low Últimos 32 bits do double
 * @return double de 64 bits retornados
 */
long makeLong(uint32_t high, uint32_t low);
/**
 * @brief Realiza a montagem de um objeto a partir de um class loaded
 * 
 * @param lclass Ponteiro para a estrutura class_loaded que possui os campos necessários
 * @return object* Objeto montado é retornado
 */
object* buildObject(class_loaded *lclass);
/**
 * @brief Realiza a conversão de dobule para Uint64_t
 * 
 * @param number Valor de paramêtro em double
 * @return uint64_t Valor em inteiro de 64 bits retornado
 */
uint64_t doubleToUint64(double number);
/**
 * @brief Realiza conversão de long para Uint64_t
 * 
 * @param number Valor de paramêtro em long
 * @return uint64_t Valor em inteiro de 64 bits retornado
 */
uint64_t longToUint64(long number);
/**
 * @brief Realiza conversão de float para Uint32_t
 * 
 * @param bytes Valor de paramêtro em float
 * @return uint32_t Valor em inteiro de 32 bits retornado
 */
uint32_t floatToUint32(float bytes);
/**
 * @brief Realiza um switch case para verificar qual o tipo da variável
 * 
 * @param atype Inteiro com o valor já definido para cada tipo
 * @return data_type Tipo da variável já definido
 */
data_type PrimitiveType(int8_t atype);
int countArgs(char * type);

#endif