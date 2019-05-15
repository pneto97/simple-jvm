//j8_class_structure.h
//Estruturas de dados necessárias para armazenar os dados do .class

#include <stdint.h>
#include "j8_constant_pool.h"

//um item do constant pool, possui a tag que informa o tipo de dado e mais alguns bytes que dependem da tag
typedef struct constant_pool{
    uint8_t tag;
//    uint8_t* info;
    union{
        ClassInfo classInfo; //para o CONSTANT_Class_info

        //para fields, metodos e interfaces
        Ref refInfo;

        StringInfo stringInfo; //para o CONSTANT_String_info

        Number32 integerInfo, floatInfo, number32Info; //Para o Integer e float

        Number64 longInfo, doubleInfo, number64Info; //Para CONSTANT_Long_info e CONSTANT_Double_info

        NameAndTypeInfo nameAndTypeInfo; //CONSTANT_NameAndType_info

        Utf8Info utf8Info; //CONSTANT_Utf8_info

        MethodHandleInfo methodHandleInfo; //CONSTANT_MethodHandle_info

        MethodTypeInfo methodTypeInfo; //CONSTANT_MethodType_info

        InvokeDynamicInfo invokeDynamicInfo; //CONSTANT_InvokeDynamic_info

    }info;

} cp_info;

typedef struct attribute_info{
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint8_t *info;
} attribute_info;

typedef struct inner_classes_attribute {
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint16_t number_of_classes;
    classes  *classes;
} inner_classes_attribute;

typedef struct classes{
    uint16_t inner_class_info_index;
    uint16_t outer_class_info_index;
    uint16_t inner_name_index;
    uint16_t inner_class_access_flags;
}classes;

typedef struct field_info{
   uint16_t access_flags;
   uint16_t name_index;
   uint16_t descriptor_index;
   uint16_t attributes_count;
   attribute_info *attributes;
} field_info;

//constant_value_attribute é associado ao field_info
typedef struct constant_value_attribute {
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint16_t constantvalue_index;
}constant_value_attribute;

typedef struct method_info{
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    attribute_info *attribute_info;
} method_info;

//code_attribute é relacionado ao method_info
typedef struct code_attribute {
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint16_t max_stack;
    uint16_t max_locals;
    uint32_t code_length;
    //uint8_t code[code_length];  ler secao 4.9 da documentacao
    uint16_t exception_table_length;
    uint16_t *exception_table;
    uint16_t attributes_count;
    attribute_info *attributes;
} code_attribute;

typedef struct exceptions_attribute {
       uint16_t attribute_name_index;
       uint32_t attribute_length;
       uint16_t number_of_exceptions;
       uint16_t *info; //ponteiro para a leitura de info->classInfo
} exceptions_attribute;

typedef struct exception_table {
    uint16_t start_pc;
    uint16_t end_pc;
    uint16_t handler_pc;
    uint16_t catch_type;
} exception_table;

//estrutura da classe. Guarda os lados lidos do .class
typedef struct class_structure {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    cp_info* constant_pool;
    uint16_t access_flags;
    uint16_t this_class;
    uint16_t super_class;
    //Lucas
    uint16_t interfaces_count;
    uint16_t *interfaces;
    //Demetrio
    uint16_t fields_count;
    field_info *fields;
    //Chris
    uint16_t methods_count;
    method_info *methods;
    //Jomas
    uint16_t attributes_cont;
    attribute_info *attributes;
} class_structure ;
