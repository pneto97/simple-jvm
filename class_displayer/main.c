#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "j8_class_structure.h"


int main(int argc , char* argv[]){

    if(argc != 2){
        printf("Especifique um arquivo .class!\n");
        exit(1);
    }

    class_structure* java_class;
    java_class = ( class_structure* ) malloc( sizeof(class_structure) );

    printf("Rodou!\n");

    free(java_class);

    return 0;
}
