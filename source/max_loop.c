#include <stdio.h>

int main(void)
{
	float max = 0.0f, num;
	
	printf("Enter a number: ");
	scanf("%f", &num);	
	
	while(num != 0)
	{
		if(num > max)
			max = num;
		printf("Enter a number: ");
		scanf("%f", &num);
	}
	
	printf("The largest number entered was %.2f\n", max);
	return 0;
}
