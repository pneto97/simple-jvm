//main.c
#include "class_displayer.h"
#include "class_reader.h"
#include "class_structure.h"
#include "global.h"
#include "read_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRT_YEL  "\x1B[33m"
#define E_PRT_YEL "\033[0m"

int main(int argc, char *argv[]) {
    FILE *class_file        = NULL;
    class_structure *jclass = NULL;
    class_loaded *lclass;
    char tipo;
    char ponto_class_path[100], ponto_class_name[100];
    initMethodArea();
    initJVMStack();
    //(*inst_vector[0x00])(); como chamar a funcao da array

    if (argc == 1) {
        printf("Se preferir, você pode passar os argumentos via linha de comando:\n\n");

        printf("LEITOR:         %s./main l [NOME_CLASSE.class]%s\n", PRT_YEL, E_PRT_YEL);
        printf("INTERPRETADOR:  %s./main e [DIRETORIO] [NOME_CLASSE]%s\n\n", PRT_YEL, E_PRT_YEL);

        printf("Digite l para leitura ou e para executar\n");
        scanf("%c", &tipo);
    } else {
        tipo = argv[1][0];
    }

    switch (tipo) {
    case 'l':

        if (argc != 3) {
            printf("Insira o caminho completo com o .class: ");
            scanf("%s", ponto_class_path);
        } else if (argc == 3) {
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

    case 'e':

        if (argc != 4) {
            printf("Insira o diretório onde o .class se encontra\n");
            scanf("%s", ponto_class_path);
            printf("Insira o nome do .class sem a extensão\n");
            scanf("%s", ponto_class_name);
        } else if (argc == 4) {
            strcpy(ponto_class_path, argv[2]);
            strcpy(ponto_class_name, argv[3]);
        }

        GLOBAL_path = ponto_class_path;
        lclass               = loadClass(GLOBAL_path, ponto_class_name);
        method_info *method  = findMain(lclass);
        code_attribute *code = findCode(lclass, method);

        createFrame(code, lclass->class_str->constant_pool);

        // Para debugar, descomente a linha de baixo
        execute(code);

        //freeClass(jclass);

        //free(lclass);
        //free_frame(fr);
        

    default:
        break;
    }

    freeJVMStack();
    freeMethodArea();

    return 0;
}


/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */