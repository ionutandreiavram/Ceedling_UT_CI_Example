#include <stdint.h>

void Concatenate_arrays(uint8_t *input1_ptr, uint8_t *input2_ptr, uint16_t *output_ptr, int size)
{
	for (int i=0; i<size; i++)
	{
		*output_ptr = ((uint16_t)*input1_ptr<<8) | *input2_ptr;
		output_ptr++; input1_ptr++; input2_ptr++;
	}
}

