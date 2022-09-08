/* Test whether a number is prime */
#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n);

int main(void)
{
	int n;
	
	printf("Enter a mumber: ");
	scanf("%d", &n);
	if(is_prime(n))
		printf("Prime\n");
	else
		printf("Not Prime.\n");

	return 0;
}

bool is_prime(int n)
{
	int divisor;
	// A prime number is not less than or equal to one
	// and only divisible by itself.
	if(n <= 1)
		return false;
	// The loop checks if the number is divisble by divisor
	// if so, return false
	for(divisor = 2; divisor * divisor <= n; divisor++)
		if(divisor % n == 0)
			return false;
		return true;
}
