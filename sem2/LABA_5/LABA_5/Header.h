#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_CASH 3
#define SIZE_TABLE 3
#define NOT_FOUND -1
#define MATCH_FOUND -2

typedef struct TableItem {
	char* key;
	char* value;
}TableItem;

typedef struct LIST {
	TableItem* item;
	struct LIST* next;
	struct LIST* prev;
}LIST;

typedef struct HashTable {
	TableItem** item;
	LIST* cash;
	int count;
}HashTable;

HashTable* printItem(HashTable* table, char* key);
void printCash(LIST* cash);
int searchTable(HashTable* table, char* key);
void freeTable(HashTable* table);
HashTable* insertTable(HashTable* table, char* key, char* value);
int hashFunc(char* key);
HashTable* createTable();
void freeCash(LIST* cash);
LIST* deleteLastCash(HashTable* table, LIST* cash, int* index);
HashTable* deleteItem(HashTable* table, char* key, int type);
LIST* deleteMatchCash(LIST* cash, char* key);
LIST* addCash(LIST* cash);
void freeItem(TableItem* item);
TableItem* createItem(char* key, char* value);
void getString(char** strAll);
char* readFile(FILE* fileDB, char* domain);
char* readDB(char* domain);