#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

#define WORD_LEN 20

bool pattern(const char *str, char ch);
int read_line(char str[], int n);

int main(void)
{
	char word[WORD_LEN], letter;
	
	printf("Enter a word: ");
	read_line(word, WORD_LEN);
	printf("Enter a letter that you want to find in word: ");
	scanf(" %c", &letter);
	
	if(pattern(word, letter))
		printf("letter %c is found in %s\n", letter, word);
	else
		printf("letter %c is not found in %s\n", letter, word);
	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))
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

bool pattern(const char *str, char ch)
{
	while(*str != '\0')
	{
		if(toupper(*str++) == toupper(ch))
			return true;
	}
	
	return false;
}
