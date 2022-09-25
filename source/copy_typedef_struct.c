#include <stdio.h>

struct person
{
	int age;
	char name[20];
};

//using typedef
typedef struct
{
	int age;
	char name[20];
}Person_typedef;

int main(void)
{
	 //copying struct
	 //  They are declared on same struct tag named person
	 struct person person1 = { 100, "Mario" };
	 struct person person2 = person1;
	 
	 printf("person1:\n");
	 printf("Name: %s, Age: %d\n", person1.name, person1.age);
	 printf("person2:\n");
	 printf("Name: %s, Age: %d\n", person2.name, person2.age);
	 
	 //using typedef
	 Person_typedef person_typedef = { .age = 100, .name = "Luigi" };
	 printf("Person from typedef\n");
	 printf("Name: %s\n", person_typedef.name);
	 printf("Age: %d\n", person_typedef.age);
	 
	 //copying
	 Person_typedef person2_typedef = person_typedef;
	return 0;
}
