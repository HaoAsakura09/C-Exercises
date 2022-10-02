#include <stdio.h>

#define N 10

int main(void)
{
	int arr[N];
	printf("Enter %d integers: ", N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
		
	// reverse the array
	int i, j, temp;
	for(i = 0, j = N - 1; i < N / 2; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	printf("The reversal:");
	for(int i = 0; i < N; i++)
		printf(" %d", arr[i]);
	return 0;
}
