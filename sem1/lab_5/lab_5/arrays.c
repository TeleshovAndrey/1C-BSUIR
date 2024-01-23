#include "arrays.h"

//1 задание 


void input_secure(int* ell) {
	while (scanf_s("%d", ell) == 0 || *ell <= 0 || *ell > 100 || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
}

void input_array(int max_ell, double* array) {
	for (int i = 0; i < max_ell; i++) {
		printf("mass[%d]=", i);
		while (scanf_s("%lf", (array + i)) == 0 || *(array + i) <= -10000 || *(array + i) > 10000 || getchar() != '\n')
		{
			printf("Error, try again\n");
			rewind(stdin);
		}
	}
}

void delete_int_ell(int*max_ell, double* array) {
	for (int k = 0; k < *max_ell; k++)
		if (*(array + k) == (int)*(array + k)) {
			for (int i = k + 1; i < *max_ell; i++)
				*(array + i - 1) = *(array + i);
			*max_ell = *max_ell - 1;

			k--;
		}
}

void outpoot_array(int max, double* array) {
	if (max == 0) printf("Mass is empty");
	else printf("\n Resulsing array");
	for (int i = 0; i < max; i++)
		printf("\n array[%d]=%lf", i, *(array + i));
}


// 2 задача


void delete_side_diagonal(int row, int col, int** matrix) {
	
	for (int i = row - 1, j = 0; i >= 0; i--,j++) 
	{
		for (int k = j; k < col; k++)
			matrix[i][k] = matrix[i][k + 1];
	
		*(matrix + i) = realloc(*(matrix + i), (col - 1) * sizeof(int));
	}
}


void input_matrix(int row, int col, int** matrix) {
	for (int i = 0; i < row; i++) {
		*(matrix + i) = (int*)malloc(col * sizeof(int));
		for (int j = 0; j < col; j++) {
			printf("\n matrix[%d][%d]= ", i, j);
			while (scanf_s("%d", &matrix[i][j]) == 0 || matrix[i][j] <= -10000 || matrix[i][j] > 10000 || getchar() != '\n')
			{
				printf("Error, try again\n");
				rewind(stdin);
			}
		}
	}
}

void output_matrix(int row, int col, int** matrix) {
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < col; j++)
			printf(" %d", matrix[i][j]);
	}
}

void free_matrix(int row, int** matrix) {
	for (int i = 0; i < row; i++) {
		free(*(matrix + i));
	}
	free(matrix);
}


// 3 задача


void input_duo_array(int row, int** array) {
	for (int i = 0, row_length; i < row; i++) {
		row_length=1;
		array[i] = (int*)malloc(sizeof(int) * row_length);
		for (int j = 0; j < row_length; j++) {
			scanf_s("%d", &array[i][j]);
			
			if (array[i][j] != -100)
			{
				row_length++;
				array[i] = realloc(array[i], sizeof(int) * row_length);
			}
		}
	}
}

void add_odd_elements_even_lines(int row, int** array) {
	
	for (int i = 0; i < row; i++)
		if (i % 2 != 0) {
			int col = 1;
			for (int num = 0; array[i][num] != 0;num++) col++;
			for (int j = col - 1; j >= 0; j--)
				if (array[i][j] % 2 != 0) {
					*(array + i) = realloc(*(array + i), (col + 1) * sizeof(int));

					for (int k = col - 1; k >= j; k--) {
						array[i][k + 1] = array[i][k];
					}
					col++;
				}
		}
}

void output_duo_array(int row, int** array) {
	for (int i = 0,j; i < row; i++) {
		j = 0;
		printf("\n");
		while (array[i][j]!=-100) {
			printf(" %d ", array[i][j]);
			j++;
		}
	}
}
