#include <stdio.h>
#include <stdlib.h>
#include "j8_class_structure.h"


int main(){
    class_structure* java_class;
    java_class = ( class_structure* ) malloc( sizeof(class_structure) );

    printf("Rodou!\n");

    free(java_class);
}
