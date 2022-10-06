#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_LEN 50

int read_line(char str[], int len);

int main(void)
{
	char txt[MAX_LEN + 1], *p = txt;
	int num;
	 bool is_digit_seen = false;
	read_line(txt, MAX_LEN);

	while (*p != '\0')
	{
		if (isdigit(*p))
		{
			num = (int)strtol(p, &p, 10);
			is_digit_seen = true;
		}
		else 
			printf("%c", *p);
		
		if(*p == ' ' && is_digit_seen)
		{
			switch(num)
			{
			case 0: printf("zero "); break;
			case 1: printf("one "); break;
			case 2: printf("two "); break;
			case 3: printf("three "); break;
			case 4: printf("four "); break;
			case 5: printf("five "); break;
			case 6: printf("six "); break;
			case 7: printf("seven "); break;
			case 8: printf("eight "); break;
			case 9: printf("nine "); break;
			}
			
			if(num == 10)
				printf("ten ");
			num = 0;
			is_digit_seen = false;
		}
		p++;
  }

	return 0;
}


int read_line(char str[], int len)
{
	int ch, i = 0;
	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF)
	{
		if (i < len)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}
