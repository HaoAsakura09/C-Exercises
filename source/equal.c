#include <stdio.h>

int main(void)
{
	int num1, num2;
	
	printf("Simple program that prints out to the screen whether the two numbers are equal or not.\n\n");
	
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);
	
	if(num1 == num2)
		printf("num1 and num2 are equal.\n");
	else
		printf("num1 and num2 are not equal.\n");
		
	return 0;
}
