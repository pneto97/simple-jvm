//j8_class_reader.c

#include "j8_class_displayer.h" // RETIRAR
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

void readAttributes(FILE *class_file, attribute_info *attr_info, uint16_t attribute_count, class_structure *jclass){

    for(int i = 0; i < attribute_count; i++){
        attr_info[i].attribute_name_index = beRead16(class_file);
        attr_info[i].attribute_length = beRead32(class_file);


        uint16_t name_index = attr_info[i].attribute_name_index;

        printf("Attribute: %d\n",i+1);
        printf("\tname_index: %u\n", attr_info[i].attribute_name_index);
        printf("\tattribute_length: %u\n", attr_info[i].attribute_length);

        char *attribute_type  = (char *) malloc(
            (jclass->constant_pool[name_index-1].info.utf8Info.length+1) * sizeof(char *)
        );

        strcpy(attribute_type,(char *)jclass->constant_pool[name_index-1].info.utf8Info.bytes);
        printf("\tType: %s\n", attribute_type);

        if(!strcmp(attribute_type, "Code")){
            //falta implementacao
            //fseek(class_file,attr_info[i].attribute_length,SEEK_CUR);
            attr_info[i].info.code_attribute.max_stack = beRead16(class_file);
            attr_info[i].info.code_attribute.max_locals = beRead16(class_file);
            attr_info[i].info.code_attribute.code_length = beRead32(class_file);
            printf("Max stack: %d\n", attr_info[i].info.code_attribute.max_stack);
            printf("Max locals: %d\n", attr_info[i].info.code_attribute.max_locals);
            printf("Code Length: %d\n", attr_info[i].info.code_attribute.code_length);

            //aloca o vetor para code
            if(attr_info[i].info.code_attribute.code_length > 0){
            attr_info[i].info.code_attribute.code = (uint8_t *) malloc(
                (attr_info[i].info.code_attribute.code_length) * sizeof(uint8_t)
            );
            }
            else{
                attr_info[i].info.code_attribute.code = NULL;
            }
            for (int j = 0; j < attr_info[i].info.code_attribute.code_length; j++)
            {
                attr_info[i].info.code_attribute.code[j] = beRead8(class_file);
                printf("\tCode[%d]: %hhx\n", j+1,attr_info[i].info.code_attribute.code[j]);
            }


            attr_info[i].info.code_attribute.exception_table_length = beRead16(class_file);
            printf("exception_table_length: %d \n", attr_info[i].info.code_attribute.exception_table_length);
            //aloca o vetor para exception_table

            if (attr_info[i].info.code_attribute.exception_table_length != 0){
            attr_info[i].info.code_attribute.exception_table = (exception_table *) malloc(
                (attr_info[i].info.code_attribute.exception_table_length) * sizeof(exception_table)
            );
            }
            else {
                attr_info[i].info.code_attribute.exception_table = NULL;
            }
            for (int j = 0; j < attr_info[i].info.code_attribute.exception_table_length; j++)
            {
                attr_info[i].info.code_attribute.exception_table[j].start_pc = beRead16(class_file);
                attr_info[i].info.code_attribute.exception_table[j].end_pc = beRead16(class_file);
                attr_info[i].info.code_attribute.exception_table[j].handler_pc = beRead16(class_file);
                attr_info[i].info.code_attribute.exception_table[j].catch_type = beRead16(class_file);
                printf("EXCEPTION %d",j+1);
                printf("\tstart_pc[%d]: %d\n", j+1,attr_info[i].info.code_attribute.exception_table[j].start_pc);
                printf("\tend_pc[%d]: %d\n", j+1,attr_info[i].info.code_attribute.exception_table[j].end_pc);
                printf("\thandler_pc[%d]: %d\n", j+1,attr_info[i].info.code_attribute.exception_table[j].handler_pc);
                printf("\tCatch Type: ");
                printClassName(attr_info[i].info.code_attribute.exception_table[j].catch_type,jclass);
                printf("\n");
            }

            attr_info[i].info.code_attribute.attributes_count = beRead16(class_file);

            //aloca o vetor para attributes
            if (attr_info[i].info.code_attribute.attributes_count != 0){
                attr_info[i].info.code_attribute.attributes = (attribute_info *) malloc(
                (attr_info[i].info.code_attribute.attributes_count) * sizeof(attribute_info)
            );
            }
            else {
                attr_info[i].info.code_attribute.attributes = NULL;
            }

            // Leitura dos atributos de cada atributo code (Sim, a parada é recursiva :o )
            readAttributes(class_file,attr_info[i].info.code_attribute.attributes,
                 attr_info[i].info.code_attribute.attributes_count,jclass);

        } else if(!strcmp(attribute_type, "ConstantValue")){

            attr_info[i].info.constant_value_attribute.constantvalue_index
                = beRead16(class_file);
            printf("\tConstant Value Index: %d\n", attr_info[i].info.constant_value_attribute.constantvalue_index);

        } else if(!strcmp(attribute_type, "Exceptions")){

            attr_info[i].info.exceptions_attribute.number_of_exceptions = beRead16(class_file);
            printf("number_of_oxceptions: %d\n", attr_info[i].info.exceptions_attribute.number_of_exceptions);

            //alocacao para a tabela de excessoes
            if (attr_info[i].info.exceptions_attribute.number_of_exceptions != 0){
            attr_info[i].info.exceptions_attribute.excepetions_table = (uint16_t*) malloc(
                (attr_info[i].info.exceptions_attribute.number_of_exceptions)
                    * sizeof(uint16_t)
                );
            }
            else{
                attr_info[i].info.exceptions_attribute.excepetions_table = NULL;
            }
            for(int j=0;i<attr_info[i].info.exceptions_attribute.number_of_exceptions;j++){
                //nao tenho certeza se sao 2 bytes
                    attr_info[i].info.exceptions_attribute.excepetions_table[j] = beRead16(class_file);
                    printf("excepetions_table[%d]: %d\n", j+1,attr_info[i].info.exceptions_attribute.excepetions_table[j]);
                }

            fseek(class_file,attr_info[i].attribute_length,SEEK_CUR);
        } else if(!strcmp(attribute_type, "StackMapTable")){
            printf("\tSem implementação\n");
            fseek(class_file,attr_info[i].attribute_length,SEEK_CUR);
        } else if(!strcmp(attribute_type, "BootstrapMethods")){

            printf("Bootstrap Methods\n");
            attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods
                = beRead16(class_file);
            printf("Num Bootstrap methods: %d\n", attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods);
            if(attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods != 0){
                attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods = (bootstrap_methods *) malloc(
                    (attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods) * sizeof(bootstrap_methods));

            }else{
                attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods = NULL;
            }

            for(int j = 0; j < attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods; j++){
                attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_method_ref = beRead16(class_file);
                attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments = beRead16(class_file);
                printf("\tMethod Ref: #%d\n", attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_method_ref);
                printf("\tNum bootstrap arguments: %d\n", attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments);
                if(attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments != 0){
                    attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments = (uint16_t *) malloc(
                        (attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments) * sizeof(uint16_t));

                }else{
                    attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments = NULL;
                }
                for(int k = 0; k < attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments; k++){
                    attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments[k] = beRead16(class_file);
                    printf("\t\tBootstrap arguments: #%d\n", attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments[k]);

                }

            }

        } else if(!strcmp(attribute_type, "Signature")){

            attr_info[i].info.signature_attribute.signature_index
                = beRead16(class_file);
            printf("\tSignature Index: %d\n", attr_info[i].info.signature_attribute.signature_index);

        } else if(!strcmp(attribute_type, "LineNumberTable")){
            attr_info[i].info.lineNumberTable_attribute.line_number_table_length = beRead16(class_file);
            printf("line_number_table_length: %d\n", attr_info[i].info.lineNumberTable_attribute.line_number_table_length);
            if (attr_info[i].info.lineNumberTable_attribute.line_number_table_length != 0)
            {
                attr_info[i].info.lineNumberTable_attribute.line_number_table = (line_number_table *) malloc(
                    (attr_info[i].info.lineNumberTable_attribute.line_number_table_length)
                    * sizeof(line_number_table)
                );
            }
            else
            {
                attr_info[i].info.lineNumberTable_attribute.line_number_table = NULL;
            }
            printf("Line : Start Program Counter\n");
            for (int j = 0; j < attr_info[i].info.lineNumberTable_attribute.line_number_table_length; j++)
            {
                attr_info[i].info.lineNumberTable_attribute.line_number_table[j].start_pc = beRead16(class_file);
                attr_info[i].info.lineNumberTable_attribute.line_number_table[j].line_number = beRead16(class_file);
                printf("%d : %d\n",attr_info[i].info.lineNumberTable_attribute.line_number_table[j].line_number,attr_info[i].info.lineNumberTable_attribute.line_number_table->start_pc);

            }

        } else if(!strcmp(attribute_type, "SourceFile")){

            attr_info[i].info.sourceFile_attribute.sourcefile_index
                = beRead16(class_file);

            uint16_t sourcefile_index = attr_info[i].info.sourceFile_attribute.sourcefile_index;
            printf("\tSourceFile Index: %s\n", jclass->constant_pool[sourcefile_index-1].info.utf8Info.bytes);

        } else if(!strcmp(attribute_type, "InnerClasses")){

            attr_info[i].info.innerClasses_attribute.number_of_classes = beRead16(class_file);

            printf("number_of_classes: %d\n",attr_info[i].info.innerClasses_attribute.number_of_classes);

            if(attr_info[i].info.innerClasses_attribute.number_of_classes != 0){

                attr_info[i].info.innerClasses_attribute.classes = (classes *) malloc (
                    (attr_info[i].info.innerClasses_attribute.number_of_classes)
                        * sizeof(classes)
                );

            } else {
                attr_info[i].info.innerClasses_attribute.classes = NULL;
            }

            for (int j = 0; j < attr_info[i].info.innerClasses_attribute.number_of_classes; j++)
            {
                attr_info[i].info.innerClasses_attribute.classes[j].inner_class_info_index = beRead16(class_file);
                attr_info[i].info.innerClasses_attribute.classes[j].outer_class_info_index = beRead16(class_file);
                attr_info[i].info.innerClasses_attribute.classes[j].inner_name_index = beRead16(class_file);
                attr_info[i].info.innerClasses_attribute.classes[j].inner_class_access_flags = beRead16(class_file);
                printf("InnerClasses:\n");
                printf("#%d = ",attr_info[i].info.innerClasses_attribute.classes[j].inner_name_index);
                printf("#%d",attr_info[i].info.innerClasses_attribute.classes[j].outer_class_info_index);
                printf(" of #%d;\n",attr_info[i].info.innerClasses_attribute.classes[j].inner_class_info_index);
                printf("inner_class_access_flags: %d\n",attr_info[i].info.innerClasses_attribute.classes[j].inner_class_access_flags);
            }
        }

         else {
            printf("\tDesconhecido!\n");
            fseek(class_file,attr_info[i].attribute_length,SEEK_CUR);
        }
        //Faltam ainda mais opcoes de name.index!


        //Free na string auxiliar (serve apenas para realizar a comparacao dos tipos de atributo)
        free(attribute_type);

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

    jclass->fields = (field_info *) malloc (
        (jclass->fields_count) * sizeof(field_info)
    );

    for(int i = 0; i < fields_count; i++){
        jclass->fields[i].access_flags = beRead16(class_file);
        jclass->fields[i].name_index = beRead16(class_file);
        jclass->fields[i].descriptor_index = beRead16(class_file);
        jclass->fields[i].attributes_count = beRead16(class_file);

        printf("\n------------------------------\n");
        printf("FIELD: %d\n", i+1);
        printf("Access Flag: %u\n", jclass->fields[i].access_flags);
        printf("Name Index: %u\n", jclass->fields[i].name_index);
        printf("Descriptor Index: %u\n", jclass->fields[i].descriptor_index);
        printf("Attribute Count: %u\n", jclass->fields[i].attributes_count);

        uint16_t attribute_count = jclass->fields[i].attributes_count;

        if(attribute_count > 0){
            jclass->fields[i].attributes = (attribute_info *) malloc (
                (attribute_count) * sizeof(attribute_info)
            );
            readAttributes(class_file, jclass->fields[i].attributes, attribute_count, jclass);
        } else{
            jclass->fields[i].attributes = NULL;
        }
    }

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

        printf("\n------------------------------\n");
        printf("METHOD: %d\n", i+1);
        printf("Access Flag: %u\n", jclass->methods[i].access_flags);
        printf("Name Index: %u\n", jclass->methods[i].name_index);
        printf("Descriptor Index: %u\n", jclass->methods[i].descriptor_index);
        printf("Attribute Count: %u\n", jclass->methods[i].attributes_count);

        uint16_t attribute_count = jclass->methods[i].attributes_count;

        if(attribute_count > 0){
            jclass->methods[i].attributes = (attribute_info *) malloc(
                (attribute_count) * sizeof(attribute_info)
            );
            readAttributes(class_file, jclass->methods[i].attributes, attribute_count, jclass);
        } else {
            jclass->methods[i].attributes = NULL;
        }
    }
}

void readClassAttributes(FILE *class_file, class_structure* jclass){

    uint16_t attribute_class_count = jclass->attributes_count;

    if(attribute_class_count > 0){
        jclass->attribute = (attribute_info *) malloc(
            (attribute_class_count) * sizeof(attribute_info)
        );
        readAttributes(class_file, jclass->attribute, attribute_class_count, jclass);
    } else {
        jclass->attribute = NULL;
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
