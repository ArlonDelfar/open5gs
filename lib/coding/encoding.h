#ifndef ENCODING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define ERROR_OUTPUT_BUFFER_TOO_SMALL 1

uint8_t block_encode(uint8_t* in_buffer, uint8_t in_length, uint8_t* out_buffer, uint8_t out_length);

#ifdef __cplusplus
}
#endif

#endif //ENCODING_H