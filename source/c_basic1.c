#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch;
	printf("Enter a character: ");
	ch = getchar();
	
	if(isalpha(ch))
		printf("This is an alphabet character.\n");
	else if(isalnum(ch))
		printf("This is a alpha numeric character.\n");
	else
		printf("This is a special character.\n");
	return 0;
}
