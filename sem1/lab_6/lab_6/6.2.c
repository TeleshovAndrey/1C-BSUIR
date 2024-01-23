#include "functions.h"
/*
2.	¬ матрице размером NxM выполнить сортировку строк по возрастанию суммы четных элементов методом сли€ни€
*/

int main() {
	int** matrix;
	int sum;
	int row, col;
	
	printf("Enter row ");
	scanfSecure(&row, 1 ,10);

	printf("\nEnter col ");
	scanfSecure(&col, 1, 10);
	
	matrix = (int**)malloc(row * sizeof(int*));
	
	inputMatrix(matrix, row, col);

	for (int i = 0; i < row; i++) {
		sum = 0;
		sumEvenEll(matrix[i], col, &sum);
		matrix[i][col] = sum;
	}

	printf("\nstart matrix");
	outputMatrix(matrix, row, col);

	mergeSort (matrix, row, col);

	printf("\nresulting matrix");
	outputMatrix(matrix, row, col);
	
	freeMatrix(matrix, row);
}