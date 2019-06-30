//main.c
#include "read_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef H_CLASS_STRUCTURE
#define H_CLASS_STRUCTURE
#include "class_structure.h"
#endif

#include "class_displayer.h"
#include "class_reader.h"

int main(int argc, char *argv[]) {
    FILE *class_file = NULL;
    class_structure *jclass = NULL;

    printf("%d",argc);
    if (argc != 3) {
        printf("Especifique um arquivo .class!\n");
        exit(1);
    }

    switch (argv[1][0])
    {
        case 'l':

            class_file = fopen(argv[2], "rb");
            if (class_file == NULL) {
                printf("Erro ao abrir o arquivo!\n");
                exit(1);
            }
            
            jclass = readClassFile(class_file);
            checkConsistency(jclass, argv[2]);

            printClassFile(jclass);
            freeClass(jclass);
            break;

        case 'r':

            class_file = fopen(argv[2], "rb");
            if (class_file == NULL) {
                printf("Erro ao abrir o arquivo %s!\n", argv[2]);
                exit(1);
            }

            jclass = readClassFile(class_file);
            checkConsistency(jclass, argv[2]);

            printClassFile(jclass);
            freeClass(jclass);

        default:
            break;
    }

    fclose(class_file);

    return 0;
}
