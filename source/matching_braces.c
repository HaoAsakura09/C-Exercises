#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
int pop(void);

int main(void)
{
	bool is_match = false;
	int pos;
	char ch;

	printf("Enter parentheses and/or braces: ");

	while ((ch = getchar()) != '\n')
	{
		if (ch == ' ')
			continue;
		push(ch);
		
	  switch(ch)
	  {
	  	case ')':
	  	{
	  		pos = pop();
	  		if(contents[pos - 1] == '(' && contents[pos] == ')')
	  			is_match = true;
	  		else if(contents[pos - 1] != '(')
	  			is_match = false;
	  	} break;
	  	case '}':
	  	{
	  		pos = pop();
	  		if(contents[pos - 1] == '{' && contents[pos] == '}')
	  			is_match = true;
	  		else if(contents[pos - 1])
	  			is_match = false;
	  	}break;
	}
	}

	if (is_match)
		printf("Parenthesis/braces are nested properly.\n");
	else
		printf("Parenthesis/braces are not nested properly.\n");

	return 0;
}

bool is_empty(void)
{
	if (top == 0)
		return true;
	return false;
}

bool is_full(void)
{
	if (top == 100)
		return true;
	return false;
}

void push(char ch)
{
	if (is_full())
	{
		printf("Stack Overflow!\n");
		return;
	}
	else
	{
		contents[top++] = ch;
	}
}

int pop(void)
{
	if (is_empty())
	{
		printf("Stack Underflow!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		return --top;
	}
}
