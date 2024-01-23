#include "functions.h"

// 6.1
void scanfSecure(int* number, int min, int max) {
	while (scanf_s("%d", number) == 0 || *number < min || *number > max || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
}
void selectionSortEvenEll(int* array, int choice) {
	for (int i = 0; i < choice; i++)
	{
		int i1 = i;
		int m;
		if (array[i] % 2 == 0) {
			for (int j = i + 1; j < choice; j++)
				if (array[i1] > array[j] && array[j] % 2 == 0) i1 = j;
			m = array[i];
			array[i] = array[i1];
			array[i1] = m;
		}
	}
}
void inputArray(int maxEll, int* array, int choise) {
	if (choise == 1) {
		for (int i = 0; i < maxEll; i++)
		{
			array[i] = -1000 + rand() % 2001;
			if (array[i] < array[0]) array[0] = array[i];
		}
	}
	else if (choise == 2)
		for (int i = 0; i < maxEll; i++) {
			printf("\narray[%d]=", i);
			scanfSecure(&array[i], -10000, 10000);
		}
	else {
		int max = maxEll;
		for (int i = 0; i < maxEll; i++)
			array[i] = max--;
	}
}
void bubleSort(int* array, int maxEll) {
	int emptyCell = 0;
	for (int i = 0; i < maxEll - 1; i += 1)
		if(array[i]%2==0)
			for (int j = maxEll - 1; j > i; j -= 1)
			{
				if (array[j] % 2 == 0) {
					int k = j - 1;
					while (array[k] % 2 != 0 && k >= 0) k--;
					if (array[k] > array[j] && array[k] % 2 == 0)
					{
						emptyCell = array[k];
						array[k] = array[j];
						array[j] = emptyCell;
					}
				}
			}
}


// 6.2
void merge(int** nextArray, int** array1, int** array2, int lenght1, int lenght2, int col)
{
	int array1MinIndex = 0, array2MinIndex = 0, nextArrayMinIndex = 0;
	while (array1MinIndex < lenght1 && array2MinIndex < lenght2) {
		if (array1[array1MinIndex][col] <= array2[array2MinIndex][col])
		{
			nextArray[nextArrayMinIndex] = realloc(array1[array1MinIndex], (col + 1) * sizeof(int));
			array1MinIndex++;
		}
		else
		{
			nextArray[nextArrayMinIndex] = realloc(array2[array2MinIndex], (col + 1) * sizeof(int));
			array2MinIndex++;
		}
		nextArrayMinIndex++;
	}
	if (array1MinIndex < lenght1)
		while (array1MinIndex < lenght1)
		{
			nextArray[nextArrayMinIndex] = realloc(array1[array1MinIndex], (col + 1) * sizeof(int));
			array1MinIndex++;
			nextArrayMinIndex++;
		}
	if (array2MinIndex < lenght2)
		while (array2MinIndex < lenght2)
		{
			nextArray[nextArrayMinIndex] = realloc(array2[array2MinIndex], (col + 1) * sizeof(int));
			array2MinIndex++;
			nextArrayMinIndex++;
		}
}
void mergeSort(int** array, int maxEll, int col) {
	int** left;
	int** right;

	if (maxEll < 2) return;
	int mid = maxEll / 2;
	left = (int**)malloc(mid * sizeof(int*));
	right = (int**)malloc((maxEll - mid) * sizeof(int*));

	for (int i = 0; i < mid; i++)
	{
		left[i] = realloc(array[i], (col + 1) * sizeof(int));
	}
	for (int i = mid; i < maxEll; i++)
	{
		right[i - mid] = realloc(array[i], (col + 1) * sizeof(int));
	}
	mergeSort(left, mid, col);
	mergeSort(right, maxEll - mid, col);
	merge(array, left, right, mid, maxEll - mid, col);
}
void inputMatrix(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		*(matrix + i) = (int*)malloc((col + 1) * sizeof(int));
		for (int j = 0; j < col; j++) {
			printf("\n mareix[%d][%d]= ", i+1, j+1);
			scanfSecure(&matrix[i][j], -10000, 10000);
		}
	}
}
void sumEvenEll(int* array, int max, int* sum) {
	for (int i = 0; i < max; i++)
		if (array[i] % 2 == 0)
			*sum += array[i];
}
void outputMatrix(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < col; j++)
			printf(" %d", matrix[i][j]);
	}
}
void freeMatrix(int** matrix, int row) {
	for (int i = 0; i < row; i++) {
		free(*(matrix + i));
	}
	free(matrix);
}