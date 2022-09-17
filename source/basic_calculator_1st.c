/* 2021 */
#include <stdio.h>

int main(void)
{
	int num1, num2, result;
	num1 = num2 = result = 0;
	
	char operator;
	
	printf("Basic Calculator\n");
	
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter an operator to be performed( +, - , *, / ): ");
	scanf(" %c", &operator);
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	if(num2 == 0)
	{
		printf("Cannot be divided by 0\n");
		return 0;
	}
	
	switch(operator)
	{
		case '+': result = num1 + num2; break;
		case '-': result = num1 - num2;	break;
		case '*': result = num1 * num2; break;
		case '/': result = num1 / num2; break;
		default: printf("Invalid Operator!\n"); return 0;
	}
	
	printf("%d %s %d is equal to %d", num1, (operator == '+') ? 																				"plus" : (operator == '-') ? "minus" : (operator == '*') ? "times" : "divided by", num2, result);
	return 0;
}
