#include "struct.h"

void scanfSecure(int* number, int min, int max) {
	while (scanf_s("%d", number) == 0 || *number < min || *number > max || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
}

void createArrayCars(car** cars, int* size)
{
	printf("Set limit of structures in array (MAX 10)\n");
	scanfSecure(size,0,10000000);
	(*size) = (*size) <= MAX_SIZE ? (*size) : MAX_SIZE;

	*cars = (car*)malloc((*size) * sizeof(car));
}

void outputArrayStruct(car* cars, int size, char(*str)[6]) {
	if (size == 0) printf("No structure instances created !\n");
	for (int i = 0; i < size; i++)
		printf("%d) Stamp - %s  model:%s  cost:%d$  year:%d s \n", i + 1, str[cars[i].stampCar], cars[i].model, cars[i].cost, cars[i].year);
	getchar();
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

void initializeStruct(car* instance, int* count, int limit, char(*str)[6]) {
	if ((*count) == limit)
	{
		printf("limit exceeded\n");
		return;
	}
	printf("\n    Struct %d  \n", (*count) + 1);
	
	int stampCar;
	for (int i = 0; i < 5; i++)
		printf("%d) %s   ", i, str[i]);
	printf("\n");
	scanfSecure(&stampCar, 0, 4);
	instance->stampCar = stampCar;
	
	
	int cost;
	printf("cost - ");
	scanfSecure(&cost, 0, 1000000);
	instance->cost = cost;

	int year;
	printf("year - ");
	scanfSecure(&year, 0 , 2023);
	instance->year = year;


	rewind(stdin);
	printf("Model - ");
	instance->model = (char*)malloc(sizeof(char) * 128);
	getString(&(instance->model));


	(*count) += 1;
}

void sortPart1(car* cars, int choise, int start, int end) {
	if (choise == 1) {
		for (int i = start; i <= end; i++) {
			car helper;

			for (int j = end; j > i; j--)
				if (cars[j - 1].cost > cars[j].cost) {
					helper = cars[j - 1];
					cars[j - 1] = cars[j];
					cars[j] = helper;
				}
		}
	}

	if (choise == 2) {
		for (int i = start; i <= end; i++) {
			car helper;

			for (int j = end; j > i; j--)
				if (cars[j - 1].year > cars[j].year) {
					helper = cars[j - 1];
					cars[j - 1] = cars[j];
					cars[j] = helper;
				}
		}
	}

	if (choise == 3) {
		for (int i = start; i <= end; i++) {
			car helper;

			for (int j = end; j > i; j--) {
				if (cars[j - 1].stampCar > cars[j].stampCar) {
					helper = cars[j - 1];
					cars[j - 1] = cars[j];
					cars[j] = helper;
				}
			}
		}
	}

	if (choise == 4) {
		for (int i = start; i <= end; i++) {
			car helper;
			char a, b;
			for (int j = end; j > i; j--) {
				if (cars[j - 1].model[0] > cars[j].model[0]) {
					helper = cars[j - 1];
					cars[j - 1] = cars[j];
					cars[j] = helper;
				}
			}
		}
	}
}

void sortPart2(car* cars, int size, int choise1, int choise2) {
	int start = 0;
	int end = 0;
	if (choise1 == 1)
		for (int i = start; i < size; i++) {
			end = i;
			if (cars[start].cost != cars[end].cost) {
				sortPart1(cars, choise2, start, end - 1);
				start = end;
			}
		}

	if (choise1 == 2)
		for (int i = start; i < size; i++) {
			end = i;
			if (cars[start].year != cars[end].year) {
				sortPart1(cars, choise2, start, end - 1);
				start = end;
			}
		}

	if (choise1 == 3)
		for (int i = start; i < size; i++) {
			end = i;
			if (cars[start].stampCar != cars[end].stampCar) {
				sortPart1(cars, choise2, start, end - 1);
				start = end;
			}
		}
	if (choise1 == 4)
		for (int i = start; i < size; i++) {
			end = i;
		
			if (cars[start].model[0] > cars[end].model[0]) {
				sortPart1(cars, choise2, start, end - 1);
				start = end;
			}
		}
}

void sortStructTwoFilds(car* cars, int size) {

	int choise1;
	printf("Select first field to sort \n 1)Cost    2)Year    3)Stamp  4)Name\n");
	scanfSecure(&choise1, 1, 4);

	sortPart1(cars, choise1, 0, size-1);

	int choise2;
	printf("Select second field to sort \n 1)Cost    2)Year    3)Stamp  4)Name\n");
	scanfSecure(&choise2, 1, 4);

	sortPart2(cars, size, choise1, choise2);
}

void deleteCar(car * cars, int *size) {
	printf("Choise number of car");
	
	int number;
	scanf_s("%d", &number);

	for (int i = (*size) - 1; i >= number; i--) {
		free(cars[i].model);
		cars[i - 1] = cars[i];
	}
	(*size)--;
}
void freeArrayStruct(car* cars, int size) {
	for (int i = 0; i < size; i++) {
		free(cars[i].model);
	}
	free(cars);
}


