#include <stdio.h>

#define N 20

struct Part
{
	int age;
	char name[N + 1];
	int number;
};

void print_struct(struct Part part1);

int main(void)
{
	// Compound literals v1
	//print_struct((struct Part){ 27, "Jones Beach", 23 });
	
	// v2
	print_struct((struct Part) {.age = 27,
																 .name = "Jones Beach",
																 .number = 23});
	return 0;
}

void print_struct(struct Part part1)
{
	printf("Name: %s\n", part1.name);
	printf("Age: %d\n", part1.age);
	printf("Number: %d\n", part1.number);
}
