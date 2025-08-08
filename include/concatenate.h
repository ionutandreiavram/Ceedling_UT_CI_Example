#ifndef CONCATENATE_H
#define CONCATENATE_H
#include <stdint.h>

void Concatenate_arrays(uint8_t *input1_ptr, uint8_t *input2_ptr, uint16_t *output_ptr, int input1_size, int input2_size, int out_size);
void concatenate_main(void);
#endif
