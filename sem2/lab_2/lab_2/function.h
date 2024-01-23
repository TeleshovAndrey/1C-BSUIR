#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strDescription {
	char* word;
	int repeats;
	int size;
	int state;
}strDescription;

typedef struct couples {
	int posOriginal;
	int posReplacement;
}couples;

int repeat—heck(strDescription* words, char* str, int countWords);
int strEquale(char* str1, char* str2);
void createWord(strDescription* words, char* str, int countWords);
void freeWords(strDescription* words, int countWords);
void createKaywords(strDescription* words, couples** keywords, int countWords, int* countKeywords);
void inputReplacementData(FILE* finishFile, couples* keywords, int countKeywords, strDescription* words);
void replace(char* strOrig, char* strReplace);
int countStrWords(char* str);

void detectEndStrs(FILE* startFile, int** endStrs, int* countEndStrs, char* str);
void writeCompressedFile(FILE* startFile, FILE* finishFile, couples* keywords, strDescription* words, int countKeywords, char* str, int* endStrs);