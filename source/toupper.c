#include <stdio.h>

#define TOUPPER(c) (((c) <= 'a' && (c) <= 'z') ? (c) - 'a' + 'A' : (c))

int main(void)
{
	char c;
	printf("This program converts any lowercase letter to uppercase using function-like macro.\n");
	printf("Enter a letter: ");
	scanf("%c", &c);
	
	printf("%c", TOUPPER('a'));
	return 0;
}
