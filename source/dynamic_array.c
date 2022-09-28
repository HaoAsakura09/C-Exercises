#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 10;
	int *a = malloc(n * sizeof(n));
	
	if(a == NULL)
	{
		printf("Malloc failed to alocate memory for a.\n");
		return 0;
	}
	printf("Enter %d integers\n", n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	printf("Your entered");
	for(int i = 0; i < n; i++)
		printf(" %d", a[i]);
	return 0;
}
