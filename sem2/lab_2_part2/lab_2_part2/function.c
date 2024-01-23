#include "function.h"

int countKeywords(char*str) {
	int amountKeywords = 0;
	int pointStr = 0;
	while (str[pointStr] != '#') {
		while (str[pointStr] != ' ') pointStr++;
		amountKeywords++;
		while (str[pointStr] == ' ')pointStr++;
	}
	return amountKeywords;
}

void writeKeywords(char* str, couples ** keywords) {
	int pointStr = 0;
	int pointKeywords = 0;
	while (str[pointStr] != '#') {
		int pointOriginal = 0;
		int pointReplacement = 0;
		

		int lengthOriginal = 0;
		int lengthReplacement = 0;
		for (int i = pointStr; str[i] != ' '; i++) lengthReplacement++;
		(*keywords)[pointKeywords].replacement = (char*)realloc((*keywords)[pointKeywords].replacement, sizeof(char) * (lengthReplacement + 1));
		while (str[pointStr] != ' ') {
			(*keywords)[pointKeywords].replacement[pointReplacement] = str[pointStr];
			pointReplacement++;
			pointStr++;
		}
		pointStr++;
		(*keywords)[pointKeywords].replacement[pointReplacement] = '\0';

		for (int i = pointStr; str[i] != ' '; i++) lengthOriginal++;
		(*keywords)[pointKeywords].original = (char*)realloc((*keywords)[pointKeywords].original, sizeof(char) * (lengthOriginal + 1));
		while (str[pointStr] != ' ') {
			(*keywords)[pointKeywords].original[pointOriginal] = str[pointStr];
			pointOriginal++;
			pointStr++;
		}
		(*keywords)[pointKeywords].original[pointOriginal] = '\0';
		pointKeywords++;
		while (str[pointStr] == ' ')pointStr++;
	}
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

void replace(char* strOrig, char* strReplace) {
	int pointOrig = 0;
	int button = 0;

	while (strOrig[pointOrig] < 'A' || strOrig[pointOrig]>'Z' && strOrig[pointOrig] < 'a' || strOrig[pointOrig]>'z') pointOrig++;
	while (button == 0) {
		if (strOrig[pointOrig] >= 'A' && strOrig[pointOrig] <= 'Z' || strOrig[pointOrig] >= 'a' && strOrig[pointOrig] <= 'z')
			for (int i = pointOrig; strOrig[i] != '\0'; i++)
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
	int error = 1;
	while (!feof(startFile)) {
		(*endStrs) = (int*)realloc((*endStrs), (*countEndStrs + 1) * sizeof(int));
		fgets(str, 2050, startFile);
		if (error == 0) {
			(*endStrs)[*countEndStrs] = countStrWords(str);
			(*countEndStrs)++;
		}
		else error = 0;
	}
	fseek(startFile, 0, SEEK_SET);
}

void writeDecompressedFile(FILE* startFile, FILE* finishFile, couples* keywords, int countKeywords, char* str, int* endStrs) {
	int pointEndStrs = 0;
	int end = 0;
	while (!feof(startFile)) {
		int enter = 0;
		
		
		fgets(str, 1030, startFile);
		int pointStr = 0;
		char buffer[50];
		while (str[pointStr] != '\0') {
			int amountSpace = 0;
			int amountWords = 0;
			int pointBuffer = 0;
			while (str[pointStr] == ' '){
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
				if (strEquale(buffer, keywords[i].original))
					replace(buffer, keywords[i].replacement);
				else
					if (strEquale(buffer, keywords[i].replacement))
						replace(buffer, keywords[i].original);
			}
			if (end == 0) {
				if (feof(startFile) && enter == 1) {
					for (int i = 0; i < amountSpace; i++) {
						for (int j = strlen(buffer); j >= 0; j--)
							buffer[j + 1] = buffer[j];
						buffer[0] = ' ';
					}
					fprintf(finishFile, "%s", buffer);
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
		}
	}
}