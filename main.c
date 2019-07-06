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
    class_loaded *lclass;
    char tipo;
    char ponto_class_path[100],ponto_class_name[100];
    initMethodArea();
    initJVMStack();

    
    if (argc == 1){
        printf("Digite l para leitura ou r para rodar\n");
        scanf("%c", &tipo);
    }
    else tipo = argv[1][0];
    switch (tipo)
    {
        case 'l':

            
            if (argc != 3) {
                printf("Insira o caminho completo com o .class: ");
                scanf("%s", ponto_class_path);
            }
            else if(argc == 3){
                strcpy(ponto_class_path, argv[2]);
            }
            class_file = fopen(ponto_class_path, "rb");
            if (class_file == NULL) {
                printf("Erro ao abrir o arquivo!\n");
                exit(1);
            }
            
            jclass = readClassFile(class_file);
            checkConsistency(jclass, ponto_class_path);

            printClassFile(jclass);
            freeClass(jclass);
            fclose(class_file);
            break;

        case 'r':


            if (argc != 4) {
                printf("Insira o diretório onde o .class se encontra\n");
                scanf("%s", ponto_class_path);
                printf("Insira o nome do .class sem a extensão\n");
                scanf("%s", ponto_class_name);
            }
            else if(argc == 4){
                strcpy(ponto_class_path, argv[2]);
                strcpy(ponto_class_name, argv[3]);
            }
            lclass = loadClass(ponto_class_path,ponto_class_name);
            method_info *method = findMain(lclass);
            code_attribute *code = findCode(lclass, method);

            frame *fr = createFrame(code, lclass->class_str->constant_pool);

            execute(code);

            //freeClass(jclass);

            //free(lclass);
            //free_frame(fr);
            fclose(class_file);

        default:
            break;
    }

    freeJVMStack();
    freeMethodArea();

    return 0;
}
