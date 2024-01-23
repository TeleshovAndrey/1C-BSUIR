#include "function.h"

int repeat—heck(strDescription* words, char* str, int countWords) {
	for (int i = 0; i < countWords; i++)
		if (strEquale(str, words[i].word)) {
			words[i].repeats++;
			words[i].size = words[i].repeats * strlen(words[i].word);
			return 1;
		}
	return 0;
}

int strEquale(char* str1, char* str2) {
	int pointStr1 = 0;
	int pointStr2 = 0;
	
	int lengthStr1 = 0;
	int lengthStr2 = strlen(str2);

	while (pointStr1 != strlen(str1)) {
		if (str1[pointStr1] >= 'A' && str1[pointStr1] <= 'Z' || str1[pointStr1] >= 'a' && str1[pointStr1] <= 'z')
			lengthStr1++;
		pointStr1++;
	}
	if (lengthStr2 != lengthStr1) return 0;
	pointStr1 = 0;
	while (pointStr1 != strlen(str1) && pointStr2 != strlen(str2)) {
		if (str1[pointStr1] >= 'A' && str1[pointStr1] <= 'Z' || str1[pointStr1] >= 'a' && str1[pointStr1] <= 'z') {
			if (str1[pointStr1] == str2[pointStr2]) pointStr2++;
			else return 0;
		}
		pointStr1++;
	}

	return 1;
}

void createWord(strDescription* words, char* str, int countWords) {
	words[countWords - 1].state = 0;
	words[countWords - 1].repeats = 1;

	int pointStr = 0;
	int pointWord = 0;

	while (str[pointStr] != '\0') {
		if (str[pointStr] >= 'A' && str[pointStr] <= 'Z' || str[pointStr] >= 'a' && str[pointStr] <= 'z') {
			words[countWords - 1].word[pointWord] = str[pointStr];
			pointWord++;
		}
		pointStr++;
	}

	words[countWords - 1].word[pointWord] = '\0';
	words[countWords - 1].word = (char*)realloc(words[countWords - 1].word, sizeof(char) * (pointWord + 1));
	words[countWords - 1].size = pointWord;
}
void createKaywords(strDescription* words, couples** keywords, int countWords, int* countKeywords) {
	int button = 1;
	while (button) {
		int benefit = 20;
		int posOriginal = -1;
		int posReplacement = -1;
		int error = 0;
		for (int i = 0; i < countWords; i++) {
			if (words[i].state == 1)error = 1;
			if (error == 0) {
				for (int j = 0; j < countWords; j++) {
					if (words[j].state == 1)error = 1;
					int lengthOriginal = strlen(words[j].word);
					int lengthReplacement = strlen(words[i].word);
					if (error == 0 && lengthOriginal > lengthReplacement) {
						int firstSize = words[i].size + words[j].size;
						int secondSize = words[j].repeats * strlen(words[i].word) + words[i].repeats * strlen(words[j].word);
						if (firstSize - secondSize > benefit) {
							benefit = firstSize - secondSize;
							posReplacement = i;
							posOriginal = j;
						}
					}
					else error = 0;
				}
			}
			else error = 0;
		}
		if (posOriginal == -1 && posReplacement == -1) button = 0;
		else {
			(*countKeywords)++;
			printf("new %d", (*countKeywords));
			int point = (*countKeywords) - 1;
			(*keywords) = (couples*)realloc((*keywords), (point + 1) * sizeof(couples));
			(*keywords)[point].posOriginal = posOriginal;
			(*keywords)[point].posReplacement = posReplacement;
			words[posOriginal].state = 1;
			words[posReplacement].state = 1;
		}
	}
}

void freeWords(strDescription* words, int countWords) {
	for (int i = 0; i < countWords; i++)
		free(words[i].word);
	free(words);
}


void inputReplacementData(FILE* finishFile, couples* keywords, int countKeywords, strDescription* words) {
	for (int i = 0; i < countKeywords; i++) {
		int posOriginal = keywords[i].posOriginal;
		int posReplacement = keywords[i].posReplacement;
		fprintf(finishFile, "%s %s ", words[posOriginal].word, words[posReplacement].word);
	}
	fprintf(finishFile, "#\n");
}

