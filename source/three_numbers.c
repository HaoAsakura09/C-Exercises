#include <stdio.h>

#define N 10

int main(void)
{
	int n;
	printf("Enter %d integers: ", N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &n);
		if(i % 3 == 0)
			printf(" %d, ", n);
	}
	
	return 0;
}
