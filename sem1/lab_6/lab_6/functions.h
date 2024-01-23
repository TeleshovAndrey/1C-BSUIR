#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 6.1
void scanfSecure(int* number, int min, int max);
void inputArray(int maxEll, int* array, int choise);
void selectionSortEvenEll(int* array, int choice);
void bubleSort(int* array, int maxEll);

// 6.2
void merge(int** nextArray, int** array1, int** array2, int lenght1, int lenght2, int col);
void mergeSort(int** array, int maxEll, int col);
void inputMatrix(int** matrix, int row, int col);
void sumEvenEll(int* array, int max, int* sum);
void outputMatrix(int** matrix, int row, int col);
void freeMatrix(int** matrix, int row);