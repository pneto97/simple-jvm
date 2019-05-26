//read_utils.c
#include "read_utils.h"

//inverte bytes de  inteiro de 16 bits
uint16_t reverse16(uint16_t a) {
    a = ((a & 0x00FF) << 8) | ((a & 0xFF00) >> 8);
    return a;
}

//inverte bytes de inteiro de 32 bits
uint32_t reverse32(uint32_t a) {
    a = ((a & 0x000000FF) << 24) |
        ((a & 0x0000FF00) << 8) |
        ((a & 0x00FF0000) >> 8) |
        ((a & 0xFF000000) >> 24);
    return a;
}

//le 8 bits
uint8_t beRead8(FILE *fp) {
    uint8_t buff = 0;
    fread(&buff, sizeof(buff), 1, fp);
    return buff;
}

//le 16 bits e converte de big endian pra little endian
uint16_t beRead16(FILE *fp) {
    uint16_t buff = 0;
    fread(&buff, sizeof(buff), 1, fp);
    buff = reverse16(buff);
    return buff;
}

//le 32 bits e converte de big endian para little endian
uint32_t beRead32(FILE *fp) {
    uint32_t buff = 0;
    fread(&buff, sizeof(buff), 1, fp);
    buff = reverse32(buff);
    return buff;
}


//Constroi valor de 16 bits a partir de dois de 8 bits
uint16_t build16(uint8_t hi, uint8_t low){
    return ((uint16_t)hi << 8) | low;
}
