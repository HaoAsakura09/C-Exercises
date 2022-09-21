#include <stdio.h>

#define LEN 20

void get_info(char *name, int *age);

int main(void)
{
	char name[LEN];
	int age;
	get_info(&name, &age);
	
	printf("Your name: %s\n", name);
	printf("Your age: %d\n", age);
	return 0;
}

void get_info(char *name, int *age)
{
	int ch, i = 0;
	printf("Enter your name: ");
	while((ch = getchar()) != '\n')
		if(i < LEN)
			name[i++] = ch;
	name[i] = '\0';
	
	printf("Enter your age: ");
	scanf("%d", age);
}
