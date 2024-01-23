#include <stdio.h>
#include <stdlib.h>
/*
Проверить, все ли строки матрицы содержат хотя бы один положительный элемент.
Если да, то изменить знаки всех элементов матрицы на обратные
*/
int main() {
	int col, choise, row, DuoMass[100][100] = { 0 };
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

	//Просмтрт эл-тов мвтрицы 
	for (int row_i=0;row_i<row;row_i++)
		for (int col_j=0; col_j<col;col_j++)
			//Если хотя бы один эл-мент матрицы отрицательный то меняет знаки её элементов
			if (DuoMass[row_i, col_j] > 0) {
				printf("resulting matrix\n");
				for (int change_sign_row = 0; change_sign_row < row; change_sign_row++) {
					for (int change_sign_col = 0; change_sign_col < col; change_sign_col++) {
						DuoMass[change_sign_row][change_sign_col] *= -1;
						printf("%d ", DuoMass[change_sign_row][change_sign_col]);
					}
					printf("\n");
				}
				return 0;
			}
	printf("resulting matrix\n");
	for (int output_row = 0; output_row < row; output_row++) {
		for (int output_col = 0; output_col < col; output_col++) {
			printf("%d ", DuoMass[output_row][output_col]);
		}
		printf("\n");
	}
	return 0;
}