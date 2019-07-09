#ifndef INSTRUCTION_HELPERS_H
#define INSTRUCTION_HELPERS_H
#include <stdint.h>

char *getUtf8Class(uint16_t index);
char *getUtf8Name(uint16_t index);
char *getUtf8Type(uint16_t index);
double makeDouble(uint32_t high, uint32_t low);
float makeFloat(uint32_t bytes);
uint64_t doubleToUint64(double number);
uint32_t floatToUint32(float bytes);

#endif