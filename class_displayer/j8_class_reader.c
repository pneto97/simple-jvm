//j8_class_reader.c

#include "j8_class_reader.h"
#include "read_utils.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Função que lê o jclass e returna uma struct com todas as infos
class_structure *readClassFile(FILE *class_file) {
    class_structure *jclass = (class_structure *)malloc(sizeof(class_structure));

    if (jclass == NULL) {
        printf("Erro na alocacao!\n");
        exit(2);
    }

    readInitialParams(jclass, class_file); //magic, minor e major version
    readConstantPool(class_file, jclass); // Constant pool
    jclass->access_flags = beRead16(class_file); // access flag
    jclass->this_class   = beRead16(class_file); // this class
    jclass->super_class  = beRead16(class_file); // Super class
    readInterfaces(class_file, jclass); // Interfaces
    readFields(class_file, jclass); // Fields
    readMethods(class_file, jclass); // Methods
    readClassAttributes(class_file, jclass); // Class Attributes
    return jclass;
}

void checkConsistency(class_structure *jclass, char *file) {
    uint16_t name_index_pos = jclass->constant_pool[jclass->this_class - 1].info.classInfo.name_index;
    char *name_index        = (char *)jclass->constant_pool[name_index_pos - 1].info.utf8Info.bytes;
    char *formatted_filename;

    formatted_filename = getFilename(file);

    if (strcmp(name_index, formatted_filename) != 0) {
        printf("Falha de consistencia.\n");
        exit(-1);
    }
}

char *getFilename(char *sentence) {
    char *buffer;
    char *result    = sentence;
    char split_by[] = "/\\";

    buffer = strtok(sentence, split_by);

    while (buffer != NULL) {
        result = buffer;
        buffer = strtok(NULL, split_by);
    }

    //Remove tudo apos o '.', ou seja, o .class
    sscanf(result, "%[^.]s", result);

    return result;
}

int isClassFile(class_structure *jclass) {
    int i = (jclass->magic == 0xCAFEBABE) ? 1 : 0;
    return i;
}

// leitura do magic number, minor e major version
void readInitialParams(class_structure *jclass, FILE *class_file) {
    jclass->magic = beRead32(class_file);

    if (!isClassFile(jclass)) {
        printf("\n\nErro! O arquivo deve ser um .class!\n\n");
        fclose(class_file);
        free(jclass);
        exit(3);
    }

    jclass->minor_version = beRead16(class_file);
    jclass->major_version = beRead16(class_file);

    if (jclass->major_version > (uint16_t)52) {
        printf("\n\nErro! Versão Incompativel!\n\n");
        fclose(class_file);
        free(jclass);
        exit(3);
    }
}

