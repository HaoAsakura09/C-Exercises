#include <stdbool.h>
#include <stdio.h>

bool is_divisible(int n);

int main(void)
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	if(is_divisible(n))
		printf("%d is divisible by 2.\n", n);
	else
		printf("%d is not divisible by 2.\n", n);
	return 0;
}

bool is_divisible(int n)
{
	return n % 2 == 0;
}
