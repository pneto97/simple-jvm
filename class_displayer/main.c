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

    jclass->magic = beRead32(class_file);
    printf("Magic Number: %x\n",jclass->magic);

    jclass->minor_version = beRead16(class_file);
    printf("Minor Version: %x\n",jclass->minor_version);

    jclass->major_version = beRead16(class_file);
    printf("Major Version: %d\n",jclass->major_version);

    jclass->constant_pool_count = beRead16(class_file);
    printf("Constant Pool Count: %d\n",jclass->constant_pool_count);
    
    readConstantPool(class_file, jclass);
    printConstantPool(class_file, jclass);

    jclass->access_flags = beRead16(class_file);
    printf("Access Flags: %d\n",jclass->access_flags);

    jclass->this_class = beRead16(class_file);
    printf("This class: %d\n",jclass->this_class);

    jclass->super_class = beRead16(class_file);
    printf("Super class: %d\n",jclass->super_class);

    //TODO: fazer o parse dos outros campos...
    
    freeClass(jclass);

    fclose(class_file);

    return 0;
}
