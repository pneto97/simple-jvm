//j8_class_reader.h
//Funções usadas para leitura do .class, a ideia é que tudo relacionado a leitura dos campos fique aqui e saia da main

#include <stdio.h>

#ifndef H_J8_CLASS_STRUCTURE
#define H_J8_CLASS_STRUCTURE
#include "j8_class_structure.h"
#endif

// leitura do magic number, minor e major version
void readInitialParams(class_structure* jclass, FILE *class_file);

//le o constant pool se o arquivo estiver na posicao certa
void readConstantPool(FILE *class_file, class_structure* jclass);

//le as interfaces se o arquivos estiver na posição certa
void readInterfaces(FILE *class_file, class_structure* jclass);

//le os metodos se o arquivo estiver na posicao certa
void readMethods(FILE *class_file, class_structure* jclass);

//le os campos se o arquivo estiver na posicao certa
void readFields(FILE *class_file, class_structure* jclass);

//le os atributos gerais se estiver na posicao certa
void readAttributes(FILE *class_file, attribute_info *attribute_info, uint16_t attribute_count, class_structure *jclass);

//le os attributos da classe se estiver na posicao certa
void readClassAttributes(FILE *class_file, class_structure* jclass);

//desaloca a classe incluindo o utf8 do constant pool
void freeClass(class_structure *jclass);

//desaloca attributos da class
void freeAttributes(attribute_info *attr_info, uint16_t attribute_count, class_structure *jclass);

//função que chama todos os outros readers
void readClassFile(FILE *class_file, class_structure* jclass);

// checa se é um class file
int isClassFile(class_structure* jclass);