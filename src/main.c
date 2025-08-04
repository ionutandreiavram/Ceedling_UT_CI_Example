#include "fibonacci.h"
#include "concatenate.h"
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void main(void)
{
	uint8_t input1[5] = {0x12, 0x13, 0x14, 0x15, 0x16};
	uint8_t input2[5] = {0x17, 0x18, 0x19, 0x20, 0xBB};
	int size = (sizeof(input1)/sizeof(input1[0]));
	uint16_t output[size];
	
	uint64_t fibonacci = 10;
	

	for (int i=0; i<size; i++)
	{
		output[i] = 0x0000;
	}

	Concatenate_arrays(input1, input2, output, size);
	
	for (int i=0; i<size; i++)
	{
		printf("Value of output[%d] is 0x%04x \n", i, output[i]);
	}
	
	printf("For value %d, fibonacci is %d: " , fibonacci, fibonacci_calculator(fibonacci));

}
