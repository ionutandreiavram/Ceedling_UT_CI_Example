/*
 * Reads a binary matrix from user input with dynamic allocation.
 * Uses dynamic programming to find the largest square of 1's.
 * Handles memory allocation errors and input validation.
 * Demonstrates structs, pointers, and DP on 2D data.
 */
 
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "square_area.h"

int min(int a, int b, int c){
	int min, temp;
	temp = (a<b)?a:b;
	min = (c<temp)?c:temp;
	return min;
}

int best_area_found(const in_matrix *inp_matr){
	
	out_matrix output;
	output.best_case = 0;
	if (inp_matr->rows == 0 || inp_matr->cols == 0){
		return output.best_case;
	}
	output.dp = malloc(sizeof(int*)*inp_matr->rows);
	if (output.dp != NULL){
		for(int i=0; i<inp_matr->rows; i++){
			output.dp[i] = malloc(sizeof(int)*inp_matr->cols);
			if (output.dp[i] == NULL){
				while(i>0){
					free(output.dp[--i]);
				}
				free(output.dp);
				printf("error at dinamyc alloc");
				return -1;
			}
		}
	}
	else{
		printf("error at memory alloc!!");
		return -1;
	}
	for(int i=0; i<inp_matr->rows; i++){
		for(int j=0; j<inp_matr->cols; j++){
			if(inp_matr->input_matrix[i][j]==1){
				if(i==0 || j==0){
					output.dp[i][j] = 1;
				}
				else{
					output.dp[i][j] = 1 + min(output.dp[i-1][j], output.dp[i][j-1], output.dp[i-1][j-1]);
				}
			}
			else{
				output.dp[i][j] = 0;
			}
			if(output.best_case < output.dp[i][j]){
				output.best_case = output.dp[i][j];
			}
		}
	}
	for(int i=0; i<inp_matr->rows; i++){
		free(output.dp[i]);
	}
	free(output.dp);
	return output.best_case;
}

int profi_square_main(void){
	in_matrix input;
	int c;
	printf("insert rows: ");
	while(scanf("%d",&input.rows) != 1){
		printf("Rows invalid!!\n");
		while((c = getchar()) != '\n' && c != EOF){
			//empty buffer
		}
		printf("insert rows again: ");
	}
	
	printf("insert cols: ");
	while(scanf("%d",&input.cols)!=1){
		printf("Columns invalid! \n");
		while((c = getchar()) != '\n' && c != EOF){
			//empty buffer
		}
		printf("insert cols again: ");
	}

	input.input_matrix = malloc(sizeof(int*)*input.rows);
	if (input.input_matrix != NULL){
		for (int i=0; i<input.rows; i++){
			input.input_matrix[i] = malloc(sizeof(int)*input.cols);
			if (input.input_matrix[i] != NULL){
				continue;
			}
			else{
				while (i>0){
					free(input.input_matrix[--i]);
				}
				free(input.input_matrix);
				printf("error at dinamic allocation!!!");
				return -1;
			}
		}
	}
	else{
		printf("error at dinamic allocation!!!");
		return -1;
	}
	
	for (int i = 0; i<input.rows; i++){
		printf("Line %d values: \n", i);
		for (int j = 0; j<input.cols; j++){
			printf("Insert element for index %d: \n", j);
			while ((scanf("%d", &input.input_matrix[i][j]) != 1) || (input.input_matrix[i][j] < 0) || (input.input_matrix[i][j] > 1)){
				printf("Invalid value. Should be 0 or 1 \n");
				while((c = getchar()) != '\n' && c != EOF){
					//empty buffer
				}
				printf("Insert again element for index %d: \n", j);
			}
		}
	}
	int temp = best_area_found(&input);
	printf("For the given matrix, best square area you can form is %d:",  temp*temp);
	for (int i=0; i<input.rows; i++){
		free(input.input_matrix[i]);
	}
	free(input.input_matrix);
	return 0;
}
