#include "read_input.h"
#include <ctype.h>
#include <stdio.h>

int read_input(char str[], int n)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))			//Ignores space
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}
