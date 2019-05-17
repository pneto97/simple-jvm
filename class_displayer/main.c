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
    printAccessFlags(jclass);

    jclass->this_class = beRead16(class_file);
    printf("This Class: ");
    printClassName(jclass->this_class, jclass);

    jclass->super_class = beRead16(class_file);
    printf("Super Class: ");
    printClassName(jclass->super_class, jclass);

    jclass->interfaces_count = beRead16(class_file);
    printf("Interfaces Count: %d\n",jclass->interfaces_count);

    readInterfaces(class_file, jclass);
    printInterfaces(jclass);
      
    jclass->fields_count = beRead16(class_file);
    printf("Fields Count: %d\n",jclass->fields_count);

    // readFields(class_file, jclass);
    // printFields(jclass);
    
    jclass->methods_count = beRead16(class_file);
    printf("Methods Count: %d\n",jclass->methods_count);

    readMethods(class_file, jclass);

    //TODO: fazer o parse dos outros campos...
    
    freeClass(jclass);

    fclose(class_file);

    return 0;
}
