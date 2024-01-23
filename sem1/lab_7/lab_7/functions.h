#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void getString(char** strAll);
int strLength(char* str);
int comparisonWords(char* word1, char* word2);
void commonWord(char** strWords, int words, int* repeats);
void scanfSecure(int* number, int min, int max);
void strWordsExtracts(char* strAll, char** strWords, int* words);
void outputCommonWord(char** strWords, int* repeats, int words);
void deleteWords(char* strS, char** wordsSO, char** wordsS, int wordsAmountSO, char C);
void task1();
void task2();