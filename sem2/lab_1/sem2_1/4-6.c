//#include "struct.h"
//
////Реализовать меню, для проверки функционала
//int main() {
//	int choise=0;
//	int limit=0;
//	int count = 0;
//	
//	product* products = NULL;
//	while (choise != 5) {
//
//		printf("        menu\n");
//		printf("  1) Create array struct \n");
//		printf("  2) Output array stract \n");
//		printf("  3) Initialize struct \n");
//		printf("  4) Sort array struct\n");
//		printf("  5) Exit \n");
//
//		scanf_s("%d", &choise);
//
//		while (choise != 1 && choise != 5 && products == NULL) {
//			printf("First you need to create an array !\n");
//			scanf_s("%d", &choise);
//		}
//		if (products != NULL && choise == 1) freeArrayStruct(products, count);
//		
//		if (choise == 1) products = createArrayStruct(&limit);
//		if (choise == 2) outputArrayStruct(products, count);
//		if (choise == 3) initializeStruct(&products[count], &count, limit);
//		if (choise == 4) sortStruct(products, count);
//		
//	}
//	
//	freeArrayStruct(products, count);
//}