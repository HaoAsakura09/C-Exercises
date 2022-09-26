#include <stdbool.h>
#include <stdio.h>
#include <math.h>

struct Calculator
{
	double first_operand;
	char operator;
	double  second_operand;
};

struct Calculator calculate(struct Calculator c)
{
	printf("Enter first operand: ");
	scanf("%lf", &c.first_operand);
	printf("Enter operator (+, -, *, /): ");
	scanf(" %c", &c.operator);
	printf("Enter second operand: ");
	scanf("%lf", &c.second_operand);
	
	return c;
}

double result(struct Calculator c);
bool check_operator(char operator);

int main(void)
{
	bool is_operator_valid = false;
	struct Calculator calculator;
	
	float num1, num2, operation_result;	
   
	for(;;)
	{
		calculator = calculate(calculator);
		if(calculator.second_operand == '/' && calculator.second_operand == 0)
		{
			printf("Cannot be divided by 0\n");
			break;
		}
		
		is_operator_valid = check_operator(calculator.operator);		if(!is_operator_valid)
		{
			printf("Invalid operator!\n");
			break;
		}
		
		num1 = calculator.first_operand;
		num2 = calculator.second_operand;
		operation_result = result(calculator);
		
		num1 -= (int)calculator.first_operand;
		num2 -= (int)calculator.second_operand;
		operation_result = operation_result - (int)operation_result;
		
		if(num1 == 0 && num2 == 0 && operation_result == 0)
		{
			printf("%d %c %d = %d\n", (int)calculator.first_operand, 		calculator.operator, (int)calculator.second_operand, 		(int)result(calculator));
		}
		else if(operation_result == 0)
		{
			printf("%f %c %f = %d\n",  calculator.first_operand, 		calculator.operator, calculator.second_operand, 		(int)operation_result);
		}
		else
		{
				printf("%f %c %f = %f\n", calculator.first_operand, calculator.operator, calculator.second_operand, result(calculator));
		}
		
		if(calculator.first_operand == 0 && calculator.second_operand == 0)
			break;
	}
	return 0;
}

double result(struct Calculator c)
{
	switch(c.operator)
	{
		case '+': return c.first_operand + c.second_operand;
		case '-': return c.first_operand - c.second_operand;
		case '*': return c.first_operand * c.second_operand;
		case '/': return c.first_operand / c.second_operand;
	}
}

bool check_operator(char operator)
{
	switch(operator)
	{
		case '+': return true;
		case '-': return true;
		case '*': return true;
		case '/': return true;
		default: return false;
	}
}
