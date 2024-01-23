#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STATIC 1
#define DINAMIC 0
//DYNAMIC
typedef struct tnode {
	char* data;
	char deep;
	struct tnode* left;
	struct tnode* right;
}tnode;

tnode* addTree(tnode* tree, char* str, char deepWrite);

void strCopy(char** startStr, char* finishStr, int mode);

void strTok(char** str, char** strToken);

void printTree(tnode* tree);
void freeTree(tnode* tree);

int checkQuession(char* str);
void getString(char** strAll);

tnode* addCharacter(tnode* tree);
void findCharacter(tnode* tree);

void squeeze(char s[], char s2[]);
void addS1InS2(char* s1, char* s2);
void getDeepStrs(tnode* root, char* buffer, char deep);
void editDB(tnode* root);