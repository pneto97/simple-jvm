//j8_class_reader.c

#include "j8_class_reader.h"
#include <stdint.h>
#include <stdlib.h>
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
    // }
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
