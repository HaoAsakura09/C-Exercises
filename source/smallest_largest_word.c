#include <stdio.h>
#include <string.h>

#define LEN 10

int read_line(char *str, int len);

int main(void)
{
	char word[LEN - 1], smallest[LEN - 1], largest[LEN - 1];
	int word_length;
	
	printf("Enter word: ");
	word_length = read_line(word, LEN - 1);
	
	strncpy(largest, word, sizeof(word) - 1);
	strncpy(smallest, word, sizeof(word) - 1);
	
	while(word_length != 4)
	{
		if(strcmp(word, largest) > 0)
			strncpy(largest, word, sizeof(word) - 1);
		else if(strcmp(word, smallest) < 0)
			strncpy(smallest, word, sizeof(word) - 1);
		printf("Enter word: ");
		word_length = read_line(word, LEN - 1);	
	}
	
	printf("Smallest: %s\n", smallest);
	printf("Largest: %s\n", largest);
	return 0;
}

int read_line(char *str, int len)
{
	int ch, i = 0;
	while((ch = getchar()) == ' ')
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < len)
			*str++ = ch;
		ch = getchar();
		i++;
	}
	*str = '\0';
	return i;
}
