//#include "arrays.h"
//
///*
//3.В двумерном массиве 
//(количество чисел в строке может быть различным, последнее число - -100.) 
//в каждой четной строке продублировать нечетный элемент.
//*/
//
//int main () {
//	int **array;
//	int row;
//	
//	printf("Enter row");
//	input_secure(&row);
//
//	array = (int *)malloc(row * sizeof(int*));
//
//	input_duo_array(row, array);
//	printf("Start array\n");
//	output_duo_array(row, array);
//
//	add_odd_elements_even_lines(row, array);
//	printf("\nResult array\n");
//	output_duo_array(row, array);
//	
// 	free_matrix(row, array);
//	
//}
