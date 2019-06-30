//j8_class_displayer.h

/**
 * @file j8_class_displayer.h
 * @brief Recursos usados para fazer o display dos dados lidos do .class
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef H_J8_CLASS_STRUCTURE
#define H_J8_CLASS_STRUCTURE
#include "j8_class_structure.h"
#endif
#include "j8_access_flags.h"

/**
 * @brief Converte o numero da tag do constant pool para uma string com o nome correspondente
 * 
 * @param tag Valor em 8bits da tag
 * @param tagType Ponteiro para string a ser armazenado o nome
 */
void cpTagToString(uint8_t tag, char *tagType);

/**
 * @brief Imprime os valores do magic number, minor e major version
 * 
 * @param jclass Ponteiro para a estrutura do .class
 */
void printInitialParams(class_structure *jclass);

/**
 * @brief Imprime o pool de constantes
 * 
 * @param jclass Ponteiro para a estrutura do .class
 */
void printConstantPool(class_structure *jclass);


/**
 * @brief Imprime os nomes flags de acesso
 * 
 * @param access_flags Flags em hexa - 16 bits
 * @param type Tipo de estrutura (class ou method)
 */
void printAccessFlags(uint16_t access_flags, infotype type);

/**
 * @brief Imprime as Interfaces
 * 
 * @param jclass Ponteiro para a estrutura do .class
 */
void printInterfaces(class_structure *jclass);

/**
 * @brief Imprime o nome de uma constant tipo Class
 * 
 * @param index Index do pool de constantes de um tipo Class
 * @param jclass Ponteiro para a estrutura do .class
 */
void printClassName(uint16_t index, class_structure *jclass);

/**
 * @brief Imprime os fields de uma Class
 * 
 * @param jclass Ponteiro para a estrutura do .class
 */
void printFields(class_structure *jclass);

/**
 * @brief Imprime os métodos de uma Class
 * 
 * @param jclass Ponteiro para a estrutura do .class
 */
void printMethods(class_structure *jclass);

/**
 * @brief Imprime os atributos de uma Class
 * 
 * @param jclass Ponteiro para a estrutura do .class
 */
void printClassAttributes(class_structure *jclass);

/**
 * @brief Imprime o atributo Code
 * 
 * @param code_attribute Atributo code
 * @param jclass Ponteiro para a estrutura do .class
 */
void printCodes(code_attribute code_attribute, class_structure *jclass);

/**
 * @brief Função chamadora das funções que imprimem cada atributo
 * 
 * @param attr_info Atributo
 * @param attribute_count Quantidade de atributos
 * @param jclass Ponteiro para a estrutura do .class
 */
void printAttributes(attribute_info *attr_info, uint16_t attribute_count, class_structure *jclass);

/**
 * @brief Imprime a string UTF-8 do pool de constantes
 * 
 * @param index Index do pool de constantes
 * @param jclass Ponteiro para a estrutura do .class
 */
void printUtf8(uint16_t index, class_structure *jclass);

/**
 * @brief Função principal que imprime as infomações de um arquivo .class
 * 
 * @param jclass Ponteiro para a estrutura do .class
 */
void printClassFile(class_structure *jclass);

/**
 * @brief Imprime o valor de uma entrada de formato float
 * 
 * @param bytes Bytes do float
 */
void printFloat(uint32_t bytes);

/**
 * @brief Imprime o valor de uma entrada de formato Long
 * 
 * @param high 32 Bits mais significativos
 * @param low  32 Bits menos significativos
 */
void printLong(uint32_t high, uint32_t low);

/**
 * @brief Imprime o valor de uma entrada de formato Double
 * 
 * @param high 32 Bits mais significativos
 * @param low  32 Bits menos significativos
 */
void printDouble(uint32_t high, uint32_t low);

/**
 * @brief Imprime as strings Utf8 referentes ao NameAndType
 * 
 * @param name_type_index Index no pool de constantes de um NameAndType
 * @param jclass Ponteiro para a estrutura do .class
 */
void printNameAndType(uint16_t name_type_index, class_structure *jclass);

/**
 * @brief Imprime a string Utf8 referente ao Name
 * 
 * @param name_type_index Index no pool de constantes de um Name
 * @param jclass Ponteiro para a estrutura do .class
 */
void printName(uint16_t name_type_index, class_structure *jclass);

/**
 * @brief Imprime as referências dos métodos
 * 
 * @param name_type_index Index no pool de constantes de um Method
 * @param jclass Ponteiro para a estrutura do .class
 */
void printMethodsRef(uint16_t method_index, class_structure *jclass);

/**
 * @brief Imprime os argumentos do code
 * 
 * @param code Ponteiro para vetor code
 * @param pc Index do vetor code
 * @param jclass Ponteiro para a estrutura do .class
 * @return int Quantidade de bytes utlizados
 */
int printCode(uint8_t *code, int pc, class_structure *jclass);

/**
 * @brief Imprime elemento da pool de constantes
 * 
 * @param index Index da pool de constantes
 * @param jclass Ponteiro para a estrutura do .class
 */
void printConstantPoolValue(int index,class_structure *jclass);

/**
 * @brief Imprime a versão do Java
 * 
 * @param major Major version
 * @param minor Minor version
 */
void printVersion(uint16_t major, uint16_t minor);

/**
 * @brief Imprime Class e NameAndType
 * 
 * @param method_index Index de um method da pool de constantes
 * @param jclass Ponteiro para a estrutura do .class
 */
void printClassAndNameType(uint16_t method_index, class_structure *jclass);

/**
 * @brief Imprime Class e Name
 * 
 * @param method_index Index de um method da pool de constantes
 * @param jclass Ponteiro para a estrutura do .class
 */
void printClassAndName(uint16_t method_index, class_structure *jclass);