#include <stdio.h>

void swap(int *p, int *q);

int main(void)
{
	int x, y;
	printf("Enter value for x: ");
	scanf("%d", &x);
	printf("Enter value for y: ");
	scanf("%d", &y);
	
	printf("\n");
	printf("Before: x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("After: x = %d, y = %d\n", x, y);
	return 0;
}

void swap(int *p, int *q)
{
	int temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
}
