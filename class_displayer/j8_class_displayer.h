//j8_class_displayer.h
//recursos usados para fazer o display dos dados lidos do .class

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef H_J8_CLASS_STRUCTURE
#define H_J8_CLASS_STRUCTURE
#include "j8_class_structure.h"
#endif

//converte o numero da tag do constant pool para uma string que faz sentido
void cpTagToString(uint8_t tag, char *tagType);

//printa todos os campos da classe
void printConstantPool(FILE* class_file, class_structure* jclass);
