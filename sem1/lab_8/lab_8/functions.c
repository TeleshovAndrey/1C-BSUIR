#include "functions.h"
void scanfSecure(int* number, int min, int max) {
	while (scanf_s("%d", number) == 0 || *number < min || *number > max || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
}

void getString(char** strAll) {
	int i = 0;
	char c;
	while ((c = getchar()) != EOF && c != '\n') {
		(*strAll)[i++] = c;
		if (i == 255) {
			(*strAll) = realloc((*strAll), (i * 2) * sizeof(char));
		}
	}
	(*strAll) = realloc((*strAll), i + 1);
	(*strAll)[i] = '\0';
}

void countStrWords(char* string, int* wordsAmount) {
	int length = strLength(string);
	int point = 0;
	(*wordsAmount) = 0;
	while (point < length) {
		int wordLength = 0;
		while (string[point] == ' ' && point < length) point++;
		while (string[point] != ' ' && point < length) point++;
		
		(*wordsAmount) += 1;
		while (string[point] == ' ' && point < length) point++;
	}
}

int strLength(char* str) {
	int  length = 0;
	while (str[length] != '\0') length++;
	return length;
}
void stringsInput(char*** strings, char** argv, int argc) {
	if (argc == 1) {
		printf("There is no arguments except file name!");
		exit(1);
	}
	(*strings) = (char**)malloc((argc - 1) * sizeof(char*));
	for (int i = 1; i < argc; i++) {
		int len = strLength(argv[i]);
		(*strings)[i - 1] = (char*)calloc(len, sizeof(char*));
		for (int j = 0; j < len; j++) {
			(*strings)[i - 1][j] = argv[i][j];
		}
	}
}
void merge(int* nextArray, char** nextArrayStr ,int* array1, int* array2, int lenght1, int lenght2, char**array1Str, char** array2Str)
{
	int array1MinIndex = 0, array2MinIndex = 0, nextArrayMinIndex = 0;
	while (array1MinIndex < lenght1 && array2MinIndex < lenght2) {
		if (array1[array1MinIndex] <= array2[array2MinIndex])
		{
			nextArray[nextArrayMinIndex] = array1[array1MinIndex];
			nextArrayStr[nextArrayMinIndex] = realloc(array1Str[array1MinIndex], (strLength(array1Str[array1MinIndex]) + 1) * sizeof(char*));
			array1MinIndex++;
		}
		else
		{
			nextArray[nextArrayMinIndex] = array2[array2MinIndex];
			nextArrayStr[nextArrayMinIndex] = realloc(array2Str[array2MinIndex], (strLength(array2Str[array2MinIndex]) + 1) * sizeof(char*));
			array2MinIndex++;
		}
		nextArrayMinIndex++;
	}
	if (array1MinIndex < lenght1)
		while (array1MinIndex < lenght1)
		{
			nextArray[nextArrayMinIndex] = array1[array1MinIndex];
			nextArrayStr[nextArrayMinIndex] = realloc(array1Str[array1MinIndex], (strLength(array1Str[array1MinIndex]) + 1) * sizeof(char*));
			array1MinIndex++;
			nextArrayMinIndex++;
		}
	if (array2MinIndex < lenght2)
		while (array2MinIndex < lenght2)
		{
			nextArray[nextArrayMinIndex] = array2[array2MinIndex];
			nextArrayStr[nextArrayMinIndex] = realloc(array2Str[array2MinIndex], (strLength(array2Str[array2MinIndex]) + 1) * sizeof(char*));
			array2MinIndex++;
			nextArrayMinIndex++;
		}
}
void mergeSort(int* array, int maxEll, char** strings) {
	int* left;
	int* right;

	if (maxEll < 2) return;
	int mid = maxEll / 2;
	left = malloc(mid * sizeof(int));
	right = malloc((maxEll - mid) * sizeof(int));

	for (int i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (int i = mid; i < maxEll; i++)
	{
		right[i - mid] = array[i];
	}
	char** leftStr;
	char** rightStr;
	leftStr = (char**)malloc(mid * sizeof(char*));
	for (int i = 0; i < mid; i++)
	{
		leftStr[i] = realloc(strings[i], sizeof(char*) * (strLength(strings[i]) + 1));
	}

	rightStr = (char**)malloc((maxEll - mid) * sizeof(char*));
	for (int i = mid; i < maxEll; i++)
	{
		rightStr[i - mid] = realloc(strings[i], sizeof(char*) * (strLength(strings[i]) + 1));
	}
	mergeSort(left, mid, leftStr);
	mergeSort(right, maxEll - mid, rightStr);
	merge(array, strings, left, right, mid, maxEll - mid, leftStr, rightStr);
}
