#include <stdio.h>

int main(void)
{
	char *n[] = {"first", "second", "third", "fourth", "fifth"};
	
	int num, positive_num = 0, negative_num = 0, i = 0;
	
	while(i < 5)
	{
		printf("Enter the %s number: ", n[i++]);
		scanf("%d", &num);
		
		if(num > 0)
			positive_num++;
		else
			negative_num++;
	}
	
	printf("Number of postive numbers: %d\n", positive_num);
	printf("Number of negative numbers: %d\n", negative_num);
	return 0;
}
