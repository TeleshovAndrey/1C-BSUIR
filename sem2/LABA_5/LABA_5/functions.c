#include "Header.h"

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

//START FUNCTIONS FOR TABLE ITEM
TableItem* createItem(char* key, char* value)
{
	TableItem* item = (TableItem*)malloc(sizeof(TableItem));
	int lengthKey = strlen(key) + 1;
	int lengthValue = strlen(value) + 1;

	item->key = (char*)malloc(sizeof(char) * lengthKey);
	item->value = (char*)malloc(sizeof(char) * lengthValue);
	strcpy_s(item->key, lengthKey, key);
	strcpy_s(item->value, lengthValue, value);
	return item;
}

void freeItem(TableItem* item)
{
	free(item->key);
	free(item->value);
	free(item);
}
//END FUNCTIONS FOR TABLE ITEM

//START FUNCTIONS FOR LIST

LIST* addCash(LIST* cash)
{
	LIST* newCash = (LIST*)malloc(sizeof(LIST));

	if (cash == NULL)
	{
		newCash->item = NULL;
		newCash->next = NULL;
		newCash->prev = NULL;
	}
	else
	{
		newCash->item = NULL;
		cash->prev = newCash;
		newCash->next = cash;
	}
	return newCash;
}

LIST* deleteLastCash(HashTable* table, LIST* cash, int* index)
{
	if (cash != NULL)
	{
		if (cash->next == NULL)
		{
			for (int i = 0; i < SIZE_TABLE; i++)
				if (table->item[i] != NULL)
					if (strcmp(cash->item->key, table->item[i]->key) == 0) (*index) = i;
			free(cash);
			return NULL;
		}
		cash->next = deleteLastCash(table, cash->next, index);
		return cash;
	}
}

LIST* deleteMatchCash(LIST* cash, char* key)
{
	if (cash != NULL)
	{
		if (strcmp(cash->item->key, key) == 0)
		{
			LIST* nextCash = cash->next;
			if (nextCash != NULL) cash->next->prev = cash->prev;
			free(cash);
			return nextCash;
		}
		else cash->next = deleteMatchCash(cash->next, key);
	}
	return cash;
}

void freeCash(LIST* cash)
{
	freeItem(cash->item);
	free(cash);
}

void printCash(LIST* cash)
{
	if (cash != NULL)
	{
		printf("%s->", cash->item->value);
		printCash(cash->next);
	}
	else
	{
		printf("NULL");
	}
}
//END FUNCTIONS FOR LIST

//START FUNCTIONS FOR TABLE

HashTable* createTable()
{
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));
	table->item = (TableItem**)malloc(sizeof(TableItem*) * SIZE_CASH);
	table->count = 0;
	table->cash = NULL;
	for (int i = 0; i < SIZE_CASH; i++) table->item[i] = NULL;
	return table;
}

int hashFunc(char* key)
{
	int hash = 0;
	for (int i = 0; i < strlen(key); i++) hash += key[i];
	return hash % SIZE_CASH;
}

HashTable* deleteItem(HashTable* table, char* key, int type)
{
	int index = 0;
	if (type == MATCH_FOUND)
	{
		for (int i = 0; i < SIZE_TABLE; i++)
			if (table->item[i] != NULL)
				if (strcmp(key, table->item[i]->key) == 0) index = i;

		table->cash = deleteMatchCash(table->cash, key);
		freeItem(table->item[index]);
		table->item[index] = NULL;
	}
	else if (type == NOT_FOUND) {

		table->cash = deleteLastCash(table, table->cash, &index);
		freeItem(table->item[index]);
		table->item[index] = NULL;

	}
	return table;
}

HashTable* insertTable(HashTable* table, char* key, char* value)
{
	int index = searchTable(table, key);
	if (index == NOT_FOUND || index == MATCH_FOUND)
	{
		TableItem* item = createItem(key, value);
		table = deleteItem(table, key, index);
		index = searchTable(table, key);
		table->cash = addCash(table->cash);
		table->cash->item = item;
		table->item[index] = item;
	}
	else
	{
		TableItem* item = createItem(key, value);
		table->cash = addCash(table->cash);
		table->cash->item = item;
		table->item[index] = item;
		table->count++;
	}
	return table;
}

int searchTable(HashTable* table, char* key)
{
	for (int i = 0; i < SIZE_TABLE; i++)
		if (table->item[i] != NULL)
			if (strcmp(key, table->item[i]->key) == 0) return MATCH_FOUND;

	int hash = hashFunc(key);


	for (int i = 0; i < SIZE_TABLE; i++) {
		int index = (hash + i) % 3;
		if (table->item[index] == NULL) return index;
	}

	return NOT_FOUND;
}

void freeTable(HashTable* table)
{
	freeCash(table->cash);
	free(table->item);
	free(table);
}

HashTable* printItem(HashTable* table, char* key)
{
	int hash = hashFunc(key);

	for (int i = 0; i < SIZE_TABLE; i++)
	{
		int index = (hash + i) % 3;
		if (table->item[index] != NULL)
			if (strcmp(key, table->item[index]->key) == 0) {
				printf("FOUND IP IN TABLE %s\n", table->item[index]->value);
				TableItem* item = createItem(table->item[index]->key, table->item[index]->value);
				table = deleteItem(table, table->item[index]->key, MATCH_FOUND);
				table->cash = addCash(table->cash);
				table->cash->item = item;
				return table;
			}
	}
}
//END FUNCTIONS FOR TABLE

//FILE FUNCTIONS
char* readDB(char* domain)
{
	FILE* fileDB = NULL;
	fopen_s(&fileDB, "DB.txt", "r");
	if (fileDB == NULL) exit(1);

	char* value = NULL;
	value = readFile(fileDB, domain);
	fclose(fileDB);
	return value;
}

char* readFile(FILE* fileDB, char* domain) {
	while (!feof(fileDB))
	{
		char stringDB[150];
		fgets(stringDB, 150, fileDB);

		char* domainDB = NULL;
		char* nextString = NULL;
		domainDB = strtok_s(stringDB, "	", &nextString);

		if (!strcmp(domainDB, domain))
		{
			char* IPCell = NULL;
			char* type = NULL;
			type = strtok_s(nextString, "\t", &IPCell);

			if (!strcmp(type, "IN A"))
			{
				if (IPCell[strlen(IPCell) - 1] == '\n') IPCell[strlen(IPCell) - 1] = IPCell[(strlen(IPCell))];
				printf("\nFound IP in file %s\n", IPCell);
				int lengthValue = strlen(IPCell) + 1;
				char* value = (char*)malloc(sizeof(char) * lengthValue);
				strcpy_s(value, lengthValue, IPCell);
				return value;
			}
			else
			{
				fseek(fileDB, 0, SEEK_SET);
				if (IPCell[strlen(IPCell) - 1] == '\n') IPCell[strlen(IPCell) - 1] = IPCell[(strlen(IPCell))];
				return readFile(fileDB, IPCell);
			}
		}
	}
	printf("\nNot found\n");
	return NULL;
}
