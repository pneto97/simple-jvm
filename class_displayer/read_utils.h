//read_utils.h
//Funções genéricas criadas para auxiliar leitura de arquivos e manipulações de bits
#include <stdint.h>
#include <stdio.h>

//inverte bytes de  inteiro de 16 bits
uint16_t reverse16(uint16_t a);

//inverte bytes de inteiro de 32 bits
uint32_t reverse32(uint32_t a);

//le 8 bits
uint8_t beRead8(FILE *fp);

//le 16 bits e converte de big endian pra little endian
uint16_t beRead16(FILE *fp);

//le 32 bits e converte de big endian para little endian
uint32_t beRead32(FILE *fp);

//Constroi valor de 16 bits a partir de dois de 8 bits
uint16_t build16(uint8_t hi, uint8_t low);
