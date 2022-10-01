#include <stdio.h>

int main(void)
{
	char *n[] = { "first", "second", "third", "fourth", "fifth" };
	
	int sum_odd = 0, num;
	for(int i = 0; i < 5; i++)
	{
		printf("Enter the %s mumber: ", n[i]);
		scanf("%d", &num);
		
		if(num % 2 != 0)
			sum_odd += num;
	}
	
	printf("Sum of all odd values: %d\n", sum_odd);
	return 0;
}
