/**
 * @file data_type.h
 * @brief Estruturas de dados para definir os tipos de dados
 */
#ifndef DATA_TYPE_H
#define DATA_TYPE_H

typedef enum data_type { 
    BYTE_TYPE,
    SHORT_TYPE,
    INT_TYPE,
    LONG_TYPE,
    CHAR_TYPE,
    BOOLEAN_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    RETURN_ADDR_TYPE, 
    CLASS_TYPE,
    ARRAY_TYPE,
    INTERFACE_TYPE,
    NULL_TYPE,
} data_type;

typedef enum cat_type { 
    UNIQUE,
    FIRST,
    SECOND,
} cat_type;

#endif