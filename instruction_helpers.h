#ifndef INSTRUCTION_HELPERS_H
#define INSTRUCTION_HELPERS_H
#include <stdint.h>
#include "frame.h"

char *getUtf8Class(uint16_t index);
char *getUtf8Name(uint16_t index);
char *getUtf8Type(uint16_t index);
char *getUtf8Ref(uint16_t index);
double makeDouble(uint32_t high, uint32_t low);
float makeFloat(uint32_t bytes);
long makeLong(uint32_t high, uint32_t low);
object* buildObject(class_loaded *lclass);
uint64_t doubleToUint64(double number);
uint64_t longToUint64(long number);
uint32_t floatToUint32(float bytes);
data_type PrimitiveType(int8_t atype);

#endif