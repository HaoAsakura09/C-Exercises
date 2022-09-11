#include <stdbool.h>
#include <stdio.h>

#define N 50

int str_compare(const char *s1, const char *s2);
int readline(char s[], int n);

int main(void)
{
	char str1[N - 1], str2[N - 1];
	int status;
	printf("My ugly program that compares two strings\n");

	printf("Enter string 1: ");
	readline(str1, N);
	printf("Enter string 2: ");
	readline(str2, N);

	status = str_compare(str1, str2);
	
	if (status < 0)
		printf("String 1 is less than String 2\n");
	else if (status == 1)
		printf("String 1 is greater than string 2\n");
	else if(status == 0)
		printf("String 1 is equal to String 2\n");

	return 0;
}

int readline(char s[], int n)
{
	int c, i = 0;
	while ((c = getchar()) != '\n')
		if (i < n)
			s[i++] = c;
	s[i] = '\0';

	return i;
}

int str_compare(const char *s1, const char *s2)
{
	for(;;)
	{		
		if(*s1 < *s2)
			return -1;
		else if(*s1 > *s2)
			return -1;
			
		while(*s1++ == *s2++)
			break;
			
		if(*s1 == '\0' && *s2 == '\0')
			return 0;
		else if(*s1 == '\0')
			return -1;
		else if(*s2 == '\0')
			return 1;
	}
}
