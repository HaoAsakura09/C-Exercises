#include <stdio.h>

int get_square(int n);

int main(void)
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	printf("Square of %d is %d\n", n, get_square(n));
	return 0;
}

int get_square(int n)
{
	return n * n;
}
