#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

typedef struct product {
	char* name;
	int cost;
	int contain;
}product;

void getString(char** strAll);
//void freeArrayStruct(product* smartphones, int size);
//void sortStruct(product* products, int size);
//void initializeStruct(product* instance, int* count, int limit);
//void outputArrayStruct(product* smartphones, int size);
//product* createArrayStruct(int* size);

// 4-6
////////////////////////////////////////
typedef enum stamp {
		Audi,
		BMW,
		Ford,
		Honda,
		Lada
}stamp;

void scanfSecure(int* number, int min, int max);

typedef struct car {
	stamp stampCar;
	int cost;
	int year;
	char* model;
}car;


void outputArrayStruct(car* cars, int size, char* str);
void createArrayCars(car** cars, int* size);
void sortPart1(car* cars, int choise, int start, int end);
void sortStructTwoFilds(car* cars, int size);
void sortPart2(car* cars, int size, int choise1, int choise2);
void initializeStruct(car* instance, int* count, int limit, char* str);
void deleteCar(car* cars, int* size);
void freeArrayStruct(product* smartphones, int size);

//7-8
////////////////////////////////////////////////////////////////