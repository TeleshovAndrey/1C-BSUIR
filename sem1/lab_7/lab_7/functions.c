#include "functions.h"
// task 1
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

int strLength(char* str) {
	int  length = 0;
	while (str[length] != '\0') length++;
	return length;
}

int comparisonWords(char* word1, char* word2) {
	int length1 = strLength(word1);
	int length2 = strLength(word2);
	int equality = 0;
	if (length1 == length2)
		for (int i = 0; word1[i] != '\0'; i++)
			if (word1[i] == word2[i]) equality++;
	if (equality == length1) return 1;
	else return 0;
}

void commonWord(char** strWords, int wordAmount, int* repeats) {
	for (int i = 0; i < wordAmount; i++) {
		repeats[i] = 0;
		for (int j = i; j < wordAmount; j++)
			if (comparisonWords(strWords[i], strWords[j])) repeats[i] += 1;
	}
}

void scanfSecure(int* number, int min, int max) {
	while (scanf_s("%d", number) == 0 || *number < min || *number > max || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
}

void strWordsExtracts(char* string, char** wordsStr, int* wordsAmount) {
	int length = strLength(string);
	int point = 0;
	while (point < length) {
		int wordLength = 0;
		while (string[point] == ' ' && point < length) point++;
		while (string[point] != ' ' && point < length) {
			point++;
			wordLength++;
		}
		wordsStr[*wordsAmount] = (char*)malloc((wordLength + 1)*sizeof(char));
		for (int i = point - wordLength, j = 0; i < point; i++, j++) {
			wordsStr[*wordsAmount][j] = string[i];
			if (i == point - 1) {
				j++;
				wordsStr[*wordsAmount][j] = '\0';
			}
		}
		(*wordsAmount) += 1;
		while (string[point] == ' ' && point < length) point++;
	}
}

void outputCommonWord(char** strWords, int* repeats, int words) {
	int max = 1;
	for (int i = 0; i < words; i++)
		if (repeats[i] > max) max = repeats[i];
	if (max == 1)printf("All words diferent");
	else if (max > 1) {
		printf("Most common words: \n");
		for (int i = 0; i < words; i++)
			if (max == repeats[i]) printf("%s ", strWords[i]);
	}

}
//task 2
void deleteWords(char* strS,char **wordsSO,char** wordsS, int wordsAmountSO, char C) {
	int point = 0;
	int wordAmountS = 0;
	int savePoint = 0;
	

	while(strS[point]!='\0') {
		int startLength = strLength(strS);
		int wordLength = 0;
		int delete=1;
		while (strS[point] == ' ' && strS[point] != '\0') point++;

		while (strS[point] != ' ' && strS[point] != '\0') {
			point++;
			wordLength++;
		}
		for (int i = 0; i < wordsAmountSO; i++)
			if (comparisonWords(wordsS[wordAmountS], wordsSO[i])) delete = 0;
			
		if (strS[point - wordLength] == C && delete==1) {
			for (int i = point - wordLength, j, count = 0; count < wordLength; count++) {
				j = i + 1;
				while (strS[j] != '\0') {
					strS[j - 1] = strS[j];
					j++;
				}
				for (int k = 0; k < 1; k++)
					strS[j - 1] = strS[j];
			}
		}

		for (int i = point - wordLength, j; strS[i] == ' ';) {
			j = i + 1;
			while (strS[j] != '\0') {
				strS[j - 1] = strS[j];
				j++;
			}
			for (int k = 0; k < 1; k++)
				strS[j - 1] = strS[j];
		}
		if (startLength == strLength(strS))
			savePoint += wordLength+1;
		else 
			point = savePoint;

		wordAmountS++;
	}
}