/*

Demonstrates finding the largest square of 1's in a fixed-size binary matrix.

Uses static 2D arrays and dynamic programming for simplicity and clarity.

Limited to 5x5 matrices and fixed input; no dynamic allocation or input validation.

Good for educational purposes, illustrating DP without complexity of memory management.
*/

#include <stdlib.h>
#include <stdio.h>
#include "dummy_sqare_area.h"

int min_dummy(int a, int b, int c){
	int min, temp;
	temp = (a<b)?a:b;
	min = (c<temp)?c:temp;
	return min;
}

int return_sqare_dummy(int matrix[][5], int row, int col){
	int dp[5][5] = {0};
	int best_case = 0;
	
	if (row < 0 || col < 0){
		return 0;
	}
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			if (matrix[i][j] == 1){
				if (i==0 || j==0){ 
					dp[i][j] = 1;
				}
				else{
					dp[i][j] = 1 + min_dummy(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]); 
				}
			}
			else{
				dp[i][j] = 0; 
			}
			if (best_case < dp[i][j]){
				best_case = dp[i][j];
			}
		}
	}
	return best_case;
}