//leitura do constant pool, o class_file precisa estar já na posição correta
void readConstantPool(FILE *class_file, class_structure *jclass) {

    // leitura do constant pool count
    jclass->constant_pool_count = beRead16(class_file);
    //aloca o campo do cp_info, esse -1 é porque o indice do constant pool começa em 1
    jclass->constant_pool = (cp_info *)malloc(
        (jclass->constant_pool_count - 1) * sizeof(cp_info));

    if (jclass->constant_pool == NULL) {
        printf("Erro na alocacao!\n");
        exit(2);
    }

    //lê cada tag, de acordo com a tag, le os campos corretos da union "info"
    // recomendo ler o capitulo 4 da doc da jvm para entender essa parte, na parte do constant_pool
    for (int i = 0; i < jclass->constant_pool_count - 1; i++) {

        //le a tag de 8 bits
        jclass->constant_pool[i].tag = beRead8(class_file);

        switch (jclass->constant_pool[i].tag) {

        case CONSTANT_Class:

            jclass->constant_pool[i].info.classInfo.name_index = beRead16(class_file);

            break;
        //Os 3 proximos utilizam os mesmos campos
        case CONSTANT_Fieldref:
        case CONSTANT_Methodref:
        case CONSTANT_InterfaceMethodref:

            jclass->constant_pool[i].info.refInfo.class_index         = beRead16(class_file);
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
            jclass->constant_pool[i].info.number64Info.low_bytes  = beRead32(class_file);
            i++; //64 bits usa duas posicoes na tabela do constant pool
            break;

        case CONSTANT_NameAndType:

            jclass->constant_pool[i].info.nameAndTypeInfo.name_index       = beRead16(class_file);
            jclass->constant_pool[i].info.nameAndTypeInfo.descriptor_index = beRead16(class_file);
            break;
        case CONSTANT_Utf8:

            //pega o tamanho da string
            jclass->constant_pool[i].info.utf8Info.length = beRead16(class_file);

            //aloca espaço para esse tamanho
            jclass->constant_pool[i].info.utf8Info.bytes = (uint8_t *)malloc(
                (jclass->constant_pool[i].info.utf8Info.length + 1) * sizeof(uint8_t));

            if (jclass->constant_pool[i].info.utf8Info.bytes == NULL) {
                printf("Erro na alocacao!\n");
                exit(2);
            }

            //le a string do arquivo para o espaço alocado
            fread(jclass->constant_pool[i].info.utf8Info.bytes,
                sizeof(uint8_t),
                jclass->constant_pool[i].info.utf8Info.length,
                class_file);

            jclass->constant_pool[i].info.utf8Info.bytes[jclass->constant_pool[i].info.utf8Info.length] = '\0';

            break;
        case CONSTANT_MethodHandle:

            jclass->constant_pool[i].info.methodHandleInfo.reference_kind  = beRead8(class_file);
            jclass->constant_pool[i].info.methodHandleInfo.reference_index = beRead16(class_file);
            break;
        case CONSTANT_MethodType:

            jclass->constant_pool[i].info.methodTypeInfo.descriptor_index = beRead16(class_file);

            break;
        case CONSTANT_InvokeDynamic:

            jclass->constant_pool[i].info.invokeDynamicInfo.bootstrap_method_attr_index = beRead16(class_file);
            jclass->constant_pool[i].info.invokeDynamicInfo.name_and_type_index         = beRead16(class_file);

            break;
        defaut:
            printf("TAG do constant pool inexistente!\n");
            exit(1);
        }
    }
}

