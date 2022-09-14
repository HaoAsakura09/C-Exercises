#include <stdio.h>

void print_result(int x, char ch, int y);
char operator(void);
int num(void);

int main(void)
{
	print_result(num(), operator(), num());
	return 0;
}

int num(void)
{
	printf("Enter a number: ");
	int d;
	scanf("%d", &d);
	
	return d;
}

char operator(void)
{
	printf("Enter operator: ");
	char c;
	scanf(" %c", &c);
	return c;
}

void print_result(int x, char ch, int y)
{
	int result = 0;
	
	switch(ch)
	{
		case '+': result = x + y; break;
		case '-': result = x - y; break;
		case '*': result = x * y; break;
		case '/': result = x / y; break;
		default: printf("Invalid operator!\n");
	}
	
	printf("%d %c %d = %d\n", x, ch, y, result);
}

