#include <stdbool.h>
#include <stdio.h>

#define N 50

bool is_alnum(const char *s);
int read_input(char s[], int n);

int main(void)
{
	char str[N  + 1];
	printf("This program checks if there's alphanumeric in your string.\n");
	printf("Enter a string: ");
	read_input(str, N);
	
	if(is_alnum(str))
		printf("String contains alphanumeric.\n");
	else
		printf("String doesn't contain alphanumeric\n");
	return 0;
}

int read_input(char s[], int n)
{
	int c, i = 0;
	
	while((c = getchar()) != '\n')
		if(i < n)
			s[i++] = c;
		s[i] = '\0';
		
	return i;
}

bool is_alnum(const char *s)
{
	while(*s++ != '\0')
		if(*s >= '0' && *s<= '9')
			return true;
	return false;
}