void replace(char* strOrig, char* strReplace) { 
	int pointOrig = 0;
	int button = 0;

	while (strOrig[pointOrig] < 'A' || strOrig[pointOrig]>'Z' && strOrig[pointOrig] < 'a' || strOrig[pointOrig]>'z') pointOrig++;
	while (button == 0) {
		if (strOrig[pointOrig] >= 'A' && strOrig[pointOrig] <= 'Z' || strOrig[pointOrig]>='a' && strOrig[pointOrig] <= 'z')
			for (int i = pointOrig; strOrig[i]!='\0'; i++)
				strOrig[i] = strOrig[i + 1];
		else button = 1;
	}
	
	for (int i = 0; i < strlen(strReplace); i++) {
		for (int j = strlen(strOrig); j >= pointOrig; j--)
			strOrig[j + 1] = strOrig[j];
		if (strlen(strOrig) == 0) strOrig[0] = ' ';
		
		if (strOrig[pointOrig] == '\0') { 
		strOrig[pointOrig + 1] = '\0';
		strOrig[pointOrig] = ' ';
		}
	}

	for (int i = 0; strReplace[i] != '\0'; i++) {
		strOrig[pointOrig] = strReplace[i];
		pointOrig++;
	}
}

int countStrWords(char* str) {
	int count = 0;
	int posStr = 0;
	while (str[posStr] != '\0') {
		while (str[posStr] == ' ' && str[posStr] != '\0') posStr++;
		while (str[posStr] != ' ' && str[posStr] != '\0') posStr++;
		count++;
	}
	return count;
}

void detectEndStrs(FILE* startFile, int** endStrs, int* countEndStrs, char* str) {
	while (!feof(startFile)) {
		(*endStrs) = (int*)realloc((*endStrs), (*countEndStrs + 1) * sizeof(int));
		fgets(str, 2500, startFile);
		(*endStrs)[*countEndStrs] = countStrWords(str);
		(*countEndStrs)++;
	}
	fseek(startFile, 0, SEEK_SET);
}

void writeCompressedFile(FILE* startFile, FILE* finishFile, couples* keywords, strDescription* words, int countKeywords, char* str, int* endStrs) {
	inputReplacementData(finishFile, keywords, countKeywords, words);
	int pointEndStrs = 0;
	int end = 0;
	while (!feof(startFile)) {
		int enter = 0;
		int amountWords = 0;
		
		fgets(str, 2500, startFile);
		int pointStr = 0;
		char buffer[50];
		while (str[pointStr] != '\0') {
			int amountSpace = 0;
			int pointBuffer = 0;
			while (str[pointStr] == ' ') {
				amountSpace++;
				pointStr++;
			}
			while (str[pointStr] != ' ' && str[pointStr] != '\0') {
				buffer[pointBuffer] = str[pointStr];
				pointStr++;
				pointBuffer++;
			}
			amountWords++;
			if (amountWords == endStrs[pointEndStrs]) {
				enter = 1;
				pointEndStrs++;
				amountWords = 0;
			}
			buffer[pointBuffer] = '\0';
			for (int i = 0; i < countKeywords; i++) {
				if (strEquale(buffer, words[keywords[i].posOriginal].word))
					replace(buffer, words[keywords[i].posReplacement].word);
				else
					if (strEquale(buffer, words[keywords[i].posReplacement].word))
						replace(buffer, words[keywords[i].posOriginal].word);
			}
			if (end == 0) {
				if (feof(startFile) && enter == 1) {
					for (int i = 0; i < amountSpace; i++) {
						for (int j = strlen(buffer); j >= 0; j--)
							buffer[j + 1] = buffer[j];
						buffer[0] = ' ';
					}
					fprintf(finishFile,"%s", buffer);
					end = 1;
				}
				else {
					for (int i = 0; i < amountSpace; i++) {
						for (int j = strlen(buffer); j >= 0; j--)
							buffer[j + 1] = buffer[j];
						buffer[0] = ' ';
					}
					fprintf(finishFile, "%s", buffer);
				}
			}
			amountSpace = 0;
		}
	}
}
