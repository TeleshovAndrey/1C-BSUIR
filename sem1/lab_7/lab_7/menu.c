#include "functions.h"
int main() {
	int choise;
	setlocale(LC_ALL, "Rus");
	printf("\n Welcome to lab_7! \n");
	printf(" Select a task \n");
	printf("1) ���� ������.����� ����� ����� ������������� ����� � ���\n");
	printf("2) ��� ������ C � ������ S, S0. ������� ��� �����, ������������ � ������� C �� ������ S ������� ��� � ������ S0\n");
	scanfSecure(&choise, 1, 2);

	void (*function[2])() = { &task1, &task2 };
	function[choise - 1]();
	return 0;
}