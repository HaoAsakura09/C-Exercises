#include <stdio.h>

int get_sum(int n);

int main(void)
{
	int n, sum_return;
	printf("Enter how many numbers you want to add: ");
	scanf("%d", &n);
	
	sum_return = get_sum(n);
	
	printf("Total sum of from 1 to n: %d\n", sum_return);
	return 0;
}

int get_sum(int n)
{
	int sum = 0;
	
	for(int i = 1; i <= n; i++)
		sum += i;
	return sum;
}
