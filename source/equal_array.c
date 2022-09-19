#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LENGTH 26

void read_word(int counts[]);
bool equal_array(int counts1[], int counts2[]);

int main(void)
{
	int counts1[LENGTH] = { 0 },  counts2[LENGTH] = { 0 };
	
	printf("Enter first word: ");
	read_word(counts1);
	printf("Enter second word: ");
	read_word(counts2);
	
	if(equal_array(counts1, counts2))
		printf("They are equal.\n");
	else
		printf("They are not equal.\n");
	return 0;
}

void read_word(int counts[])
{
	int i = 0, ch;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF)
	{
			if(i < LENGTH)
				++counts[tolower(ch) - 'a'];
			ch = getchar();
			i++;
	}
}

bool equal_array(int counts1[], int counts2[])
{
	int i;
	
	for(i = 0; i < LENGTH; i++)
		if(counts1[i] != counts2[i])
			return false;
	return true;
}
