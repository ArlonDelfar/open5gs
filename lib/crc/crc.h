#ifndef CRC_H
#define CRC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum {
    CRC24A = 0b110000110010011001111101,
    CRC24B = 0b110000000000000000110001,
    CRC24C = 0b110110010101100010001011,
    CRC16  = 0b1000100000010000,
    CRC11  = 0b11100010000,
    CRC6   = 0b110000,
} crc_type_e;

uint32_t calculate_crc(uint8_t* buffer, uint8_t size, crc_type_e crc_type);


#ifdef __cplusplus
}
#endif

#endif /* CRC_H */
