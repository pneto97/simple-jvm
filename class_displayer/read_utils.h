/**
 * @file read_utils.h
 * @brief Funções genéricas criadas para auxiliar leitura de arquivos e manipulações de bits
 */

#include <stdint.h>
#include <stdio.h>

/**
 * @brief Inverte bytes de inteiro de 16 bits
 * 
 * @param 16 Bits de entrada
 * @return uint16_t Resultado da inversão em 16 Bits
 */
uint16_t reverse16(uint16_t a);

/**
 * @brief Inverte bytes de inteiro de 32 bits
 * 
 * @param 32 Bits de entrada
 * @return uint16_t Resultado da inversão em 32 Bits
 */
uint32_t reverse32(uint32_t a);

/**
 * @brief Lê 8 bits e converte de big endian pra little endian
 * 
 * @param 8 Bits de entrada
 * @return uint16_t Resultado da inversão em 8 Bits
 */
uint8_t beRead8(FILE *fp);

/**
 * @brief Lê 16 bits e converte de big endian pra little endian
 * 
 * @param 16 Bits de entrada
 * @return uint16_t Resultado da inversão em 16 Bits
 */
uint16_t beRead16(FILE *fp);

/**
 * @brief Lê 32 bits e converte de big endian pra little endian
 * 
 * @param 32 Bits de entrada
 * @return uint16_t Resultado da inversão em 32 Bits
 */
uint32_t beRead32(FILE *fp);

/**
 * @brief Constroi valor de 16 bits a partir de dois de 8 bits
 * 
 * @param hi 8 bits mais signficativos
 * @param low 8 bits menos significativos
 * @return uint16_t Resultado da construção em 16 bits
 */
uint16_t build16(uint8_t hi, uint8_t low);

/**
 * @brief Constroi valor de 32 bits a partir de dois de 16 bits
 * 
 * @param hi 16 bits mais signficativos
 * @param low 16 bits menos significativos
 * @return uint32_t Resultado da construção em 32 bits
 */
uint32_t build32(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4);
