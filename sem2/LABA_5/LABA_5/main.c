#include "Header.h"

void main()
{
	HashTable* table = createTable();
	int run = 1;

	while (run)
	{
		char* domain = (char*)malloc(sizeof(char) * 255);
		printf("================================\n");
		printf("Enter domain\n");
		getString(&domain);

		int check = searchTable(table, domain);

		if (check == MATCH_FOUND) table = printItem(table, domain);
		else
		{
			char* IP = readDB(domain);
			if (IP != NULL) table = insertTable(table, domain, IP);
			free(IP);
		}
		free(domain);
		printf("CASH - ");
		printCash(table->cash);
		printf("\n================================");
		getchar();
		system("cls");
	}

	freeTable(table);
}

//aplle.com	IN A	192.122.012.32
//apIIe.com	IN CNAME	aplle.com
//google.com	IN A	123.222.234.20
//iis.bsuir.by	IN A	213.211.112.10
//iis.bsuir1.by	IN CNAME	iis.bsuir.by