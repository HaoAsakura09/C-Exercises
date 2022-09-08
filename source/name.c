#include <ctype.h>
#include <stdio.h>

#define MAX_LEN 20

int read_input(char str[], int size);

int main(void)
{
	char name[MAX_LEN], initial = ' ';
	
	int i = 0, str_len;
	
	str_len = read_input(name, MAX_LEN);
			initial = name[i];
		
	while(name[i] != ' ')
	{
		i++;
	}
	
	i++; 
	
	while(i < str_len)
	{
		printf("%c", name[i]);
		i++;
	}
	
	printf(", %c\n", initial);
	return 0;
}

int read_input(char str[], int size)
{
	int i = 0, c;
	
	while((c = getchar()) != '\n')
	{

		if(i < size)
		{
			str[i] = c;
			i++;
		}
	}
	
	return i;
}
