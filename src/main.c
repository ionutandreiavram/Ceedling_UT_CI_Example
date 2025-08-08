#include "fibonacci.h"
#include "concatenate.h"
#include "calculator.h"
#include "square_area.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void main(void)
{
	int choose=0;
	int buf;
	printf("Choose what you need: \n")
	printf("1 - Fibonacci \n 2- Concatenate Arrays \n 3 - Dummy Sqare Area \n");
	printf("4 - Profi Sqare Area");
	while ((scanf("%d", &choose)!=1) || (choose>4) || (choose<1)){
		printf("Invalid choose! \n");
		while(buf != '\n' && buf != EOF){
			buf = getchar();
		}
	}
	switch(choose){
		case FIBONACCI:
			int fibonacci;
			printf("Insert fibonacii number: \n");
			while(((scanf("%d" &fibonacci)!=1)) || (fibonacci>80) || (fibonacci < 0)){
				printf("Invalid number!  \n");
				while(fibonacci != '\n' && fibonacci != EOF){
					buf = getchar();
				}
			}
			(void)fibonacci_calculator(fibonacci);
			break;
		
		case CONCATENATE_ARR:
			concatenate_main();
			break;
		
		case DUMMY_SQ_AREA:
			int matrix[5][5]={{1,1,1,0,0},
				  {1,0,1,1,1},
				  {1,0,1,1,1},
				  {0,1,1,1,1},
				  {1,0,1,1,1}};
			int val = return_sqare_dummy(matrix,5,5);
			printf("Best sqare area found is %d", val*val);
			break;
		
		case PROFI_SQ_AREA:
			profi_square_main();
			break;

	}
}
