//attribute.h
//estruturas de dados necessarias para o attribute

#include <stdint.h>

//constant_value_attribute é associado ao field_info
typedef struct constant_value_attribute {
    uint16_t constantvalue_index;
}constant_value_attribute;

//code_attribute é relacionado ao method_info
typedef struct code_attribute {
    uint16_t max_stack;
    uint16_t max_locals;
    uint32_t code_length;
    //uint8_t code[code_length];  ler secao 4.9 da documentacao
    uint16_t exception_table_length;
    uint16_t *exception_table;
    uint16_t attributes_count;
    //attribute *attributes;
} code_attribute;

typedef struct exceptions_attribute {
    uint16_t number_of_exceptions;
    uint16_t *excepetions_table;
} exceptions_attribute;

typedef struct classes{
    uint16_t inner_class_info_index;
    uint16_t outer_class_info_index;
    uint16_t inner_name_index;
    uint16_t inner_class_access_flags;
}classes;

typedef struct inner_classes_attribute {
    uint16_t number_of_classes;
    classes  *classes;
} inner_classes_attribute;

//ainda faltam mais estruturas!
