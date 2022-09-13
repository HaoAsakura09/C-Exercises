#include <stdio.h>
#include <string.h>

#define LEN 25

struct person_name
{
	char first_name[LEN + 1];
	char middle_initial;
	char last_name[LEN + 1];
};

struct student
{
	struct person_name name;
	int id, age;
	char sex;
}person1, person2;

void print_struct(struct person_name p);

int main(void)
{
	strcpy(person1.name.first_name, "Beach");
	print_struct(person1.name);
	return 0;
}

void print_struct(struct person_name p)
{
	printf("Name: %s\n", p.first_name);
}
