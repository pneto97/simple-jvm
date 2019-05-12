//constant_pool.h
//estruturas de dados necessarias para o constant pool
#include <stdint.h>

//Constant POOL TAGS
#define CONSTANT_Class 7
#define CONSTANT_Fieldref 9
#define CONSTANT_Methodref 10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_String 8
#define CONSTANT_Integer 3
#define CONSTANT_Float 4
#define CONSTANT_Long 5
#define CONSTANT_Double 6
#define CONSTANT_NameAndType 12
#define CONSTANT_Utf8 1
#define CONSTANT_MethodHandle 15
#define CONSTANT_MethodType 16
#define CONSTANT_InvokeDynamic 18

//para CONSTANT_Class_info
typedef struct class_info{
    uint16_t name_index;
} ClassInfo;

//referencias para Fiedref_info, Methodref_info e InterfaceMethodref_info
typedef struct references{
    uint16_t class_index;
    uint16_t name_and_type_index;
}Ref;

//CONSTANT_String_info
typedef struct string_info{
    uint16_t string_index;
} StringInfo;

//CONSTANT_Integer_info e CONSTANT_Float_info
typedef struct number32{
    uint32_t bytes;
} Number32;

//CONSTANT_Long_info e CONSTANT_Double_info
typedef struct number64{
   uint32_t high_bytes;
   uint32_t low_bytes;
}Number64;

//CONSTANT_NameAndType_info
typedef struct name_and_type_info{
    uint16_t name_index;
    uint16_t descriptor_index;
}NameAndTypeInfo;

//CONSTANT_Utf8_info
typedef struct utf8_info{
    uint16_t length;
    uint8_t* bytes;
}Utf8Info;

//CONSTANT_MethodHandle_info
typedef struct method_handle_info{
   uint8_t reference_kind;
   uint16_t reference_index;
} MethodHandleInfo;

//CONSTANT_MethodType_info
typedef struct Method_Type_info{
    uint16_t descriptor_index;
} MethodTypeInfo;

//CONSTANT_InvokeDynamic_info
typedef struct invoke_dynamic_info{
    uint16_t bootstrap_method_attr_index;
    uint16_t name_and_type_index;
} InvokeDynamicInfo;
