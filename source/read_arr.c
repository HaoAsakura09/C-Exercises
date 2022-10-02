#include <stdio.h>

#define N 10

int main(void)
{
	int arr[N];
	printf("Input %d elements in the array: \n", N);
	for(int i = 0; i < N;  i++)
	{
		printf("Enter element-%d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	printf("Elements in array are:");
	for(int i = 0; i < N; i++)
		printf(" %d", arr[i]);
	return 0;
}
