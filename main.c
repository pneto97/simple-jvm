//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class_structure.h"
#include "class_displayer.h"
#include "class_reader.h"
#include "read_utils.h"
#include "global.h"

int main(int argc, char *argv[]) {
    FILE *class_file = NULL;
    class_structure *jclass = NULL;
    
    initMethodArea();
    initJVMStack();

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
            fclose(class_file);
            break;

        case 'r':

            class_file = fopen(argv[2], "rb");
            if (class_file == NULL) {
                printf("Erro ao abrir o arquivo %s!\n", argv[2]);
                exit(1);
            }

            jclass = readClassFile(class_file);
            checkConsistency(jclass, argv[2]);

            class_instance *iclass = insertClassStructure(jclass);
            uint16_t method = findMain(iclass);
            code_attribute code = findCode(iclass, method);

            frame *fr = createFrame(&code, jclass->constant_pool);

            execute();

            freeClass(jclass);
            fclose(class_file);

        default:
            break;
    }

    return 0;
}
