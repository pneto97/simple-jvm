//j8_class_displayer.h
//recursos usados para fazer o display dos dados lidos do .class

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef H_J8_CLASS_STRUCTURE
#define H_J8_CLASS_STRUCTURE
#include "j8_class_structure.h"
#endif
#include "j8_access_flags.h"

//converte o numero da tag do constant pool para uma string que faz sentido
void cpTagToString(uint8_t tag, char *tagType);

// print do magic number, minor e major version
void printInitialParams(class_structure* jclass);

//printa todos os campos da classe
void printConstantPool(class_structure* jclass);

// Imprime o nome das flags presentes classe
void printAccessFlags(uint16_t access_flags, infotype type);

// Imprime as Interfaces
void printInterfaces(class_structure* jclass);

// Imprime o nome de uma constant tipo Class
void printClassName(uint16_t index, class_structure *jclass);

// Imprime os fields de uma Class
void printFields(class_structure *jclass);

// Imprime os metodos de uma Class
void printMethods(class_structure *jclass);

// Função que imprime os atributos de um Classe
void printClassAttributes(class_structure *jclass);

// Função que printa os codigos
void printCodes(code_attribute code_attribute, class_structure* jclass);

// Função-mestre dos atributos que chama todas os prints de atributos
void printAttributes(attribute_info* attr_info,uint16_t attribute_count, class_structure* jclass);

// Função default pra printar um utf-8 do constant_pool
void printUtf8(uint16_t index, class_structure *jclass);

// Função que chama todas as outras para printar
void printClassFile(class_structure * jclass);