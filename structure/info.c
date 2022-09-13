#include <stdio.h>
#include <string.h>

#define N 20

struct Info
{
	int age;
	char name[N + 1];
};

struct Info Build_Info(char *name, int age)
{
	struct Info person;
	person.age = age;
	strcpy(person.name, name);
	
	return person;
};

void print_struct(struct Info person);
int get_age(void);
int read_input(char name[], int n);

int main(void)
{
	struct Info person;
	char name[N + 1];
	int age;
	
	printf("Enter your name: ");
	read_input(name, N);
	printf("Enter your age: ");
	age = get_age();
	
	person = Build_Info(name, age);
	
	print_struct(person);
	return 0;
}

int read_input(char name[], int n)
{
	int c, i = 0;
	
	while((c = getchar()) == ' ')
		;
	while(c != '\n')
	{
		if(i < n)
			name[i++] = c;
		c = getchar();
	}
	name[i] = '\0';
	
	return i;
}

int get_age(void)
{
	int age;
	scanf("%d", &age);
	
	return age;
}

void print_struct(struct Info person)
{
	printf("Name: %s\n", person.name);
	printf("Age: %d\n", person.age);
}
