// Program sorts the elements as you enter them
#include <stdio.h>

#define N 10

int main(void)
{
	int arr[N] = { 0 }, temp;
	
	printf("Enter %d element in the array:\n", N);
	for(int i = 0; i < N; i++)
	{
		printf("Enter the %d-element: ", i + 1);
		scanf("%d", &arr[i]);
		for(int j = 0; j < i; j++)
		{
			if(arr[j] > arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Elements in the array:");
	for(int i = 0; i < N; i++)
		printf(" %d", arr[i]);
	return 0;
}
