#include <stdio.h>

#define N 10

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
	int a[N], i, largest, second_largest;
	printf("Enter %d integers: ", N);
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	find_two_largest(a, N, &largest, &second_largest);

	printf("First largest integer: %d\n", largest);
	printf("Second largest integer: %d\n", second_largest);
	return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
	int i;
	*largest = *second_largest = a[0];

	for (i = 0; i < n; i++)
	{
		if (a[i] > *largest)
			*largest = a[i];
	}
	
	for(i = 0; i < n; i++)
	{
		if(a[i] == *largest)
			continue;
		if(a[i] > *second_largest)
			*second_largest = a[i];
	}
}
