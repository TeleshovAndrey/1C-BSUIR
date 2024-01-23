//#include "struct.h"
//void getString(char** strAll) {
//	int i = 0;
//	char c;
//	while ((c = getchar()) != EOF && c != '\n') {
//		(*strAll)[i++] = c;
//		if (i == 255) {
//			(*strAll) = realloc((*strAll), (i * 2) * sizeof(char));
//		}
//	}
//	(*strAll) = realloc((*strAll), i + 1);
//	(*strAll)[i] = '\0';
//}
//
////Реализовать функцию для создания массива структур
//product* createArrayStruct(int* size)
//{
//	printf("Set limit of structures in array\n");
//	scanf_s("%d", size);
//	(*size) = (*size) <= MAX_SIZE ? (*size) : MAX_SIZE;
//
//	product* arrayStruct = (product*)malloc((*size) * sizeof(product));
//	return arrayStruct;
//}
////- Реализовать функцию для вывода массива структур на экран.
//void outputArrayStruct(product* smartphones, int size) {
//	if (size == 0) printf("No structure instances created !\n");
//	for (int i = 0; i < size; i++)
//		printf("%d)Name - %s  cost:%d$  contained:%d pieces \n", i + 1, smartphones[i].name, smartphones[i].cost, smartphones[i].contain);
//}
////- Реализовать функцию для инициализации экземпляра структуры.
//void initializeStruct(product* instance, int* count, int limit) {
//	if ((*count) == limit)
//	{
//		printf("limit exceeded\n");
//		return;
//	}
//	printf("\n    Struct %d  \n", (*count) + 1);
//
//	int cost;
//	printf("cost - ");
//	scanf_s("%d", &cost);
//	instance->cost = cost;
//
//	int contain;
//	printf("contain - ");
//	scanf_s("%d", &contain);
//
//	instance->contain = contain;
//	printf("Name - ");
//
//	getchar();
//
//	instance->name = (char*)malloc(sizeof(char) * 128);
//	getString(&instance->name);
//	(*count) += 1;
//}
//
////Реализовать функции сортировки массива по каждому полю структуры.
//void sortStruct(product* products, int size) {
//	int choise;
//	printf("Choise sort \n 1)cost    2)contained    3)Name \n");
//	scanf_s("%d", &choise);
//	if (choise == 1) {
//		for (int i = 0; i < size; i++) {
//			product helper;
//
//			for (int j = size - 1; j > i; j--)
//				if (products[j - 1].cost > products[j].cost) {
//					helper = products[j - 1];
//					products[j - 1] = products[j];
//					products[j] = helper;
//				}
//		}
//	}
//
//	if (choise == 2) {
//		for (int i = 0; i < size; i++) {
//			product helper;
//
//			for (int j = size - 1; j > i; j--)
//				if (products[j - 1].contain > products[j].contain) {
//					helper = products[j - 1];
//					products[j - 1] = products[j];
//					products[j] = helper;
//				}
//		}
//	}
//
//	if (choise == 3) {
//		for (int i = 0; i < size; i++) {
//			product helper;
//			char a, b;
//			for (int j = size - 1; j > i; j--) {
//				if (products[j - 1].name[0] > products[j].name[0]) {
//					helper = products[j - 1];
//					products[j - 1] = products[j];
//					products[j] = helper;
//				}
//			}
//		}
//	}
//}
//
////(Например, можно отсортировать студентов сначала по дате рождения, затем передумать и отсортировать по среднему баллу
//
//void freeArrayStruct(product* smartphones, int size) {
//	for (int i = 0; i < size; i++) {
//		free(smartphones[i].name);
//	}
//	free(smartphones);
//}
//
////4-6
///////////////////////////////////////////////////////////////////////
//
