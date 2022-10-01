#include <stdio.h>

int main(void)
{
	int a, b, c;
	printf("Input the first number: ");
	scanf("%d", &a);
	printf("Input the second number: ");
	scanf("%d", &b);
	printf("Input the third number: ");
	scanf("%d", &c);
	
	if((a + b > c) && (b + c > a) && (c + a > b))
		printf("Perimeter = %d\n", a + b + c);
	else
		printf("Can't make a triangle!\n");
	return 0;
}
