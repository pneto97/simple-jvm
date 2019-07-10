/**
 * @file attribute.h
 * @brief Arquivo com as estruturas de dados necessárias para o attribute
 * 
 */
#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <stdint.h>

//Exception_table

/**
 * Struct para atributo do tipo excepetion table
 */
typedef struct exception_table {
	uint16_t start_pc;
	uint16_t end_pc;
	uint16_t handler_pc;
	uint16_t catch_type;
} exception_table;

/**
 * Struct para atributo do tipo Constant value
 * constant_value_attribute é também associado ao field_info
 */
typedef struct constant_value_attribute {
	uint16_t constantvalue_index;
} constant_value_attribute;

/**
 * Struct para atributo do tipo Code
 * Utilizado nas instrucoes
 */
typedef struct code_attribute {
	uint16_t max_stack;
	uint16_t max_locals;
	uint32_t code_length;
	uint8_t *code;
	uint16_t exception_table_length;
	exception_table *exception_table;
	uint16_t attributes_count;
	struct attribute *attributes;
} code_attribute;

/**
 * Struct para atributo BootstrapMethods
 */
typedef struct bootstrapMethods_attributes {
	uint16_t num_bootstrap_methods;
	struct bootstrap_methods *bootstrap_methods;
} bootstrapMethods_attributes;

/**
 * Struct para os componentes de BootstrapMethods
 */
typedef struct bootstrap_methods {
	uint16_t bootstrap_method_ref;
	uint16_t num_bootstrap_arguments;
	uint16_t *bootstrap_arguments;
} bootstrap_methods;

/**
 * Struct para o atributo Excepetions
 */
typedef struct exceptions_attribute {
	uint16_t number_of_exceptions;
	uint16_t *excepetions_table;
} exceptions_attribute;

/**
 * Struct para o atributo Signature
 */
typedef struct signature_attribute {
	uint16_t signature_index;
} signature_attribute;

/**
 * Struct para o atributo Line Number Table
 */
typedef struct lineNumberTable_attribute {
	uint16_t line_number_table_length;
	struct line_number_table *line_number_table;
} lineNumberTable_attribute;

/**
 * Struct para os componentes do atributo Line Number Table
 */
typedef struct line_number_table {
	uint16_t start_pc;
	uint16_t line_number;
} line_number_table;

/**
 * Struct para o atributo Source File
 */
typedef struct sourceFile_attribute {
	uint16_t sourcefile_index;
} sourceFile_attribute;

/**
 * Struct para o atributo Inner Classes
 */
typedef struct innerClasses_attribute {
	uint16_t number_of_classes;
	struct classes *classes;
} innerClasses_attribute;

/**
 * Struct para os componentes do atributo Inner Classes
 */
typedef struct classes {
	uint16_t inner_class_info_index;
	uint16_t outer_class_info_index;
	uint16_t inner_name_index;
	uint16_t inner_class_access_flags;
} classes;

/**
 * Struct para o atributo Local Variable Table
 */
typedef struct localVariableTable_attribute {
	uint16_t attribute_name_index;
	uint32_t attribute_length;
	uint16_t local_variable_table_length;
	struct local_variable_table *local_variable_table;
} localVariableTable_attribute;

/**
 * Struct para os componentes do atributo Local Variable Table
 */
typedef struct local_variable_table {
	uint16_t start_pc;
	uint16_t length;
	uint16_t name_index;
	uint16_t descriptor_index;
	uint16_t index;
} local_variable_table;

/**
 * Struct geral dos attributtes
 * Union contendo todos os diferentes tipos de attributes
 */
typedef struct attribute {
	uint16_t attribute_name_index;
	uint32_t attribute_length;
	union {
		code_attribute code_attribute;
		constant_value_attribute constant_value_attribute;
		exceptions_attribute exceptions_attribute;
		bootstrapMethods_attributes bootstrapMethods_attributes;
		signature_attribute signature_attribute;
		lineNumberTable_attribute lineNumberTable_attribute;
		sourceFile_attribute sourceFile_attribute;
		innerClasses_attribute innerClasses_attribute;
		localVariableTable_attribute localVariableTable_attribute;
	} info;
} attribute_info;

#endif