/**
 * @file class_reader.h
 * @brief Funções usadas para leitura do .class, a ideia é que tudo relacionado a leitura dos campos fique aqui e saia da main
 * 
 */

#include <stdio.h>

#ifndef H_CLASS_STRUCTURE
#define H_CLASS_STRUCTURE
#include "class_structure.h"
#endif

/**
 * @brief Leitura do magic number, minor e major version
 * 
 * @param jclass Ponteiro para a estrutura do .class
 * @param class_file Arquivo do .class
 */
void readInitialParams(class_structure *jclass, FILE *class_file);

/**
 * @brief Leitura do constant pool se o arquivo estiver na posicao correta
 * 
 * @param class_file Arquivo do .class
 * @param jclass Ponteiro para a estrutura do .class
 */
void readConstantPool(FILE *class_file, class_structure *jclass);

/**
 * @brief Leitura das interfaces se o arquivo estiver na posição correta
 * 
 * @param class_file Arquivo do .class
 * @param jclass Ponteiro para a estrutura do .class
 */
void readInterfaces(FILE *class_file, class_structure *jclass);

/**
 * @brief Leitura dos metodos se o arquivo estiver na posicao correta
 * 
 * @param class_file Arquivo do .class
 * @param jclass Ponteiro para a estrutura do .class
 */
void readMethods(FILE *class_file, class_structure *jclass);

/**
 * @brief Leitura dos campos se o arquivo estiver na posicao correta
 * 
 * @param class_file Arquivo do .class
 * @param jclass Ponteiro para a estrutura do .class
 */
void readFields(FILE *class_file, class_structure *jclass);

/**
 * @brief Leitura dos atributos gerais se o arquivo estiver na posicao correta
 * 
 * @param class_file Arquivo do .class
 * @param attribute_info Ponteiro para a estrutura do atributo
 * @param attribute_count Inteiro de 16 bits com o número de atributos
 * @param jclass Ponteiro para a estrutura do .class
 */

void readAttributes(FILE *class_file, attribute_info *attribute_info, uint16_t attribute_count, class_structure *jclass);

/**
 * @brief Leitura dos attributos da classe se o arquivo estiver na posicao correta
 * 
 * @param class_file Arquivo do .class
 * @param jclass Ponteiro para a estrutura do .class
 */
void readClassAttributes(FILE *class_file, class_structure *jclass);

/**
 * @brief Desaloca a estrutura da classe incluindo o utf8 do constant pool
 * 
 * @param jclass Ponteiro para a estrutura do .class
 */
void freeClass(class_structure *jclass);

/**
 * @brief Desaloca attributos da estrutura da classe
 * 
 * @param attr_info Ponteiro para a estrutura attributes
 * @param attribute_count Inteiro de 16 bits com o numero de atributos
 * @param jclass Ponteiro para a estrutura do .class
 */
void freeAttributes(attribute_info *attr_info, uint16_t attribute_count, class_structure *jclass);

/**
 * @brief Dunção que chama todos os outros readers
 * 
 * @param class_file Arquivo do .class
 * @return class_structure* Retorna uma estrutura do .class
 */
class_structure *readClassFile(FILE *class_file);

/**
 * @brief Checa consistencia do arquivo .class
 * 
 * @param jclass Ponteiro para a estrutura do .class
 * @param file String com o nome do arquivo
 */
void checkConsistency(class_structure *jclass, char *file);

/**
 * @brief Formata o argv e retorna apenas o nome do arquivo
 * 
 * @param sentence String inserida no argv
 * @return char* String com o nome do arquivo 
 */
char *getFilename(char *sentence);

/**
 * @brief Realiza a checagem para confirmar se é um class file
 * 
 * @param jclass Ponteiro para a estrutura do .class
 * @return int Inteiro 0 ou 1
 */
int isClassFile(class_structure *jclass);