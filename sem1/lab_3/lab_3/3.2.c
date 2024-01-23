//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int choise,massiv[100],array_el,max=0,i=0;
//	printf("Enter the number(1 to 100) of elements in the array\n");
//	while (scanf_s("%d", &array_el) == 0 || array_el <= 0 || array_el > 100 || getchar()!='\n') //Проверка на ввод кол-во эл-ов массива
//	{
//		printf("Error, try again");
//		rewind(stdin);
//	}
//	printf("How do you want to set the values \n1)themselves \n2)randomly\n");
//	while (scanf_s("%d", &choise) == 0 || choise != 1 && choise != 2) //Выбор условия и проверка на ввод
//	{
//		printf("Error, try again");
//		rewind(stdin);
//	}
//	if (choise == 1) {
//		while (i < array_el)
//		{
//			printf("massiv[%i]=", i);
//			while (scanf_s(" %d", &massiv[i]) == 0 || massiv[i] > 10000 || massiv[i] < -10000 || getchar()!='\n') //Проверка на ввод значений эл-тов массива
//			{
//				printf("This number don't suitable, try again (limit(-10000 to 10000))\n");
//				rewind(stdin);
//			}
//			if (massiv[i] % 2 == 0) max = i;
//			i++;
//		}
//		
//	}
//	if (choise==2)	
//		for (int i = 0; array_el > i; i++) {
//			massiv[i] = -100 + rand() % 201;
//			printf("massiv[%d]=%d\n", i, massiv[i]);
//			if (massiv[i] % 2 == 0) max = i;
//		}
//	printf("Remaining array ");
//	for (int i = 0; i <= max; i++) printf("\n massiv[%d]=%d", i, massiv[i]);
//}