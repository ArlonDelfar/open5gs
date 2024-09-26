#ifndef CRC_H
#define CRC_H

#include <stdint.h>

#define CRC_SUCCESS 0
#define CRC_FAILURE -1

uint8_t crc(uint8_t* buffor, uint8_t bufforSize, uint8_t poly);

#endif