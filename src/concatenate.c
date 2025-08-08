#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void Concatenate_arrays(uint8_t *input1_ptr, uint8_t *input2_ptr, uint16_t *output_ptr, int input1_size, int input2_size, int out_size)
{
	int array_sizes_diff = input1_size - input2_size;
	int min_size = input1_size > input2_size? input2_size:input1_size;
	for (int i=0; i<min_size; i++)
	{
		*output_ptr = ((uint16_t)*input1_ptr<<8) | *input2_ptr;
		output_ptr++; input1_ptr++; input2_ptr++;
	}
	if(array_sizes_diff < 0){ //first vector is smaller
		for (int i=min_size; i<out_size; i++){
			*output_ptr = ((uint16_t)*input1_ptr<<8);
			output_ptr++; input1_ptr++;
		}
	}
	else if (array_sizes_diff > 0){ //second vector is smaller
		for (int i=min_size; i<out_size; i++){
			*output_ptr = ((uint16_t)*input2_ptr);
			output_ptr++; input2_ptr++;
		}
	}
}


void concatenate_main(void){
	uint8_t arr_size1; uint8_t arr_size2;
	int buf;
	printf("Insert 1st arr size (max 10): \n");
	while((scanf("%u", &arr_size1)!=1) || (arr_size1 > 10)){
		printf("Invalid value! \n");
		while(((buf=getchar())!='\n') && (buf != EOF)){
			//just empty buffer
		}
		printf("Try again: \n");
	}
	printf("Insert 2nd arr size (max 10): \n");
	while((scanf("%u", &arr_size2)!=1) || (arr_size2 > 10)){
		printf("Invalid value! \n");
		while(((buf=getchar())!='\n') && (buf != EOF)){
			//just empty buffer
		}
		printf("Try again: \n");
	}

	uint8_t* array1=malloc(sizeof(uint8_t)*arr_size1);
	uint8_t* array2=malloc(sizeof(uint8_t)*arr_size2);
	int out_arr_size = arr_size1>arr_size2? arr_size1:arr_size2;
	uint16_t* out_array=malloc(sizeof(uint16_t)*out_arr_size);

	for(int i=0; i<arr_size1; i++){
		printf("Insert element %d out of %u of 1st array: \n", i, arr_size1);
		while((scanf("%u", &array1[i]))!=1){
			printf("Invalid value! \n");
			while(((buf=getchar())!='\n') && (buf != EOF)){
			//just empty buffer
			}
			printf("Try again! \n");
		}
	}
	for(int i = 0; i<arr_size2; i++){
		printf("Insert element %d out of %u of 2nd array: \n", i, arr_size2);
		while((scanf("%u", &array2[i]))!=1){
			printf("Invalid value! \n");
			while(((buf=getchar())!='\n') && (buf != EOF)){
				//just empty buffer
			}
			printf("Try again! \n");
		}
	}
	Concatenate_arrays(array1, array2, out_array, arr_size1, arr_size2, out_arr_size);
	for (int i=0; i<out_arr_size; i++){
		printf("Concatenated arrays output: %d ", out_array[i]);
	}
	free(array1);
	free(array2);
	free(out_array);
}
