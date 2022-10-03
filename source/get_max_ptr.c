#include <stdio.h>

int *get_max(int *x, int *y);

int main(void)
{
	int a, b, *max;
	
	printf("Enter the first number: ");
	scanf("%d", &a);
	printf("Enter the second number: ");
	scanf("%d", &b);
	
	max = get_max(&a, &b);
	
	printf("%d is the maximum number.\n", *max);
	return 0;
}

int *get_max(int *x, int *y)
{
	return (*x > *y) ? x : y;
}
