#include "Header.h"

int checkQuession(char* str) {
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '?') return 1;
	return 0;
}

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

void strCopy(char** startStr, char* finishStr, int mode) {
	if (mode == 0) (*startStr) = (char*)realloc((*startStr), sizeof(char) * (strlen(finishStr) + 1));
	for (int i = 0; finishStr[i] != '\0'; i++) {
		(*startStr)[i] = finishStr[i];
	}
	(*startStr)[strlen(finishStr)] = '\0';
}

void strTok(char** str, char** strToken) {
	char* token = NULL;
	char* nextToken = NULL;
	char delimiter = '\t';
	token = strtok_s((*str), &delimiter, &nextToken);
	strCopy(strToken, token, DINAMIC);
	if (strlen(nextToken) != 0) strCopy(str, nextToken, STATIC);
	else (*str)[0] = '\0';

}

tnode* addTree(tnode* tree, char* str, char deepWrite) {
	if (tree == NULL) {
		tree = (tnode*)malloc(sizeof(tnode));
		tree->deep = deepWrite;
		tree->data = (char*)malloc(sizeof(char));
		tree->data[0] = '\0';

		strTok(&str, &tree->data);
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (checkQuession(tree->data) == 1) {
		tree->left = addTree(tree->left, str, deepWrite);
		tree->right = addTree(tree->right, str, deepWrite);
	}
	return tree;
}

void printTree(tnode* tree) {
	if (tree != NULL) {
		printf("deep - %d	%s\n", tree->deep, tree->data);
		printTree(tree->left);
		printTree(tree->right);
	}
}

void freeTree(tnode* tree) {
	if (tree != NULL) {
		freeTree(tree->left);
		freeTree(tree->right);
		free(tree->data);
		free(tree);
	}
}


void findCharacter(tnode* tree) {

	printf("%s \n 1)No\t2)Yes\n", tree->data);
	int check = checkQuession(tree->data);
	int choise;
	scanf_s("%d", &choise);
	if (choise == 1) {
		if (check == 1) findCharacter(tree->left);
		else tree = addCharacter(tree);
	}
	else if (choise == 2) {
		if (check == 1) findCharacter(tree->right);
		else printf("\nÑharacter found\n END");
	}
}

tnode* addCharacter(tnode* tree) {

	printf("How is it?\n");
	char* name = (char*)malloc(sizeof(char) * 255);
	getchar();
	getString(&name);

	char buffer[255];
	buffer[0] = '\0';
	addS1InS2(buffer, tree->data);
	buffer[strlen(buffer) + 1] = '\0';
	buffer[strlen(buffer)] = '\t';
	addS1InS2(buffer, name);
	free(name);

	printf("Enter a badge\n");
	char* newQuession = (char*)malloc(sizeof(char) * 255);
	getString(&newQuession);
	if (checkQuession(newQuession) == 0) {
		newQuession = (char*)realloc(newQuession, sizeof(char) * (strlen(newQuession) + 2));
		newQuession[strlen(newQuession) + 1] = '\0';
		newQuession[strlen(newQuession)] = '?';
	}
	strCopy(&tree->data, newQuession, DINAMIC);
	free(newQuession);

	tree = addTree(tree, buffer, tree->deep + 1);
	return tree;
}

void squeeze(char s[], char s2[]) {
	int k, i, j;

	for (k = 0; s2[k] != '\0'; k++) {
		for (i = j = 0; s[i] != '\0'; i++)
			if (s[i] != s2[k])
				s[j++] = s[i];
		s[j] = '\0';
	}
}


void addS1InS2(char* s1, char* s2) {
	if (strlen(s1) == 0) strCopy(&s1, s2, STATIC);
	else {
		int posS1 = strlen(s1);
		int posS2 = 0;
		while (s2[posS2] != '\0') {
			s1[posS1] = s2[posS2];
			posS1++;
			posS2++;
		}
		s1[posS1] = '\0';
	}
}

void getDeepStrs(tnode* root, char* buffer, char deep) {
	if (root != NULL) {
		if (root->deep == deep) {
			int point = strlen(buffer);
			if (buffer[0] == '\0') {
				for (int i = 0; root->data[i] != '\0'; i++) {
					buffer[point] = root->data[i];
					point++;
				}
				buffer[point] = '\t';
				point++;
				buffer[point] = '\0';
			}
			else {

				for (int i = 0; root->data[i] != '\0'; i++) {
					buffer[point] = root->data[i];
					point++;
				}
				buffer[point] = '\t';
				point++;
				buffer[point] = '\0';
			}
		}
		getDeepStrs(root->left, buffer, deep);
		getDeepStrs(root->right, buffer, deep);
	}
}


void editDB(tnode* root) {
	FILE* finishFile = NULL;
	fopen_s(&finishFile, "DB.txt", "w");
	if (finishFile == NULL) exit(1);

	int deep = 1;
	int button = 1;
	while (button) {
		char buffer[2000];
		buffer[0] = '\0';
		getDeepStrs(root, buffer, deep);
		if (buffer[0] == '\0') button = 0;
		else {
			buffer[strlen(buffer) - 1] = '\n';
			fprintf(finishFile, "%s", buffer);
		}
		deep++;
	}
	fclose(finishFile);

}