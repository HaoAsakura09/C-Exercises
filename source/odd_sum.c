#include <stdio.h>

int main(void)
{
	char *n[] = { "first", "second", "third", "fourth", "fifth" };
	
	int odd_sum = 0, i = 0, num;
	
	while(i < 5)
	{
		printf("Enter the %s number: ", n[i++]);
		scanf("%d", &num);
		
		if(num % 2 != 0)
			odd_sum += num;
	}
	
	printf("Sum of all odd values: %d\n", odd_sum);
	return 0;
}
