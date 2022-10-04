#include <stdio.h>

int main(void)
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	printf("Find all the factors of %d:\n", n);
	printf("Factors\n");
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			printf(" %2d x %-2d = %3d\n", i, (n / i), (n / i) * i);
	}
	return 0;
}
