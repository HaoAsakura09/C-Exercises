#include <stdio.h>

void sum_number(int *x, int *y, int *sum);

int main(void)
{
	int x, y, sum;
	printf("Input the first number: ");
	scanf("%d", &x);
	printf("Input the second number: ");
	scanf("%d", &y);
	
	sum_number(&x, &y, &sum);
	
	printf("The sum of %d and %d is %d\n", x, y, sum);
	return 0;
}

void sum_number(int *x, int *y, int *sum)
{
	*sum = *x + *y;
}
