//main.c
#include "read_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef H_J8_CLASS_STRUCTURE
#define H_J8_CLASS_STRUCTURE
#include "j8_class_structure.h"
#endif

#include "j8_class_displayer.h"
#include "j8_class_reader.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Especifique um arquivo .class!\n");
        exit(1);
    }

    FILE *class_file = fopen(argv[1], "rb");
    if (class_file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    class_structure *jclass;

    jclass = readClassFile(class_file);
    printClassFile(jclass);
    freeClass(jclass);

    fclose(class_file);

    return 0;
}
