#include "functions.h"

void task2() {

	printf(" selected a task 2\n");
	printf("2) Дан символ C и строки S, S0. Удалить все слова, начинающиеся с символа C из строки S которых нет в строке S0\n");

	char* strS;
	char* strSO;
	int wordsAmountS = 0;
	int wordsAmountSO = 0;
	char** strWordsSO;
	char** strWordsS;
	char C;
	strWordsS = (char**)malloc(150 * sizeof(char*));
	strWordsSO = (char**)malloc(150 * sizeof(char*));

	strS = (char*)malloc(256);
	printf("strS \n");
	getString(&strS);
	strWordsExtracts(strS, strWordsS, &wordsAmountS);
	

	strSO = (char*)malloc(256);
	printf("strSO \n");
	getString(&strSO);
	strWordsExtracts(strSO, strWordsSO, &wordsAmountSO);
	

	printf("C= ");
	C = getchar();
	deleteWords(strS, strWordsSO, strWordsS, wordsAmountSO, C);
	printf("%s", strS);

	for (int i = 0; i < wordsAmountS; i++)
		free(strWordsS[i]);
	free(strWordsS);

	for (int i = 0; i < wordsAmountSO; i++)
		free(strWordsSO[i]);
	free(strWordsSO);

	free(strS);
	free(strSO);
}