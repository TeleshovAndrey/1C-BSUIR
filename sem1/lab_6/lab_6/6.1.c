//#include "functions.h"
///*
//1.	¬ одномерном массиве выполнить сортировку четных элементов методом выбора
//*/
//
//int main() {
//	int* array;
//	int maxEll;
//	int choiseInput;
//	int choiseSort;
//	int choiseSelectionSort;
//
//	printf("\nEnter max ell array ");
//	scanfSecure(&maxEll, 0 , 10000);
//	array = malloc(maxEll *sizeof(int));
//
//	printf("Choose input	1)randomly		2)themself		3)Bad case\n");
//	scanfSecure(&choiseInput, 1, 3);
//
//	inputArray(maxEll, array, choiseInput);
//
//	//printf("\nStart array");
//	//for (int i = 0; i < maxEll; i++)
//	//printf(" %d", array[i]);
//
//	printf("\n1) selectionSort		2) bubleSort");
//	scanfSecure(&choiseSort, 1, 2);
//	if (choiseSort == 1) {
//
//		printf("\nChoice selection");
//		scanfSecure(&choiseSelectionSort, 0, maxEll);
//
//		clock_t begin = clock();
//		selectionSortEvenEll(array, choiseSelectionSort);
//		clock_t end = clock();
//		double seconds = (double)(end - begin) / CLOCKS_PER_SEC;
//
//		//printf("\nResulting array");
//		//for (int i = 0; i < maxEll; i++)
//		//	printf(" %d", array[i]);
//		printf("\n time: %lf", seconds);
//
//		free(array);
//	}
//	else {
//
//		clock_t begin = clock();
//		bubleSort(array, maxEll);
//		clock_t end = clock();
//		double seconds = (double)(end - begin) / CLOCKS_PER_SEC;
//		
//		//printf("\nResulting array");
//		//for (int i = 0; i < maxEll; i++)
//		//	printf(" %d", array[i]);		
//		printf("\n time: %lf", seconds);
//		
//		free(array);
//	}
//}