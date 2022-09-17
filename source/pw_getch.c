#include <conio.h>
#include <ctype.h>
#include <stdio.h>

int read_input( char str[], int n);

int main(void)
{
	char password[50];
	printf("Enter your password: ");
	read_input(password, 49);
	
	int i = 0;
	printf("\n");
	printf("Your password in ASCII: ");
	while(password[i] != '\0')
		printf("%d", password[i++]);
	return 0;
}

int read_input( char str[], int n)
{
	int ch, i = 0;
	while(isspace(ch = getch()))
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < n && ch != 127)
		{
			printf("*");
			str[i++] = ch;
		}
		ch = getch();	
	}
	str[i] = '\0';
	return i;
}
