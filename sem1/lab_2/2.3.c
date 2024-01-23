#include <stdio.h>
int main() {
	int n,f3=0,f2=1,f1=1;
	printf("Enter the Fibonacci number\n");
	scanf_s("%d", &n);
		while (n>f3)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
			if (n == f3) {
				printf("Previous fibonacci number is %d\n", f1);
				f3 = f1 + f2;
				printf("The next Fibonacci number is %d\n", f3);
				break;
			}
			if (n<f3)
				printf("The number is not a fibonacci number");
		}	
}
