//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int choise, mass1[100],j, el_mass3, el_mass1, el_mass2, mass2[100],mass3[200], empty_cell;
//	printf("Enter the number(1 to 100) of elements in the firts array\n");
//	while (scanf_s("%d", &el_mass1) == 0 || el_mass1 <= 0 || el_mass1 > 100 || getchar() != '\n') //�������� �� ���� ���-�� ��-�� ������� �������
//	{
//		printf("Error, try again\n");
//		rewind(stdin);
//	}
//	printf("Enter the number(1 to 100) of elements in the second array\n");
//	while (scanf_s("%d", &el_mass2) == 0 || el_mass2 <= 0 || el_mass2 > 100 || getchar() != '\n') //�������� �� ���� ���-�� ��-�� ������� �������
//	{
//		printf("Error, try again\n");
//		rewind(stdin);
//	}
//	printf("How do you want to set the values \n1)themselves \n2)randomly\n");
//	while (scanf_s("%d", &choise) == 0 || choise != 1 && choise != 2 || getchar()!='\n') //����� ������� � �������� �� ����
//	{
//		printf("Error, try again\n");
//		rewind(stdin);
//	}
//
//	if (choise == 1) {//������ � ��������������� ����������� �������
//		printf("Enter %d elements the first array\n", el_mass1);
//		for (int i=0; i < el_mass1; i++) // ������������ �������� ��-��� 1 ������� 
//		{
//			while (scanf_s("%d", &mass1[i]) == 0 || mass1[i] > 10000 || mass1[i] < -10000 || getchar() != '\n') //�������� �� ���� �������� ��-��� �������
//			{
//				printf("This number don't suitable, try again (limit(-10000 to 10000))\n");
//				rewind(stdin);
//			}
//		}
//
//		printf("Enter %d elements the first array\n", el_mass2);
//		for (int i=0; i < el_mass2; i++)//������������ ��-��� 2-��� ������� 
//		{
//			while (scanf_s("%d", &mass2[i]) == 0 || mass2[i] > 10000 || mass2[i] < -10000 || getchar() != '\n') //�������� �� ���� �������� ��-��� �������
//			{
//				printf("This number don't suitable, try again (limit(-10000 to 10000))\n");
//				rewind(stdin);
//			}
//		}
//	}
//	if (choise == 2) {//������ � ��������������� ����������� �������
//		printf("\nFilling the first array\n");
//		for (int i = 0; el_mass1 > i; i++) {
//			mass1[i] = -100 + rand() % 201;
//			printf("%d\n", mass1[i]);
//		}
//		printf("\nFilling the second array\n");
//		for (int i = 0; el_mass2 > i; i++) {
//			mass2[i] = -100 + rand() % 201;
//			printf("%d\n", mass2[i]);
//		}
//	}
//	for (int i = 0; i < el_mass1 - 1; ++i) // ���������� ��������� �� �������� 1 �������
//	{
//		for (int j = el_mass1 - 1; j > i; --j)
//		{
//			if (mass1[j - 1] < mass1[j])
//			{
//				empty_cell = mass1[j - 1];
//				mass1[j - 1] = mass1[j];
//				mass1[j] = empty_cell;
//			}
//		}
//	}
//	for (int i = 0; i < el_mass2 - 1; ++i)//���������� 2-��� ������� ��������� �� �����������
//	{
//		for (int j = el_mass2 - 1; j > i; --j)
//		{
//			if (mass2[j - 1] > mass2[j])
//			{
//				empty_cell = mass2[j - 1];
//				mass2[j - 1] = mass2[j];
//				mass2[j] = empty_cell;
//			}
//		}
//	}
//	printf("\nresulting first array\n");
//	for (int i = 0; i < el_mass1; i++) printf("mass1[%d]=%d\n", i, mass1[i]); //����� ������������� 1 �������
//	printf("\nresulting second array\n");
//	for (int i = 0; i < el_mass2; i++) printf("mass1[%d]=%d\n", i, mass2[i]);//����� ���������������� 2-��� �������
//
//	el_mass3 = el_mass1 + el_mass2;
//
//	//������� 2-�� �������� � 3-�� �� ��������
//	for (int u = 0, v = el_mass2 - 1, count = 0; count < el_mass3; count++) {
//		if (mass2[v] > mass1[u] && v >= 0 && u < el_mass1) {
//			mass3[count] = mass2[v];
//			v--;
//		}
//		else if (mass1[u] > mass2[v] && v >= 0 && u < el_mass1)
//		{
//			mass3[count] = mass1[u];
//			u++;
//		}
//		else {
//			if (v >= 0) {
//				mass3[count] = mass2[v];
//				v--;
//			}
//			else if (u < el_mass1) {
//				mass3[count] = mass1[u];
//				u++;
//			}
//		}
//	}
//	printf("\nThe resulting third array\n");
//	for (int i = 0; i < el_mass3; i++) printf("mass3[%d]=%d\n", i, mass3[i]);
//}