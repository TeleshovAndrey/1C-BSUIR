#include "function.h"

int main() {

	FILE* startFile = NULL;
	fopen_s(&startFile, "start.txt", "r");
	if (startFile == NULL) exit(1);

	char str[1050];
	int countEndStrs = 0;
	int* endStrs = (int*)malloc(sizeof(int));
	detectEndStrs(startFile, &endStrs, &countEndStrs, str);


	int countWords = 1;
	strDescription* words = (strDescription*)malloc(sizeof(strDescription));
	fscanf_s(startFile, "%s", str, _countof(str));
	words[countWords - 1].word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	createWord(words, str, countWords);
	while (!feof(startFile)) {
		fscanf_s(startFile, "%s", str, _countof(str));
		if (repeat—heck(words, str, countWords) == 0)
		{
			countWords++;
			words = (strDescription*)realloc(words, sizeof(strDescription) * countWords);
			words[countWords - 1].word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
			createWord(words, str, countWords);
		}
	}
	fseek(startFile, 0, SEEK_SET);


	couples* keywords = (couples*)malloc(sizeof(couples));
	int countKeywords = 0;
	createKaywords(words, &keywords, countWords, &countKeywords);


	FILE* finishFile = NULL;
	fopen_s(&finishFile, "compressed.txt", "w");
	if (finishFile == NULL) exit(1);


	writeCompressedFile(startFile, finishFile, keywords, words, countKeywords, str, endStrs);


	fclose(finishFile);
	free(keywords);
	freeWords(words, countWords);
	free(endStrs);

	fclose(startFile);
}