void readAttributes(FILE *class_file, attribute_info *attr_info, uint16_t attribute_count, class_structure *jclass) {

    for (int i = 0; i < attribute_count; i++) {
        attr_info[i].attribute_name_index = beRead16(class_file);
        attr_info[i].attribute_length     = beRead32(class_file);

        uint16_t name_index = attr_info[i].attribute_name_index;

        char *attribute_type = (char *)malloc(
            (jclass->constant_pool[name_index - 1].info.utf8Info.length + 1) * sizeof(char *));

        if (attribute_type == NULL) {
            printf("Erro na alocacao!\n");
            exit(2);
        }

        strcpy(attribute_type, (char *)jclass->constant_pool[name_index - 1].info.utf8Info.bytes);

        if (!strcmp(attribute_type, "Code")) {
            attr_info[i].info.code_attribute.max_stack   = beRead16(class_file);
            attr_info[i].info.code_attribute.max_locals  = beRead16(class_file);
            attr_info[i].info.code_attribute.code_length = beRead32(class_file);

            //aloca o vetor para code
            if (attr_info[i].info.code_attribute.code_length > 0) {
                attr_info[i].info.code_attribute.code = (uint8_t *)malloc(
                    (attr_info[i].info.code_attribute.code_length) * sizeof(uint8_t));
                if (attr_info[i].info.code_attribute.code == NULL) {
                    printf("Erro na alocacao!\n");
                    exit(2);
                }
            } else {
                attr_info[i].info.code_attribute.code = NULL;
            }
            for (int j = 0; j < attr_info[i].info.code_attribute.code_length; j++) {
                attr_info[i].info.code_attribute.code[j] = beRead8(class_file);
            }

            attr_info[i].info.code_attribute.exception_table_length = beRead16(class_file);

            //aloca o vetor para exception_table
            if (attr_info[i].info.code_attribute.exception_table_length != 0) {
                attr_info[i].info.code_attribute.exception_table = (exception_table *)malloc(
                    (attr_info[i].info.code_attribute.exception_table_length) * sizeof(exception_table));
                if (attr_info[i].info.code_attribute.exception_table == NULL) {
                    printf("Erro na alocacao!\n");
                    exit(2);
                }
            } else {
                attr_info[i].info.code_attribute.exception_table = NULL;
            }
            for (int j = 0; j < attr_info[i].info.code_attribute.exception_table_length; j++) {
                attr_info[i].info.code_attribute.exception_table[j].start_pc   = beRead16(class_file);
                attr_info[i].info.code_attribute.exception_table[j].end_pc     = beRead16(class_file);
                attr_info[i].info.code_attribute.exception_table[j].handler_pc = beRead16(class_file);
                attr_info[i].info.code_attribute.exception_table[j].catch_type = beRead16(class_file);
            }

            attr_info[i].info.code_attribute.attributes_count = beRead16(class_file);

            //aloca o vetor para attributes
            if (attr_info[i].info.code_attribute.attributes_count != 0) {
                attr_info[i].info.code_attribute.attributes = (attribute_info *)malloc(
                    (attr_info[i].info.code_attribute.attributes_count) * sizeof(attribute_info));
                if (attr_info[i].info.code_attribute.attributes == NULL) {
                    printf("Erro na alocacao!\n");
                    exit(2);
                }
            } else {
                attr_info[i].info.code_attribute.attributes = NULL;
            }

            // Leitura dos atributos de cada atributo code (Sim, a parada é recursiva :o )
            readAttributes(class_file, attr_info[i].info.code_attribute.attributes,
                attr_info[i].info.code_attribute.attributes_count, jclass);

        } else if (!strcmp(attribute_type, "ConstantValue")) {

            attr_info[i].info.constant_value_attribute.constantvalue_index = beRead16(class_file);
        } else if (!strcmp(attribute_type, "Synthetic")) {
            // O synthetic não lê nada!
            continue;
        } else if (!strcmp(attribute_type, "Deprecated")) {
            // O deprecated não lê nada!
            continue;
        } else if (!strcmp(attribute_type, "LocalVariableTable")) {
            attr_info[i].info.localVariableTable_attribute.local_variable_table_length = beRead16(class_file);

            if (attr_info[i].info.localVariableTable_attribute.local_variable_table_length != 0) {
                attr_info[i].info.localVariableTable_attribute.local_variable_table = (local_variable_table *)malloc(
                    (attr_info[i].info.localVariableTable_attribute.local_variable_table_length) * sizeof(local_variable_table));
                if (attr_info[i].info.localVariableTable_attribute.local_variable_table == NULL) {
                    printf("Erro na alocacao!\n");
                    exit(2);
                }
            } else {
                attr_info[i].info.localVariableTable_attribute.local_variable_table = NULL;
            }
            for (int j = 0; j < attr_info[i].info.localVariableTable_attribute.local_variable_table_length; j++) {
                attr_info[i].info.localVariableTable_attribute.local_variable_table[j].start_pc         = beRead16(class_file);
                attr_info[i].info.localVariableTable_attribute.local_variable_table[j].length           = beRead16(class_file);
                attr_info[i].info.localVariableTable_attribute.local_variable_table[j].descriptor_index = beRead16(class_file);
                attr_info[i].info.localVariableTable_attribute.local_variable_table[j].index            = beRead16(class_file);
            }

        } else if (!strcmp(attribute_type, "Exceptions")) {

            attr_info[i].info.exceptions_attribute.number_of_exceptions = beRead16(class_file);

            //alocação para a tabela de exceções
            if (attr_info[i].info.exceptions_attribute.number_of_exceptions != 0) {
                attr_info[i].info.exceptions_attribute.excepetions_table = (uint16_t *)malloc(
                    (attr_info[i].info.exceptions_attribute.number_of_exceptions) * sizeof(uint16_t));
                if (attr_info[i].info.exceptions_attribute.excepetions_table == NULL) {
                    printf("Erro na alocacao!\n");
                    exit(2);
                }

            } else {
                attr_info[i].info.exceptions_attribute.excepetions_table = NULL;
            }
            for (int j = 0; i < attr_info[i].info.exceptions_attribute.number_of_exceptions; j++) {
                attr_info[i].info.exceptions_attribute.excepetions_table[j] = beRead16(class_file);
            }

            fseek(class_file, attr_info[i].attribute_length, SEEK_CUR);
        } else if (!strcmp(attribute_type, "BootstrapMethods")) {

            attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods = beRead16(class_file);
            if (attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods != 0) {
                attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods = (bootstrap_methods *)malloc(
                    (attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods) * sizeof(bootstrap_methods));

                if (attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods == NULL) {
                    printf("Erro na alocacao!\n");
                    exit(2);
                }

            } else {
                attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods = NULL;
            }

            for (int j = 0; j < attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods; j++) {
                attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_method_ref    = beRead16(class_file);
                attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments = beRead16(class_file);
                if (attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments != 0) {
                    attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments = (uint16_t *)malloc(
                        (attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments) * sizeof(uint16_t));

                    if (attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments == NULL) {
                        printf("Erro na alocacao!\n");
                        exit(2);
                    }

                } else {
                    attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments = NULL;
                }
                for (int k = 0; k < attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments; k++) {
                    attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments[k] = beRead16(class_file);
                }
            }

        } else if (!strcmp(attribute_type, "Signature")) {

            attr_info[i].info.signature_attribute.signature_index = beRead16(class_file);

        } else if (!strcmp(attribute_type, "LineNumberTable")) {
            attr_info[i].info.lineNumberTable_attribute.line_number_table_length = beRead16(class_file);
            if (attr_info[i].info.lineNumberTable_attribute.line_number_table_length != 0) {
                attr_info[i].info.lineNumberTable_attribute.line_number_table = (line_number_table *)malloc(
                    (attr_info[i].info.lineNumberTable_attribute.line_number_table_length) * sizeof(line_number_table));
                if (attr_info[i].info.lineNumberTable_attribute.line_number_table == NULL) {
                    printf("Erro na alocacao!\n");
                    exit(2);
                }
            } else {
                attr_info[i].info.lineNumberTable_attribute.line_number_table = NULL;
            }
            for (int j = 0; j < attr_info[i].info.lineNumberTable_attribute.line_number_table_length; j++) {
                attr_info[i].info.lineNumberTable_attribute.line_number_table[j].start_pc    = beRead16(class_file);
                attr_info[i].info.lineNumberTable_attribute.line_number_table[j].line_number = beRead16(class_file);
            }

        } else if (!strcmp(attribute_type, "SourceFile")) {

            attr_info[i].info.sourceFile_attribute.sourcefile_index = beRead16(class_file);

            uint16_t sourcefile_index = attr_info[i].info.sourceFile_attribute.sourcefile_index;

        } else if (!strcmp(attribute_type, "InnerClasses")) {

            attr_info[i].info.innerClasses_attribute.number_of_classes = beRead16(class_file);

            if (attr_info[i].info.innerClasses_attribute.number_of_classes != 0) {

                attr_info[i].info.innerClasses_attribute.classes = (classes *)malloc(
                    (attr_info[i].info.innerClasses_attribute.number_of_classes) * sizeof(classes));
                if (attr_info[i].info.innerClasses_attribute.classes == NULL) {
                    printf("Erro na alocacao!\n");
                    exit(2);
                }

            } else {
                attr_info[i].info.innerClasses_attribute.classes = NULL;
            }

            for (int j = 0; j < attr_info[i].info.innerClasses_attribute.number_of_classes; j++) {
                attr_info[i].info.innerClasses_attribute.classes[j].inner_class_info_index   = beRead16(class_file);
                attr_info[i].info.innerClasses_attribute.classes[j].outer_class_info_index   = beRead16(class_file);
                attr_info[i].info.innerClasses_attribute.classes[j].inner_name_index         = beRead16(class_file);
                attr_info[i].info.innerClasses_attribute.classes[j].inner_class_access_flags = beRead16(class_file);
            }
        } else {
            fseek(class_file, attr_info[i].attribute_length, SEEK_CUR);
        }
        //Free na string auxiliar (serve apenas para realizar a comparacao dos tipos de atributo)
        free(attribute_type);
    }
}

