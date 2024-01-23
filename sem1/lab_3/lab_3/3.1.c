#include <stdio.h>
#include <stdlib.h>
int main() 
{
	int array_el = 0, choise, i = 0, massiv[100], min=0,max=0, sum=0, counter=0;
	printf("Enter the number(1 to 100) of elements in the array\n");
	while (scanf_s("%d", &array_el) == 0 || array_el <= 0 || array_el >100 || getchar()!='\n') //Проверка на ввод кол-во эл-ов массива
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
	printf("How do you want to set the values \n1)themselves \n2)randomly\n");
	while (scanf_s("%d", &choise) == 0 || choise != 1 && choise != 2 || getchar() != '\n') //Выбор условия и проверка на ввод
	{
			printf("Error, try again");
			rewind(stdin);
	}
	if (choise == 1) {
		while (i < array_el)
		{
			printf("massiv[%i]=", i);
			while (scanf_s(" %d", &massiv[i]) == 0 || massiv[i] > 10000 || massiv[i] < -10000 || getchar() != '\n') //Проверка на ввод значений эл-тов массива
			{
				printf("This number don't suitable, try again (limit(-10000 to 10000))\n");
				rewind(stdin);
			}
			if (massiv[i] < massiv[0]) massiv[0] = massiv[i];
			i++;
		}
	}
	else if (choise==2) {
		while (i < array_el)
		{
			massiv[i] = -100 + rand() % 201;
			if (massiv[i] < massiv[0]) massiv[0] = massiv[i];
			printf("massiv[%i]=%d\n", i, massiv[i]);
			i++;
		}
	}
	//Поиск максимального и минимального положительных значений
	for (int k = 0; k < array_el - 1; k++) {
		if (massiv[k] >= 0 && counter == 0) {
			min = k;
			counter += 1;
		}
		if (massiv[k] >= 0) max = i;
	}
	//Сложение элементов между минимальным и максимальным значениями
	for (int j = min+1; j < max-1; j++) sum += massiv[j];

	printf("Min value %d\n Sum = %d ", massiv[0],sum);	
	return 0;
}