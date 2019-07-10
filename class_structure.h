/**
 * @file class_structure.h
 * @brief Arquivo contendo as principais estruturas de dados necessárias para armazenar os dados do .class
 */

#ifndef CLASS_STRUCTURE_H
#define CLASS_STRUCTURE_H
#include "attribute.h"
#include "constant_pool.h"
#include <stdint.h>

/**
 * @brief Estrutura de dados para armazenar o constant pool, possui tag inteiro de 8 bits em comum para todos os elementos  
 * Na union, possui todos os tipos de info possíveis
 */
typedef struct constant_pool {
	uint8_t tag;
	// uint8_t* info;
	union {
		ClassInfo classInfo; //para o CONSTANT_Class_info
		Ref refInfo; //para fields, metodos e interfaces
		StringInfo stringInfo; //para o CONSTANT_String_info
		Number32 integerInfo, floatInfo, number32Info; //Para o Integer e float
		Number64 longInfo, doubleInfo, number64Info; //Para CONSTANT_Long_info e CONSTANT_Double_info
		NameAndTypeInfo nameAndTypeInfo; //CONSTANT_NameAndType_info
		Utf8Info utf8Info; //CONSTANT_Utf8_info
		MethodHandleInfo methodHandleInfo; //CONSTANT_MethodHandle_info
		MethodTypeInfo methodTypeInfo; //CONSTANT_MethodType_info
		InvokeDynamicInfo invokeDynamicInfo; //CONSTANT_InvokeDynamic_info
	} info;

} cp_info;

/**
 * @brief Estrutura de dados para armazenar as informações os fields
 * 
 */
typedef struct field_info {
	uint16_t access_flags;
	uint16_t name_index;
	uint16_t descriptor_index;
	uint16_t attributes_count;
	attribute_info *attributes;
} field_info;

/**
 * @brief Estrutura de dados para armazenar as informações os métodos
 * 
 */
typedef struct method_info {
	uint16_t access_flags;
	uint16_t name_index;
	uint16_t descriptor_index;
	uint16_t attributes_count;
	attribute_info *attributes;
} method_info;

/**
 * @brief Estrutura geral da classe. Guarda os dados lidos do .class
 * 
 */
typedef struct class_structure {
	uint32_t magic;
	uint16_t minor_version;
	uint16_t major_version;
	uint16_t constant_pool_count;
	cp_info *constant_pool;
	uint16_t access_flags;
	uint16_t this_class;
	uint16_t super_class;
	uint16_t interfaces_count;
	uint16_t *interfaces;
	uint16_t fields_count;
	field_info *fields;
	uint16_t methods_count;
	method_info *methods;
	uint16_t attributes_count;
	attribute_info *attribute;
} class_structure;

#endif