#include <stdio.h>

void swap_var(int* a, int* b);

int main(void)
{
	int a, b;
	
	printf("Enter 2 integers: ");
	scanf("%d %d", &a, &b);
	
	printf("Before swap: a = %d, b = %d\n", a, b);
	swap_var(&a, &b);
	printf("After swap: a = %d, b = %d\n", a, b);
	return 0;
}

void swap_var(int* a, int* b)
{
	int temp = 0;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
