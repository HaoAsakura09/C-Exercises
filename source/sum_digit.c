#include <stdio.h>

long sum_digit(long n);

int main(void)
{
	long n;
	printf("Enter a number: ");
	scanf("%ld", &n);
	
	printf("Sum of digits: %ld\n", sum_digit(n));
	return 0;
}

long sum_digit(long n)
{
	long sum = 0;
	
	while(n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	
	return sum;
}
