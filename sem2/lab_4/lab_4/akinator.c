#include "Header.h"
void main() {
	printf("Welcome to akinator mortal kombat 11!\n");
	FILE* startFile = NULL;
	fopen_s(&startFile, "DB.txt", "r");
	if (startFile == NULL) exit(0);

	tnode* tree = NULL;
	char deep = 1;
	while (!feof(startFile)) {
		char str[500];
		fgets(str, 498, startFile);
		squeeze(str, "\n");
		tree = addTree(tree, str, deep);
		deep++;
	}
	fclose(startFile);

	findCharacter(tree);
	editDB(tree);
	printTree(tree);
	freeTree(tree);
}