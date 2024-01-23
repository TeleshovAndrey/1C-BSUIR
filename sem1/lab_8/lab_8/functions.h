#include <stdio.h>
#include <stdlib.h>

void scanfSecure(int* number, int min, int max);
void getString(char** strAll);
int strLength(char* str);
void countStrWords(char* string, int* wordsAmount);
void merge(int* nextArray, char** nextArrayStr, int* array1, int* array2, int lenght1, int lenght2, char** arrayStr1, char** arrayStr2);
void mergeSort(int* arrayNum, int maxEll, char** strings);
void stringsInput(char*** strings, char** argv, int argc);