void readInterfaces(FILE *class_file, class_structure *jclass) {
    jclass->interfaces_count = beRead16(class_file);

    uint8_t interfaces_count = jclass->interfaces_count;

    //aloca o vetor de indices de constantes
    jclass->interfaces = (uint16_t *)malloc(
        (jclass->constant_pool_count - 1) * sizeof(uint16_t));
    if (jclass->interfaces == NULL) {
        printf("Erro na alocacao!\n");
        exit(2);
    }

    //lê do arquivo os indices e armazena no vetor de interfaces
    for (int i = 0; i < jclass->interfaces_count; i++) {
        jclass->interfaces[i] = beRead16(class_file);
    }
}

void readFields(FILE *class_file, class_structure *jclass) {
    jclass->fields_count = beRead16(class_file);

    uint8_t fields_count = jclass->fields_count;

    jclass->fields = (field_info *)malloc(
        (jclass->fields_count) * sizeof(field_info));

    if (jclass->fields == NULL) {
        printf("Erro na alocacao!\n");
        exit(2);
    }

    for (int i = 0; i < fields_count; i++) {
        jclass->fields[i].access_flags     = beRead16(class_file);
        jclass->fields[i].name_index       = beRead16(class_file);
        jclass->fields[i].descriptor_index = beRead16(class_file);
        jclass->fields[i].attributes_count = beRead16(class_file);

        uint16_t attribute_count = jclass->fields[i].attributes_count;

        if (attribute_count > 0) {
            jclass->fields[i].attributes = (attribute_info *)malloc(
                (attribute_count) * sizeof(attribute_info));
            if (jclass->fields[i].attributes == NULL) {
                printf("Erro na alocacao!\n");
                exit(2);
            }
            readAttributes(class_file, jclass->fields[i].attributes, attribute_count, jclass);
        } else {
            jclass->fields[i].attributes = NULL;
        }
    }
}

