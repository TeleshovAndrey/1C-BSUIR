#include "functions.h"
int main() {
	int choise;
	setlocale(LC_ALL, "Rus");
	printf("\n Welcome to lab_7! \n");
	printf(" Select a task \n");
	printf("1) Дана строка.Найти самое часто встречающееся слово в ней\n");
	printf("2) Дан символ C и строки S, S0. Удалить все слова, начинающиеся с символа C из строки S которых нет в строке S0\n");
	scanfSecure(&choise, 1, 2);

	void (*function[2])() = { &task1, &task2 };
	function[choise - 1]();
	return 0;
}