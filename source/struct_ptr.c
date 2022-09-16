#include <conio.h>
#include <ctype.h>
#include <stdio.h>

#define LEN 20

struct Name
{
	char *name;
};

void clear(void);
void set_name(struct Name *set_name, char name[], int n);
char *read_line(char name[], int n);

int main(void)
{
	struct Name assign_name;
	char my_name[LEN];
	
	set_name(&assign_name, my_name, LEN);
	clear();
	printf("Your name is shika shika %s\n", assign_name.name);
	return 0;
}

void set_name(struct Name *set_name, char name[], int n)
{
	set_name -> name = read_line(name, n);
}

char *read_line(char name[], int n)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && EOF)
	{
		if(i < n)
			name[i++] = ch;
		ch = getchar();
	}
	name[i] = '\0';
	return name;
}

void clear(void)
{
	clrscr();
}
