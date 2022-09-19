#include <stdio.h>

long sum_even(long n);

int main(void)
{
	long n;
	printf("Enter a number: ");
	scanf("%ld", &n);
	
	printf("Sum of even numbers: %ld\n", sum_even(n));
	return 0;
}

long sum_even(long n)
{
	long sum = 0;
	for(int i = 1; i < n; i++)
		if(i % 2 == 0) 
			sum += i;
	
	return sum;
}
