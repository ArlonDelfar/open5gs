#include <stdint.h>

#include "crc.h"

#define CRC24_MSB_BIT_MASK 0x800000U
#define CRC16_MSB_BIT_MASK 0x8000U
#define CRC11_MSB_BIT_MASK 0x400U
#define CRC6_MSB_BIT_MASK  0x20U

#define CRC24_MASK 0xFFFFFFU
#define CRC16_MASK 0xFFFFU
#define CRC11_MASK 0x7FFU
#define CRC6_MASK  0x3FU

#define CRC24_BIT_SHIFT 16
#define CRC16_BIT_SHIFT 8
#define CRC11_BIT_SHIFT 3
#define CRC6_BIT_SHIFT 0

typedef struct {
    uint32_t crc;
    uint32_t mask;
    uint32_t msb_bit_mask;
    uint8_t bit_shift;
} crc_params_t;

static void set_crc_params(crc_params_t* crc_params, crc_type_e crc_type) {

    if (crc_type == CRC24A || 
        crc_type == CRC24B ||
        crc_type == CRC24C) {
        crc_params->mask = CRC24_MASK;
        crc_params->msb_bit_mask = CRC24_MSB_BIT_MASK;
        crc_params->bit_shift = CRC24_BIT_SHIFT;  
    }
    else if (crc_type == CRC16) {
        crc_params->mask = CRC16_MASK;
        crc_params->msb_bit_mask = CRC16_MSB_BIT_MASK; 
        crc_params->bit_shift = CRC16_BIT_SHIFT;   
    }
    else if (crc_type == CRC11) {
        crc_params->mask = CRC11_MASK;
        crc_params->msb_bit_mask = CRC11_MSB_BIT_MASK; 
        crc_params->bit_shift = CRC11_BIT_SHIFT;  
    }
    else if (crc_type == CRC6) {
        crc_params->mask = CRC6_MASK;
        crc_params->msb_bit_mask = CRC6_MSB_BIT_MASK; 
        crc_params->bit_shift = CRC6_BIT_SHIFT;  
    }
    else
    {
        //wrong poly!;
    }
}

uint32_t calculate_crc(uint8_t* bytes, uint8_t size, crc_type_e crc_type) {

    crc_params_t crc_params;
    set_crc_params(&crc_params, crc_type);

    for (uint8_t byte_idx=0; byte_idx<size; byte_idx++)
    {
        crc_params.crc ^= (bytes[byte_idx] << crc_params.bit_shift); 					

         for (uint8_t bit_idx = 0; bit_idx < 8; bit_idx++)
        {
            if ((crc_params.crc & crc_params.msb_bit_mask) != 0)
            {
                crc_params.crc = ((crc_params.crc << 1) ^ crc_type);
            }
            else
            {
                crc_params.crc <<= 1;
            }
        }
    }

    return (crc_params.crc & crc_params.mask); 
}