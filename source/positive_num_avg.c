#include <stdio.h>

int main(void)
{
	char *n[] = { "first", "second", "third", "fourth", "fifth" };
	
	int num, positive_num = 0, sum = 0, i = 0;
	double positive_average;
	
	while(i < 5)
	{
		printf("Enter the %s number: ", n[i++]);
		scanf("%d", &num);
		if(num > 0)
		{
			positive_num++;
			sum += num;
		}
	}
	
	positive_average = sum / positive_num;
	printf("Number of positive numbers: %d\n", positive_num);
	printf("Average value of the said positive numbers: %.2f\n", positive_average);
	return 0;
}