void readMethods(FILE *class_file, class_structure *jclass) {
    jclass->methods_count = beRead16(class_file);

    uint8_t methods_count = jclass->methods_count;

    jclass->methods = (method_info *)malloc(
        (jclass->methods_count) * sizeof(method_info));
    if (jclass->methods == NULL) {
        printf("Erro na alocacao!\n");
        exit(2);
    }

    for (int i = 0; i < methods_count; i++) {
        jclass->methods[i].access_flags     = beRead16(class_file);
        jclass->methods[i].name_index       = beRead16(class_file);
        jclass->methods[i].descriptor_index = beRead16(class_file);
        jclass->methods[i].attributes_count = beRead16(class_file);

        uint16_t attribute_count = jclass->methods[i].attributes_count;

        if (attribute_count > 0) {
            jclass->methods[i].attributes = (attribute_info *)malloc(
                (attribute_count) * sizeof(attribute_info));
            if (jclass->methods[i].attributes == NULL) {
                printf("Erro na alocacao!\n");
                exit(2);
            }
            readAttributes(class_file, jclass->methods[i].attributes, attribute_count, jclass);
        } else {
            jclass->methods[i].attributes = NULL;
        }
    }
}

void readClassAttributes(FILE *class_file, class_structure *jclass) {
    jclass->attributes_count = beRead16(class_file);

    uint16_t attribute_class_count = jclass->attributes_count;

    if (attribute_class_count > 0) {
        jclass->attribute = (attribute_info *)malloc(
            (attribute_class_count) * sizeof(attribute_info));
        if (jclass->attribute == NULL) {
            printf("Erro na alocacao!\n");
            exit(2);
        }
        readAttributes(class_file, jclass->attribute, attribute_class_count, jclass);
    } else {
        jclass->attribute = NULL;
    }
}

