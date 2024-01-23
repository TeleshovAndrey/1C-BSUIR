#include "struct.h"


int main() {
	int choise = 0;
	int limit = 0;
	int count = 0;
	char stamps[5][6] = {
		"Audi",
		"BMW",
		"Ford",
		"Honda",
		"Lada"
	};

	car* cars = NULL;
	while (choise != 6) {
		printf("        menu\n");
		printf("  1) Create array struct \n");
		printf("  2) Output array stract \n");
		printf("  3) Initialize struct \n");
		printf("  4) Sorting array struct by two fields\n");
		printf("  5) Delete struct \n");
		printf("  6) end \n");

		scanfSecure(&choise, 1 , 6);

		while (choise != 1 && choise != 6 && cars == NULL) {
			printf("First you need to create an array !\n");
			scanfSecure(&choise, 1, 6);
		}
		if (cars != NULL && choise == 1) free(cars);

		if (choise == 1) createArrayCars(&cars,&limit);
		if (choise == 2) outputArrayStruct(cars, count, stamps);
		if (choise == 3) initializeStruct(&cars[count], &count, limit, stamps);
		if (choise == 4) sortStructTwoFilds(cars, count);
		if (choise == 5) deleteCar(cars, &count);
		system("cls");
	}

	freeArrayStruct(cars, count);
}