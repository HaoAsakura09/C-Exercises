#include <stdio.h>

int even_sum(int n);
void print_even(int n);

int main(void)
{
	int n = 200;
	printf("Even numbers between 1-200\n");
	print_even(n);
	printf("\nSum of even numbers: %d\n", even_sum(n));
	return 0;
}

int even_sum(int n)
{
	int i, sum = 0;
	for(i = 1; i <= n; i++)
		if(i % 2 == 0)
			sum += i;
	return sum;
}

void print_even(int n)
{
	int i;
	for(i = 1; i <= n; i++)
		if(i % 2 == 0)
			printf(" %d", i);
}
