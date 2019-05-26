//j8_class_displayer.h
//recursos usados para fazer o display dos dados lidos do .class

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef H_J8_CLASS_STRUCTURE
#define H_J8_CLASS_STRUCTURE
#include "j8_class_structure.h"
#endif
#include "j8_access_flags.h"

//converte o numero da tag do constant pool para uma string que faz sentido
void cpTagToString(uint8_t tag, char *tagType);

// print do magic number, minor e major version
void printInitialParams(class_structure *jclass);

//printa todos os campos da classe
void printConstantPool(class_structure *jclass);

// Imprime o nome das flags presentes classe
void printAccessFlags(uint16_t access_flags, infotype type);

// Imprime as Interfaces
void printInterfaces(class_structure *jclass);

// Imprime o nome de uma constant tipo Class
void printClassName(uint16_t index, class_structure *jclass);

// Imprime os fields de uma Class
void printFields(class_structure *jclass);

// Imprime os metodos de uma Class
void printMethods(class_structure *jclass);

// Função que imprime os atributos de um Classe
void printClassAttributes(class_structure *jclass);

// Função que printa os codigos
void printCodes(code_attribute code_attribute, class_structure *jclass);

// Função-mestre dos atributos que chama todas os prints de atributos
void printAttributes(attribute_info *attr_info, uint16_t attribute_count, class_structure *jclass);

// Função default pra printar um utf-8 do constant_pool
void printUtf8(uint16_t index, class_structure *jclass);

// Função que chama todas as outras para printar
void printClassFile(class_structure *jclass);

// Função que imprime na tela um número formato Float
void printFloat(uint32_t bytes);

// Função que imprime na tela um número formato Long
void printLong(uint32_t high, uint32_t low);

// Função que imprime na tela um número formato Double
void printDouble(uint32_t high, uint32_t low);

// Função que imprime os Utf8 referentes ao NameAndType
void printNameAndType(uint16_t name_type_index, class_structure *jclass);

//Funcao que imprime as referencias dos metodos
void printMethodsRef(uint16_t method_index, class_structure *jclass);

//Funcao que imprime os args do code
int printCode(uint8_t *code, int pc, class_structure *jclass);

//Funcao que imprime os argumentos do ConstantPool
void printConstantPoolValue(int index,class_structure *jclass);