//
//#include "arrays.h"
//
///*
//2.� ������� �������� NxM ������� ��� �������� �� �������� ���������
//*/
//int main() {
//	int** matrix;
//	int row=1, col=0;
//	
//	while (row != col)
//	{
//		printf("Enter row \n");
//		input_secure(&row);
//
//		printf("Enter col \n");
//		input_secure(&col);
//
//		if (row != col) printf("Try again\n");
//	}
//	matrix = (int**)malloc(row * sizeof(int*));
//
//	input_matrix(row, col, matrix);
//	
//	printf("Start matrix \n");
//	output_matrix(row, col, matrix);
//	
//	delete_side_diagonal(row, col, matrix);
//	col -= 1;
//	
//	printf("\n Resulting matrix \n");
//	output_matrix(row, col, matrix);
//	
//
//	free_matrix(row, matrix);
//
//// 1 2 
//// 1 3
//// 2 3 
//
////���� ������� NxM ���� ������� ��� �������� �� ���������� ��������� � ������ ���������
//}
//	