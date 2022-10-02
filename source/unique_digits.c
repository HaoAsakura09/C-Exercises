#include <stdio.h>

#define N 10

int main(void)
{
	int num[N], occurences[N] = {0}, n;

	printf("Enter %d element in the array: ", N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
		n = num[i];
		++occurences[n];
	}

	// Print the unique digits; not repeated digits
	printf("The unique elements found in the array:");
	for (int i = 0; i < N; i++)
	{
		 if(occurences[i] < 2 && occurences[i] != 0)
		 	printf(" %d", i);
	}

	return 0;
}
