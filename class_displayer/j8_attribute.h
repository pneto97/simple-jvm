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
    uint8_t  *code;
    uint16_t exception_table_length;
    //exception_table *exception_table;
    uint16_t attributes_count;
    //attribute_info *attributes;
}code_attribute;

/*
typedef struct exception_table{
    uint16_t start_pc;
    uint16_t end_pc;
    uint16_t handler_pc;
    uint16_t catch_type;
}exception_table;
*/
typedef struct stackMapTable_attribute {
    uint16_t  attribute_name_index;
    uint32_t  attribute_length;
    uint16_t  number_of_entries;
    //stack_map_frame *entries;
}stackMapTable_attribute;

typedef struct bootstrapMethods_attribute {
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint16_t num_bootstrap_methods;
    /*union{
        uint16_t bootstrap_method_ref;
        uint16_t num_bootstrap_arguments;
        uint16_t *bootstrap_arguments;
    } bootstrap_methods;*/
}bootstrapMethods_attribute;

typedef struct exceptions_attribute {
    uint16_t number_of_exceptions;
    uint16_t *excepetions_table;
}exceptions_attribute;


//ainda faltam mais estruturas!
