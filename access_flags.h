/**
 * @file access_flags.h
 * @brief Defines com todos os tipos de flags utilizadas
 */

#define ACC_PUBLIC          0x0001
#define ACC_PRIVATE         0x0002
#define ACC_PROTECTED       0x0004
#define ACC_STATIC          0x0008
#define ACC_FINAL           0x0010
#define ACC_SUPER           0x0020 //Class
#define ACC_SYCRONIZED      0x0020 //Method
#define ACC_BRIDGE          0x0040 //Method
#define ACC_VOLATILE        0X0040 //Field
#define ACC_VARARGS         0x0080
#define ACC_NATIVE          0x0100
#define ACC_INTERFACE       0x0200
#define ACC_ABSTRACT        0x0400
#define ACC_STRICT          0x0800
#define ACC_SYNTHETIC       0x1000 
#define ACC_ANNOTATION      0x2000
#define ACC_ENUM            0x4000

typedef enum infotype {CLASS, METHOD, FIELD} infotype;

