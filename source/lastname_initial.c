#include <stdio.h>

#define NAME_LEN 20

int read_line(char name[], int size);

int main(void)
{
	char name[NAME_LEN + 1];
	read_line(name, NAME_LEN);
	
	int i = 0;
	while(name[i] != '\0')
		printf("%c", name[i++]);
	return 0;
}

int read_line(char name[], int size)
{
	char initial = ' ';
	int ch, i = 0;
	
	while((ch = getchar()) != ' ')
		if(initial == ' ')
			initial = ch;
				
	while((ch = getchar()) != '\n' && ch != EOF)
	{
		if(i < size)
			name[i++] = ch;
	}
 	name[i++] = ',';
 	name[i++] = ' ';
 	name[i++] = initial;
 	name[i++] = '.';
 	name[i] = '\0';
	return i;
}
