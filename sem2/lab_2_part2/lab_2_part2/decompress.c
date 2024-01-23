#include "function.h"
int main() {
	FILE* startFile = NULL;
	fopen_s(&startFile, "C:/sem2/lab_2/lab_2/compressed.txt", "r");
	if (startFile == NULL) exit(1);


	char str[2050];
	int countEndStrs = 0;
	int* endStrs = (int*)malloc(sizeof(int));
	detectEndStrs(startFile, &endStrs, &countEndStrs, str);
	fgets(str, 2050, startFile);

	int amountKeywords = countKeywords(str);
	couples* keywords = (couples*)malloc(sizeof(couples) * amountKeywords);
	for (int i = 0; i < amountKeywords; i++) {
		keywords[i].original = (char*)malloc(sizeof(char));
		keywords[i].replacement = (char*)malloc(sizeof(char));
	}

	writeKeywords(str, &keywords);
	FILE* finishFile = NULL;
	fopen_s(&finishFile, "C:/sem2/lab_2/lab_2/decompressed.txt", "w");
	if (startFile == NULL) exit(1);

	writeDecompressedFile(startFile, finishFile, keywords, amountKeywords, str, endStrs);
	fclose(finishFile);
	fclose(startFile);

	for (int i = 0; i < amountKeywords; i++){
		free(keywords[i].original);
		free(keywords[i].replacement);
	}
	free(keywords);
	free(endStrs);
}
