#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "j8_class_structure.h"

uint16_t reverse16(uint16_t a){
    a = ((a & 0x00FF) << 8) | ((a & 0xFF00) >> 8);
    return a;
}

uint32_t reverse32(uint32_t a){
  a = ((a & 0x000000FF) << 24) |
    ((a & 0x0000FF00) <<  8) |
    ((a & 0x00FF0000) >>  8) |
    ((a & 0xFF000000) >> 24);
    return a;
}

uint8_t read8(FILE* fp){
    uint8_t buff = 0; 
    fread(&buff,sizeof(buff),1,fp);
    return buff;
}

uint16_t read16(FILE* fp){
    uint16_t buff = 0; 
    fread(&buff,sizeof(buff),1,fp);
    buff = reverse16(buff);
    return buff;
}

uint32_t read32(FILE* fp){
    uint32_t buff = 0; 
    fread(&buff,sizeof(buff),1,fp);
    buff = reverse32(buff);
    return buff;
}

int main(int argc , char* argv[]){

    if(argc != 2){
        printf("Especifique um arquivo .class!\n");
        exit(1);
    }

    FILE *fclass = fopen(argv[1], "rb");
    if(fclass == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    class_structure* jclass;
    jclass = ( class_structure* ) malloc( sizeof(class_structure) );

    jclass->magic = read32(fclass);
    printf("%x\n",jclass->magic);

    jclass->minor_version = read16(fclass);
    printf("%x\n",jclass->minor_version);

    jclass->major_version = read16(fclass);
    printf("%d\n",jclass->major_version);

    jclass->constant_pool_count = read16(fclass);
    printf("%d\n",jclass->constant_pool_count);

    free(jclass);
    fclose(fclass);

    return 0;
}
