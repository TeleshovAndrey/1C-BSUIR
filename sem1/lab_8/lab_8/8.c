#include "functions.h"
//3.	Отсортировать методом слияния массив строк по возрастанию количества слов

int main(int argc, char** argv) {
	char** strings;
	int* wordsAmount;
	int amountStrings = argc - 1;
	wordsAmount = (int*)malloc(sizeof(int) * argc-1);
	stringsInput(&strings, argv, argc);
	
	for (int i = 0; i < amountStrings; i++) {
		printf("%s \n", strings[i]);
		countStrWords(strings[i], &wordsAmount[i]);
	}
	
	mergeSort(wordsAmount, amountStrings, strings);
	
	printf("\n resulting strings \n");
	for (int i = 0; i < argc; i++) {
		printf("%s \n", strings[i]);
		free(strings[i]);
	}
	free(strings);
}
//// C:\Users\37529\Desktop\papka\lab_8\x64\Debug\