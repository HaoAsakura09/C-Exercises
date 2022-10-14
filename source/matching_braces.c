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
	bool is_match = false, brace_paren, brace_curly;
	char ch, leftBrace;
  
	printf("Enter parentheses and/or braces: ");
   
	while ((ch = getchar()) != '\n')
	{
		// add to contents if the input is a brace
		if( ch == '(' || ch == ')' || ch == '{' || ch == '}' )
			push(ch);
	    
		brace_paren = brace_curly= false;

		switch(ch)
		{
			case ')': 
				brace_paren = true;
				--top; 
				leftBrace = contents[pop()]; break;
			case '}': 
				brace_curly = true;
				--top;
				leftBrace = contents[pop()]; break;
		}
		
	   if( brace_curly && leftBrace == '{' && ch == '}')
	   {
	   	is_match = true;
	   }
	   else if( brace_paren && leftBrace == '(' && ch == ')')
	   {
	   	is_match = true;
	   }
	}
	
	if (is_match && top == 0)
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
