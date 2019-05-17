//j8_class_reader.c

#include "j8_class_reader.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "read_utils.h"

//leitura do constant pool, o class_file precisa estar já na posição correta
void readConstantPool(FILE *class_file, class_structure* jclass){

    //aloca o campo do cp_info, esse -1 é porque o indice do constant pool começa em 1
    jclass->constant_pool = (cp_info *) malloc(
        (jclass->constant_pool_count-1) * sizeof(cp_info)
    );

    //lê cada tag, de acordo com a tag, le os campos corretos da union "info"
    // recomendo ler o capitulo 4 da doc da jvm para entender essa parte, na parte do constant_pool
    for(int i = 0; i < jclass->constant_pool_count-1 ; i++){

        //le a tag de 8 bits
        jclass->constant_pool[i].tag = beRead8(class_file);

        switch(jclass->constant_pool[i].tag){

            case CONSTANT_Class:

                jclass->constant_pool[i].info.classInfo.name_index = beRead16(class_file);

                break;
            //Os 3 proximos utilizam os mesmos campos
            case CONSTANT_Fieldref:
            case CONSTANT_Methodref:
            case CONSTANT_InterfaceMethodref:

                jclass->constant_pool[i].info.refInfo.class_index = beRead16(class_file);
                jclass->constant_pool[i].info.refInfo.name_and_type_index = beRead16(class_file);
                break;

            case CONSTANT_String:

                jclass->constant_pool[i].info.stringInfo.string_index = beRead16(class_file);

                break;
            //ambos 32 bits
            case CONSTANT_Integer:
            case CONSTANT_Float:
                jclass->constant_pool[i].info.number32Info.bytes = beRead32(class_file);
                break;

            //ambos 64 bits
            case CONSTANT_Long:
            case CONSTANT_Double:

                jclass->constant_pool[i].info.number64Info.high_bytes = beRead32(class_file);
                jclass->constant_pool[i].info.number64Info.low_bytes = beRead32(class_file);
                i++; //64 bits usa duas posicoes na tabela do constant pool
                break;

            case CONSTANT_NameAndType:

                jclass->constant_pool[i].info.nameAndTypeInfo.name_index = beRead16(class_file);
                jclass->constant_pool[i].info.nameAndTypeInfo.descriptor_index = beRead16(class_file);
                break;
            case CONSTANT_Utf8:

                //pega o tamanho da string
                jclass->constant_pool[i].info.utf8Info.length = beRead16(class_file);

                //aloca espaço para esse tamanho
                jclass->constant_pool[i].info.utf8Info.bytes =
                    (uint8_t*) malloc(
                        (jclass->constant_pool[i].info.utf8Info.length+1) * sizeof(uint8_t)
                    );

                //le a string do arquivo para o espaço alocado
                fread(jclass->constant_pool[i].info.utf8Info.bytes,
                      sizeof(uint8_t),
                      jclass->constant_pool[i].info.utf8Info.length,
                      class_file
                );

                jclass->constant_pool[i].info.utf8Info.bytes[jclass->constant_pool[i].info.utf8Info.length] = '\0';

                break;
            case CONSTANT_MethodHandle:

                jclass->constant_pool[i].info.methodHandleInfo.reference_kind = beRead8(class_file);
                jclass->constant_pool[i].info.methodHandleInfo.reference_index = beRead16(class_file);
                break;
            case CONSTANT_MethodType:

                jclass->constant_pool[i].info.methodTypeInfo.descriptor_index = beRead16(class_file);

                break;
            case CONSTANT_InvokeDynamic:

                jclass->constant_pool[i].info.invokeDynamicInfo.bootstrap_method_attr_index =
                    beRead16(class_file);
                jclass->constant_pool[i].info.invokeDynamicInfo.name_and_type_index =
                    beRead16(class_file);

                break;
            defaut:
                printf("TAG do constant pool inexistente!\n");
                exit(1);
        }

    }
}

