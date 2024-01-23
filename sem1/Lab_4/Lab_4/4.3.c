#include <stdio.h>
#include <stdlib.h>
/*
В квадратной матрице размером NxN найти сумму элементов в 2-ой области
*/
int main() {
	int row, col, choise, DuoMass[100][100] = { 0 }, end_row, start_col, sum=0;
	//Функция на ввод и проверку стороны квадратной матрицы
	printf("Enter number of row \n");
	while (scanf_s("%d", &row) == 0 || row <= 0 || row > 100 || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}

	col = row;

	//Выбор (Рандомный или самостоятельный ввод)
	printf("How do you want to enter the values? \n 1)Youself \n 2)Random \n");
	while (scanf_s("%d", &choise) == 0 || choise != 1 && choise != 2 || getchar() != '\n')
	{
		printf("Error, try again\n");
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

	printf("Start matrix\n");
	for (int row_count = 0; row_count < row; row_count++) {
		for (int col_count = 0; col_count < col; col_count++) {
			printf("%d ", DuoMass[row_count][col_count]);
		}
		printf("\n");
	}

	//Устанавливаем границы
	if (row % 2 == 0) {
		end_row = row / 2;
		start_col = col / 2+1;
	}
	else {
		end_row = row / 2 + 1;
		start_col = col / 2 + 1;
	}

	//Получившаяся матрица
	printf("The resulting part of the matrix\n");
	for (int row_i=0; row_i < end_row; row_i++) {
		for (int col_i = start_col-1; col_i < col; col_i++) {
			sum += DuoMass[row_i][col_i];
			printf("%d ", DuoMass[row_i][col_i]);
		}
		printf("\n");
	}
	printf("Sum_part = %d", sum);
	return 0;
}