//desaloca a classe incluindo o utf8 do constant pool
void freeClass(class_structure *jclass) {
    if (jclass != NULL) {

        if (jclass->fields != NULL) {
            for (int i = 0; i < jclass->fields_count; i++) {
                freeAttributes(jclass->fields[i].attributes, jclass->fields[i].attributes_count, jclass);
            }

            free(jclass->fields);
        }

        if (jclass->methods != NULL) {
            for (int i = 0; i < jclass->methods_count; i++) {
                freeAttributes(jclass->methods[i].attributes, jclass->methods[i].attributes_count, jclass);
            }
            free(jclass->methods);
        }

        if (jclass->attribute != NULL) {
            freeAttributes(jclass->attribute, jclass->attributes_count, jclass);
        }

        if (jclass->interfaces != NULL) {
            free(jclass->interfaces);
        }

        for (int i = 0; i < jclass->constant_pool_count - 1; i++) {
            if (jclass->constant_pool[i].tag == CONSTANT_Utf8) {
                if (jclass->constant_pool[i].info.utf8Info.bytes != NULL)
                    free(jclass->constant_pool[i].info.utf8Info.bytes);
            }
        }

        if (jclass->constant_pool != NULL) {
            free(jclass->constant_pool);
        }

        free(jclass);
    }
}

void freeAttributes(attribute_info *attr_info, uint16_t attribute_count, class_structure *jclass) {

    for (int i = 0; i < attribute_count; i++) {
        uint16_t name_index = attr_info[i].attribute_name_index;

        char *attribute_type = (char *)malloc(
            (jclass->constant_pool[name_index - 1].info.utf8Info.length + 1) * sizeof(char *));

        if (attribute_type == NULL) {
            printf("Erro na alocacao!\n");
            exit(2);
        }

        strcpy(attribute_type, (char *)jclass->constant_pool[name_index - 1].info.utf8Info.bytes);

        if (!strcmp(attribute_type, "Code")) {

            //aloca o vetor para code
            if (attr_info[i].info.code_attribute.code != NULL) {
                free(attr_info[i].info.code_attribute.code);
            }

            //aloca o vetor para exception_table

            if (attr_info[i].info.code_attribute.exception_table != NULL) {
                free(attr_info[i].info.code_attribute.exception_table);
            }

            //aloca o vetor para attributes
            if (attr_info[i].info.code_attribute.attributes != NULL) {
                freeAttributes(attr_info[i].info.code_attribute.attributes,
                    attr_info[i].info.code_attribute.attributes_count, jclass);
            }
        } else if (!strcmp(attribute_type, "LocalVariableTable")) {

            if (attr_info[i].info.localVariableTable_attribute.local_variable_table != NULL) {
                free(attr_info[i].info.localVariableTable_attribute.local_variable_table);
            }

        } else if (!strcmp(attribute_type, "Exceptions")) {
            //alocacao para a tabela de exceções
            if (attr_info[i].info.exceptions_attribute.excepetions_table != NULL) {
                free(attr_info[i].info.exceptions_attribute.excepetions_table);
            }
        } else if (!strcmp(attribute_type, "BootstrapMethods")) {
            if (attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods != NULL) {
                for (int j = 0; j < attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods; j++) {
                    if (attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments != NULL) {
                        free(attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments);
                    }
                }
                free(attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods);
            }
        } else if (!strcmp(attribute_type, "LineNumberTable")) {
            if (attr_info[i].info.lineNumberTable_attribute.line_number_table != NULL) {
                free(attr_info[i].info.lineNumberTable_attribute.line_number_table);
            }
        } else if (!strcmp(attribute_type, "InnerClasses")) {
            if (attr_info[i].info.innerClasses_attribute.classes != NULL) {
                free(attr_info[i].info.innerClasses_attribute.classes);
            }
        }
        free(attribute_type);
    }
    free(attr_info);
}
