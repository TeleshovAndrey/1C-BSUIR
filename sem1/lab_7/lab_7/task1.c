#include "functions.h"

void task1() {
	char* strAll;
	int wordAmount = 0;
	int* repeats;
	char** strWords;
	
	printf("\n Selected a task 1 \n");
	printf("1) Дана строка.Найти самое часто встречающееся слово в ней\n");
	
	strAll = (char*)malloc(256 * sizeof(char));
	strWords = (char**)malloc(256 * sizeof(char*));
	
	printf("Enter string ");
	getString(&strAll);
	
	strWordsExtracts(strAll, strWords, &wordAmount);
	
	if (wordAmount != 1) {
		repeats = malloc(sizeof(int) * wordAmount);
		commonWord(strWords, wordAmount, repeats);

		outputCommonWord(strWords, repeats, wordAmount);
	}
	else
		printf("%s", strWords[0]);

	free(strAll);
	for (int i = 0; i < wordAmount; i++)
		free(strWords[i]);
	free(strWords);
}