#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct couples {
	char* replacement;
	char* original;
}couples;

int countKeywords(char* str);
void writeKeywords(char* str, couples** keywords);

void detectEndStrs(FILE* startFile, int** endStrs, int* countEndStrs, char* str);
int countStrWords(char* str);

void replace(char* strOrig, char* strReplace);
int strEquale(char* str1, char* str2);
void writeDecompressedFile(FILE* startFile, FILE* finishFile, couples* keywords, int countKeywords, char* str, int* endStrs);