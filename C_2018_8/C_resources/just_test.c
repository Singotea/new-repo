#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
int main(void)
{
	int i = 1;
	long int num1 = 1, a = 0, b1 = 0;
	long long int b = 0;
	printf("input a new number : ");
	scanf_s("%d", &num1);
	printf("num1 = %d \n\n", num1);
	a = num1;
	/*printf("a = %d \n\n\n",a);*/
	while (a >= 1)
	{
		b1 = (int)(log(a) / log(2));
		printf("The %d time have found : b1 = %d \n\n\n", i, a);
		printf("b1 = %d and %d \n", b1, (int)pow(2, b1));
		a = a - (int)pow(2, b1);
		printf("a = %d \n", a);
		printf("answer i = %d \n\n", i);
		b += 1 * pow(10, b1);
		printf("b = %lld\n\n", b);
		i++;
	}
	printf("the number cuts to : %lld\n\n", b);

	system("pause");
}