//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_utils.h"

#ifndef H_J8_CLASS_STRUCTURE
#define H_J8_CLASS_STRUCTURE
#include "j8_class_structure.h"
#endif

#include "j8_class_reader.h"
#include "j8_class_displayer.h"

int main(int argc , char* argv[]){
    if(argc != 2){
        printf("Especifique um arquivo .class!\n");
        exit(1);
    }

    FILE *class_file = fopen(argv[1], "rb");
    if(class_file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    class_structure* jclass;
    jclass = ( class_structure* ) malloc( sizeof(class_structure) );

    readClassFile(class_file, jclass);

    if (isClassFile(jclass)) 
        printClassFile(jclass);
    else 
        printf("\n\nErro! O arquivo deve ser um .class!\n\n");
    
    freeClass(jclass);

    fclose(class_file);

    return 0;
}
