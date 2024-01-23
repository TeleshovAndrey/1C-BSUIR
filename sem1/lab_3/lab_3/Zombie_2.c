//#include <stdio.h>
//#include <stdlib.h>
//int main() {
//	int max_el_v, max_el_u, mass_v[100], mass_u[100], mass3[200], max_el3, suport;
//	
//	printf("Vvedite max el ms1 \n");
//	scanf_s("%d", &max_el_v);
//	
//	
//	printf("Vvedite max el ms2 \n");
//	scanf_s("%d", &max_el_u);
//	
//	
//	printf("Vvedite el ms2 po vosrastaniu\n");
//	for (int count_i=0; count_i< max_el_v; count_i++)
//		while (scanf_s(" %d", &mass_v[count_i]) == 0 || mass_v[count_i] > 10000 || mass_v[count_i] < -10000 || getchar() != '\n') //Проверка на ввод значений эл-тов массива
//		{
//			printf("This number don't suitable, try again (limit(-10000 to 10000))\n");
//			rewind(stdin);
//		}
//	
//	
//	printf("Vvedite el ms1 po ubivaniu\n");
//	for (int count_i = 0; count_i < max_el_u; count_i++)
//		while (scanf_s(" %d", &mass_u[count_i]) == 0 || mass_u[count_i] > 10000 || mass_u[count_i] < -10000 || getchar() != '\n') //Проверка на ввод значений эл-тов массива
//		{
//			printf("This number don't suitable, try again (limit(-10000 to 10000))\n");
//			rewind(stdin);
//		}
//
//	max_el3 = max_el_v + max_el_u;
//	for (int u = 0,v=max_el_v-1, count=0; count < max_el3; count++) {
//		if (mass_v[v] > mass_u && v>=0 && u<max_el_u) {
//			mass3[count] = mass_v[v];
//			v--;
//		}
//		else if (mass_u[u] > mass_v[v] && v >= 0 && u < max_el_u)
//		{
//			mass3[count] = mass_u[u];
//			u++;
//		}
//		else {
//			if (v >= 0) {
//				mass3[count] = mass_v[v];
//				v--;
//			}
//			else if (u < max_el_u) {
//				mass3[count] = mass_u[u];
//				u++;
//			}
//		}
//	}
//	printf("Resulting mass3 sorted po ubivaniu \n");
//	for (int i = 0; i < max_el3; i++) {
//		printf("mass3[%d]=%d \n", i, mass3[i]);
//	}
//		
//} 
