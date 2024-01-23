#include <stdio.h>
#include <stdlib.h>

int main() {
	int DuoMass[100][100] = { 0 }, row, col, choise, characters[100] = { 0 }, sum_col[100] = { 0 }, suport_col[100] = { 0 }, suport_characters;

	//Функция на ввод и проверку строк матрици
	printf("Enter number of row \n");
	while (scanf_s("%d", &row) == 0 || row <= 0 || row > 100 || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}

	//Функция на ввод и проверку столбцев матрици
	printf("Enter number of columns \n");
	while (scanf_s("%d", &col) == 0 || col <= 0 || col > 100 || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}

	//Выбор (Рандомный или самостоятельный ввод)
	printf("How do you want to enter the values? \n 1)Youself \n 2)Random \n");
	while (scanf_s("%d", &choise) == 0 || choise != 1 && choise != 2 || getchar() != '\n')
	{
		printf("Error, try again");
		rewind(stdin);
	}

	//Vvod elements matrix samomu
	if (choise == 1)
		for (int j = 0; j < row; j++) {
			for (int i = 0; i < col; i++) {
				printf("Enter matrix[%d][%d] \n", j + 1, i + 1);
				while (scanf_s(" %d", &DuoMass[j][i]) == 0 || DuoMass[j][i] > 10000 || DuoMass[j][i] < -10000 || getchar() != '\n')
				{
					printf("This number don't suitable, try again (limit(-10000 to 10000))\n");
					rewind(stdin);
				}
			}
		}
	//Vvod randomno
	else
		for (int j = 0; j < col; j++)
			for (int i = 0; i < row; i++) DuoMass[j][i] = -100 + rand() % 201;

	//Подсчёт характеристики в каждом столбце
	for (int count_j = 0; count_j < row; count_j++)
		for (int count_i = 0; count_i < col; count_i++)
			if (DuoMass[count_j][count_i] < 0)
				characters[count_i] -= DuoMass[count_j][count_i];


	//Сортировка столбцев по их характеристикам в порядке возрастания 
	for (int col_i = 0; col_i < col; col_i++)
		for (int col_j = col - 1; col_j > col_i; col_j--)
			if (characters[col_j - 1] < characters[col_j])
			{
				suport_characters = characters[col_j - 1]; // замена j-1 и j элементов
				characters[col_j - 1] = characters[col_j];
				characters[col_j] = suport_characters;

				for (int k = 0; k < row; k++) {
					suport_col[k] = DuoMass[k][col_j - 1];
					DuoMass[k][col_j - 1] = DuoMass[k][col_j];
					DuoMass[k][col_j] = suport_col[k];
				}
			}

	//Вывод получившейся матрицы
	printf("Resulting matrix\n");
	for (int output_i = 0; output_i < row; output_i++) {
		for (int output_k = 0; output_k < col; output_k++)
			printf("%d ", DuoMass[output_i][output_k]);
		printf("\n");
	}

	//подсчёт и вывод получившейся суммы столбцев там где есть характеристика
	for (int sum_i = 0; sum_i < col; sum_i++) {
		if (characters[sum_i] != 0) {
			for (int count = 0; count < row; count++)
				sum_col[sum_i] += DuoMass[count][sum_i];
			printf("Sum_col_%d=%d\n", sum_i + 1, sum_col[sum_i]);
		}
	}
	return 0;
}
