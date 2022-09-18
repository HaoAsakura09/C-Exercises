#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand((unsigned)time(NULL));
	int num_apples, num_get, your_apple = 0;
	
	for(;;)
	{
		num_apples = rand() % 100 + 1;
		if(num_apples == 0)
			continue;
		
		printf("Number of available apples: %d\n", num_apples);
		printf("How many apples do you want to get? You can take all the apples!\n");
		scanf("%d", &num_get);
		
		if(num_get > num_apples)
		{
			printf("There's only %d apple%c!\n", num_apples, (num_apples > 1) ? 's' : ' ');
		}
		else
			num_apples -= num_get;
		
		your_apple += num_get;
		if(num_apples == 0)
		{
			printf("No more apples left.\n");
			break;
		}
	}
	
	printf("You have got %d apples\n", your_apple);
	return 0;
}