void readAtributtes(FILE *class_file, attribute_info *attribute_info, uint16_t attribute_count, class_structure *jclass){
    int i = 0;
    printf("count  %d\n", attribute_count);
    for(i = 0; i < (int)attribute_count; i++){
        printf("for loop %d\n", i);
        attribute_info[i].attribute_name_index = beRead16(class_file);
        attribute_info[i].attribute_length = beRead32(class_file);


        uint16_t name_index = attribute_info[i].attribute_name_index;

        printf("Attribute[%d]\n",i);
        printf("\t name_index: %u\n", attribute_info[i].attribute_name_index);
        printf("\t attribute_length: %u\n", attribute_info[i].attribute_length);

        char *attribute_type  = (char *) malloc(
            (jclass->constant_pool[name_index-1].info.utf8Info.length+1) * sizeof(char *)
        );

        attribute_type = (char *) jclass->constant_pool[name_index-1].info.utf8Info.bytes;

        if(strcmp(attribute_type, "Code")){
            //falta implementacao
            fseek(class_file,attribute_info[i].attribute_length,SEEK_CUR);
        }

        else if(strcmp(attribute_type, "ConstantValue")){

            /*attribute_info[i].info.constant_value_attribute.constantvalue_index
                = beRead16(class_file);
            */
            fseek(class_file,attribute_info[i].attribute_length,SEEK_CUR);
        }
        else if(strcmp(attribute_type, "Exceptions")){
            /*
            attribute_info[i].info.exceptions_attribute.number_of_exceptions = beRead16(class_file);

                //alocacao para a tabela de excessoes
            attribute_info[i].info.exceptions_attribute.excepetions_table = (uint16_t*) malloc(
                (attribute_info[i].info.exceptions_attribute.number_of_exceptions)
                    * sizeof(uint16_t)
                );

            for(int i=0;i<attribute_info[i].info.exceptions_attribute.number_of_exceptions;i++){
                //nao tenho certeza se sao 2 bytes
                    attribute_info[i].info.exceptions_attribute.excepetions_table[i] = beRead16(class_file);
                }
            */
            fseek(class_file,attribute_info[i].attribute_length,SEEK_CUR);
        }
        else if(strcmp(attribute_type, "StackMapTable")){
            //falta implementacao
            fseek(class_file,attribute_info[i].attribute_length,SEEK_CUR);
        }

        else if(strcmp(attribute_type, "BootstrapMethods")){
            //falta implementacao
            fseek(class_file,attribute_info[i].attribute_length,SEEK_CUR);

        }
        else {
            fseek(class_file,attribute_info[i].attribute_length,SEEK_CUR);
        }
        //Faltam ainda mais opcoes de name.index!


        //Free na string auxiliar (serve apenas para realizar a comparacao dos tipos de atributo)
        printf("ola inicio %d\n", i);
        if(attribute_type!=NULL){

            //free(attribute_type);

        }
        printf("ola fim\n");
    }

}


void readInterfaces(FILE *class_file, class_structure* jclass){

    uint8_t interfaces_count = jclass->interfaces_count;

    //aloca o vetor de indices de constantes
    jclass->interfaces = (uint16_t *) malloc(
        (jclass->constant_pool_count-1) * sizeof(uint16_t)
    );

    //lê do arquivo os indices e armazena no vetor de interfaces
    for(int i = 0; i < jclass->interfaces_count; i++){
        jclass->interfaces[i] = beRead16(class_file);
    }
}

void readFields(FILE *class_file, class_structure* jclass){

    uint8_t fields_count = jclass->fields_count;

    //aloca o vetor de indices de constantes
    // jclass->fields = (uint16_t *) malloc(
    //     (jclass->constant_pool_count-1) * sizeof(uint16_t)
    // );

    // //lê do arquivo os indices e armazena no vetor de interfaces
    // for(int i = 0; i < jclass->interfaces_count; i++){
    //     jclass->interfaces[i] = beRead16(class_file);

}

void readMethods(FILE *class_file, class_structure* jclass){
    uint8_t methods_count = jclass->methods_count;

    jclass->methods = (method_info *) malloc(
        (jclass->methods_count) * sizeof(method_info)
    );

    for(int i = 0; i < methods_count; i++){
        jclass->methods[i].access_flags = beRead16(class_file);
        jclass->methods[i].name_index = beRead16(class_file);
        jclass->methods[i].descriptor_index = beRead16(class_file);
        jclass->methods[i].attributes_count = beRead16(class_file);

        printf("Index: %d\n\n", i);
        printf("Access Flag: %u\n", jclass->methods[i].access_flags);
        printf("Name Index: %u\n", jclass->methods[i].name_index);
        printf("Descriptor Index: %u\n", jclass->methods[i].descriptor_index);
        printf("Attribute Count: %u\n", jclass->methods[i].attributes_count);


        uint16_t attribute_count = jclass->methods[i].attributes_count;

        jclass->methods[i].attributes = (attribute_info*) malloc(
            (attribute_count) * sizeof(attribute_info)
        );

        readAtributtes(class_file, jclass->methods[i].attributes, attribute_count, jclass);

    }
}

//desaloca a classe incluindo o utf8 do constant pool
void freeClass(class_structure *jclass){
    if(jclass != NULL){

        for(int i = 0; i < jclass->constant_pool_count-1 ; i++){
            if(jclass->constant_pool[i].info.utf8Info.bytes != NULL && jclass->constant_pool[i].tag == CONSTANT_Utf8)
                free(jclass->constant_pool[i].info.utf8Info.bytes);
        }

        if(jclass->interfaces != NULL){
            free(jclass->interfaces);
        }

        if(jclass->constant_pool != NULL){
            free(jclass->constant_pool);
        }

        free(jclass);
    }

}
