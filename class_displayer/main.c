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

    uint16_t name_index_pos = jclass->constant_pool[jclass->this_class - 1].info.classInfo.name_index;
    char *name_index = (char *)jclass->constant_pool[name_index_pos - 1].info.utf8Info.bytes;
    char *formatted_filename;

    formatted_filename = getFilename(argv[1]);

    if (strcmp(name_index, formatted_filename) != 0) {
        printf("Falha de consistencia.\n");
        exit(-1);
    }

    printClassFile(jclass);
    freeClass(jclass);

    fclose(class_file);

    return 0;
}
