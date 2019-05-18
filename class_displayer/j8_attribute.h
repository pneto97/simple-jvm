//attribute.h
//estruturas de dados necessarias para o attribute

#include <stdint.h>

// struct attribute_info;
// struct code_attribute;

//Exception_table
typedef struct exception_table {
    uint16_t start_pc;
    uint16_t end_pc;
    uint16_t handler_pc;
    uint16_t catch_type;
} exception_table;

//constant_value_attribute é associado ao field_info
typedef struct constant_value_attribute {
    uint16_t constantvalue_index;
}constant_value_attribute;

//code_attribute é relacionado ao method_info
typedef struct code_attribute {
    uint16_t max_stack;
    uint16_t max_locals;
    uint32_t code_length;
    uint8_t *code;
    uint16_t exception_table_length;
    exception_table *exception_table;
    uint16_t attributes_count;
    struct attribute *attributes;
}code_attribute;

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

typedef struct signature_attribute {
    uint16_t signature_index;
}signature_attribute;

typedef struct lineNumberTable_attribute {
    uint16_t line_number_table_length;
    struct line_number_table *line_number_table;
}lineNumberTable_attribute;

typedef struct line_number_table {
    uint16_t start_pc;
    uint16_t line_number;
}line_number_table;

typedef struct sourceFile_attribute {
    uint16_t sourcefile_index;
}sourceFile_attribute;

typedef struct innerClasses_attribute {
    uint16_t number_of_classes;
    struct classes *classes;
}innerClasses_attribute;

typedef struct classes {
    uint16_t inner_class_info_index;
        uint16_t outer_class_info_index;
        uint16_t inner_name_index;
        uint16_t inner_class_access_flags;
}classes;

//Atribute info
typedef struct attribute{
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    //attribute_info;
    union{
        code_attribute code_attribute;
        constant_value_attribute constant_value_attribute;
        exceptions_attribute exceptions_attribute;
        stackMapTable_attribute stackMapTable_attribute;
        bootstrapMethods_attribute bootstrapMethods_attribute;
        signature_attribute signature_attribute;
        lineNumberTable_attribute lineNumberTable_attribute;
        sourceFile_attribute sourceFile_attribute;
        innerClasses_attribute innerClasses_attribute;
    }info;
} attribute_info;

//ainda faltam mais estruturas!
