//j8_class_reader.h
//Funções usadas para leitura do .class, a ideia é que tudo relacionado a leitura dos campos fique aqui e saia da main

#include <stdio.h>

#ifndef H_J8_CLASS_STRUCTURE
#define H_J8_CLASS_STRUCTURE
#include "j8_class_structure.h"
#endif

//le o constant pool se o arquivo estiver na posicao certa
void readConstantPool(FILE *class_file, class_structure* jclass);

//desaloca a classe incluindo o utf8 do constant pool
void freeClass(class_structure *jclass);
