#include "encoding.h"

// static const dictionary[8] = {
//     0b000000,
//     0b101001,
//     0b011010,
//     0b110011,
//     0b110100,
//     0b011101,
//     0b101110,
//     0b000111
// };

// static const dictionary[8] = {
//     0b000000,
//     0b100101,
//     0b010110,
//     0b110011,
//     0b001011,
//     0b101110,
//     0b011101,
//     0b111000
// };

static const dictionary[8] = {
    0b00000000,
    0b10100100,
    0b01101000,
    0b11001100,
    0b11010000,
    0b01110100,
    0b10111000,
    0b00011100
};

uint8_t block_encode(uint8_t* in_buffer, uint8_t in_length, uint8_t* out_buffer, uint8_t out_length) {
    if (out_length < (in_length * 2 + ((in_length % 3) != 0))) return ERROR_OUTPUT_BUFFER_TOO_SMALL;

    memset(out_buffer, 0, out_length);

    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t msg_v = 0;
    for (;i < in_length * 8; i++) {
        uint8_t byte = i / 8;
        uint8_t bit = 7 - i % 8;
        
        msg_v = (msg_v << 1) | ((in_buffer[byte] >> bit) & 1);

        if (i != 0 && i % 3 == 2) {
            uint8_t codeword = dictionary[msg_v];
            for (;j < (i+1) * 2; ++j) {
                uint8_t out_byte = j / 8;
                uint8_t out_bit = j % 8;
                out_buffer[out_byte] |= (codeword & 128) >> out_bit;
                codeword <<= 1;
            }
            msg_v = 0;
        }
    }
    if (i % 3 != 0) {
        msg_v <<= 3 - i % 3;
        uint8_t codeword = dictionary[msg_v];
        for (;j < (i+1) * 2; ++j) {
            uint8_t out_byte = j / 8;
            uint8_t out_bit = j % 8;
            out_buffer[out_byte] |= (codeword & 128) >> out_bit;
            codeword <<= 1;
        }
    }
    return 0;
}