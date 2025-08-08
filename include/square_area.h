#ifndef SQUARE_AREA_H
#define SQUARE_AREA_H

typedef struct {
	int rows;
	int cols;
	int **input_matrix;
}in_matrix;

typedef struct {
	int **dp;
	int best_case;
}out_matrix;

int best_area_found(const in_matrix *inp_matr);
int profi_square_main(void);

#endif