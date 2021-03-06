/**
 * @file primitive_types.h
 * @brief Contêm defines para os tipos de dados primitivos
 */
#define T_BOOLEAN	4
#define T_CHAR	    5
#define T_FLOAT	    6
#define T_DOUBLE	7
#define T_BYTE	    8
#define T_SHORT	    9
#define T_INT	    10
#define T_LONG	    11

#include <stdint.h>

/**
 * @brief Realiza o print do tipo primitivo
 * 
 * @param atype 
 */
void printPrimitiveType(int8_t atype);