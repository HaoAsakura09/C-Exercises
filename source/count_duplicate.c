#include <stdio.h>

#define N 10

int main(void)
{
	int num_duplicate[N] = { 0 }, num, n_duplicate = 0;
	int arr[N];
	printf("Enter %d elements in the array:\n", N);
	for(int i = 0; i < N; i++)
	{
		printf("Element-%d: ", i);
		scanf("%d", &arr[i]);
		
		num = arr[i];
		++num_duplicate[num];
	}
	
	printf("Total number of duplicate items found in the array is: ");
	for(int i = 0; i < N; i++)
		if(num_duplicate[i] > 1)
			n_duplicate++;
			
	printf("%d\n", n_duplicate);
	return 0;
}
